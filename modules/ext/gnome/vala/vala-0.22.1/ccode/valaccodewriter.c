/* valaccodewriter.c generated by valac, the Vala compiler
 * generated from valaccodewriter.vala, do not modify */

/* valaccodewriter.vala
 *
 * Copyright (C) 2006-2009  Jürg Billeter
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Jürg Billeter <j@bitron.ch>
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <glib/gstdio.h>
#include <version.h>
#include <gobject/gvaluecollector.h>


#define VALA_TYPE_CCODE_WRITER (vala_ccode_writer_get_type ())
#define VALA_CCODE_WRITER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_WRITER, ValaCCodeWriter))
#define VALA_CCODE_WRITER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_WRITER, ValaCCodeWriterClass))
#define VALA_IS_CCODE_WRITER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_WRITER))
#define VALA_IS_CCODE_WRITER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_WRITER))
#define VALA_CCODE_WRITER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_WRITER, ValaCCodeWriterClass))

typedef struct _ValaCCodeWriter ValaCCodeWriter;
typedef struct _ValaCCodeWriterClass ValaCCodeWriterClass;
typedef struct _ValaCCodeWriterPrivate ValaCCodeWriterPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _fclose0(var) ((var == NULL) ? NULL : (var = (fclose (var), NULL)))
#define _g_mapped_file_free0(var) ((var == NULL) ? NULL : (var = (g_mapped_file_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define VALA_TYPE_CCODE_NODE (vala_ccode_node_get_type ())
#define VALA_CCODE_NODE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_NODE, ValaCCodeNode))
#define VALA_CCODE_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_NODE, ValaCCodeNodeClass))
#define VALA_IS_CCODE_NODE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_NODE))
#define VALA_IS_CCODE_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_NODE))
#define VALA_CCODE_NODE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_NODE, ValaCCodeNodeClass))

typedef struct _ValaCCodeNode ValaCCodeNode;
typedef struct _ValaCCodeNodeClass ValaCCodeNodeClass;

#define VALA_TYPE_CCODE_LINE_DIRECTIVE (vala_ccode_line_directive_get_type ())
#define VALA_CCODE_LINE_DIRECTIVE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_LINE_DIRECTIVE, ValaCCodeLineDirective))
#define VALA_CCODE_LINE_DIRECTIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_LINE_DIRECTIVE, ValaCCodeLineDirectiveClass))
#define VALA_IS_CCODE_LINE_DIRECTIVE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_LINE_DIRECTIVE))
#define VALA_IS_CCODE_LINE_DIRECTIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_LINE_DIRECTIVE))
#define VALA_CCODE_LINE_DIRECTIVE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_LINE_DIRECTIVE, ValaCCodeLineDirectiveClass))

typedef struct _ValaCCodeLineDirective ValaCCodeLineDirective;
typedef struct _ValaCCodeLineDirectiveClass ValaCCodeLineDirectiveClass;
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
typedef struct _ValaParamSpecCCodeWriter ValaParamSpecCCodeWriter;
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

struct _ValaCCodeWriter {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ValaCCodeWriterPrivate * priv;
};

struct _ValaCCodeWriterClass {
	GTypeClass parent_class;
	void (*finalize) (ValaCCodeWriter *self);
};

struct _ValaCCodeWriterPrivate {
	gchar* _filename;
	gchar* source_filename;
	gboolean _line_directives;
	gchar* temp_filename;
	gboolean file_exists;
	FILE* stream;
	gint indent;
	gint current_line_number;
	gboolean using_line_directive;
	gboolean _bol;
};

struct _ValaParamSpecCCodeWriter {
	GParamSpec parent_instance;
};


static gpointer vala_ccode_writer_parent_class = NULL;

gpointer vala_ccode_writer_ref (gpointer instance);
void vala_ccode_writer_unref (gpointer instance);
GParamSpec* vala_param_spec_ccode_writer (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_ccode_writer (GValue* value, gpointer v_object);
void vala_value_take_ccode_writer (GValue* value, gpointer v_object);
gpointer vala_value_get_ccode_writer (const GValue* value);
GType vala_ccode_writer_get_type (void) G_GNUC_CONST;
#define VALA_CCODE_WRITER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VALA_TYPE_CCODE_WRITER, ValaCCodeWriterPrivate))
enum  {
	VALA_CCODE_WRITER_DUMMY_PROPERTY
};
ValaCCodeWriter* vala_ccode_writer_new (const gchar* filename, const gchar* source_filename);
ValaCCodeWriter* vala_ccode_writer_construct (GType object_type, const gchar* filename, const gchar* source_filename);
void vala_ccode_writer_set_filename (ValaCCodeWriter* self, const gchar* value);
gboolean vala_ccode_writer_open (ValaCCodeWriter* self, gboolean write_version);
const gchar* vala_ccode_writer_get_filename (ValaCCodeWriter* self);
void vala_ccode_writer_write_string (ValaCCodeWriter* self, const gchar* s);
void vala_ccode_writer_write_newline (ValaCCodeWriter* self);
void vala_ccode_writer_close (ValaCCodeWriter* self);
gpointer vala_ccode_node_ref (gpointer instance);
void vala_ccode_node_unref (gpointer instance);
GParamSpec* vala_param_spec_ccode_node (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_ccode_node (GValue* value, gpointer v_object);
void vala_value_take_ccode_node (GValue* value, gpointer v_object);
gpointer vala_value_get_ccode_node (const GValue* value);
GType vala_ccode_node_get_type (void) G_GNUC_CONST;
GType vala_ccode_line_directive_get_type (void) G_GNUC_CONST;
void vala_ccode_writer_write_indent (ValaCCodeWriter* self, ValaCCodeLineDirective* line);
gboolean vala_ccode_writer_get_line_directives (ValaCCodeWriter* self);
void vala_ccode_node_write (ValaCCodeNode* self, ValaCCodeWriter* writer);
gboolean vala_ccode_writer_get_bol (ValaCCodeWriter* self);
void vala_ccode_writer_write_begin_block (ValaCCodeWriter* self);
void vala_ccode_writer_write_end_block (ValaCCodeWriter* self);
void vala_ccode_writer_write_comment (ValaCCodeWriter* self, const gchar* text);
void vala_ccode_writer_set_line_directives (ValaCCodeWriter* self, gboolean value);
static void vala_ccode_writer_finalize (ValaCCodeWriter* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


ValaCCodeWriter* vala_ccode_writer_construct (GType object_type, const gchar* filename, const gchar* source_filename) {
	ValaCCodeWriter* self = NULL;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	g_return_val_if_fail (filename != NULL, NULL);
	self = (ValaCCodeWriter*) g_type_create_instance (object_type);
	_tmp0_ = filename;
	vala_ccode_writer_set_filename (self, _tmp0_);
	_tmp1_ = source_filename;
	_tmp2_ = g_strdup (_tmp1_);
	_g_free0 (self->priv->source_filename);
	self->priv->source_filename = _tmp2_;
	return self;
}


ValaCCodeWriter* vala_ccode_writer_new (const gchar* filename, const gchar* source_filename) {
	return vala_ccode_writer_construct (VALA_TYPE_CCODE_WRITER, filename, source_filename);
}


/**
 * Opens the file.
 *
 * @return true if the file has been opened successfully,
 *         false otherwise
 */
