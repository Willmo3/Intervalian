//
// Created by will on 9/10/25.
//

#include "PowNode.h"

/*
 * Constructors
 */
PowNode::PowNode(AstNode *child, uint32_t pow): UnaryOpNode(POW, child), _pow(pow) {}
PowNode::~PowNode() = default;

/*
 * Accessors
 */
uint32_t PowNode::pow() const {
    return _pow;
}