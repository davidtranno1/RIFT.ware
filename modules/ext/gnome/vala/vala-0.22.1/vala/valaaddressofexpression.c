/* valaaddressofexpression.c generated by valac, the Vala compiler
 * generated from valaaddressofexpression.vala, do not modify */

/* valaaddressofexpression.vala
 *
 * Copyright (C) 2007-2010  Jürg Billeter
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
typedef struct _ValaExpressionPrivate ValaExpressionPrivate;

#define VALA_TYPE_ADDRESSOF_EXPRESSION (vala_addressof_expression_get_type ())
#define VALA_ADDRESSOF_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_ADDRESSOF_EXPRESSION, ValaAddressofExpression))
#define VALA_ADDRESSOF_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_ADDRESSOF_EXPRESSION, ValaAddressofExpressionClass))
#define VALA_IS_ADDRESSOF_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_ADDRESSOF_EXPRESSION))
#define VALA_IS_ADDRESSOF_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_ADDRESSOF_EXPRESSION))
#define VALA_ADDRESSOF_EXPRESSION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_ADDRESSOF_EXPRESSION, ValaAddressofExpressionClass))

typedef struct _ValaAddressofExpression ValaAddressofExpression;
typedef struct _ValaAddressofExpressionClass ValaAddressofExpressionClass;
typedef struct _ValaAddressofExpressionPrivate ValaAddressofExpressionPrivate;
#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))

#define VALA_TYPE_SOURCE_REFERENCE (vala_source_reference_get_type ())
#define VALA_SOURCE_REFERENCE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_SOURCE_REFERENCE, ValaSourceReference))
#define VALA_SOURCE_REFERENCE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_SOURCE_REFERENCE, ValaSourceReferenceClass))
#define VALA_IS_SOURCE_REFERENCE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_SOURCE_REFERENCE))
#define VALA_IS_SOURCE_REFERENCE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_SOURCE_REFERENCE))
#define VALA_SOURCE_REFERENCE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_SOURCE_REFERENCE, ValaSourceReferenceClass))

typedef struct _ValaSourceReference ValaSourceReference;
typedef struct _ValaSourceReferenceClass ValaSourceReferenceClass;

#define VALA_TYPE_ELEMENT_ACCESS (vala_element_access_get_type ())
#define VALA_ELEMENT_ACCESS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_ELEMENT_ACCESS, ValaElementAccess))
#define VALA_ELEMENT_ACCESS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_ELEMENT_ACCESS, ValaElementAccessClass))
#define VALA_IS_ELEMENT_ACCESS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_ELEMENT_ACCESS))
#define VALA_IS_ELEMENT_ACCESS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_ELEMENT_ACCESS))
#define VALA_ELEMENT_ACCESS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_ELEMENT_ACCESS, ValaElementAccessClass))

typedef struct _ValaElementAccess ValaElementAccess;
typedef struct _ValaElementAccessClass ValaElementAccessClass;

#define VALA_TYPE_MEMBER_ACCESS (vala_member_access_get_type ())
#define VALA_MEMBER_ACCESS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_MEMBER_ACCESS, ValaMemberAccess))
#define VALA_MEMBER_ACCESS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_MEMBER_ACCESS, ValaMemberAccessClass))
#define VALA_IS_MEMBER_ACCESS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_MEMBER_ACCESS))
#define VALA_IS_MEMBER_ACCESS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_MEMBER_ACCESS))
#define VALA_MEMBER_ACCESS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_MEMBER_ACCESS, ValaMemberAccessClass))

typedef struct _ValaMemberAccess ValaMemberAccess;
typedef struct _ValaMemberAccessClass ValaMemberAccessClass;

#define VALA_TYPE_REFERENCE_TYPE (vala_reference_type_get_type ())
#define VALA_REFERENCE_TYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_REFERENCE_TYPE, ValaReferenceType))
#define VALA_REFERENCE_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_REFERENCE_TYPE, ValaReferenceTypeClass))
#define VALA_IS_REFERENCE_TYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_REFERENCE_TYPE))
#define VALA_IS_REFERENCE_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_REFERENCE_TYPE))
#define VALA_REFERENCE_TYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_REFERENCE_TYPE, ValaReferenceTypeClass))

typedef struct _ValaReferenceType ValaReferenceType;
typedef struct _ValaReferenceTypeClass ValaReferenceTypeClass;

#define VALA_TYPE_ARRAY_TYPE (vala_array_type_get_type ())
#define VALA_ARRAY_TYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_ARRAY_TYPE, ValaArrayType))
#define VALA_ARRAY_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_ARRAY_TYPE, ValaArrayTypeClass))
#define VALA_IS_ARRAY_TYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_ARRAY_TYPE))
#define VALA_IS_ARRAY_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_ARRAY_TYPE))
#define VALA_ARRAY_TYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_ARRAY_TYPE, ValaArrayTypeClass))

typedef struct _ValaArrayType ValaArrayType;
typedef struct _ValaArrayTypeClass ValaArrayTypeClass;

#define VALA_TYPE_POINTER_TYPE (vala_pointer_type_get_type ())
#define VALA_POINTER_TYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_POINTER_TYPE, ValaPointerType))
#define VALA_POINTER_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_POINTER_TYPE, ValaPointerTypeClass))
#define VALA_IS_POINTER_TYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_POINTER_TYPE))
#define VALA_IS_POINTER_TYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_POINTER_TYPE))
#define VALA_POINTER_TYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_POINTER_TYPE, ValaPointerTypeClass))

typedef struct _ValaPointerType ValaPointerType;
typedef struct _ValaPointerTypeClass ValaPointerTypeClass;

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

struct _ValaExpression {
	ValaCodeNode parent_instance;
	ValaExpressionPrivate * priv;
};

struct _ValaExpressionClass {
	ValaCodeNodeClass parent_class;
	gboolean (*is_constant) (ValaExpression* self);
	gboolean (*is_pure) (ValaExpression* self);
	gboolean (*is_non_null) (ValaExpression* self);
};

struct _ValaAddressofExpression {
	ValaExpression parent_instance;
	ValaAddressofExpressionPrivate * priv;
};

struct _ValaAddressofExpressionClass {
	ValaExpressionClass parent_class;
};

struct _ValaAddressofExpressionPrivate {
	ValaExpression* _inner;
};


static gpointer vala_addressof_expression_parent_class = NULL;

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
GType vala_addressof_expression_get_type (void) G_GNUC_CONST;
#define VALA_ADDRESSOF_EXPRESSION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VALA_TYPE_ADDRESSOF_EXPRESSION, ValaAddressofExpressionPrivate))
enum  {
	VALA_ADDRESSOF_EXPRESSION_DUMMY_PROPERTY
};
gpointer vala_source_reference_ref (gpointer instance);
void vala_source_reference_unref (gpointer instance);
GParamSpec* vala_param_spec_source_reference (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_source_reference (GValue* value, gpointer v_object);
void vala_value_take_source_reference (GValue* value, gpointer v_object);
gpointer vala_value_get_source_reference (const GValue* value);
GType vala_source_reference_get_type (void) G_GNUC_CONST;
ValaAddressofExpression* vala_addressof_expression_new (ValaExpression* inner, ValaSourceReference* source_reference);
ValaAddressofExpression* vala_addressof_expression_construct (GType object_type, ValaExpression* inner, ValaSourceReference* source_reference);
ValaExpression* vala_expression_construct (GType object_type);
void vala_code_node_set_source_reference (ValaCodeNode* self, ValaSourceReference* value);
void vala_addressof_expression_set_inner (ValaAddressofExpression* self, ValaExpression* value);
static void vala_addressof_expression_real_accept (ValaCodeNode* base, ValaCodeVisitor* visitor);
void vala_code_visitor_visit_addressof_expression (ValaCodeVisitor* self, ValaAddressofExpression* expr);
void vala_code_visitor_visit_expression (ValaCodeVisitor* self, ValaExpression* expr);
static void vala_addressof_expression_real_accept_children (ValaCodeNode* base, ValaCodeVisitor* visitor);
ValaExpression* vala_addressof_expression_get_inner (ValaAddressofExpression* self);
void vala_code_node_accept (ValaCodeNode* self, ValaCodeVisitor* visitor);
static void vala_addressof_expression_real_replace_expression (ValaCodeNode* base, ValaExpression* old_node, ValaExpression* new_node);
static gboolean vala_addressof_expression_real_is_pure (ValaExpression* base);
gboolean vala_expression_is_pure (ValaExpression* self);
static gboolean vala_addressof_expression_real_check (ValaCodeNode* base, ValaCodeContext* context);
gboolean vala_code_node_get_checked (ValaCodeNode* self);
gboolean vala_code_node_get_error (ValaCodeNode* self);
void vala_code_node_set_checked (ValaCodeNode* self, gboolean value);
void vala_expression_set_lvalue (ValaExpression* self, gboolean value);
gboolean vala_code_node_check (ValaCodeNode* self, ValaCodeContext* context);
void vala_code_node_set_error (ValaCodeNode* self, gboolean value);
GType vala_element_access_get_type (void) G_GNUC_CONST;
GType vala_member_access_get_type (void) G_GNUC_CONST;
ValaSymbol* vala_expression_get_symbol_reference (ValaExpression* self);
ValaExpression* vala_element_access_get_container (ValaElementAccess* self);
ValaDataType* vala_expression_get_value_type (ValaExpression* self);
GType vala_reference_type_get_type (void) G_GNUC_CONST;
GType vala_array_type_get_type (void) G_GNUC_CONST;
GType vala_pointer_type_get_type (void) G_GNUC_CONST;
void vala_report_error (ValaSourceReference* source, const gchar* message);
ValaSourceReference* vala_code_node_get_source_reference (ValaCodeNode* self);
gboolean vala_data_type_is_reference_type_or_type_parameter (ValaDataType* self);
ValaPointerType* vala_pointer_type_new (ValaDataType* base_type, ValaSourceReference* source_reference);
ValaPointerType* vala_pointer_type_construct (GType object_type, ValaDataType* base_type, ValaSourceReference* source_reference);
void vala_expression_set_value_type (ValaExpression* self, ValaDataType* value);
static void vala_addressof_expression_real_emit (ValaCodeNode* base, ValaCodeGenerator* codegen);
void vala_code_node_emit (ValaCodeNode* self, ValaCodeGenerator* codegen);
void vala_code_node_set_parent_node (ValaCodeNode* self, ValaCodeNode* value);
static void vala_addressof_expression_finalize (ValaCodeNode* obj);


/**
 * Creates a new address-of expression.
 *
 * @param inner variable whose address is to be computed
 * @return      newly created address-of expression
 */
