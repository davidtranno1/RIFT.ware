/* Copyright (c) 2005-2008, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ---
 * Author: Markus Gutschke, Carl Crous
 *
 * Code to extract a core dump snapshot of the current process.
 */
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "google/coredumper.h"
#include "elfcore.h"
#include "linux_syscall_support.h"
#include "linuxthreads.h"
#include "thread_lister.h"
 
#define UNW_LOCAL_ONLY
#include <libunwind.h>
#define MAX_STACK_DEPTH 1024
#include "python3.3m/Python.h"
#include "python3.3m/frameobject.h"

static const char *const no_args_bzip2[]    = { "bzip2",    NULL };
static const char *const no_args_gzip[]     = { "gzip",     NULL };
static const char *const no_args_compress[] = { "compress", NULL };
const struct CoredumperCompressor COREDUMPER_COMPRESSED[] = {
  { "/bin/bzip2",        no_args_bzip2,    ".bz2" },
  { "/usr/bin/bzip2",    no_args_bzip2,    ".bz2" },
  { "bzip2",             no_args_bzip2,    ".bz2" },
  { "/bin/gzip",         no_args_gzip,     ".gz"  },
  { "/usr/bin/gzip",     no_args_gzip,     ".gz"  },
  { "gzip",              no_args_gzip,     ".gz"  },
  { "/bin/compress",     no_args_compress, ".Z"   },
  { "/usr/bin/compress", no_args_compress, ".Z"   },
  { "compress",          no_args_compress, ".Z"   },
  { "",                  0,                ""     },
  { 0,                   0,                0      } };
const struct CoredumperCompressor COREDUMPER_BZIP2_COMPRESSED[] = {
  { "/bin/bzip2",        no_args_bzip2,    ".bz2" },
  { "/usr/bin/bzip2",    no_args_bzip2,    ".bz2" },
  { "bzip2",             no_args_bzip2,    ".bz2" },
  { 0,                   0,                0      } };
const struct CoredumperCompressor COREDUMPER_GZIP_COMPRESSED[] = {
  { "/bin/gzip",         no_args_gzip,     ".gz"  },
  { "/usr/bin/gzip",     no_args_gzip,     ".gz"  },
  { "gzip",              no_args_gzip,     ".gz"  },
  { 0,                   0,                0      } };
const struct CoredumperCompressor COREDUMPER_COMPRESS_COMPRESSED[] = {
  { "/bin/compress",     no_args_compress, ".Z"   },
  { "/usr/bin/compress", no_args_compress, ".Z"   },
  { "compress",          no_args_compress, ".Z"   },
  { 0,                   0,                0      } };
const struct CoredumperCompressor COREDUMPER_TRY_BZIP2_COMPRESSED[] = {
  { "/bin/bzip2",        no_args_bzip2,    ".bz2" },
  { "/usr/bin/bzip2",    no_args_bzip2,    ".bz2" },
  { "bzip2",             no_args_bzip2,    ".bz2" },
  { "",                  0,                ""     },
  { 0,                   0,                0      } };
const struct CoredumperCompressor COREDUMPER_TRY_GZIP_COMPRESSED[] = {
  { "/bin/gzip",         no_args_gzip,     ".gz"  },
  { "/usr/bin/gzip",     no_args_gzip,     ".gz"  },
  { "gzip",              no_args_gzip,     ".gz"  },
  { "",                  0,                ""     },
  { 0,                   0,                0      } };
const struct CoredumperCompressor COREDUMPER_TRY_COMPRESS_COMPRESSED[] = {
  { "/bin/compress",     no_args_compress, ".Z"   },
  { "/usr/bin/compress", no_args_compress, ".Z"   },
  { "compress",          no_args_compress, ".Z"   },
  { "",                  0,                ""     },
  { 0,                   0,                0      } };
const struct CoredumperCompressor COREDUMPER_UNCOMPRESSED[] = {
  { "",                  0,                ""     },
  { 0,                   0,                0      } };


#ifndef DUMPER
/* If the target platform lacks the necessary support for generating core dumps
 * on the fly, or if nobody has ported the code, then return an error.
 */
typedef void *Frame;
#define FRAME(f) void *f = &&label; label:


int InternalGetCoreDump(void *frame, int num_threads, pid_t *thread_pids,
                        va_list ap) {
  errno = EINVAL;
  return -1;
}
#endif


/* Internal helper method used by GetCoreDump().
 */
static int GetCoreDumpFunction(void *frame,
                               const struct CoreDumpParameters *params) {
  return ListAllProcessThreads(frame, InternalGetCoreDump, params, NULL,
                               getenv("PATH"));
}

