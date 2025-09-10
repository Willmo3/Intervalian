//
// Created by will on 9/10/25.
//

#include "UnaryOpNode.h"

/*
 * Constructors
 */
UnaryOpNode::UnaryOpNode(UnaryOpType op, AstNode *child) : AstNode(Interval(0, 0)), _op(op), _child(child) {}
UnaryOpNode::~UnaryOpNode() = default;

/*
 * Accessors
 */
UnaryOpNode::UnaryOpType UnaryOpNode::optype() const { return _op; }

/*
 * Traversers
 */
void UnaryOpNode::accept(AstVisitor *visitor) {
    _child->accept(visitor);
    visitor->visit(this);
}