gboolean vala_ccode_writer_open (ValaCCodeWriter* self, gboolean write_version) {
	gboolean result = FALSE;
	const gchar* _tmp0_ = NULL;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp2_ = FALSE;
	FILE* _tmp12_ = NULL;
	gchar* _tmp13_ = NULL;
	gboolean _tmp14_ = FALSE;
	gchar* opening = NULL;
	const gchar* _tmp23_ = NULL;
	gchar* _tmp24_ = NULL;
	const gchar* _tmp25_ = NULL;
	const gchar* _tmp26_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_filename;
	_tmp1_ = g_file_test (_tmp0_, G_FILE_TEST_EXISTS);
	self->priv->file_exists = _tmp1_;
	_tmp2_ = self->priv->file_exists;
	if (_tmp2_) {
		const gchar* _tmp3_ = NULL;
		gchar* _tmp4_ = NULL;
		const gchar* _tmp5_ = NULL;
		FILE* _tmp6_ = NULL;
		_tmp3_ = self->priv->_filename;
		_tmp4_ = g_strdup_printf ("%s.valatmp", _tmp3_);
		_g_free0 (self->priv->temp_filename);
		self->priv->temp_filename = _tmp4_;
		_tmp5_ = self->priv->temp_filename;
		_tmp6_ = g_fopen (_tmp5_, "w");
		_fclose0 (self->priv->stream);
		self->priv->stream = _tmp6_;
	} else {
		gchar* dirname = NULL;
		const gchar* _tmp7_ = NULL;
		gchar* _tmp8_ = NULL;
		const gchar* _tmp9_ = NULL;
		const gchar* _tmp10_ = NULL;
		FILE* _tmp11_ = NULL;
		_tmp7_ = self->priv->_filename;
		_tmp8_ = g_path_get_dirname (_tmp7_);
		dirname = _tmp8_;
		_tmp9_ = dirname;
		g_mkdir_with_parents (_tmp9_, 0755);
		_tmp10_ = self->priv->_filename;
		_tmp11_ = g_fopen (_tmp10_, "w");
		_fclose0 (self->priv->stream);
		self->priv->stream = _tmp11_;
		_g_free0 (dirname);
	}
	_tmp12_ = self->priv->stream;
	if (_tmp12_ == NULL) {
		result = FALSE;
		return result;
	}
	_tmp14_ = write_version;
	if (_tmp14_) {
		const gchar* _tmp15_ = NULL;
		gchar* _tmp16_ = NULL;
		gchar* _tmp17_ = NULL;
		gchar* _tmp18_ = NULL;
		_tmp15_ = self->priv->_filename;
		_tmp16_ = g_path_get_basename (_tmp15_);
		_tmp17_ = _tmp16_;
		_tmp18_ = g_strdup_printf ("/* %s generated by valac %s, the Vala compiler", _tmp17_, BUILD_VERSION);
		_g_free0 (_tmp13_);
		_tmp13_ = _tmp18_;
		_g_free0 (_tmp17_);
	} else {
		const gchar* _tmp19_ = NULL;
		gchar* _tmp20_ = NULL;
		gchar* _tmp21_ = NULL;
		gchar* _tmp22_ = NULL;
		_tmp19_ = self->priv->_filename;
		_tmp20_ = g_path_get_basename (_tmp19_);
		_tmp21_ = _tmp20_;
		_tmp22_ = g_strdup_printf ("/* %s generated by valac, the Vala compiler", _tmp21_);
		_g_free0 (_tmp13_);
		_tmp13_ = _tmp22_;
		_g_free0 (_tmp21_);
	}
	_tmp23_ = _tmp13_;
	_tmp24_ = g_strdup (_tmp23_);
	opening = _tmp24_;
	_tmp25_ = opening;
	vala_ccode_writer_write_string (self, _tmp25_);
	_tmp26_ = self->priv->source_filename;
	if (_tmp26_ != NULL) {
		const gchar* _tmp27_ = NULL;
		gchar* _tmp28_ = NULL;
		gchar* _tmp29_ = NULL;
		gchar* _tmp30_ = NULL;
		gchar* _tmp31_ = NULL;
		vala_ccode_writer_write_newline (self);
		_tmp27_ = self->priv->source_filename;
		_tmp28_ = g_path_get_basename (_tmp27_);
		_tmp29_ = _tmp28_;
		_tmp30_ = g_strdup_printf (" * generated from %s", _tmp29_);
		_tmp31_ = _tmp30_;
		vala_ccode_writer_write_string (self, _tmp31_);
		_g_free0 (_tmp31_);
		_g_free0 (_tmp29_);
	}
	vala_ccode_writer_write_string (self, ", do not modify */");
	vala_ccode_writer_write_newline (self);
	vala_ccode_writer_write_newline (self);
	result = TRUE;
	_g_free0 (opening);
	_g_free0 (_tmp13_);
	return result;
}