ValaAddressofExpression* vala_addressof_expression_construct (GType object_type, ValaExpression* inner, ValaSourceReference* source_reference) {
	ValaAddressofExpression* self = NULL;
	ValaSourceReference* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	g_return_val_if_fail (inner != NULL, NULL);
	self = (ValaAddressofExpression*) vala_expression_construct (object_type);
	_tmp0_ = source_reference;
	vala_code_node_set_source_reference ((ValaCodeNode*) self, _tmp0_);
	_tmp1_ = inner;
	vala_addressof_expression_set_inner (self, _tmp1_);
	return self;
}


ValaAddressofExpression* vala_addressof_expression_new (ValaExpression* inner, ValaSourceReference* source_reference) {
	return vala_addressof_expression_construct (VALA_TYPE_ADDRESSOF_EXPRESSION, inner, source_reference);
}


static void vala_addressof_expression_real_accept (ValaCodeNode* base, ValaCodeVisitor* visitor) {
	ValaAddressofExpression * self;
	ValaCodeVisitor* _tmp0_ = NULL;
	ValaCodeVisitor* _tmp1_ = NULL;
	self = (ValaAddressofExpression*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = visitor;
	vala_code_visitor_visit_addressof_expression (_tmp0_, self);
	_tmp1_ = visitor;
	vala_code_visitor_visit_expression (_tmp1_, (ValaExpression*) self);
}


static void vala_addressof_expression_real_accept_children (ValaCodeNode* base, ValaCodeVisitor* visitor) {
	ValaAddressofExpression * self;
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	ValaCodeVisitor* _tmp2_ = NULL;
	self = (ValaAddressofExpression*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = vala_addressof_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = visitor;
	vala_code_node_accept ((ValaCodeNode*) _tmp1_, _tmp2_);
}


static void vala_addressof_expression_real_replace_expression (ValaCodeNode* base, ValaExpression* old_node, ValaExpression* new_node) {
	ValaAddressofExpression * self;
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	ValaExpression* _tmp2_ = NULL;
	self = (ValaAddressofExpression*) base;
	g_return_if_fail (old_node != NULL);
	g_return_if_fail (new_node != NULL);
	_tmp0_ = vala_addressof_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = old_node;
	if (_tmp1_ == _tmp2_) {
		ValaExpression* _tmp3_ = NULL;
		_tmp3_ = new_node;
		vala_addressof_expression_set_inner (self, _tmp3_);
	}
}


static gboolean vala_addressof_expression_real_is_pure (ValaExpression* base) {
	ValaAddressofExpression * self;
	gboolean result = FALSE;
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	self = (ValaAddressofExpression*) base;
	_tmp0_ = vala_addressof_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = vala_expression_is_pure (_tmp1_);
	result = _tmp2_;
	return result;
}


static gpointer _vala_code_node_ref0 (gpointer self) {
	return self ? vala_code_node_ref (self) : NULL;
}


static gboolean vala_addressof_expression_real_check (ValaCodeNode* base, ValaCodeContext* context) {
	ValaAddressofExpression * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	ValaExpression* _tmp4_ = NULL;
	ValaExpression* _tmp5_ = NULL;
	ValaExpression* _tmp6_ = NULL;
	ValaExpression* _tmp7_ = NULL;
	ValaCodeContext* _tmp8_ = NULL;
	gboolean _tmp9_ = FALSE;
	ValaElementAccess* ea = NULL;
	ValaExpression* _tmp10_ = NULL;
	ValaExpression* _tmp11_ = NULL;
	ValaElementAccess* _tmp12_ = NULL;
	gboolean _tmp13_ = FALSE;
	ValaExpression* _tmp14_ = NULL;
	ValaExpression* _tmp15_ = NULL;
	gboolean _tmp20_ = FALSE;
	ValaExpression* _tmp38_ = NULL;
	ValaExpression* _tmp39_ = NULL;
	ValaDataType* _tmp40_ = NULL;
	ValaDataType* _tmp41_ = NULL;
	gboolean _tmp42_ = FALSE;
	gboolean _tmp57_ = FALSE;
	gboolean _tmp58_ = FALSE;
	self = (ValaAddressofExpression*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = vala_code_node_get_checked ((ValaCodeNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_) {
		gboolean _tmp2_ = FALSE;
		gboolean _tmp3_ = FALSE;
		_tmp2_ = vala_code_node_get_error ((ValaCodeNode*) self);
		_tmp3_ = _tmp2_;
		result = !_tmp3_;
		return result;
	}
	vala_code_node_set_checked ((ValaCodeNode*) self, TRUE);
	_tmp4_ = vala_addressof_expression_get_inner (self);
	_tmp5_ = _tmp4_;
	vala_expression_set_lvalue (_tmp5_, TRUE);
	_tmp6_ = vala_addressof_expression_get_inner (self);
	_tmp7_ = _tmp6_;
	_tmp8_ = context;
	_tmp9_ = vala_code_node_check ((ValaCodeNode*) _tmp7_, _tmp8_);
	if (!_tmp9_) {
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	}
	_tmp10_ = vala_addressof_expression_get_inner (self);
	_tmp11_ = _tmp10_;
	_tmp12_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp11_, VALA_TYPE_ELEMENT_ACCESS) ? ((ValaElementAccess*) _tmp11_) : NULL);
	ea = _tmp12_;
	_tmp14_ = vala_addressof_expression_get_inner (self);
	_tmp15_ = _tmp14_;
	if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp15_, VALA_TYPE_MEMBER_ACCESS)) {
		ValaExpression* _tmp16_ = NULL;
		ValaExpression* _tmp17_ = NULL;
		ValaSymbol* _tmp18_ = NULL;
		ValaSymbol* _tmp19_ = NULL;
		_tmp16_ = vala_addressof_expression_get_inner (self);
		_tmp17_ = _tmp16_;
		_tmp18_ = vala_expression_get_symbol_reference (_tmp17_);
		_tmp19_ = _tmp18_;
		_tmp13_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp19_, VALA_TYPE_VARIABLE);
	} else {
		_tmp13_ = FALSE;
	}
	_tmp20_ = _tmp13_;
	if (_tmp20_) {
	} else {
		gboolean _tmp21_ = FALSE;
		ValaElementAccess* _tmp22_ = NULL;
		gboolean _tmp35_ = FALSE;
		_tmp22_ = ea;
		if (_tmp22_ != NULL) {
			gboolean _tmp23_ = FALSE;
			ValaElementAccess* _tmp24_ = NULL;
			ValaExpression* _tmp25_ = NULL;
			ValaExpression* _tmp26_ = NULL;
			ValaDataType* _tmp27_ = NULL;
			ValaDataType* _tmp28_ = NULL;
			gboolean _tmp34_ = FALSE;
			_tmp24_ = ea;
			_tmp25_ = vala_element_access_get_container (_tmp24_);
			_tmp26_ = _tmp25_;
			_tmp27_ = vala_expression_get_value_type (_tmp26_);
			_tmp28_ = _tmp27_;
			if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp28_, VALA_TYPE_ARRAY_TYPE)) {
				_tmp23_ = TRUE;
			} else {
				ValaElementAccess* _tmp29_ = NULL;
				ValaExpression* _tmp30_ = NULL;
				ValaExpression* _tmp31_ = NULL;
				ValaDataType* _tmp32_ = NULL;
				ValaDataType* _tmp33_ = NULL;
				_tmp29_ = ea;
				_tmp30_ = vala_element_access_get_container (_tmp29_);
				_tmp31_ = _tmp30_;
				_tmp32_ = vala_expression_get_value_type (_tmp31_);
				_tmp33_ = _tmp32_;
				_tmp23_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp33_, VALA_TYPE_POINTER_TYPE);
			}
			_tmp34_ = _tmp23_;
			_tmp21_ = _tmp34_;
		} else {
			_tmp21_ = FALSE;
		}
		_tmp35_ = _tmp21_;
		if (_tmp35_) {
		} else {
			ValaSourceReference* _tmp36_ = NULL;
			ValaSourceReference* _tmp37_ = NULL;
			vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
			_tmp36_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
			_tmp37_ = _tmp36_;
			vala_report_error (_tmp37_, "Address-of operator not supported for this expression");
			result = FALSE;
			_vala_code_node_unref0 (ea);
			return result;
		}
	}
	_tmp38_ = vala_addressof_expression_get_inner (self);
	_tmp39_ = _tmp38_;
	_tmp40_ = vala_expression_get_value_type (_tmp39_);
	_tmp41_ = _tmp40_;
	_tmp42_ = vala_data_type_is_reference_type_or_type_parameter (_tmp41_);
	if (_tmp42_) {
		ValaExpression* _tmp43_ = NULL;
		ValaExpression* _tmp44_ = NULL;
		ValaDataType* _tmp45_ = NULL;
		ValaDataType* _tmp46_ = NULL;
		ValaPointerType* _tmp47_ = NULL;
		ValaPointerType* _tmp48_ = NULL;
		ValaPointerType* _tmp49_ = NULL;
		ValaPointerType* _tmp50_ = NULL;
		_tmp43_ = vala_addressof_expression_get_inner (self);
		_tmp44_ = _tmp43_;
		_tmp45_ = vala_expression_get_value_type (_tmp44_);
		_tmp46_ = _tmp45_;
		_tmp47_ = vala_pointer_type_new (_tmp46_, NULL);
		_tmp48_ = _tmp47_;
		_tmp49_ = vala_pointer_type_new ((ValaDataType*) _tmp48_, NULL);
		_tmp50_ = _tmp49_;
		vala_expression_set_value_type ((ValaExpression*) self, (ValaDataType*) _tmp50_);
		_vala_code_node_unref0 (_tmp50_);
		_vala_code_node_unref0 (_tmp48_);
	} else {
		ValaExpression* _tmp51_ = NULL;
		ValaExpression* _tmp52_ = NULL;
		ValaDataType* _tmp53_ = NULL;
		ValaDataType* _tmp54_ = NULL;
		ValaPointerType* _tmp55_ = NULL;
		ValaPointerType* _tmp56_ = NULL;
		_tmp51_ = vala_addressof_expression_get_inner (self);
		_tmp52_ = _tmp51_;
		_tmp53_ = vala_expression_get_value_type (_tmp52_);
		_tmp54_ = _tmp53_;
		_tmp55_ = vala_pointer_type_new (_tmp54_, NULL);
		_tmp56_ = _tmp55_;
		vala_expression_set_value_type ((ValaExpression*) self, (ValaDataType*) _tmp56_);
		_vala_code_node_unref0 (_tmp56_);
	}
	_tmp57_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp58_ = _tmp57_;
	result = !_tmp58_;
	_vala_code_node_unref0 (ea);
	return result;
}