/* Returns a file handle that can be read to obtain a snapshot of the
 * current state of this process. If a core file could not be
 * generated for any reason, -1 is returned.
 *
 * This function momentarily suspends all threads, while creating a
 * COW copy of the process's address space.
 *
 * This function is neither reentrant nor async signal safe. Callers
 * should wrap a mutex around the invocation of this function, if necessary.
 *
 * The current implementation tries very hard to do behave reasonably when
 * called from a signal handler, but no guarantees are made that this will
 * always work.
 */
int GetCoreDump(void) {
  FRAME(frame);
  struct CoreDumpParameters params;
  ClearCoreDumpParameters(&params);
  return GetCoreDumpFunction(&frame, &params);
}

int GetCoreDumpWith(const struct CoreDumpParameters *params) {
  FRAME(frame);
  if ((params->flags & COREDUMPER_FLAG_LIMITED) ||
      (params->flags & COREDUMPER_FLAG_LIMITED_BY_PRIORITY)) {
    errno = EINVAL;
    return -1;
  }
  return GetCoreDumpFunction(&frame, params);
}

/* Attempts to compress the core file on the fly, if a suitable compressor
 * could be located. Sets "selected_compressor" to the compressor that
 * was picked.
 */
int GetCompressedCoreDump(const struct CoredumperCompressor compressors[],
                          struct CoredumperCompressor **selected_compressor) {
  FRAME(frame);
  struct CoreDumpParameters params;
  ClearCoreDumpParameters(&params);
  SetCoreDumpCompressed(&params, compressors, selected_compressor);
  return GetCoreDumpFunction(&frame, &params);
}

/* Re-runs fn until it doesn't cause EINTR.
 */
#define NO_INTR(fn)   do {} while ((fn) < 0 && errno == EINTR)


/* Internal helper method used by WriteCoreDump().
 */
static int WriteCoreDumpFunction(void *frame,
                                 const struct CoreDumpParameters *params,
                                 const char *file_name) {
  return ListAllProcessThreads(frame, InternalGetCoreDump, params, file_name,
                               getenv("PATH"));
}

/* Writes the core file to disk. This is a convenience method wrapping
 * GetCoreDump(). If a core file could not be generated for any reason,
 * -1 is returned. On success, zero is returned.
 */
int WriteCoreDump(const char *file_name) {
  FRAME(frame);
  struct CoreDumpParameters params;
  ClearCoreDumpParameters(&params);
  return WriteCoreDumpFunction(&frame, &params, file_name);
}

int WriteCoreDumpWith(const struct CoreDumpParameters *params,
                      const char *file_name) {
  FRAME(frame);
  return WriteCoreDumpFunction(&frame, params, file_name);
}

/* Callers might need to restrict the maximum size of the core file. This
 * convenience method provides the necessary support to emulate "ulimit -c".
 */
int WriteCoreDumpLimited(const char *file_name, size_t max_length) {
  FRAME(frame);
  struct CoreDumpParameters params;
  ClearCoreDumpParameters(&params);
  SetCoreDumpLimited(&params, max_length);
  return WriteCoreDumpFunction(&frame, &params, file_name);
}

/* This function will record important python debugging symbols in the
 * global array so that we do not remove the python debugging symbols
 * while truncating the core file.
 */
int g_debug_py_sz = 0; /* globals needed */
void *g_debug_py_frame[10*MAX_STACK_DEPTH];

void RwRecordPyStack()
{
  unw_cursor_t cursor; unw_context_t uc;
  unw_word_t off;
  char name[256];
  int depth = 0;
  int loopcnt;
  loopcnt = sizeof(g_debug_py_frame);

  g_debug_py_sz = 0;
  unw_getcontext(&uc);
  unw_init_local(&cursor, &uc);
  while (unw_step(&cursor) > 0) {
    // Avoid going too deep
    if (depth++ > MAX_STACK_DEPTH) {
      return;
    }

    if (unw_get_proc_name(&cursor, name, sizeof (name), &off) != 0) {
      return;
    }
    /* Check for Python backtrace */
    if (!strncmp(name,"PyEval_EvalFrameEx", 18)) {
      {
        unw_word_t bp;
        PyFrameObject *frame;
        int pydepth = 0;
        unw_get_reg(&cursor, UNW_X86_64_RBP, &bp);
        frame = (PyFrameObject*)bp;
        while (frame && (pydepth < loopcnt-10)) {
          g_debug_py_frame[pydepth++] = (void*) frame;        /* frame pointer */
          g_debug_py_frame[pydepth++] = (void*) frame->f_code;       /* code segment */
          g_debug_py_frame[pydepth++] = (void*) frame->f_builtins;   /* builtin symbol table (PyDictObject) */
          g_debug_py_frame[pydepth++] = (void*) frame->f_globals;    /* global symbol table (PyDictObject) */
          g_debug_py_frame[pydepth++] = (void*) frame->f_locals;     /* local symbol table (any mapping) */
          g_debug_py_frame[pydepth++] = (void*) frame->f_tstate;     /* State */
          g_debug_py_frame[pydepth++] = (void*) frame->f_exc_type;
          g_debug_py_frame[pydepth++] = (void*) frame->f_exc_value;
          g_debug_py_frame[pydepth++] = (void*) frame->f_exc_traceback;
          g_debug_py_frame[pydepth++] = (void*) frame->f_trace;

          frame = frame->f_back;
          pydepth++;
        }
        g_debug_py_sz = pydepth;
      }
      return;
    }
  }
}