/**
 * Closes the file.
 */
void vala_ccode_writer_close (ValaCCodeWriter* self) {
	gboolean _tmp0_ = FALSE;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	_fclose0 (self->priv->stream);
	self->priv->stream = NULL;
	_tmp0_ = self->priv->file_exists;
	if (_tmp0_) {
		gboolean changed = FALSE;
		gboolean _tmp16_ = FALSE;
		changed = TRUE;
		{
			GMappedFile* old_file = NULL;
			const gchar* _tmp1_ = NULL;
			GMappedFile* _tmp2_ = NULL;
			GMappedFile* new_file = NULL;
			const gchar* _tmp3_ = NULL;
			GMappedFile* _tmp4_ = NULL;
			gsize len = 0UL;
			GMappedFile* _tmp5_ = NULL;
			gsize _tmp6_ = 0UL;
			gsize _tmp7_ = 0UL;
			GMappedFile* _tmp8_ = NULL;
			gsize _tmp9_ = 0UL;
			_tmp1_ = self->priv->_filename;
			_tmp2_ = g_mapped_file_new (_tmp1_, FALSE, &_inner_error_);
			old_file = _tmp2_;
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_FILE_ERROR) {
					goto __catch0_g_file_error;
				}
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
			_tmp3_ = self->priv->temp_filename;
			_tmp4_ = g_mapped_file_new (_tmp3_, FALSE, &_inner_error_);
			new_file = _tmp4_;
			if (_inner_error_ != NULL) {
				_g_mapped_file_free0 (old_file);
				if (_inner_error_->domain == G_FILE_ERROR) {
					goto __catch0_g_file_error;
				}
				_g_mapped_file_free0 (old_file);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return;
			}
			_tmp5_ = old_file;
			_tmp6_ = g_mapped_file_get_length (_tmp5_);
			len = _tmp6_;
			_tmp7_ = len;
			_tmp8_ = new_file;
			_tmp9_ = g_mapped_file_get_length (_tmp8_);
			if (_tmp7_ == _tmp9_) {
				GMappedFile* _tmp10_ = NULL;
				gchar* _tmp11_ = NULL;
				GMappedFile* _tmp12_ = NULL;
				gchar* _tmp13_ = NULL;
				gsize _tmp14_ = 0UL;
				gint _tmp15_ = 0;
				_tmp10_ = old_file;
				_tmp11_ = g_mapped_file_get_contents (_tmp10_);
				_tmp12_ = new_file;
				_tmp13_ = g_mapped_file_get_contents (_tmp12_);
				_tmp14_ = len;
				_tmp15_ = memcmp (_tmp11_, _tmp13_, _tmp14_);
				if (_tmp15_ == 0) {
					changed = FALSE;
				}
			}
			_g_mapped_file_free0 (old_file);
			old_file = NULL;
			_g_mapped_file_free0 (new_file);
			new_file = NULL;
			_g_mapped_file_free0 (new_file);
			_g_mapped_file_free0 (old_file);
		}
		goto __finally0;
		__catch0_g_file_error:
		{
			GError* e = NULL;
			e = _inner_error_;
			_inner_error_ = NULL;
			_g_error_free0 (e);
		}
		__finally0:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_tmp16_ = changed;
		if (_tmp16_) {
			const gchar* _tmp17_ = NULL;
			const gchar* _tmp18_ = NULL;
			_tmp17_ = self->priv->temp_filename;
			_tmp18_ = self->priv->_filename;
			g_rename (_tmp17_, _tmp18_);
		} else {
			const gchar* _tmp19_ = NULL;
			_tmp19_ = self->priv->temp_filename;
			g_unlink (_tmp19_);
		}
	}
}