static void vala_addressof_expression_real_emit (ValaCodeNode* base, ValaCodeGenerator* codegen) {
	ValaAddressofExpression * self;
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	ValaCodeGenerator* _tmp2_ = NULL;
	ValaCodeGenerator* _tmp3_ = NULL;
	ValaCodeGenerator* _tmp4_ = NULL;
	self = (ValaAddressofExpression*) base;
	g_return_if_fail (codegen != NULL);
	_tmp0_ = vala_addressof_expression_get_inner (self);
	_tmp1_ = _tmp0_;
	_tmp2_ = codegen;
	vala_code_node_emit ((ValaCodeNode*) _tmp1_, _tmp2_);
	_tmp3_ = codegen;
	vala_code_visitor_visit_addressof_expression ((ValaCodeVisitor*) _tmp3_, self);
	_tmp4_ = codegen;
	vala_code_visitor_visit_expression ((ValaCodeVisitor*) _tmp4_, (ValaExpression*) self);
}


ValaExpression* vala_addressof_expression_get_inner (ValaAddressofExpression* self) {
	ValaExpression* result;
	ValaExpression* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_inner;
	result = _tmp0_;
	return result;
}


void vala_addressof_expression_set_inner (ValaAddressofExpression* self, ValaExpression* value) {
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	ValaExpression* _tmp2_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_code_node_ref0 (_tmp0_);
	_vala_code_node_unref0 (self->priv->_inner);
	self->priv->_inner = _tmp1_;
	_tmp2_ = self->priv->_inner;
	vala_code_node_set_parent_node ((ValaCodeNode*) _tmp2_, (ValaCodeNode*) self);
}


