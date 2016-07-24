/* valadelegatetype.c generated by valac, the Vala compiler
 * generated from valadelegatetype.vala, do not modify */

/* valadelegatetype.vala
 *
 * Copyright (C) 2007-2012  Jürg Billeter
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
#include <valagee.h>


#define VALA_TYPE_CODE_NODE (vala_code_node_get_type ())
#define VALA_CODE_NODE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CODE_NODE, ValaCodeNode))
#define VALA_CODE_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CODE_NODE, ValaCodeNodeClass))
#define VALA_IS_CODE_NODE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CODE_NODE))
#define VALA_IS_CODE_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CODE_NODE))
#define VALA_CODE_NODE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CODE_NODE, ValaCodeNodeClass))

typedef struct _ValaCodeNode ValaCodeNode;
typedef struct _ValaCodeNodeClass ValaCodeNodeClass;
typedef struct _ValaCodeNodePrivate ValaCodeNodePrivate;

#define VALA_TYPE_CODE_VISITOR (vala_code_visitor_get_type ())
#define VALA_CODE_VISITOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CODE_VISITOR, ValaCodeVisitor))
#define VALA_CODE_VISITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CODE_VISITOR, ValaCodeVisitorClass))
#define VALA_IS_CODE_VISITOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CODE_VISITOR))
#define VALA_IS_CODE_VISITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CODE_VISITOR))
#define VALA_CODE_VISITOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CODE_VISITOR, ValaCodeVisitorClass))

typedef struct _ValaCodeVisitor ValaCodeVisitor;
typedef struct _ValaCodeVisitorClass ValaCodeVisitorClass;

#define VALA_TYPE_CODE_CONTEXT (vala_code_context_get_type ())
#define VALA_CODE_CONTEXT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CODE_CONTEXT, ValaCodeContext))
#define VALA_CODE_CONTEXT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CODE_CONTEXT, ValaCodeContextClass))
#define VALA_IS_CODE_CONTEXT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CODE_CONTEXT))
#define VALA_IS_CODE_CONTEXT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CODE_CONTEXT))
#define VALA_CODE_CONTEXT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CODE_CONTEXT, ValaCodeContextClass))

typedef struct _ValaCodeContext ValaCodeContext;
typedef struct _ValaCodeContextClass ValaCodeContextClass;

#define VALA_TYPE_CODE_GENERATOR (vala_code_generator_get_type ())
#define VALA_CODE_GENERATOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CODE_GENERATOR, ValaCodeGenerator))
#define VALA_CODE_GENERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CODE_GENERATOR, ValaCodeGeneratorClass))
#define VALA_IS_CODE_GENERATOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CODE_GENERATOR))
#define VALA_IS_CODE_GENERATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CODE_GENERATOR))
#define VALA_CODE_GENERATOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CODE_GENERATOR, ValaCodeGeneratorClass))

typedef struct _ValaCodeGenerator ValaCodeGenerator;
typedef struct _ValaCodeGeneratorClass ValaCodeGeneratorClass;

#define VALA_TYPE_DATA_TYPE (vala_data_type_get_type ())
#define VALA_DATA_TYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_DATA_TYPE, ValaDataType))
#define VALA_DATA_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_DATA_TYPE, ValaDataTypeClass))
#define VALA_IS_DATA_TYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_DATA_TYPE))
#define VALA_IS_DATA_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_DATA_TYPE))
#define VALA_DATA_TYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_DATA_TYPE, ValaDataTypeClass))

typedef struct _ValaDataType ValaDataType;
typedef struct _ValaDataTypeClass ValaDataTypeClass;

#define VALA_TYPE_EXPRESSION (vala_expression_get_type ())
#define VALA_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_EXPRESSION, ValaExpression))
#define VALA_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_EXPRESSION, ValaExpressionClass))
#define VALA_IS_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_EXPRESSION))
#define VALA_IS_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_EXPRESSION))
#define VALA_EXPRESSION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_EXPRESSION, ValaExpressionClass))

typedef struct _ValaExpression ValaExpression;
typedef struct _ValaExpressionClass ValaExpressionClass;

#define VALA_TYPE_SYMBOL (vala_symbol_get_type ())
#define VALA_SYMBOL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_SYMBOL, ValaSymbol))
#define VALA_SYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_SYMBOL, ValaSymbolClass))
#define VALA_IS_SYMBOL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_SYMBOL))
#define VALA_IS_SYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_SYMBOL))
#define VALA_SYMBOL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_SYMBOL, ValaSymbolClass))

typedef struct _ValaSymbol ValaSymbol;
typedef struct _ValaSymbolClass ValaSymbolClass;

#define VALA_TYPE_VARIABLE (vala_variable_get_type ())
#define VALA_VARIABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_VARIABLE, ValaVariable))
#define VALA_VARIABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_VARIABLE, ValaVariableClass))
#define VALA_IS_VARIABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_VARIABLE))
#define VALA_IS_VARIABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_VARIABLE))
#define VALA_VARIABLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_VARIABLE, ValaVariableClass))

typedef struct _ValaVariable ValaVariable;
typedef struct _ValaVariableClass ValaVariableClass;

#define VALA_TYPE_ATTRIBUTE (vala_attribute_get_type ())
#define VALA_ATTRIBUTE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_ATTRIBUTE, ValaAttribute))
#define VALA_ATTRIBUTE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_ATTRIBUTE, ValaAttributeClass))
#define VALA_IS_ATTRIBUTE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_ATTRIBUTE))
#define VALA_IS_ATTRIBUTE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_ATTRIBUTE))
#define VALA_ATTRIBUTE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_ATTRIBUTE, ValaAttributeClass))

typedef struct _ValaAttribute ValaAttribute;
typedef struct _ValaAttributeClass ValaAttributeClass;
typedef struct _ValaDataTypePrivate ValaDataTypePrivate;

#define VALA_TYPE_SCOPE (vala_scope_get_type ())
#define VALA_SCOPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_SCOPE, ValaScope))
#define VALA_SCOPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_SCOPE, ValaScopeClass))
#define VALA_IS_SCOPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_SCOPE))
#define VALA_IS_SCOPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_SCOPE))
#define VALA_SCOPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_SCOPE, ValaScopeClass))

typedef struct _ValaScope ValaScope;
typedef struct _ValaScopeClass ValaScopeClass;

#define VALA_TYPE_PARAMETER (vala_parameter_get_type ())
#define VALA_PARAMETER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_PARAMETER, ValaParameter))
#define VALA_PARAMETER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_PARAMETER, ValaParameterClass))
#define VALA_IS_PARAMETER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_PARAMETER))
#define VALA_IS_PARAMETER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_PARAMETER))
#define VALA_PARAMETER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_PARAMETER, ValaParameterClass))

typedef struct _ValaParameter ValaParameter;
typedef struct _ValaParameterClass ValaParameterClass;

#define VALA_TYPE_MEMBER_ACCESS (vala_member_access_get_type ())
#define VALA_MEMBER_ACCESS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_MEMBER_ACCESS, ValaMemberAccess))
#define VALA_MEMBER_ACCESS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_MEMBER_ACCESS, ValaMemberAccessClass))
#define VALA_IS_MEMBER_ACCESS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_MEMBER_ACCESS))
#define VALA_IS_MEMBER_ACCESS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_MEMBER_ACCESS))
#define VALA_MEMBER_ACCESS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_MEMBER_ACCESS, ValaMemberAccessClass))

typedef struct _ValaMemberAccess ValaMemberAccess;
typedef struct _ValaMemberAccessClass ValaMemberAccessClass;

#define VALA_TYPE_DELEGATE_TYPE (vala_delegate_type_get_type ())
#define VALA_DELEGATE_TYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_DELEGATE_TYPE, ValaDelegateType))
#define VALA_DELEGATE_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_DELEGATE_TYPE, ValaDelegateTypeClass))
#define VALA_IS_DELEGATE_TYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_DELEGATE_TYPE))
#define VALA_IS_DELEGATE_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_DELEGATE_TYPE))
#define VALA_DELEGATE_TYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_DELEGATE_TYPE, ValaDelegateTypeClass))

typedef struct _ValaDelegateType ValaDelegateType;
typedef struct _ValaDelegateTypeClass ValaDelegateTypeClass;
typedef struct _ValaDelegateTypePrivate ValaDelegateTypePrivate;

#define VALA_TYPE_TYPESYMBOL (vala_typesymbol_get_type ())
#define VALA_TYPESYMBOL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_TYPESYMBOL, ValaTypeSymbol))
#define VALA_TYPESYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_TYPESYMBOL, ValaTypeSymbolClass))
#define VALA_IS_TYPESYMBOL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_TYPESYMBOL))
#define VALA_IS_TYPESYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_TYPESYMBOL))
#define VALA_TYPESYMBOL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_TYPESYMBOL, ValaTypeSymbolClass))

typedef struct _ValaTypeSymbol ValaTypeSymbol;
typedef struct _ValaTypeSymbolClass ValaTypeSymbolClass;

#define VALA_TYPE_DELEGATE (vala_delegate_get_type ())
#define VALA_DELEGATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_DELEGATE, ValaDelegate))
#define VALA_DELEGATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_DELEGATE, ValaDelegateClass))
#define VALA_IS_DELEGATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_DELEGATE))
#define VALA_IS_DELEGATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_DELEGATE))
#define VALA_DELEGATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_DELEGATE, ValaDelegateClass))

typedef struct _ValaDelegate ValaDelegate;
typedef struct _ValaDelegateClass ValaDelegateClass;
#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _vala_scope_unref0(var) ((var == NULL) ? NULL : (var = (vala_scope_unref (var), NULL)))
#define _vala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (vala_iterable_unref (var), NULL)))

#define VALA_TYPE_SOURCE_REFERENCE (vala_source_reference_get_type ())
#define VALA_SOURCE_REFERENCE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_SOURCE_REFERENCE, ValaSourceReference))
#define VALA_SOURCE_REFERENCE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_SOURCE_REFERENCE, ValaSourceReferenceClass))
#define VALA_IS_SOURCE_REFERENCE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_SOURCE_REFERENCE))
#define VALA_IS_SOURCE_REFERENCE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_SOURCE_REFERENCE))
#define VALA_SOURCE_REFERENCE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_SOURCE_REFERENCE, ValaSourceReferenceClass))

typedef struct _ValaSourceReference ValaSourceReference;
typedef struct _ValaSourceReferenceClass ValaSourceReferenceClass;

struct _ValaCodeNode {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ValaCodeNodePrivate * priv;
	GList* attributes;
};

struct _ValaCodeNodeClass {
	GTypeClass parent_class;
	void (*finalize) (ValaCodeNode *self);
	void (*accept) (ValaCodeNode* self, ValaCodeVisitor* visitor);
	void (*accept_children) (ValaCodeNode* self, ValaCodeVisitor* visitor);
	gboolean (*check) (ValaCodeNode* self, ValaCodeContext* context);
	void (*emit) (ValaCodeNode* self, ValaCodeGenerator* codegen);
	void (*replace_type) (ValaCodeNode* self, ValaDataType* old_type, ValaDataType* new_type);
	void (*replace_expression) (ValaCodeNode* self, ValaExpression* old_node, ValaExpression* new_node);
	gchar* (*to_string) (ValaCodeNode* self);
	void (*get_defined_variables) (ValaCodeNode* self, ValaCollection* collection);
	void (*get_used_variables) (ValaCodeNode* self, ValaCollection* collection);
};

struct _ValaDataType {
	ValaCodeNode parent_instance;
	ValaDataTypePrivate * priv;
};

struct _ValaDataTypeClass {
	ValaCodeNodeClass parent_class;
	gchar* (*to_qualified_string) (ValaDataType* self, ValaScope* scope);
	ValaDataType* (*copy) (ValaDataType* self);
	gboolean (*equals) (ValaDataType* self, ValaDataType* type2);
	gboolean (*stricter) (ValaDataType* self, ValaDataType* type2);
	gboolean (*compatible) (ValaDataType* self, ValaDataType* target_type);
	gboolean (*is_invokable) (ValaDataType* self);
	ValaDataType* (*get_return_type) (ValaDataType* self);
	ValaList* (*get_parameters) (ValaDataType* self);
	gboolean (*is_reference_type_or_type_parameter) (ValaDataType* self);
	gboolean (*is_array) (ValaDataType* self);
	gboolean (*is_accessible) (ValaDataType* self, ValaSymbol* sym);
	ValaSymbol* (*get_member) (ValaDataType* self, const gchar* member_name);
	ValaSymbol* (*get_pointer_member) (ValaDataType* self, const gchar* member_name);
	gboolean (*is_real_struct_type) (ValaDataType* self);
	gboolean (*is_disposable) (ValaDataType* self);
	ValaDataType* (*get_actual_type) (ValaDataType* self, ValaDataType* derived_instance_type, ValaMemberAccess* method_access, ValaCodeNode* node_reference);
};

struct _ValaDelegateType {
	ValaDataType parent_instance;
	ValaDelegateTypePrivate * priv;
};

struct _ValaDelegateTypeClass {
	ValaDataTypeClass parent_class;
};

struct _ValaDelegateTypePrivate {
	ValaDelegate* _delegate_symbol;
	gboolean _is_called_once;
};


static gpointer vala_delegate_type_parent_class = NULL;

gpointer vala_code_node_ref (gpointer instance);
void vala_code_node_unref (gpointer instance);
GParamSpec* vala_param_spec_code_node (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_code_node (GValue* value, gpointer v_object);
void vala_value_take_code_node (GValue* value, gpointer v_object);
gpointer vala_value_get_code_node (const GValue* value);
GType vala_code_node_get_type (void) G_GNUC_CONST;
gpointer vala_code_visitor_ref (gpointer instance);
void vala_code_visitor_unref (gpointer instance);
GParamSpec* vala_param_spec_code_visitor (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_code_visitor (GValue* value, gpointer v_object);
void vala_value_take_code_visitor (GValue* value, gpointer v_object);
gpointer vala_value_get_code_visitor (const GValue* value);
GType vala_code_visitor_get_type (void) G_GNUC_CONST;
gpointer vala_code_context_ref (gpointer instance);
void vala_code_context_unref (gpointer instance);
GParamSpec* vala_param_spec_code_context (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_code_context (GValue* value, gpointer v_object);
void vala_value_take_code_context (GValue* value, gpointer v_object);
gpointer vala_value_get_code_context (const GValue* value);
GType vala_code_context_get_type (void) G_GNUC_CONST;
GType vala_code_generator_get_type (void) G_GNUC_CONST;
GType vala_data_type_get_type (void) G_GNUC_CONST;
GType vala_expression_get_type (void) G_GNUC_CONST;
GType vala_symbol_get_type (void) G_GNUC_CONST;
GType vala_variable_get_type (void) G_GNUC_CONST;
GType vala_attribute_get_type (void) G_GNUC_CONST;
gpointer vala_scope_ref (gpointer instance);
void vala_scope_unref (gpointer instance);
GParamSpec* vala_param_spec_scope (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_scope (GValue* value, gpointer v_object);
void vala_value_take_scope (GValue* value, gpointer v_object);
gpointer vala_value_get_scope (const GValue* value);
GType vala_scope_get_type (void) G_GNUC_CONST;
GType vala_parameter_get_type (void) G_GNUC_CONST;
GType vala_member_access_get_type (void) G_GNUC_CONST;
GType vala_delegate_type_get_type (void) G_GNUC_CONST;
GType vala_typesymbol_get_type (void) G_GNUC_CONST;
GType vala_delegate_get_type (void) G_GNUC_CONST;
#define VALA_DELEGATE_TYPE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VALA_TYPE_DELEGATE_TYPE, ValaDelegateTypePrivate))
enum  {
	VALA_DELEGATE_TYPE_DUMMY_PROPERTY
};
ValaDelegateType* vala_delegate_type_new (ValaDelegate* delegate_symbol);
ValaDelegateType* vala_delegate_type_construct (GType object_type, ValaDelegate* delegate_symbol);
ValaDataType* vala_data_type_construct (GType object_type);
void vala_delegate_type_set_delegate_symbol (ValaDelegateType* self, ValaDelegate* value);
gchar* vala_code_node_get_attribute_string (ValaCodeNode* self, const gchar* attribute, const gchar* argument, const gchar* default_value);
void vala_delegate_type_set_is_called_once (ValaDelegateType* self, gboolean value);
static gboolean vala_delegate_type_real_is_invokable (ValaDataType* base);
static ValaDataType* vala_delegate_type_real_get_return_type (ValaDataType* base);
ValaDelegate* vala_delegate_type_get_delegate_symbol (ValaDelegateType* self);
ValaDataType* vala_delegate_get_return_type (ValaDelegate* self);
static ValaList* vala_delegate_type_real_get_parameters (ValaDataType* base);
ValaList* vala_delegate_get_parameters (ValaDelegate* self);
static gchar* vala_delegate_type_real_to_qualified_string (ValaDataType* base, ValaScope* scope);
ValaSymbol* vala_symbol_get_parent_symbol (ValaSymbol* self);
const gchar* vala_symbol_get_name (ValaSymbol* self);
ValaSymbol* vala_scope_lookup (ValaScope* self, const gchar* name);
ValaScope* vala_scope_get_parent_scope (ValaScope* self);
gchar* vala_symbol_get_full_name (ValaSymbol* self);
ValaList* vala_data_type_get_type_arguments (ValaDataType* self);
gboolean vala_data_type_get_value_owned (ValaDataType* self);
gchar* vala_data_type_to_qualified_string (ValaDataType* self, ValaScope* scope);
gboolean vala_data_type_get_nullable (ValaDataType* self);
static ValaDataType* vala_delegate_type_real_copy (ValaDataType* base);
gpointer vala_source_reference_ref (gpointer instance);
void vala_source_reference_unref (gpointer instance);
GParamSpec* vala_param_spec_source_reference (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_source_reference (GValue* value, gpointer v_object);
void vala_value_take_source_reference (GValue* value, gpointer v_object);
gpointer vala_value_get_source_reference (const GValue* value);
GType vala_source_reference_get_type (void) G_GNUC_CONST;
ValaSourceReference* vala_code_node_get_source_reference (ValaCodeNode* self);
void vala_code_node_set_source_reference (ValaCodeNode* self, ValaSourceReference* value);
void vala_data_type_set_value_owned (ValaDataType* self, gboolean value);
void vala_data_type_set_nullable (ValaDataType* self, gboolean value);
void vala_data_type_add_type_argument (ValaDataType* self, ValaDataType* arg);
ValaDataType* vala_data_type_copy (ValaDataType* self);
gboolean vala_delegate_type_get_is_called_once (ValaDelegateType* self);
static gboolean vala_delegate_type_real_is_accessible (ValaDataType* base, ValaSymbol* sym);
gboolean vala_symbol_is_accessible (ValaSymbol* self, ValaSymbol* sym);
static gboolean vala_delegate_type_real_check (ValaCodeNode* base, ValaCodeContext* context);
void vala_report_warning (ValaSourceReference* source, const gchar* message);
gboolean vala_code_node_check (ValaCodeNode* self, ValaCodeContext* context);
static gboolean vala_delegate_type_real_is_disposable (ValaDataType* base);
gboolean vala_delegate_get_has_target (ValaDelegate* self);
static void vala_delegate_type_finalize (ValaCodeNode* obj);


ValaDelegateType* vala_delegate_type_construct (GType object_type, ValaDelegate* delegate_symbol) {
	ValaDelegateType* self = NULL;
	ValaDelegate* _tmp0_ = NULL;
	ValaDelegate* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	g_return_val_if_fail (delegate_symbol != NULL, NULL);
	self = (ValaDelegateType*) vala_data_type_construct (object_type);
	_tmp0_ = delegate_symbol;
	vala_delegate_type_set_delegate_symbol (self, _tmp0_);
	_tmp1_ = delegate_symbol;
	_tmp2_ = vala_code_node_get_attribute_string ((ValaCodeNode*) _tmp1_, "CCode", "scope", NULL);
	_tmp3_ = _tmp2_;
	vala_delegate_type_set_is_called_once (self, g_strcmp0 (_tmp3_, "async") == 0);
	_g_free0 (_tmp3_);
	return self;
}


ValaDelegateType* vala_delegate_type_new (ValaDelegate* delegate_symbol) {
	return vala_delegate_type_construct (VALA_TYPE_DELEGATE_TYPE, delegate_symbol);
}


static gboolean vala_delegate_type_real_is_invokable (ValaDataType* base) {
	ValaDelegateType * self;
	gboolean result = FALSE;
	self = (ValaDelegateType*) base;
	result = TRUE;
	return result;
}


static gpointer _vala_code_node_ref0 (gpointer self) {
	return self ? vala_code_node_ref (self) : NULL;
}


static ValaDataType* vala_delegate_type_real_get_return_type (ValaDataType* base) {
	ValaDelegateType * self;
	ValaDataType* result = NULL;
	ValaDelegate* _tmp0_ = NULL;
	ValaDataType* _tmp1_ = NULL;
	ValaDataType* _tmp2_ = NULL;
	ValaDataType* _tmp3_ = NULL;
	self = (ValaDelegateType*) base;
	_tmp0_ = self->priv->_delegate_symbol;
	_tmp1_ = vala_delegate_get_return_type (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = _vala_code_node_ref0 (_tmp2_);
	result = _tmp3_;
	return result;
}


static ValaList* vala_delegate_type_real_get_parameters (ValaDataType* base) {
	ValaDelegateType * self;
	ValaList* result = NULL;
	ValaDelegate* _tmp0_ = NULL;
	ValaList* _tmp1_ = NULL;
	self = (ValaDelegateType*) base;
	_tmp0_ = self->priv->_delegate_symbol;
	_tmp1_ = vala_delegate_get_parameters (_tmp0_);
	result = _tmp1_;
	return result;
}


static gpointer _vala_scope_ref0 (gpointer self) {
	return self ? vala_scope_ref (self) : NULL;
}


static gpointer _vala_iterable_ref0 (gpointer self) {
	return self ? vala_iterable_ref (self) : NULL;
}


static gchar* vala_delegate_type_real_to_qualified_string (ValaDataType* base, ValaScope* scope) {
	ValaDelegateType * self;
	gchar* result = NULL;
	ValaSymbol* global_symbol = NULL;
	ValaDelegate* _tmp0_ = NULL;
	ValaSymbol* _tmp1_ = NULL;
	ValaSymbol* sym = NULL;
	ValaScope* parent_scope = NULL;
	ValaScope* _tmp11_ = NULL;
	ValaScope* _tmp12_ = NULL;
	gchar* s = NULL;
	gboolean _tmp26_ = FALSE;
	ValaSymbol* _tmp27_ = NULL;
	gboolean _tmp30_ = FALSE;
	ValaList* type_args = NULL;
	ValaList* _tmp37_ = NULL;
	ValaList* _tmp38_ = NULL;
	gint _tmp39_ = 0;
	gint _tmp40_ = 0;
	gboolean _tmp70_ = FALSE;
	gboolean _tmp71_ = FALSE;
	self = (ValaDelegateType*) base;
	_tmp0_ = self->priv->_delegate_symbol;
	_tmp1_ = _vala_code_node_ref0 ((ValaSymbol*) _tmp0_);
	global_symbol = _tmp1_;
	while (TRUE) {
		ValaSymbol* _tmp2_ = NULL;
		ValaSymbol* _tmp3_ = NULL;
		ValaSymbol* _tmp4_ = NULL;
		const gchar* _tmp5_ = NULL;
		const gchar* _tmp6_ = NULL;
		ValaSymbol* _tmp7_ = NULL;
		ValaSymbol* _tmp8_ = NULL;
		ValaSymbol* _tmp9_ = NULL;
		ValaSymbol* _tmp10_ = NULL;
		_tmp2_ = global_symbol;
		_tmp3_ = vala_symbol_get_parent_symbol (_tmp2_);
		_tmp4_ = _tmp3_;
		_tmp5_ = vala_symbol_get_name (_tmp4_);
		_tmp6_ = _tmp5_;
		if (!(_tmp6_ != NULL)) {
			break;
		}
		_tmp7_ = global_symbol;
		_tmp8_ = vala_symbol_get_parent_symbol (_tmp7_);
		_tmp9_ = _tmp8_;
		_tmp10_ = _vala_code_node_ref0 (_tmp9_);
		_vala_code_node_unref0 (global_symbol);
		global_symbol = _tmp10_;
	}
	sym = NULL;
	_tmp11_ = scope;
	_tmp12_ = _vala_scope_ref0 (_tmp11_);
	parent_scope = _tmp12_;
	while (TRUE) {
		gboolean _tmp13_ = FALSE;
		ValaSymbol* _tmp14_ = NULL;
		gboolean _tmp16_ = FALSE;
		ValaScope* _tmp17_ = NULL;
		ValaSymbol* _tmp18_ = NULL;
		const gchar* _tmp19_ = NULL;
		const gchar* _tmp20_ = NULL;
		ValaSymbol* _tmp21_ = NULL;
		ValaScope* _tmp22_ = NULL;
		ValaScope* _tmp23_ = NULL;
		ValaScope* _tmp24_ = NULL;
		ValaScope* _tmp25_ = NULL;
		_tmp14_ = sym;
		if (_tmp14_ == NULL) {
			ValaScope* _tmp15_ = NULL;
			_tmp15_ = parent_scope;
			_tmp13_ = _tmp15_ != NULL;
		} else {
			_tmp13_ = FALSE;
		}
		_tmp16_ = _tmp13_;
		if (!_tmp16_) {
			break;
		}
		_tmp17_ = parent_scope;
		_tmp18_ = global_symbol;
		_tmp19_ = vala_symbol_get_name (_tmp18_);
		_tmp20_ = _tmp19_;
		_tmp21_ = vala_scope_lookup (_tmp17_, _tmp20_);
		_vala_code_node_unref0 (sym);
		sym = _tmp21_;
		_tmp22_ = parent_scope;
		_tmp23_ = vala_scope_get_parent_scope (_tmp22_);
		_tmp24_ = _tmp23_;
		_tmp25_ = _vala_scope_ref0 (_tmp24_);
		_vala_scope_unref0 (parent_scope);
		parent_scope = _tmp25_;
	}
	_tmp27_ = sym;
	if (_tmp27_ != NULL) {
		ValaSymbol* _tmp28_ = NULL;
		ValaSymbol* _tmp29_ = NULL;
		_tmp28_ = global_symbol;
		_tmp29_ = sym;
		_tmp26_ = _tmp28_ != _tmp29_;
	} else {
		_tmp26_ = FALSE;
	}
	_tmp30_ = _tmp26_;
	if (_tmp30_) {
		ValaDelegate* _tmp31_ = NULL;
		gchar* _tmp32_ = NULL;
		gchar* _tmp33_ = NULL;
		gchar* _tmp34_ = NULL;
		_tmp31_ = self->priv->_delegate_symbol;
		_tmp32_ = vala_symbol_get_full_name ((ValaSymbol*) _tmp31_);
		_tmp33_ = _tmp32_;
		_tmp34_ = g_strconcat ("global::", _tmp33_, NULL);
		_g_free0 (s);
		s = _tmp34_;
		_g_free0 (_tmp33_);
	} else {
		ValaDelegate* _tmp35_ = NULL;
		gchar* _tmp36_ = NULL;
		_tmp35_ = self->priv->_delegate_symbol;
		_tmp36_ = vala_symbol_get_full_name ((ValaSymbol*) _tmp35_);
		_g_free0 (s);
		s = _tmp36_;
	}
	_tmp37_ = vala_data_type_get_type_arguments ((ValaDataType*) self);
	type_args = _tmp37_;
	_tmp38_ = type_args;
	_tmp39_ = vala_collection_get_size ((ValaCollection*) _tmp38_);
	_tmp40_ = _tmp39_;
	if (_tmp40_ > 0) {
		const gchar* _tmp41_ = NULL;
		gchar* _tmp42_ = NULL;
		gboolean first = FALSE;
		const gchar* _tmp68_ = NULL;
		gchar* _tmp69_ = NULL;
		_tmp41_ = s;
		_tmp42_ = g_strconcat (_tmp41_, "<", NULL);
		_g_free0 (s);
		s = _tmp42_;
		first = TRUE;
		{
			ValaList* _type_arg_list = NULL;
			ValaList* _tmp43_ = NULL;
			ValaList* _tmp44_ = NULL;
			gint _type_arg_size = 0;
			ValaList* _tmp45_ = NULL;
			gint _tmp46_ = 0;
			gint _tmp47_ = 0;
			gint _type_arg_index = 0;
			_tmp43_ = type_args;
			_tmp44_ = _vala_iterable_ref0 (_tmp43_);
			_type_arg_list = _tmp44_;
			_tmp45_ = _type_arg_list;
			_tmp46_ = vala_collection_get_size ((ValaCollection*) _tmp45_);
			_tmp47_ = _tmp46_;
			_type_arg_size = _tmp47_;
			_type_arg_index = -1;
			while (TRUE) {
				gint _tmp48_ = 0;
				gint _tmp49_ = 0;
				gint _tmp50_ = 0;
				ValaDataType* type_arg = NULL;
				ValaList* _tmp51_ = NULL;
				gint _tmp52_ = 0;
				gpointer _tmp53_ = NULL;
				gboolean _tmp54_ = FALSE;
				ValaDataType* _tmp57_ = NULL;
				gboolean _tmp58_ = FALSE;
				gboolean _tmp59_ = FALSE;
				const gchar* _tmp62_ = NULL;
				ValaDataType* _tmp63_ = NULL;
				ValaScope* _tmp64_ = NULL;
				gchar* _tmp65_ = NULL;
				gchar* _tmp66_ = NULL;
				gchar* _tmp67_ = NULL;
				_tmp48_ = _type_arg_index;
				_type_arg_index = _tmp48_ + 1;
				_tmp49_ = _type_arg_index;
				_tmp50_ = _type_arg_size;
				if (!(_tmp49_ < _tmp50_)) {
					break;
				}
				_tmp51_ = _type_arg_list;
				_tmp52_ = _type_arg_index;
				_tmp53_ = vala_list_get (_tmp51_, _tmp52_);
				type_arg = (ValaDataType*) _tmp53_;
				_tmp54_ = first;
				if (!_tmp54_) {
					const gchar* _tmp55_ = NULL;
					gchar* _tmp56_ = NULL;
					_tmp55_ = s;
					_tmp56_ = g_strconcat (_tmp55_, ",", NULL);
					_g_free0 (s);
					s = _tmp56_;
				} else {
					first = FALSE;
				}
				_tmp57_ = type_arg;
				_tmp58_ = vala_data_type_get_value_owned (_tmp57_);
				_tmp59_ = _tmp58_;
				if (!_tmp59_) {
					const gchar* _tmp60_ = NULL;
					gchar* _tmp61_ = NULL;
					_tmp60_ = s;
					_tmp61_ = g_strconcat (_tmp60_, "weak ", NULL);
					_g_free0 (s);
					s = _tmp61_;
				}
				_tmp62_ = s;
				_tmp63_ = type_arg;
				_tmp64_ = scope;
				_tmp65_ = vala_data_type_to_qualified_string (_tmp63_, _tmp64_);
				_tmp66_ = _tmp65_;
				_tmp67_ = g_strconcat (_tmp62_, _tmp66_, NULL);
				_g_free0 (s);
				s = _tmp67_;
				_g_free0 (_tmp66_);
				_vala_code_node_unref0 (type_arg);
			}
			_vala_iterable_unref0 (_type_arg_list);
		}
		_tmp68_ = s;
		_tmp69_ = g_strconcat (_tmp68_, ">", NULL);
		_g_free0 (s);
		s = _tmp69_;
	}
	_tmp70_ = vala_data_type_get_nullable ((ValaDataType*) self);
	_tmp71_ = _tmp70_;
	if (_tmp71_) {
		const gchar* _tmp72_ = NULL;
		gchar* _tmp73_ = NULL;
		_tmp72_ = s;
		_tmp73_ = g_strconcat (_tmp72_, "?", NULL);
		_g_free0 (s);
		s = _tmp73_;
	}
	result = s;
	_vala_iterable_unref0 (type_args);
	_vala_scope_unref0 (parent_scope);
	_vala_code_node_unref0 (sym);
	_vala_code_node_unref0 (global_symbol);
	return result;
}


static ValaDataType* vala_delegate_type_real_copy (ValaDataType* base) {
	ValaDelegateType * self;
	ValaDataType* result = NULL;
	ValaDelegateType* _result_ = NULL;
	ValaDelegate* _tmp0_ = NULL;
	ValaDelegateType* _tmp1_ = NULL;
	ValaDelegateType* _tmp2_ = NULL;
	ValaSourceReference* _tmp3_ = NULL;
	ValaSourceReference* _tmp4_ = NULL;
	ValaDelegateType* _tmp5_ = NULL;
	gboolean _tmp6_ = FALSE;
	gboolean _tmp7_ = FALSE;
	ValaDelegateType* _tmp8_ = NULL;
	gboolean _tmp9_ = FALSE;
	gboolean _tmp10_ = FALSE;
	ValaDelegateType* _tmp25_ = NULL;
	gboolean _tmp26_ = FALSE;
	self = (ValaDelegateType*) base;
	_tmp0_ = self->priv->_delegate_symbol;
	_tmp1_ = vala_delegate_type_new (_tmp0_);
	_result_ = _tmp1_;
	_tmp2_ = _result_;
	_tmp3_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
	_tmp4_ = _tmp3_;
	vala_code_node_set_source_reference ((ValaCodeNode*) _tmp2_, _tmp4_);
	_tmp5_ = _result_;
	_tmp6_ = vala_data_type_get_value_owned ((ValaDataType*) self);
	_tmp7_ = _tmp6_;
	vala_data_type_set_value_owned ((ValaDataType*) _tmp5_, _tmp7_);
	_tmp8_ = _result_;
	_tmp9_ = vala_data_type_get_nullable ((ValaDataType*) self);
	_tmp10_ = _tmp9_;
	vala_data_type_set_nullable ((ValaDataType*) _tmp8_, _tmp10_);
	{
		ValaList* _arg_list = NULL;
		ValaList* _tmp11_ = NULL;
		gint _arg_size = 0;
		ValaList* _tmp12_ = NULL;
		gint _tmp13_ = 0;
		gint _tmp14_ = 0;
		gint _arg_index = 0;
		_tmp11_ = vala_data_type_get_type_arguments ((ValaDataType*) self);
		_arg_list = _tmp11_;
		_tmp12_ = _arg_list;
		_tmp13_ = vala_collection_get_size ((ValaCollection*) _tmp12_);
		_tmp14_ = _tmp13_;
		_arg_size = _tmp14_;
		_arg_index = -1;
		while (TRUE) {
			gint _tmp15_ = 0;
			gint _tmp16_ = 0;
			gint _tmp17_ = 0;
			ValaDataType* arg = NULL;
			ValaList* _tmp18_ = NULL;
			gint _tmp19_ = 0;
			gpointer _tmp20_ = NULL;
			ValaDelegateType* _tmp21_ = NULL;
			ValaDataType* _tmp22_ = NULL;
			ValaDataType* _tmp23_ = NULL;
			ValaDataType* _tmp24_ = NULL;
			_tmp15_ = _arg_index;
			_arg_index = _tmp15_ + 1;
			_tmp16_ = _arg_index;
			_tmp17_ = _arg_size;
			if (!(_tmp16_ < _tmp17_)) {
				break;
			}
			_tmp18_ = _arg_list;
			_tmp19_ = _arg_index;
			_tmp20_ = vala_list_get (_tmp18_, _tmp19_);
			arg = (ValaDataType*) _tmp20_;
			_tmp21_ = _result_;
			_tmp22_ = arg;
			_tmp23_ = vala_data_type_copy (_tmp22_);
			_tmp24_ = _tmp23_;
			vala_data_type_add_type_argument ((ValaDataType*) _tmp21_, _tmp24_);
			_vala_code_node_unref0 (_tmp24_);
			_vala_code_node_unref0 (arg);
		}
		_vala_iterable_unref0 (_arg_list);
	}
	_tmp25_ = _result_;
	_tmp26_ = self->priv->_is_called_once;
	vala_delegate_type_set_is_called_once (_tmp25_, _tmp26_);
	result = (ValaDataType*) _result_;
	return result;
}


static gboolean vala_delegate_type_real_is_accessible (ValaDataType* base, ValaSymbol* sym) {
	ValaDelegateType * self;
	gboolean result = FALSE;
	ValaDelegate* _tmp0_ = NULL;
	ValaSymbol* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	self = (ValaDelegateType*) base;
	g_return_val_if_fail (sym != NULL, FALSE);
	_tmp0_ = self->priv->_delegate_symbol;
	_tmp1_ = sym;
	_tmp2_ = vala_symbol_is_accessible ((ValaSymbol*) _tmp0_, _tmp1_);
	result = _tmp2_;
	return result;
}


static gboolean vala_delegate_type_real_check (ValaCodeNode* base, ValaCodeContext* context) {
	ValaDelegateType * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp4_ = FALSE;
	ValaDelegate* _tmp7_ = NULL;
	ValaCodeContext* _tmp8_ = NULL;
	gboolean _tmp9_ = FALSE;
	self = (ValaDelegateType*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp1_ = self->priv->_is_called_once;
	if (_tmp1_) {
		gboolean _tmp2_ = FALSE;
		gboolean _tmp3_ = FALSE;
		_tmp2_ = vala_data_type_get_value_owned ((ValaDataType*) self);
		_tmp3_ = _tmp2_;
		_tmp0_ = !_tmp3_;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp4_ = _tmp0_;
	if (_tmp4_) {
		ValaSourceReference* _tmp5_ = NULL;
		ValaSourceReference* _tmp6_ = NULL;
		_tmp5_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp6_ = _tmp5_;
		vala_report_warning (_tmp6_, "delegates with scope=\"async\" must be owned");
	}
	_tmp7_ = self->priv->_delegate_symbol;
	_tmp8_ = context;
	_tmp9_ = vala_code_node_check ((ValaCodeNode*) _tmp7_, _tmp8_);
	result = _tmp9_;
	return result;
}


static gboolean vala_delegate_type_real_is_disposable (ValaDataType* base) {
	ValaDelegateType * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	ValaDelegate* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
	gboolean _tmp7_ = FALSE;
	gboolean _tmp9_ = FALSE;
	self = (ValaDelegateType*) base;
	_tmp2_ = self->priv->_delegate_symbol;
	_tmp3_ = vala_delegate_get_has_target (_tmp2_);
	_tmp4_ = _tmp3_;
	if (_tmp4_) {
		gboolean _tmp5_ = FALSE;
		gboolean _tmp6_ = FALSE;
		_tmp5_ = vala_data_type_get_value_owned ((ValaDataType*) self);
		_tmp6_ = _tmp5_;
		_tmp1_ = _tmp6_;
	} else {
		_tmp1_ = FALSE;
	}
	_tmp7_ = _tmp1_;
	if (_tmp7_) {
		gboolean _tmp8_ = FALSE;
		_tmp8_ = self->priv->_is_called_once;
		_tmp0_ = !_tmp8_;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp9_ = _tmp0_;
	result = _tmp9_;
	return result;
}


ValaDelegate* vala_delegate_type_get_delegate_symbol (ValaDelegateType* self) {
	ValaDelegate* result;
	ValaDelegate* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_delegate_symbol;
	result = _tmp0_;
	return result;
}


void vala_delegate_type_set_delegate_symbol (ValaDelegateType* self, ValaDelegate* value) {
	ValaDelegate* _tmp0_ = NULL;
	ValaDelegate* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_code_node_ref0 (_tmp0_);
	_vala_code_node_unref0 (self->priv->_delegate_symbol);
	self->priv->_delegate_symbol = _tmp1_;
}


gboolean vala_delegate_type_get_is_called_once (ValaDelegateType* self) {
	gboolean result;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_is_called_once;
	result = _tmp0_;
	return result;
}


void vala_delegate_type_set_is_called_once (ValaDelegateType* self, gboolean value) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_is_called_once = _tmp0_;
}


static void vala_delegate_type_class_init (ValaDelegateTypeClass * klass) {
	vala_delegate_type_parent_class = g_type_class_peek_parent (klass);
	VALA_CODE_NODE_CLASS (klass)->finalize = vala_delegate_type_finalize;
	g_type_class_add_private (klass, sizeof (ValaDelegateTypePrivate));
	VALA_DATA_TYPE_CLASS (klass)->is_invokable = vala_delegate_type_real_is_invokable;
	VALA_DATA_TYPE_CLASS (klass)->get_return_type = vala_delegate_type_real_get_return_type;
	VALA_DATA_TYPE_CLASS (klass)->get_parameters = vala_delegate_type_real_get_parameters;
	VALA_DATA_TYPE_CLASS (klass)->to_qualified_string = vala_delegate_type_real_to_qualified_string;
	VALA_DATA_TYPE_CLASS (klass)->copy = vala_delegate_type_real_copy;
	VALA_DATA_TYPE_CLASS (klass)->is_accessible = vala_delegate_type_real_is_accessible;
	VALA_CODE_NODE_CLASS (klass)->check = vala_delegate_type_real_check;
	VALA_DATA_TYPE_CLASS (klass)->is_disposable = vala_delegate_type_real_is_disposable;
}


static void vala_delegate_type_instance_init (ValaDelegateType * self) {
	self->priv = VALA_DELEGATE_TYPE_GET_PRIVATE (self);
}


static void vala_delegate_type_finalize (ValaCodeNode* obj) {
	ValaDelegateType * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_DELEGATE_TYPE, ValaDelegateType);
	_vala_code_node_unref0 (self->priv->_delegate_symbol);
	VALA_CODE_NODE_CLASS (vala_delegate_type_parent_class)->finalize (obj);
}


/**
 * The type of an instance of a delegate.
 */
GType vala_delegate_type_get_type (void) {
	static volatile gsize vala_delegate_type_type_id__volatile = 0;
	if (g_once_init_enter (&vala_delegate_type_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ValaDelegateTypeClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_delegate_type_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaDelegateType), 0, (GInstanceInitFunc) vala_delegate_type_instance_init, NULL };
		GType vala_delegate_type_type_id;
		vala_delegate_type_type_id = g_type_register_static (VALA_TYPE_DATA_TYPE, "ValaDelegateType", &g_define_type_info, 0);
		g_once_init_leave (&vala_delegate_type_type_id__volatile, vala_delegate_type_type_id);
	}
	return vala_delegate_type_type_id__volatile;
}