/**
 * Writes tabs according to the current indent level.
 */
void vala_ccode_writer_write_indent (ValaCCodeWriter* self, ValaCCodeLineDirective* line) {
	gboolean _tmp0_ = FALSE;
	gboolean _tmp10_ = FALSE;
	gboolean _tmp11_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_line_directives;
	if (_tmp0_) {
		ValaCCodeLineDirective* _tmp1_ = NULL;
		_tmp1_ = line;
		if (_tmp1_ != NULL) {
			ValaCCodeLineDirective* _tmp2_ = NULL;
			_tmp2_ = line;
			vala_ccode_node_write ((ValaCCodeNode*) _tmp2_, self);
			self->priv->using_line_directive = TRUE;
		} else {
			gboolean _tmp3_ = FALSE;
			_tmp3_ = self->priv->using_line_directive;
			if (_tmp3_) {
				gint _tmp4_ = 0;
				const gchar* _tmp5_ = NULL;
				gchar* _tmp6_ = NULL;
				gchar* _tmp7_ = NULL;
				gchar* _tmp8_ = NULL;
				gchar* _tmp9_ = NULL;
				_tmp4_ = self->priv->current_line_number;
				_tmp5_ = self->priv->_filename;
				_tmp6_ = g_path_get_basename (_tmp5_);
				_tmp7_ = _tmp6_;
				_tmp8_ = g_strdup_printf ("#line %d \"%s\"", _tmp4_ + 1, _tmp7_);
				_tmp9_ = _tmp8_;
				vala_ccode_writer_write_string (self, _tmp9_);
				_g_free0 (_tmp9_);
				_g_free0 (_tmp7_);
				vala_ccode_writer_write_newline (self);
				self->priv->using_line_directive = FALSE;
			}
		}
	}
	_tmp10_ = vala_ccode_writer_get_bol (self);
	_tmp11_ = _tmp10_;
	if (!_tmp11_) {
		vala_ccode_writer_write_newline (self);
	}
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp12_ = FALSE;
			_tmp12_ = TRUE;
			while (TRUE) {
				gboolean _tmp13_ = FALSE;
				gint _tmp15_ = 0;
				gint _tmp16_ = 0;
				FILE* _tmp17_ = NULL;
				_tmp13_ = _tmp12_;
				if (!_tmp13_) {
					gint _tmp14_ = 0;
					_tmp14_ = i;
					i = _tmp14_ + 1;
				}
				_tmp12_ = FALSE;
				_tmp15_ = i;
				_tmp16_ = self->priv->indent;
				if (!(_tmp15_ < _tmp16_)) {
					break;
				}
				_tmp17_ = self->priv->stream;
				fputc ('\t', _tmp17_);
			}
		}
	}
	self->priv->_bol = FALSE;
}