static void vala_addressof_expression_class_init (ValaAddressofExpressionClass * klass) {
	vala_addressof_expression_parent_class = g_type_class_peek_parent (klass);
	VALA_CODE_NODE_CLASS (klass)->finalize = vala_addressof_expression_finalize;
	g_type_class_add_private (klass, sizeof (ValaAddressofExpressionPrivate));
	VALA_CODE_NODE_CLASS (klass)->accept = vala_addressof_expression_real_accept;
	VALA_CODE_NODE_CLASS (klass)->accept_children = vala_addressof_expression_real_accept_children;
	VALA_CODE_NODE_CLASS (klass)->replace_expression = vala_addressof_expression_real_replace_expression;
	VALA_EXPRESSION_CLASS (klass)->is_pure = vala_addressof_expression_real_is_pure;
	VALA_CODE_NODE_CLASS (klass)->check = vala_addressof_expression_real_check;
	VALA_CODE_NODE_CLASS (klass)->emit = vala_addressof_expression_real_emit;
}


static void vala_addressof_expression_instance_init (ValaAddressofExpression * self) {
	self->priv = VALA_ADDRESSOF_EXPRESSION_GET_PRIVATE (self);
}


static void vala_addressof_expression_finalize (ValaCodeNode* obj) {
	ValaAddressofExpression * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_ADDRESSOF_EXPRESSION, ValaAddressofExpression);
	_vala_code_node_unref0 (self->priv->_inner);
	VALA_CODE_NODE_CLASS (vala_addressof_expression_parent_class)->finalize (obj);
}


/**
 * Represents an address-of expression in the source code, e.g. `&foo`.
 */
GType vala_addressof_expression_get_type (void) {
	static volatile gsize vala_addressof_expression_type_id__volatile = 0;
	if (g_once_init_enter (&vala_addressof_expression_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ValaAddressofExpressionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_addressof_expression_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaAddressofExpression), 0, (GInstanceInitFunc) vala_addressof_expression_instance_init, NULL };
		GType vala_addressof_expression_type_id;
		vala_addressof_expression_type_id = g_type_register_static (VALA_TYPE_EXPRESSION, "ValaAddressofExpression", &g_define_type_info, 0);
		g_once_init_leave (&vala_addressof_expression_type_id__volatile, vala_addressof_expression_type_id);
	}
	return vala_addressof_expression_type_id__volatile;
}



