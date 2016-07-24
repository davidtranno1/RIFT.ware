/* valalockstatement.c generated by valac, the Vala compiler
 * generated from valalockstatement.vala, do not modify */

/* valalockstatement.vala
 *
 * Copyright (C) 2009  Jiří Zárevúcky
 * Copyright (C) 2006-2010  Jürg Billeter
 * Copyright (C) 2006-2007  Raffaele Sandrini
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
 * Authors:
 * 	Raffaele Sandrini <raffaele@sandrini.ch>
 * 	Jiří Zárevúcky <zarevucky.jiri@gmail.com>
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

#define VALA_TYPE_STATEMENT (vala_statement_get_type ())
#define VALA_STATEMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_STATEMENT, ValaStatement))
#define VALA_IS_STATEMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_STATEMENT))
#define VALA_STATEMENT_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), VALA_TYPE_STATEMENT, ValaStatementIface))

typedef struct _ValaStatement ValaStatement;
typedef struct _ValaStatementIface ValaStatementIface;

#define VALA_TYPE_LOCK_STATEMENT (vala_lock_statement_get_type ())
#define VALA_LOCK_STATEMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_LOCK_STATEMENT, ValaLockStatement))
#define VALA_LOCK_STATEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_LOCK_STATEMENT, ValaLockStatementClass))
#define VALA_IS_LOCK_STATEMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_LOCK_STATEMENT))
#define VALA_IS_LOCK_STATEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_LOCK_STATEMENT))
#define VALA_LOCK_STATEMENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_LOCK_STATEMENT, ValaLockStatementClass))

typedef struct _ValaLockStatement ValaLockStatement;
typedef struct _ValaLockStatementClass ValaLockStatementClass;
typedef struct _ValaLockStatementPrivate ValaLockStatementPrivate;

#define VALA_TYPE_BLOCK (vala_block_get_type ())
#define VALA_BLOCK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_BLOCK, ValaBlock))
#define VALA_BLOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_BLOCK, ValaBlockClass))
#define VALA_IS_BLOCK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_BLOCK))
#define VALA_IS_BLOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_BLOCK))
#define VALA_BLOCK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_BLOCK, ValaBlockClass))

typedef struct _ValaBlock ValaBlock;
typedef struct _ValaBlockClass ValaBlockClass;
#define _vala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_code_node_unref (var), NULL)))

#define VALA_TYPE_SOURCE_REFERENCE (vala_source_reference_get_type ())
#define VALA_SOURCE_REFERENCE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_SOURCE_REFERENCE, ValaSourceReference))
#define VALA_SOURCE_REFERENCE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_SOURCE_REFERENCE, ValaSourceReferenceClass))
#define VALA_IS_SOURCE_REFERENCE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_SOURCE_REFERENCE))
#define VALA_IS_SOURCE_REFERENCE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_SOURCE_REFERENCE))
#define VALA_SOURCE_REFERENCE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_SOURCE_REFERENCE, ValaSourceReferenceClass))

typedef struct _ValaSourceReference ValaSourceReference;
typedef struct _ValaSourceReferenceClass ValaSourceReferenceClass;

#define VALA_TYPE_UNLOCK_STATEMENT (vala_unlock_statement_get_type ())
#define VALA_UNLOCK_STATEMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_UNLOCK_STATEMENT, ValaUnlockStatement))
#define VALA_UNLOCK_STATEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_UNLOCK_STATEMENT, ValaUnlockStatementClass))
#define VALA_IS_UNLOCK_STATEMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_UNLOCK_STATEMENT))
#define VALA_IS_UNLOCK_STATEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_UNLOCK_STATEMENT))
#define VALA_UNLOCK_STATEMENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_UNLOCK_STATEMENT, ValaUnlockStatementClass))

typedef struct _ValaUnlockStatement ValaUnlockStatement;
typedef struct _ValaUnlockStatementClass ValaUnlockStatementClass;

#define VALA_TYPE_TRY_STATEMENT (vala_try_statement_get_type ())
#define VALA_TRY_STATEMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_TRY_STATEMENT, ValaTryStatement))
#define VALA_TRY_STATEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_TRY_STATEMENT, ValaTryStatementClass))
#define VALA_IS_TRY_STATEMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_TRY_STATEMENT))
#define VALA_IS_TRY_STATEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_TRY_STATEMENT))
#define VALA_TRY_STATEMENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_TRY_STATEMENT, ValaTryStatementClass))

typedef struct _ValaTryStatement ValaTryStatement;
typedef struct _ValaTryStatementClass ValaTryStatementClass;

#define VALA_TYPE_MEMBER_ACCESS (vala_member_access_get_type ())
#define VALA_MEMBER_ACCESS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_MEMBER_ACCESS, ValaMemberAccess))
#define VALA_MEMBER_ACCESS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_MEMBER_ACCESS, ValaMemberAccessClass))
#define VALA_IS_MEMBER_ACCESS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_MEMBER_ACCESS))
#define VALA_IS_MEMBER_ACCESS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_MEMBER_ACCESS))
#define VALA_MEMBER_ACCESS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_MEMBER_ACCESS, ValaMemberAccessClass))

typedef struct _ValaMemberAccess ValaMemberAccess;
typedef struct _ValaMemberAccessClass ValaMemberAccessClass;

#define VALA_TYPE_LOCKABLE (vala_lockable_get_type ())
#define VALA_LOCKABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_LOCKABLE, ValaLockable))
#define VALA_IS_LOCKABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_LOCKABLE))
#define VALA_LOCKABLE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), VALA_TYPE_LOCKABLE, ValaLockableIface))

typedef struct _ValaLockable ValaLockable;
typedef struct _ValaLockableIface ValaLockableIface;

#define VALA_TYPE_SEMANTIC_ANALYZER (vala_semantic_analyzer_get_type ())
#define VALA_SEMANTIC_ANALYZER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_SEMANTIC_ANALYZER, ValaSemanticAnalyzer))
#define VALA_SEMANTIC_ANALYZER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_SEMANTIC_ANALYZER, ValaSemanticAnalyzerClass))
#define VALA_IS_SEMANTIC_ANALYZER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_SEMANTIC_ANALYZER))
#define VALA_IS_SEMANTIC_ANALYZER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_SEMANTIC_ANALYZER))
#define VALA_SEMANTIC_ANALYZER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_SEMANTIC_ANALYZER, ValaSemanticAnalyzerClass))

typedef struct _ValaSemanticAnalyzer ValaSemanticAnalyzer;
typedef struct _ValaSemanticAnalyzerClass ValaSemanticAnalyzerClass;

#define VALA_TYPE_TYPESYMBOL (vala_typesymbol_get_type ())
#define VALA_TYPESYMBOL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_TYPESYMBOL, ValaTypeSymbol))
#define VALA_TYPESYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_TYPESYMBOL, ValaTypeSymbolClass))
#define VALA_IS_TYPESYMBOL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_TYPESYMBOL))
#define VALA_IS_TYPESYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_TYPESYMBOL))
#define VALA_TYPESYMBOL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_TYPESYMBOL, ValaTypeSymbolClass))

typedef struct _ValaTypeSymbol ValaTypeSymbol;
typedef struct _ValaTypeSymbolClass ValaTypeSymbolClass;

#define VALA_TYPE_OBJECT_TYPE_SYMBOL (vala_object_type_symbol_get_type ())
#define VALA_OBJECT_TYPE_SYMBOL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_OBJECT_TYPE_SYMBOL, ValaObjectTypeSymbol))
#define VALA_OBJECT_TYPE_SYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_OBJECT_TYPE_SYMBOL, ValaObjectTypeSymbolClass))
#define VALA_IS_OBJECT_TYPE_SYMBOL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_OBJECT_TYPE_SYMBOL))
#define VALA_IS_OBJECT_TYPE_SYMBOL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_OBJECT_TYPE_SYMBOL))
#define VALA_OBJECT_TYPE_SYMBOL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_OBJECT_TYPE_SYMBOL, ValaObjectTypeSymbolClass))

typedef struct _ValaObjectTypeSymbol ValaObjectTypeSymbol;
typedef struct _ValaObjectTypeSymbolClass ValaObjectTypeSymbolClass;

#define VALA_TYPE_CLASS (vala_class_get_type ())
#define VALA_CLASS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CLASS, ValaClass))
#define VALA_CLASS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CLASS, ValaClassClass))
#define VALA_IS_CLASS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CLASS))
#define VALA_IS_CLASS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CLASS))
#define VALA_CLASS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CLASS, ValaClassClass))

typedef struct _ValaClass ValaClass;
typedef struct _ValaClassClass ValaClassClass;

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

struct _ValaStatementIface {
	GTypeInterface parent_iface;
};

struct _ValaLockStatement {
	ValaCodeNode parent_instance;
	ValaLockStatementPrivate * priv;
};

struct _ValaLockStatementClass {
	ValaCodeNodeClass parent_class;
};

struct _ValaLockStatementPrivate {
	ValaExpression* _resource;
	ValaBlock* _body;
};

struct _ValaLockableIface {
	GTypeInterface parent_iface;
	gboolean (*get_lock_used) (ValaLockable* self);
	void (*set_lock_used) (ValaLockable* self, gboolean used);
};


static gpointer vala_lock_statement_parent_class = NULL;
static ValaStatementIface* vala_lock_statement_vala_statement_parent_iface = NULL;

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
GType vala_statement_get_type (void) G_GNUC_CONST;
GType vala_lock_statement_get_type (void) G_GNUC_CONST;
GType vala_block_get_type (void) G_GNUC_CONST;
#define VALA_LOCK_STATEMENT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VALA_TYPE_LOCK_STATEMENT, ValaLockStatementPrivate))
enum  {
	VALA_LOCK_STATEMENT_DUMMY_PROPERTY
};
gpointer vala_source_reference_ref (gpointer instance);
void vala_source_reference_unref (gpointer instance);
GParamSpec* vala_param_spec_source_reference (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_source_reference (GValue* value, gpointer v_object);
void vala_value_take_source_reference (GValue* value, gpointer v_object);
gpointer vala_value_get_source_reference (const GValue* value);
GType vala_source_reference_get_type (void) G_GNUC_CONST;
ValaLockStatement* vala_lock_statement_new (ValaExpression* resource, ValaBlock* body, ValaSourceReference* source_reference);
ValaLockStatement* vala_lock_statement_construct (GType object_type, ValaExpression* resource, ValaBlock* body, ValaSourceReference* source_reference);
ValaCodeNode* vala_code_node_construct (GType object_type);
void vala_lock_statement_set_body (ValaLockStatement* self, ValaBlock* value);
void vala_code_node_set_source_reference (ValaCodeNode* self, ValaSourceReference* value);
void vala_lock_statement_set_resource (ValaLockStatement* self, ValaExpression* value);
static void vala_lock_statement_real_accept (ValaCodeNode* base, ValaCodeVisitor* visitor);
ValaExpression* vala_lock_statement_get_resource (ValaLockStatement* self);
void vala_code_node_accept (ValaCodeNode* self, ValaCodeVisitor* visitor);
ValaBlock* vala_lock_statement_get_body (ValaLockStatement* self);
void vala_code_visitor_visit_lock_statement (ValaCodeVisitor* self, ValaLockStatement* stmt);
static gboolean vala_lock_statement_real_check (ValaCodeNode* base, ValaCodeContext* context);
ValaSourceReference* vala_code_node_get_source_reference (ValaCodeNode* self);
ValaBlock* vala_block_new (ValaSourceReference* source_reference);
ValaBlock* vala_block_construct (GType object_type, ValaSourceReference* source_reference);
void vala_block_add_statement (ValaBlock* self, ValaStatement* stmt);
ValaUnlockStatement* vala_unlock_statement_new (ValaExpression* resource, ValaSourceReference* source_reference);
ValaUnlockStatement* vala_unlock_statement_construct (GType object_type, ValaExpression* resource, ValaSourceReference* source_reference);
GType vala_unlock_statement_get_type (void) G_GNUC_CONST;
ValaTryStatement* vala_try_statement_new (ValaBlock* body, ValaBlock* finally_body, ValaSourceReference* source_reference);
ValaTryStatement* vala_try_statement_construct (GType object_type, ValaBlock* body, ValaBlock* finally_body, ValaSourceReference* source_reference);
GType vala_try_statement_get_type (void) G_GNUC_CONST;
ValaCodeNode* vala_code_node_get_parent_node (ValaCodeNode* self);
void vala_block_replace_statement (ValaBlock* self, ValaStatement* old_stmt, ValaStatement* new_stmt);
gboolean vala_code_node_check (ValaCodeNode* self, ValaCodeContext* context);
gboolean vala_code_node_get_checked (ValaCodeNode* self);
gboolean vala_code_node_get_error (ValaCodeNode* self);
void vala_code_node_set_checked (ValaCodeNode* self, gboolean value);
GType vala_member_access_get_type (void) G_GNUC_CONST;
ValaSymbol* vala_expression_get_symbol_reference (ValaExpression* self);
GType vala_lockable_get_type (void) G_GNUC_CONST;
void vala_code_node_set_error (ValaCodeNode* self, gboolean value);
void vala_report_error (ValaSourceReference* source, const gchar* message);
ValaSymbol* vala_symbol_get_parent_symbol (ValaSymbol* self);
GType vala_semantic_analyzer_get_type (void) G_GNUC_CONST;
ValaSemanticAnalyzer* vala_code_context_get_analyzer (ValaCodeContext* self);
GType vala_typesymbol_get_type (void) G_GNUC_CONST;
GType vala_object_type_symbol_get_type (void) G_GNUC_CONST;
GType vala_class_get_type (void) G_GNUC_CONST;
ValaClass* vala_semantic_analyzer_get_current_class (ValaSemanticAnalyzer* self);
void vala_lockable_set_lock_used (ValaLockable* self, gboolean used);
static void vala_lock_statement_real_emit (ValaCodeNode* base, ValaCodeGenerator* codegen);
void vala_code_node_emit (ValaCodeNode* self, ValaCodeGenerator* codegen);
static void vala_lock_statement_finalize (ValaCodeNode* obj);


ValaLockStatement* vala_lock_statement_construct (GType object_type, ValaExpression* resource, ValaBlock* body, ValaSourceReference* source_reference) {
	ValaLockStatement* self = NULL;
	ValaBlock* _tmp0_ = NULL;
	ValaSourceReference* _tmp1_ = NULL;
	ValaExpression* _tmp2_ = NULL;
	g_return_val_if_fail (resource != NULL, NULL);
	self = (ValaLockStatement*) vala_code_node_construct (object_type);
	_tmp0_ = body;
	vala_lock_statement_set_body (self, _tmp0_);
	_tmp1_ = source_reference;
	vala_code_node_set_source_reference ((ValaCodeNode*) self, _tmp1_);
	_tmp2_ = resource;
	vala_lock_statement_set_resource (self, _tmp2_);
	return self;
}


ValaLockStatement* vala_lock_statement_new (ValaExpression* resource, ValaBlock* body, ValaSourceReference* source_reference) {
	return vala_lock_statement_construct (VALA_TYPE_LOCK_STATEMENT, resource, body, source_reference);
}


static void vala_lock_statement_real_accept (ValaCodeNode* base, ValaCodeVisitor* visitor) {
	ValaLockStatement * self;
	ValaExpression* _tmp0_ = NULL;
	ValaCodeVisitor* _tmp1_ = NULL;
	ValaBlock* _tmp2_ = NULL;
	ValaCodeVisitor* _tmp5_ = NULL;
	self = (ValaLockStatement*) base;
	g_return_if_fail (visitor != NULL);
	_tmp0_ = self->priv->_resource;
	_tmp1_ = visitor;
	vala_code_node_accept ((ValaCodeNode*) _tmp0_, _tmp1_);
	_tmp2_ = self->priv->_body;
	if (_tmp2_ != NULL) {
		ValaBlock* _tmp3_ = NULL;
		ValaCodeVisitor* _tmp4_ = NULL;
		_tmp3_ = self->priv->_body;
		_tmp4_ = visitor;
		vala_code_node_accept ((ValaCodeNode*) _tmp3_, _tmp4_);
	}
	_tmp5_ = visitor;
	vala_code_visitor_visit_lock_statement (_tmp5_, self);
}


static gpointer _vala_code_node_ref0 (gpointer self) {
	return self ? vala_code_node_ref (self) : NULL;
}


static gboolean vala_lock_statement_real_check (ValaCodeNode* base, ValaCodeContext* context) {
	ValaLockStatement * self;
	gboolean result = FALSE;
	ValaBlock* _tmp0_ = NULL;
	gboolean _tmp34_ = FALSE;
	gboolean _tmp35_ = FALSE;
	ValaExpression* _tmp38_ = NULL;
	ValaCodeContext* _tmp39_ = NULL;
	gboolean _tmp40_ = FALSE;
	ValaExpression* _tmp41_ = NULL;
	gboolean _tmp45_ = FALSE;
	ValaExpression* _tmp50_ = NULL;
	ValaSymbol* _tmp51_ = NULL;
	ValaSymbol* _tmp52_ = NULL;
	ValaSymbol* _tmp53_ = NULL;
	ValaSymbol* _tmp54_ = NULL;
	ValaCodeContext* _tmp55_ = NULL;
	ValaSemanticAnalyzer* _tmp56_ = NULL;
	ValaSemanticAnalyzer* _tmp57_ = NULL;
	ValaClass* _tmp58_ = NULL;
	ValaClass* _tmp59_ = NULL;
	ValaExpression* _tmp64_ = NULL;
	ValaSymbol* _tmp65_ = NULL;
	ValaSymbol* _tmp66_ = NULL;
	gboolean _tmp67_ = FALSE;
	gboolean _tmp68_ = FALSE;
	self = (ValaLockStatement*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = self->priv->_body;
	if (_tmp0_ != NULL) {
		ValaBlock* fin_body = NULL;
		ValaSourceReference* _tmp1_ = NULL;
		ValaSourceReference* _tmp2_ = NULL;
		ValaBlock* _tmp3_ = NULL;
		ValaBlock* _tmp4_ = NULL;
		ValaExpression* _tmp5_ = NULL;
		ValaSourceReference* _tmp6_ = NULL;
		ValaSourceReference* _tmp7_ = NULL;
		ValaUnlockStatement* _tmp8_ = NULL;
		ValaUnlockStatement* _tmp9_ = NULL;
		ValaBlock* block = NULL;
		ValaSourceReference* _tmp10_ = NULL;
		ValaSourceReference* _tmp11_ = NULL;
		ValaBlock* _tmp12_ = NULL;
		ValaBlock* _tmp13_ = NULL;
		ValaExpression* _tmp14_ = NULL;
		ValaSourceReference* _tmp15_ = NULL;
		ValaSourceReference* _tmp16_ = NULL;
		ValaLockStatement* _tmp17_ = NULL;
		ValaLockStatement* _tmp18_ = NULL;
		ValaBlock* _tmp19_ = NULL;
		ValaBlock* _tmp20_ = NULL;
		ValaBlock* _tmp21_ = NULL;
		ValaSourceReference* _tmp22_ = NULL;
		ValaSourceReference* _tmp23_ = NULL;
		ValaTryStatement* _tmp24_ = NULL;
		ValaTryStatement* _tmp25_ = NULL;
		ValaBlock* parent_block = NULL;
		ValaCodeNode* _tmp26_ = NULL;
		ValaCodeNode* _tmp27_ = NULL;
		ValaBlock* _tmp28_ = NULL;
		ValaBlock* _tmp29_ = NULL;
		ValaBlock* _tmp30_ = NULL;
		ValaBlock* _tmp31_ = NULL;
		ValaCodeContext* _tmp32_ = NULL;
		gboolean _tmp33_ = FALSE;
		_tmp1_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp2_ = _tmp1_;
		_tmp3_ = vala_block_new (_tmp2_);
		fin_body = _tmp3_;
		_tmp4_ = fin_body;
		_tmp5_ = self->priv->_resource;
		_tmp6_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp7_ = _tmp6_;
		_tmp8_ = vala_unlock_statement_new (_tmp5_, _tmp7_);
		_tmp9_ = _tmp8_;
		vala_block_add_statement (_tmp4_, (ValaStatement*) _tmp9_);
		_vala_code_node_unref0 (_tmp9_);
		_tmp10_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp11_ = _tmp10_;
		_tmp12_ = vala_block_new (_tmp11_);
		block = _tmp12_;
		_tmp13_ = block;
		_tmp14_ = self->priv->_resource;
		_tmp15_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp16_ = _tmp15_;
		_tmp17_ = vala_lock_statement_new (_tmp14_, NULL, _tmp16_);
		_tmp18_ = _tmp17_;
		vala_block_add_statement (_tmp13_, (ValaStatement*) _tmp18_);
		_vala_code_node_unref0 (_tmp18_);
		_tmp19_ = block;
		_tmp20_ = self->priv->_body;
		_tmp21_ = fin_body;
		_tmp22_ = vala_code_node_get_source_reference ((ValaCodeNode*) self);
		_tmp23_ = _tmp22_;
		_tmp24_ = vala_try_statement_new (_tmp20_, _tmp21_, _tmp23_);
		_tmp25_ = _tmp24_;
		vala_block_add_statement (_tmp19_, (ValaStatement*) _tmp25_);
		_vala_code_node_unref0 (_tmp25_);
		_tmp26_ = vala_code_node_get_parent_node ((ValaCodeNode*) self);
		_tmp27_ = _tmp26_;
		_tmp28_ = _vala_code_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp27_, VALA_TYPE_BLOCK, ValaBlock));
		parent_block = _tmp28_;
		_tmp29_ = parent_block;
		_tmp30_ = block;
		vala_block_replace_statement (_tmp29_, (ValaStatement*) self, (ValaStatement*) _tmp30_);
		_tmp31_ = block;
		_tmp32_ = context;
		_tmp33_ = vala_code_node_check ((ValaCodeNode*) _tmp31_, _tmp32_);
		result = _tmp33_;
		_vala_code_node_unref0 (parent_block);
		_vala_code_node_unref0 (block);
		_vala_code_node_unref0 (fin_body);
		return result;
	}
	_tmp34_ = vala_code_node_get_checked ((ValaCodeNode*) self);
	_tmp35_ = _tmp34_;
	if (_tmp35_) {
		gboolean _tmp36_ = FALSE;
		gboolean _tmp37_ = FALSE;
		_tmp36_ = vala_code_node_get_error ((ValaCodeNode*) self);
		_tmp37_ = _tmp36_;
		result = !_tmp37_;
		return result;
	}
	vala_code_node_set_checked ((ValaCodeNode*) self, TRUE);
	_tmp38_ = self->priv->_resource;
	_tmp39_ = context;
	vala_code_node_check ((ValaCodeNode*) _tmp38_, _tmp39_);
	_tmp41_ = self->priv->_resource;
	if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp41_, VALA_TYPE_MEMBER_ACCESS)) {
		ValaExpression* _tmp42_ = NULL;
		ValaSymbol* _tmp43_ = NULL;
		ValaSymbol* _tmp44_ = NULL;
		_tmp42_ = self->priv->_resource;
		_tmp43_ = vala_expression_get_symbol_reference (_tmp42_);
		_tmp44_ = _tmp43_;
		_tmp40_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp44_, VALA_TYPE_LOCKABLE);
	} else {
		_tmp40_ = FALSE;
	}
	_tmp45_ = _tmp40_;
	if (!_tmp45_) {
		ValaExpression* _tmp46_ = NULL;
		ValaExpression* _tmp47_ = NULL;
		ValaSourceReference* _tmp48_ = NULL;
		ValaSourceReference* _tmp49_ = NULL;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp46_ = self->priv->_resource;
		vala_code_node_set_error ((ValaCodeNode*) _tmp46_, TRUE);
		_tmp47_ = self->priv->_resource;
		_tmp48_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp47_);
		_tmp49_ = _tmp48_;
		vala_report_error (_tmp49_, "Expression is either not a member access or does not denote a lockable" \
" member");
		result = FALSE;
		return result;
	}
	_tmp50_ = self->priv->_resource;
	_tmp51_ = vala_expression_get_symbol_reference (_tmp50_);
	_tmp52_ = _tmp51_;
	_tmp53_ = vala_symbol_get_parent_symbol (_tmp52_);
	_tmp54_ = _tmp53_;
	_tmp55_ = context;
	_tmp56_ = vala_code_context_get_analyzer (_tmp55_);
	_tmp57_ = _tmp56_;
	_tmp58_ = vala_semantic_analyzer_get_current_class (_tmp57_);
	_tmp59_ = _tmp58_;
	if (_tmp54_ != G_TYPE_CHECK_INSTANCE_CAST (_tmp59_, VALA_TYPE_SYMBOL, ValaSymbol)) {
		ValaExpression* _tmp60_ = NULL;
		ValaExpression* _tmp61_ = NULL;
		ValaSourceReference* _tmp62_ = NULL;
		ValaSourceReference* _tmp63_ = NULL;
		vala_code_node_set_error ((ValaCodeNode*) self, TRUE);
		_tmp60_ = self->priv->_resource;
		vala_code_node_set_error ((ValaCodeNode*) _tmp60_, TRUE);
		_tmp61_ = self->priv->_resource;
		_tmp62_ = vala_code_node_get_source_reference ((ValaCodeNode*) _tmp61_);
		_tmp63_ = _tmp62_;
		vala_report_error (_tmp63_, "Only members of the current class are lockable");
	}
	_tmp64_ = self->priv->_resource;
	_tmp65_ = vala_expression_get_symbol_reference (_tmp64_);
	_tmp66_ = _tmp65_;
	vala_lockable_set_lock_used (G_TYPE_CHECK_INSTANCE_CAST (_tmp66_, VALA_TYPE_LOCKABLE, ValaLockable), TRUE);
	_tmp67_ = vala_code_node_get_error ((ValaCodeNode*) self);
	_tmp68_ = _tmp67_;
	result = !_tmp68_;
	return result;
}


static void vala_lock_statement_real_emit (ValaCodeNode* base, ValaCodeGenerator* codegen) {
	ValaLockStatement * self;
	ValaExpression* _tmp0_ = NULL;
	ValaCodeGenerator* _tmp1_ = NULL;
	ValaCodeGenerator* _tmp2_ = NULL;
	self = (ValaLockStatement*) base;
	g_return_if_fail (codegen != NULL);
	_tmp0_ = self->priv->_resource;
	_tmp1_ = codegen;
	vala_code_node_emit ((ValaCodeNode*) _tmp0_, _tmp1_);
	_tmp2_ = codegen;
	vala_code_visitor_visit_lock_statement ((ValaCodeVisitor*) _tmp2_, self);
}


ValaExpression* vala_lock_statement_get_resource (ValaLockStatement* self) {
	ValaExpression* result;
	ValaExpression* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_resource;
	result = _tmp0_;
	return result;
}


void vala_lock_statement_set_resource (ValaLockStatement* self, ValaExpression* value) {
	ValaExpression* _tmp0_ = NULL;
	ValaExpression* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_code_node_ref0 (_tmp0_);
	_vala_code_node_unref0 (self->priv->_resource);
	self->priv->_resource = _tmp1_;
}


ValaBlock* vala_lock_statement_get_body (ValaLockStatement* self) {
	ValaBlock* result;
	ValaBlock* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_body;
	result = _tmp0_;
	return result;
}


void vala_lock_statement_set_body (ValaLockStatement* self, ValaBlock* value) {
	ValaBlock* _tmp0_ = NULL;
	ValaBlock* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_code_node_ref0 (_tmp0_);
	_vala_code_node_unref0 (self->priv->_body);
	self->priv->_body = _tmp1_;
}


static void vala_lock_statement_class_init (ValaLockStatementClass * klass) {
	vala_lock_statement_parent_class = g_type_class_peek_parent (klass);
	VALA_CODE_NODE_CLASS (klass)->finalize = vala_lock_statement_finalize;
	g_type_class_add_private (klass, sizeof (ValaLockStatementPrivate));
	VALA_CODE_NODE_CLASS (klass)->accept = vala_lock_statement_real_accept;
	VALA_CODE_NODE_CLASS (klass)->check = vala_lock_statement_real_check;
	VALA_CODE_NODE_CLASS (klass)->emit = vala_lock_statement_real_emit;
}


static void vala_lock_statement_vala_statement_interface_init (ValaStatementIface * iface) {
	vala_lock_statement_vala_statement_parent_iface = g_type_interface_peek_parent (iface);
}


static void vala_lock_statement_instance_init (ValaLockStatement * self) {
	self->priv = VALA_LOCK_STATEMENT_GET_PRIVATE (self);
}


static void vala_lock_statement_finalize (ValaCodeNode* obj) {
	ValaLockStatement * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_LOCK_STATEMENT, ValaLockStatement);
	_vala_code_node_unref0 (self->priv->_resource);
	_vala_code_node_unref0 (self->priv->_body);
	VALA_CODE_NODE_CLASS (vala_lock_statement_parent_class)->finalize (obj);
}


/**
 * Represents a lock statement e.g. {{{ lock (a); }}} or {{{ lock (a) { f(a); } }}}.
 *
 * If the statement is empty, the mutex remains locked until a corresponding UnlockStatement
 * occurs. Otherwise it's translated into a try/finally statement which unlocks the mutex
 * after the block is finished.
 */
GType vala_lock_statement_get_type (void) {
	static volatile gsize vala_lock_statement_type_id__volatile = 0;
	if (g_once_init_enter (&vala_lock_statement_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ValaLockStatementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_lock_statement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaLockStatement), 0, (GInstanceInitFunc) vala_lock_statement_instance_init, NULL };
		static const GInterfaceInfo vala_statement_info = { (GInterfaceInitFunc) vala_lock_statement_vala_statement_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType vala_lock_statement_type_id;
		vala_lock_statement_type_id = g_type_register_static (VALA_TYPE_CODE_NODE, "ValaLockStatement", &g_define_type_info, 0);
		g_type_add_interface_static (vala_lock_statement_type_id, VALA_TYPE_STATEMENT, &vala_statement_info);
		g_once_init_leave (&vala_lock_statement_type_id__volatile, vala_lock_statement_type_id);
	}
	return vala_lock_statement_type_id__volatile;
}