/**
 * Writes the specified string.
 *
 * @param s a string
 */
void vala_ccode_writer_write_string (ValaCCodeWriter* self, const gchar* s) {
	FILE* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (s != NULL);
	_tmp0_ = self->priv->stream;
	_tmp1_ = s;
	fputs (_tmp1_, _tmp0_);
	self->priv->_bol = FALSE;
}


/**
 * Writes a newline.
 */
void vala_ccode_writer_write_newline (ValaCCodeWriter* self) {
	FILE* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->stream;
	fputc ('\n', _tmp0_);
	_tmp1_ = self->priv->current_line_number;
	self->priv->current_line_number = _tmp1_ + 1;
	self->priv->_bol = TRUE;
}


/**
 * Opens a new block, increasing the indent level.
 */
void vala_ccode_writer_write_begin_block (ValaCCodeWriter* self) {
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	FILE* _tmp3_ = NULL;
	gint _tmp4_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = vala_ccode_writer_get_bol (self);
	_tmp1_ = _tmp0_;
	if (!_tmp1_) {
		FILE* _tmp2_ = NULL;
		_tmp2_ = self->priv->stream;
		fputc (' ', _tmp2_);
	} else {
		vala_ccode_writer_write_indent (self, NULL);
	}
	_tmp3_ = self->priv->stream;
	fputc ('{', _tmp3_);
	vala_ccode_writer_write_newline (self);
	_tmp4_ = self->priv->indent;
	self->priv->indent = _tmp4_ + 1;
}


