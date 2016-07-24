/*
 * 
 * (c) Copyright RIFT.io, 2013-2016, All Rights Reserved
 *
 * Author(s): Tim Mortsolf
 * Creation Date: 8/29/2013
 * 
 */

#ifndef __FEATURE_PLUGIN_C_H__
#define __FEATURE_PLUGIN_C_H__

#include "feature_plugin.h"

#define VAPI_TO_C_AUTOGEN
#ifdef VAPI_TO_C_AUTOGEN

/* Don't modify the code below, it is autogenerated */

G_BEGIN_DECLS

G_MODULE_EXPORT void peas_register_types(PeasObjectModule *module);

#define FEATURE_PLUGIN_C_EXTENSION_TYPE (feature_plugin_c_extension_get_type())

typedef struct _FeaturePluginCExtension       FeaturePluginCExtension;
typedef struct _FeaturePluginCExtensionClasss FeaturePluginCExtensionClass;

struct _FeaturePluginCExtension {
  PeasExtensionBase parent_instance;
};

struct _FeaturePluginCExtensionClass {
  PeasExtensionBaseClass parent_class;
};

GType feature_plugin_c_extension_get_type (void) G_GNUC_CONST;

//
//FeaturePlugin.Api
//
#define FEATURE_PLUGIN_API_C_EXTENSION_TYPE (feature_plugin_api_c_extension_get_type())

typedef struct _FeaturePluginApiCExtension       FeaturePluginApiCExtension;
typedef struct _FeaturePluginApiCExtensionClasss FeaturePluginApiCExtensionClass;

struct _FeaturePluginApiCExtension {
  PeasExtensionBase parent_instance;
};

struct _FeaturePluginApiCExtensionClass {
  PeasExtensionBaseClass parent_class;
};

GType feature_plugin_api_c_extension_get_type (void) G_GNUC_CONST;

//
//FeaturePlugin.ValaCallbackFunctor
//
#define FEATURE_PLUGIN_VALA_CALLBACK_FUNCTOR_C_EXTENSION_TYPE (feature_plugin_vala_callback_functor_c_extension_get_type())

typedef struct _FeaturePluginValaCallbackFunctorCExtension       FeaturePluginValaCallbackFunctorCExtension;
typedef struct _FeaturePluginValaCallbackFunctorCExtensionClasss FeaturePluginValaCallbackFunctorCExtensionClass;

struct _FeaturePluginValaCallbackFunctorCExtension {
  PeasExtensionBase parent_instance;
};

struct _FeaturePluginValaCallbackFunctorCExtensionClass {
  PeasExtensionBaseClass parent_class;
};

GType feature_plugin_vala_callback_functor_c_extension_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif //VAPI_TO_C_AUTOGEN

#endif // __FEATURE_PLUGIN_C_H__ 