/* This will limit the size of the core file by reducing or removing the
 * largest memory segments first, effectively prioritizing the smaller memory
 * segments. This behavior is preferred when the process has a large heap and
 * you would like to preserve the relatively small stack.
 */
int WriteCoreDumpLimitedByPriority(const char *file_name, size_t max_length) {
  RwRecordPyStack();
  FRAME(frame);
  struct CoreDumpParameters params;
  ClearCoreDumpParameters(&params);
  SetCoreDumpLimitedByPriority(&params, max_length);
  return WriteCoreDumpFunction(&frame, &params, file_name);
}

/* Attempts to compress the core file on the fly, if a suitable compressor
 * could be located. Sets "selected_compressor" to the compressor that
 * was picked. The filename automatically has a suitable suffix appended
 * to it. Normally this would be ".bz2" for bzip2 compression ".gz" for
 * gzip compression, or ".Z" for compress compression. This behavior can
 * be changed by defining custom CoredumperCompressor descriptions.
 */
int WriteCompressedCoreDump(const char *file_name, size_t max_length,
                            const struct CoredumperCompressor compressors[],
                            struct CoredumperCompressor **selected_compressor){
  FRAME(frame);
  struct CoreDumpParameters params;
  ClearCoreDumpParameters(&params);
  SetCoreDumpCompressed(&params, compressors, selected_compressor);
  SetCoreDumpLimited(&params, max_length);
  return WriteCoreDumpFunction(&frame, &params, file_name);
}

void ClearCoreDumpParametersInternal(struct CoreDumpParameters *params,
                                     size_t size) {
  memset(params, 0, size);
  params->size = size;
  SetCoreDumpParameter(params, max_length, SIZE_MAX);
}

int SetCoreDumpLimited(struct CoreDumpParameters *params, size_t max_length) {
  if (params->flags & COREDUMPER_FLAG_LIMITED_BY_PRIORITY) {
    errno = EINVAL;
    return -1;
  }
  params->flags |= COREDUMPER_FLAG_LIMITED;
  SetCoreDumpParameter(params, max_length, max_length);
  return 0;
}

int SetCoreDumpCompressed(struct CoreDumpParameters *params,
                          const struct CoredumperCompressor *compressors,
                          struct CoredumperCompressor **selected_compressor) {
  if (params->flags & COREDUMPER_FLAG_LIMITED_BY_PRIORITY) {
    errno = EINVAL;
    return -1;
  }
  SetCoreDumpParameter(params, compressors, compressors);
  SetCoreDumpParameter(params, selected_compressor, selected_compressor);
  return 0;
}

int SetCoreDumpLimitedByPriority(struct CoreDumpParameters *params,
                                 size_t max_length) {
  if (((params->flags & COREDUMPER_FLAG_LIMITED) &&
      !(params->flags & COREDUMPER_FLAG_LIMITED_BY_PRIORITY)) ||
      params->compressors != NULL) {
    errno = EINVAL;
    return -1;
  }
  SetCoreDumpParameter(params, flags, params->flags |
                       COREDUMPER_FLAG_LIMITED |
                       COREDUMPER_FLAG_LIMITED_BY_PRIORITY);
  SetCoreDumpParameter(params, max_length, max_length);
  return 0;
}

int SetCoreDumpNotes(struct CoreDumpParameters *params,
                     struct CoredumperNote *notes, int note_count) {
  SetCoreDumpParameter(params, notes, notes);
  SetCoreDumpParameter(params, note_count, note_count);
  return 0;
}