/**
 * Closes the current block, decreasing the indent level.
 */
void vala_ccode_writer_write_end_block (ValaCCodeWriter* self) {
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	FILE* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->indent;
	_vala_assert (_tmp0_ > 0, "indent > 0");
	_tmp1_ = self->priv->indent;
	self->priv->indent = _tmp1_ - 1;
	vala_ccode_writer_write_indent (self, NULL);
	_tmp2_ = self->priv->stream;
	fputc ('}', _tmp2_);
}


/**
 * Writes the specified text as comment.
 *
 * @param text the comment text
 */
void vala_ccode_writer_write_comment (ValaCCodeWriter* self, const gchar* text) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	{
		FILE* _tmp0_ = NULL;
		gboolean first = FALSE;
		GRegex* regex = NULL;
		GRegex* _tmp1_ = NULL;
		gchar** lines = NULL;
		const gchar* _tmp2_ = NULL;
		gchar** _tmp3_ = NULL;
		gchar** _tmp4_ = NULL;
		gint lines_length1 = 0;
		gint _lines_size_ = 0;
		gchar** _tmp5_ = NULL;
		gint _tmp5__length1 = 0;
		FILE* _tmp30_ = NULL;
		vala_ccode_writer_write_indent (self, NULL);
		_tmp0_ = self->priv->stream;
		fputs ("/*", _tmp0_);
		first = TRUE;
		_tmp1_ = g_regex_new ("^\t+", 0, 0, &_inner_error_);
		regex = _tmp1_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch1_g_regex_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_tmp2_ = text;
		_tmp4_ = _tmp3_ = g_strsplit (_tmp2_, "\n", 0);
		lines = _tmp4_;
		lines_length1 = _vala_array_length (_tmp3_);
		_lines_size_ = lines_length1;
		_tmp5_ = lines;
		_tmp5__length1 = lines_length1;
		{
			gchar** line_collection = NULL;
			gint line_collection_length1 = 0;
			gint _line_collection_size_ = 0;
			gint line_it = 0;
			line_collection = _tmp5_;
			line_collection_length1 = _tmp5__length1;
			for (line_it = 0; line_it < _tmp5__length1; line_it = line_it + 1) {
				gchar* _tmp6_ = NULL;
				gchar* line = NULL;
				_tmp6_ = g_strdup (line_collection[line_it]);
				line = _tmp6_;
				{
					gboolean _tmp7_ = FALSE;
					gchar* _tmp8_ = NULL;
					GRegex* _tmp9_ = NULL;
					const gchar* _tmp10_ = NULL;
					gchar* _tmp11_ = NULL;
					gchar** lineparts = NULL;
					gchar* _tmp12_ = NULL;
					gchar** _tmp13_ = NULL;
					gchar** _tmp14_ = NULL;
					gchar** _tmp15_ = NULL;
					gint _tmp15__length1 = 0;
					gint lineparts_length1 = 0;
					gint _lineparts_size_ = 0;
					_tmp7_ = first;
					if (!_tmp7_) {
						vala_ccode_writer_write_indent (self, NULL);
					} else {
						first = FALSE;
					}
					_tmp9_ = regex;
					_tmp10_ = line;
					_tmp11_ = g_regex_replace_literal (_tmp9_, _tmp10_, (gssize) (-1), 0, "", 0, &_inner_error_);
					_tmp8_ = _tmp11_;
					if (_inner_error_ != NULL) {
						_g_free0 (line);
						lines = (_vala_array_free (lines, lines_length1, (GDestroyNotify) g_free), NULL);
						_g_regex_unref0 (regex);
						if (_inner_error_->domain == G_REGEX_ERROR) {
							goto __catch1_g_regex_error;
						}
						_g_free0 (line);
						lines = (_vala_array_free (lines, lines_length1, (GDestroyNotify) g_free), NULL);
						_g_regex_unref0 (regex);
						g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
						g_clear_error (&_inner_error_);
						return;
					}
					_tmp12_ = _tmp8_;
					_tmp14_ = _tmp13_ = g_strsplit (_tmp12_, "*/", 0);
					_tmp15_ = _tmp14_;
					_tmp15__length1 = _vala_array_length (_tmp13_);
					_g_free0 (_tmp12_);
					lineparts = _tmp15_;
					lineparts_length1 = _tmp15__length1;
					_lineparts_size_ = lineparts_length1;
					{
						gint i = 0;
						i = 0;
						{
							gboolean _tmp16_ = FALSE;
							_tmp16_ = TRUE;
							while (TRUE) {
								gboolean _tmp17_ = FALSE;
								gchar** _tmp19_ = NULL;
								gint _tmp19__length1 = 0;
								gint _tmp20_ = 0;
								const gchar* _tmp21_ = NULL;
								FILE* _tmp22_ = NULL;
								gchar** _tmp23_ = NULL;
								gint _tmp23__length1 = 0;
								gint _tmp24_ = 0;
								const gchar* _tmp25_ = NULL;
								gchar** _tmp26_ = NULL;
								gint _tmp26__length1 = 0;
								gint _tmp27_ = 0;
								const gchar* _tmp28_ = NULL;
								_tmp17_ = _tmp16_;
								if (!_tmp17_) {
									gint _tmp18_ = 0;
									_tmp18_ = i;
									i = _tmp18_ + 1;
								}
								_tmp16_ = FALSE;
								_tmp19_ = lineparts;
								_tmp19__length1 = lineparts_length1;
								_tmp20_ = i;
								_tmp21_ = _tmp19_[_tmp20_];
								if (!(_tmp21_ != NULL)) {
									break;
								}
								_tmp22_ = self->priv->stream;
								_tmp23_ = lineparts;
								_tmp23__length1 = lineparts_length1;
								_tmp24_ = i;
								_tmp25_ = _tmp23_[_tmp24_];
								fputs (_tmp25_, _tmp22_);
								_tmp26_ = lineparts;
								_tmp26__length1 = lineparts_length1;
								_tmp27_ = i;
								_tmp28_ = _tmp26_[_tmp27_ + 1];
								if (_tmp28_ != NULL) {
									FILE* _tmp29_ = NULL;
									_tmp29_ = self->priv->stream;
									fputs ("* /", _tmp29_);
								}
							}
						}
					}
					lineparts = (_vala_array_free (lineparts, lineparts_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (line);
				}
			}
		}
		_tmp30_ = self->priv->stream;
		fputs ("*/", _tmp30_);
		vala_ccode_writer_write_newline (self);
		lines = (_vala_array_free (lines, lines_length1, (GDestroyNotify) g_free), NULL);
		_g_regex_unref0 (regex);
	}
	goto __finally1;
	__catch1_g_regex_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_g_error_free0 (e);
	}
	__finally1:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


const gchar* vala_ccode_writer_get_filename (ValaCCodeWriter* self) {
	const gchar* result;
	const gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_filename;
	result = _tmp0_;
	return result;
}


void vala_ccode_writer_set_filename (ValaCCodeWriter* self, const gchar* value) {
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_filename);
	self->priv->_filename = _tmp1_;
}


