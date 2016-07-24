/*
 * 
 * (c) Copyright RIFT.io, 2013-2016, All Rights Reserved
 *
 * Author(s): Tim Mortsolf
 * Creation Date: 8/29/2013
 * 
 */

#include "basic_functor-c.h"

static int
basic_functor__api__callback_example(BasicFunctorApi *api, 
                                     BasicFunctorFunctor *functor)
{
  basic_functor_functor_callback(functor);

  return 0;
}

static void
basic_functor_c_extension_init(BasicFunctorCExtension *plugin)
{
  // This is called once for each extension created
  printf("basic_functor_c_extension_init() %p called\n",plugin);
}

static void
basic_functor_c_extension_class_init(BasicFunctorCExtensionClass *klass)
{
  printf("basic_functor_c_extension_class_init() %p called\n",klass);
}


static void
basic_functor_c_extension_class_finalize(BasicFunctorCExtensionClass *klass)
{
  printf("basic_functor_c_extension_class_finalize() %p called\n", klass);
}

#define VAPI_TO_C_AUTOGEN
#ifdef VAPI_TO_C_AUTOGEN
/* Don't modify the code below, it is autogenerated */

#endif //VAPI_TO_C_AUTOGEN
