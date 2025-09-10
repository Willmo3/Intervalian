//
// Created by will on 9/10/25.
//

#include "BinaryOpNode.h"

/*
 * Constructors
 */
BinaryOpNode::BinaryOpNode(BinaryOpType op, AstNode *left, AstNode *right): AstNode(Interval(0, 0)), _op(op), _left(left), _right(right) {}
BinaryOpNode::~BinaryOpNode() = default;

/*
 * Accessors
 */
BinaryOpNode::BinaryOpType BinaryOpNode::optype() const {
    return _op;
}

/*
 * Traversers
 */
void BinaryOpNode::accept(AstVisitor *visitor) {
    _left->accept(visitor);
    _right->accept(visitor);
    visitor->visit(this);
}