gboolean vala_ccode_writer_get_line_directives (ValaCCodeWriter* self) {
	gboolean result;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_line_directives;
	result = _tmp0_;
	return result;
}


void vala_ccode_writer_set_line_directives (ValaCCodeWriter* self, gboolean value) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_line_directives = _tmp0_;
}


gboolean vala_ccode_writer_get_bol (ValaCCodeWriter* self) {
	gboolean result;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_bol;
	result = _tmp0_;
	return result;
}


static void vala_value_ccode_writer_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void vala_value_ccode_writer_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		vala_ccode_writer_unref (value->data[0].v_pointer);
	}
}


static void vala_value_ccode_writer_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = vala_ccode_writer_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer vala_value_ccode_writer_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* vala_value_ccode_writer_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		ValaCCodeWriter* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = vala_ccode_writer_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* vala_value_ccode_writer_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	ValaCCodeWriter** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = vala_ccode_writer_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* vala_param_spec_ccode_writer (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ValaParamSpecCCodeWriter* spec;
	g_return_val_if_fail (g_type_is_a (object_type, VALA_TYPE_CCODE_WRITER), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer vala_value_get_ccode_writer (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, VALA_TYPE_CCODE_WRITER), NULL);
	return value->data[0].v_pointer;
}


void vala_value_set_ccode_writer (GValue* value, gpointer v_object) {
	ValaCCodeWriter* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, VALA_TYPE_CCODE_WRITER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, VALA_TYPE_CCODE_WRITER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		vala_ccode_writer_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		vala_ccode_writer_unref (old);
	}
}


