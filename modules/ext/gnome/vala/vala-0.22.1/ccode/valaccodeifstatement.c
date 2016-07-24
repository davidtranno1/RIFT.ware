/* valaccodeifstatement.c generated by valac, the Vala compiler
 * generated from valaccodeifstatement.vala, do not modify */

/* valaccodeifstatement.vala
 *
 * Copyright (C) 2006-2008  Jürg Billeter
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


#define VALA_TYPE_CCODE_NODE (vala_ccode_node_get_type ())
#define VALA_CCODE_NODE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_NODE, ValaCCodeNode))
#define VALA_CCODE_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_NODE, ValaCCodeNodeClass))
#define VALA_IS_CCODE_NODE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_NODE))
#define VALA_IS_CCODE_NODE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_NODE))
#define VALA_CCODE_NODE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_NODE, ValaCCodeNodeClass))

typedef struct _ValaCCodeNode ValaCCodeNode;
typedef struct _ValaCCodeNodeClass ValaCCodeNodeClass;
typedef struct _ValaCCodeNodePrivate ValaCCodeNodePrivate;

#define VALA_TYPE_CCODE_WRITER (vala_ccode_writer_get_type ())
#define VALA_CCODE_WRITER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_WRITER, ValaCCodeWriter))
#define VALA_CCODE_WRITER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_WRITER, ValaCCodeWriterClass))
#define VALA_IS_CCODE_WRITER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_WRITER))
#define VALA_IS_CCODE_WRITER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_WRITER))
#define VALA_CCODE_WRITER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_WRITER, ValaCCodeWriterClass))

typedef struct _ValaCCodeWriter ValaCCodeWriter;
typedef struct _ValaCCodeWriterClass ValaCCodeWriterClass;

#define VALA_TYPE_CCODE_STATEMENT (vala_ccode_statement_get_type ())
#define VALA_CCODE_STATEMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_STATEMENT, ValaCCodeStatement))
#define VALA_CCODE_STATEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_STATEMENT, ValaCCodeStatementClass))
#define VALA_IS_CCODE_STATEMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_STATEMENT))
#define VALA_IS_CCODE_STATEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_STATEMENT))
#define VALA_CCODE_STATEMENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_STATEMENT, ValaCCodeStatementClass))

typedef struct _ValaCCodeStatement ValaCCodeStatement;
typedef struct _ValaCCodeStatementClass ValaCCodeStatementClass;
typedef struct _ValaCCodeStatementPrivate ValaCCodeStatementPrivate;

#define VALA_TYPE_CCODE_IF_STATEMENT (vala_ccode_if_statement_get_type ())
#define VALA_CCODE_IF_STATEMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_IF_STATEMENT, ValaCCodeIfStatement))
#define VALA_CCODE_IF_STATEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_IF_STATEMENT, ValaCCodeIfStatementClass))
#define VALA_IS_CCODE_IF_STATEMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_IF_STATEMENT))
#define VALA_IS_CCODE_IF_STATEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_IF_STATEMENT))
#define VALA_CCODE_IF_STATEMENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_IF_STATEMENT, ValaCCodeIfStatementClass))

typedef struct _ValaCCodeIfStatement ValaCCodeIfStatement;
typedef struct _ValaCCodeIfStatementClass ValaCCodeIfStatementClass;
typedef struct _ValaCCodeIfStatementPrivate ValaCCodeIfStatementPrivate;

#define VALA_TYPE_CCODE_EXPRESSION (vala_ccode_expression_get_type ())
#define VALA_CCODE_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_EXPRESSION, ValaCCodeExpression))
#define VALA_CCODE_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_EXPRESSION, ValaCCodeExpressionClass))
#define VALA_IS_CCODE_EXPRESSION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_EXPRESSION))
#define VALA_IS_CCODE_EXPRESSION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_EXPRESSION))
#define VALA_CCODE_EXPRESSION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_EXPRESSION, ValaCCodeExpressionClass))

typedef struct _ValaCCodeExpression ValaCCodeExpression;
typedef struct _ValaCCodeExpressionClass ValaCCodeExpressionClass;
#define _vala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (vala_ccode_node_unref (var), NULL)))

#define VALA_TYPE_CCODE_LINE_DIRECTIVE (vala_ccode_line_directive_get_type ())
#define VALA_CCODE_LINE_DIRECTIVE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_LINE_DIRECTIVE, ValaCCodeLineDirective))
#define VALA_CCODE_LINE_DIRECTIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_LINE_DIRECTIVE, ValaCCodeLineDirectiveClass))
#define VALA_IS_CCODE_LINE_DIRECTIVE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_LINE_DIRECTIVE))
#define VALA_IS_CCODE_LINE_DIRECTIVE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_LINE_DIRECTIVE))
#define VALA_CCODE_LINE_DIRECTIVE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_LINE_DIRECTIVE, ValaCCodeLineDirectiveClass))

typedef struct _ValaCCodeLineDirective ValaCCodeLineDirective;
typedef struct _ValaCCodeLineDirectiveClass ValaCCodeLineDirectiveClass;

#define VALA_TYPE_CCODE_BLOCK (vala_ccode_block_get_type ())
#define VALA_CCODE_BLOCK(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), VALA_TYPE_CCODE_BLOCK, ValaCCodeBlock))
#define VALA_CCODE_BLOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), VALA_TYPE_CCODE_BLOCK, ValaCCodeBlockClass))
#define VALA_IS_CCODE_BLOCK(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), VALA_TYPE_CCODE_BLOCK))
#define VALA_IS_CCODE_BLOCK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), VALA_TYPE_CCODE_BLOCK))
#define VALA_CCODE_BLOCK_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), VALA_TYPE_CCODE_BLOCK, ValaCCodeBlockClass))

typedef struct _ValaCCodeBlock ValaCCodeBlock;
typedef struct _ValaCCodeBlockClass ValaCCodeBlockClass;

struct _ValaCCodeNode {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ValaCCodeNodePrivate * priv;
};

struct _ValaCCodeNodeClass {
	GTypeClass parent_class;
	void (*finalize) (ValaCCodeNode *self);
	void (*write) (ValaCCodeNode* self, ValaCCodeWriter* writer);
	void (*write_declaration) (ValaCCodeNode* self, ValaCCodeWriter* writer);
	void (*write_combined) (ValaCCodeNode* self, ValaCCodeWriter* writer);
};

struct _ValaCCodeStatement {
	ValaCCodeNode parent_instance;
	ValaCCodeStatementPrivate * priv;
};

struct _ValaCCodeStatementClass {
	ValaCCodeNodeClass parent_class;
};

struct _ValaCCodeIfStatement {
	ValaCCodeStatement parent_instance;
	ValaCCodeIfStatementPrivate * priv;
};

struct _ValaCCodeIfStatementClass {
	ValaCCodeStatementClass parent_class;
};

struct _ValaCCodeIfStatementPrivate {
	ValaCCodeExpression* _condition;
	ValaCCodeStatement* _true_statement;
	ValaCCodeStatement* _false_statement;
	gboolean _else_if;
};


static gpointer vala_ccode_if_statement_parent_class = NULL;

gpointer vala_ccode_node_ref (gpointer instance);
void vala_ccode_node_unref (gpointer instance);
GParamSpec* vala_param_spec_ccode_node (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_ccode_node (GValue* value, gpointer v_object);
void vala_value_take_ccode_node (GValue* value, gpointer v_object);
gpointer vala_value_get_ccode_node (const GValue* value);
GType vala_ccode_node_get_type (void) G_GNUC_CONST;
gpointer vala_ccode_writer_ref (gpointer instance);
void vala_ccode_writer_unref (gpointer instance);
GParamSpec* vala_param_spec_ccode_writer (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void vala_value_set_ccode_writer (GValue* value, gpointer v_object);
void vala_value_take_ccode_writer (GValue* value, gpointer v_object);
gpointer vala_value_get_ccode_writer (const GValue* value);
GType vala_ccode_writer_get_type (void) G_GNUC_CONST;
GType vala_ccode_statement_get_type (void) G_GNUC_CONST;
GType vala_ccode_if_statement_get_type (void) G_GNUC_CONST;
GType vala_ccode_expression_get_type (void) G_GNUC_CONST;
#define VALA_CCODE_IF_STATEMENT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VALA_TYPE_CCODE_IF_STATEMENT, ValaCCodeIfStatementPrivate))
enum  {
	VALA_CCODE_IF_STATEMENT_DUMMY_PROPERTY
};
ValaCCodeIfStatement* vala_ccode_if_statement_new (ValaCCodeExpression* cond, ValaCCodeStatement* true_stmt, ValaCCodeStatement* false_stmt);
ValaCCodeIfStatement* vala_ccode_if_statement_construct (GType object_type, ValaCCodeExpression* cond, ValaCCodeStatement* true_stmt, ValaCCodeStatement* false_stmt);
ValaCCodeStatement* vala_ccode_statement_construct (GType object_type);
void vala_ccode_if_statement_set_condition (ValaCCodeIfStatement* self, ValaCCodeExpression* value);
void vala_ccode_if_statement_set_true_statement (ValaCCodeIfStatement* self, ValaCCodeStatement* value);
void vala_ccode_if_statement_set_false_statement (ValaCCodeIfStatement* self, ValaCCodeStatement* value);
static void vala_ccode_if_statement_real_write (ValaCCodeNode* base, ValaCCodeWriter* writer);
gboolean vala_ccode_if_statement_get_else_if (ValaCCodeIfStatement* self);
GType vala_ccode_line_directive_get_type (void) G_GNUC_CONST;
void vala_ccode_writer_write_indent (ValaCCodeWriter* self, ValaCCodeLineDirective* line);
ValaCCodeLineDirective* vala_ccode_node_get_line (ValaCCodeNode* self);
void vala_ccode_writer_write_string (ValaCCodeWriter* self, const gchar* s);
ValaCCodeExpression* vala_ccode_if_statement_get_condition (ValaCCodeIfStatement* self);
void vala_ccode_node_write (ValaCCodeNode* self, ValaCCodeWriter* writer);
ValaCCodeStatement* vala_ccode_if_statement_get_false_statement (ValaCCodeIfStatement* self);
ValaCCodeStatement* vala_ccode_if_statement_get_true_statement (ValaCCodeIfStatement* self);
GType vala_ccode_block_get_type (void) G_GNUC_CONST;
void vala_ccode_block_set_suppress_newline (ValaCCodeBlock* self, gboolean value);
gboolean vala_ccode_writer_get_bol (ValaCCodeWriter* self);
void vala_ccode_if_statement_set_else_if (ValaCCodeIfStatement* self, gboolean value);
static void vala_ccode_if_statement_finalize (ValaCCodeNode* obj);


ValaCCodeIfStatement* vala_ccode_if_statement_construct (GType object_type, ValaCCodeExpression* cond, ValaCCodeStatement* true_stmt, ValaCCodeStatement* false_stmt) {
	ValaCCodeIfStatement* self = NULL;
	ValaCCodeExpression* _tmp0_ = NULL;
	ValaCCodeStatement* _tmp1_ = NULL;
	ValaCCodeStatement* _tmp2_ = NULL;
	g_return_val_if_fail (cond != NULL, NULL);
	g_return_val_if_fail (true_stmt != NULL, NULL);
	self = (ValaCCodeIfStatement*) vala_ccode_statement_construct (object_type);
	_tmp0_ = cond;
	vala_ccode_if_statement_set_condition (self, _tmp0_);
	_tmp1_ = true_stmt;
	vala_ccode_if_statement_set_true_statement (self, _tmp1_);
	_tmp2_ = false_stmt;
	vala_ccode_if_statement_set_false_statement (self, _tmp2_);
	return self;
}


ValaCCodeIfStatement* vala_ccode_if_statement_new (ValaCCodeExpression* cond, ValaCCodeStatement* true_stmt, ValaCCodeStatement* false_stmt) {
	return vala_ccode_if_statement_construct (VALA_TYPE_CCODE_IF_STATEMENT, cond, true_stmt, false_stmt);
}


static gpointer _vala_ccode_node_ref0 (gpointer self) {
	return self ? vala_ccode_node_ref (self) : NULL;
}


static void vala_ccode_if_statement_real_write (ValaCCodeNode* base, ValaCCodeWriter* writer) {
	ValaCCodeIfStatement * self;
	gboolean _tmp0_ = FALSE;
	ValaCCodeWriter* _tmp5_ = NULL;
	ValaCCodeExpression* _tmp6_ = NULL;
	ValaCCodeWriter* _tmp9_ = NULL;
	gboolean _tmp10_ = FALSE;
	ValaCCodeStatement* _tmp11_ = NULL;
	gboolean _tmp13_ = FALSE;
	ValaCCodeStatement* _tmp17_ = NULL;
	ValaCCodeWriter* _tmp18_ = NULL;
	ValaCCodeStatement* _tmp19_ = NULL;
	self = (ValaCCodeIfStatement*) base;
	g_return_if_fail (writer != NULL);
	_tmp0_ = self->priv->_else_if;
	if (!_tmp0_) {
		ValaCCodeWriter* _tmp1_ = NULL;
		ValaCCodeLineDirective* _tmp2_ = NULL;
		ValaCCodeLineDirective* _tmp3_ = NULL;
		_tmp1_ = writer;
		_tmp2_ = vala_ccode_node_get_line ((ValaCCodeNode*) self);
		_tmp3_ = _tmp2_;
		vala_ccode_writer_write_indent (_tmp1_, _tmp3_);
	} else {
		ValaCCodeWriter* _tmp4_ = NULL;
		_tmp4_ = writer;
		vala_ccode_writer_write_string (_tmp4_, " ");
	}
	_tmp5_ = writer;
	vala_ccode_writer_write_string (_tmp5_, "if (");
	_tmp6_ = self->priv->_condition;
	if (_tmp6_ != NULL) {
		ValaCCodeExpression* _tmp7_ = NULL;
		ValaCCodeWriter* _tmp8_ = NULL;
		_tmp7_ = self->priv->_condition;
		_tmp8_ = writer;
		vala_ccode_node_write ((ValaCCodeNode*) _tmp7_, _tmp8_);
	}
	_tmp9_ = writer;
	vala_ccode_writer_write_string (_tmp9_, ")");
	_tmp11_ = self->priv->_false_statement;
	if (_tmp11_ != NULL) {
		ValaCCodeStatement* _tmp12_ = NULL;
		_tmp12_ = self->priv->_true_statement;
		_tmp10_ = G_TYPE_CHECK_INSTANCE_TYPE (_tmp12_, VALA_TYPE_CCODE_BLOCK);
	} else {
		_tmp10_ = FALSE;
	}
	_tmp13_ = _tmp10_;
	if (_tmp13_) {
		ValaCCodeBlock* cblock = NULL;
		ValaCCodeStatement* _tmp14_ = NULL;
		ValaCCodeBlock* _tmp15_ = NULL;
		ValaCCodeBlock* _tmp16_ = NULL;
		_tmp14_ = self->priv->_true_statement;
		_tmp15_ = _vala_ccode_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp14_, VALA_TYPE_CCODE_BLOCK, ValaCCodeBlock));
		cblock = _tmp15_;
		_tmp16_ = cblock;
		vala_ccode_block_set_suppress_newline (_tmp16_, TRUE);
		_vala_ccode_node_unref0 (cblock);
	}
	_tmp17_ = self->priv->_true_statement;
	_tmp18_ = writer;
	vala_ccode_node_write ((ValaCCodeNode*) _tmp17_, _tmp18_);
	_tmp19_ = self->priv->_false_statement;
	if (_tmp19_ != NULL) {
		ValaCCodeWriter* _tmp20_ = NULL;
		gboolean _tmp21_ = FALSE;
		gboolean _tmp22_ = FALSE;
		ValaCCodeStatement* _tmp26_ = NULL;
		ValaCCodeStatement* _tmp30_ = NULL;
		ValaCCodeWriter* _tmp31_ = NULL;
		_tmp20_ = writer;
		_tmp21_ = vala_ccode_writer_get_bol (_tmp20_);
		_tmp22_ = _tmp21_;
		if (_tmp22_) {
			ValaCCodeWriter* _tmp23_ = NULL;
			ValaCCodeWriter* _tmp24_ = NULL;
			_tmp23_ = writer;
			vala_ccode_writer_write_indent (_tmp23_, NULL);
			_tmp24_ = writer;
			vala_ccode_writer_write_string (_tmp24_, "else");
		} else {
			ValaCCodeWriter* _tmp25_ = NULL;
			_tmp25_ = writer;
			vala_ccode_writer_write_string (_tmp25_, " else");
		}
		_tmp26_ = self->priv->_false_statement;
		if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp26_, VALA_TYPE_CCODE_IF_STATEMENT)) {
			ValaCCodeIfStatement* cif = NULL;
			ValaCCodeStatement* _tmp27_ = NULL;
			ValaCCodeIfStatement* _tmp28_ = NULL;
			ValaCCodeIfStatement* _tmp29_ = NULL;
			_tmp27_ = self->priv->_false_statement;
			_tmp28_ = _vala_ccode_node_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp27_, VALA_TYPE_CCODE_IF_STATEMENT, ValaCCodeIfStatement));
			cif = _tmp28_;
			_tmp29_ = cif;
			vala_ccode_if_statement_set_else_if (_tmp29_, TRUE);
			_vala_ccode_node_unref0 (cif);
		}
		_tmp30_ = self->priv->_false_statement;
		_tmp31_ = writer;
		vala_ccode_node_write ((ValaCCodeNode*) _tmp30_, _tmp31_);
	}
}


ValaCCodeExpression* vala_ccode_if_statement_get_condition (ValaCCodeIfStatement* self) {
	ValaCCodeExpression* result;
	ValaCCodeExpression* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_condition;
	result = _tmp0_;
	return result;
}


void vala_ccode_if_statement_set_condition (ValaCCodeIfStatement* self, ValaCCodeExpression* value) {
	ValaCCodeExpression* _tmp0_ = NULL;
	ValaCCodeExpression* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_ccode_node_ref0 (_tmp0_);
	_vala_ccode_node_unref0 (self->priv->_condition);
	self->priv->_condition = _tmp1_;
}


ValaCCodeStatement* vala_ccode_if_statement_get_true_statement (ValaCCodeIfStatement* self) {
	ValaCCodeStatement* result;
	ValaCCodeStatement* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_true_statement;
	result = _tmp0_;
	return result;
}


void vala_ccode_if_statement_set_true_statement (ValaCCodeIfStatement* self, ValaCCodeStatement* value) {
	ValaCCodeStatement* _tmp0_ = NULL;
	ValaCCodeStatement* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_ccode_node_ref0 (_tmp0_);
	_vala_ccode_node_unref0 (self->priv->_true_statement);
	self->priv->_true_statement = _tmp1_;
}


ValaCCodeStatement* vala_ccode_if_statement_get_false_statement (ValaCCodeIfStatement* self) {
	ValaCCodeStatement* result;
	ValaCCodeStatement* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_false_statement;
	result = _tmp0_;
	return result;
}


void vala_ccode_if_statement_set_false_statement (ValaCCodeIfStatement* self, ValaCCodeStatement* value) {
	ValaCCodeStatement* _tmp0_ = NULL;
	ValaCCodeStatement* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _vala_ccode_node_ref0 (_tmp0_);
	_vala_ccode_node_unref0 (self->priv->_false_statement);
	self->priv->_false_statement = _tmp1_;
}


gboolean vala_ccode_if_statement_get_else_if (ValaCCodeIfStatement* self) {
	gboolean result;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_else_if;
	result = _tmp0_;
	return result;
}


void vala_ccode_if_statement_set_else_if (ValaCCodeIfStatement* self, gboolean value) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_else_if = _tmp0_;
}


static void vala_ccode_if_statement_class_init (ValaCCodeIfStatementClass * klass) {
	vala_ccode_if_statement_parent_class = g_type_class_peek_parent (klass);
	VALA_CCODE_NODE_CLASS (klass)->finalize = vala_ccode_if_statement_finalize;
	g_type_class_add_private (klass, sizeof (ValaCCodeIfStatementPrivate));
	VALA_CCODE_NODE_CLASS (klass)->write = vala_ccode_if_statement_real_write;
}


static void vala_ccode_if_statement_instance_init (ValaCCodeIfStatement * self) {
	self->priv = VALA_CCODE_IF_STATEMENT_GET_PRIVATE (self);
}


static void vala_ccode_if_statement_finalize (ValaCCodeNode* obj) {
	ValaCCodeIfStatement * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, VALA_TYPE_CCODE_IF_STATEMENT, ValaCCodeIfStatement);
	_vala_ccode_node_unref0 (self->priv->_condition);
	_vala_ccode_node_unref0 (self->priv->_true_statement);
	_vala_ccode_node_unref0 (self->priv->_false_statement);
	VALA_CCODE_NODE_CLASS (vala_ccode_if_statement_parent_class)->finalize (obj);
}


/**
 * Represents an if selection statement in the C code.
 */
GType vala_ccode_if_statement_get_type (void) {
	static volatile gsize vala_ccode_if_statement_type_id__volatile = 0;
	if (g_once_init_enter (&vala_ccode_if_statement_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ValaCCodeIfStatementClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) vala_ccode_if_statement_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaCCodeIfStatement), 0, (GInstanceInitFunc) vala_ccode_if_statement_instance_init, NULL };
		GType vala_ccode_if_statement_type_id;
		vala_ccode_if_statement_type_id = g_type_register_static (VALA_TYPE_CCODE_STATEMENT, "ValaCCodeIfStatement", &g_define_type_info, 0);
		g_once_init_leave (&vala_ccode_if_statement_type_id__volatile, vala_ccode_if_statement_type_id);
	}
	return vala_ccode_if_statement_type_id__volatile;
}