void vala_value_take_ccode_writer (GValue* value, gpointer v_object) {
	ValaCCodeWriter* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, VALA_TYPE_CCODE_WRITER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, VALA_TYPE_CCODE_WRITER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		vala_ccode_writer_unref (old);
	}
}


static void vala_ccode_writer_class_init (ValaCCodeWriterClass * klass) {
	vala_ccode_writer_parent_class = g_type_class_peek_parent (klass);
	VALA_CCODE_WRITER_CLASS (klass)->finalize = vala_ccode_writer_finalize;
	g_type_class_add_private (klass, sizeof (ValaCCodeWriterPrivate));
}


static void vala_ccode_writer_instance_init (ValaCCodeWriter * self) {
	self->priv = VALA_CCODE_WRITER_GET_PRIVATE (self);
	self->priv->current_line_number = 1;
	self->priv->_bol = TRUE;
	self->ref_count = 1;
}


static void vala_ccode_writer_finalize (ValaCCodeWriter* obj) {
	ValaCCodeWriter * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_CCODE_WRITER, ValaCCodeWriter);
	_g_free0 (self->priv->_filename);
	_g_free0 (self->priv->source_filename);
	_g_free0 (self->priv->temp_filename);
	_fclose0 (self->priv->stream);
}


/**
 * Represents a writer to write C source files.
 */
GType vala_ccode_writer_get_type (void) {
	static volatile gsize vala_ccode_writer_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_writer_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { vala_value_ccode_writer_init, vala_value_ccode_writer_free_value, vala_value_ccode_writer_copy_value, vala_value_ccode_writer_peek_pointer, "p", vala_value_ccode_writer_collect_value, "p", vala_value_ccode_writer_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeWriterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_writer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeWriter), 0, (GInstanceInitFunc) vala_ccode_writer_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType vala_ccode_writer_type_id;
		vala_ccode_writer_type_id = g_type_register_fundamental (g_type_fundamental_next (), "ValaCCodeWriter", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&vala_ccode_writer_type_id__volatile, vala_ccode_writer_type_id);
	}
	return vala_ccode_writer_type_id__volatile;
}


gpointer vala_ccode_writer_ref (gpointer instance) {
	ValaCCodeWriter* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void vala_ccode_writer_unref (gpointer instance) {
	ValaCCodeWriter* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		VALA_CCODE_WRITER_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



