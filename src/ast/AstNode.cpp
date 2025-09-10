//
// Created by will on 9/10/25.
//

#include "AstNode.h"

/*
 * Constructors
 */
AstNode::AstNode(Interval value): _value(value) {}
AstNode::~AstNode() = default;

/*
 * Accessors
 */
Interval AstNode::value() {
    return _value;
}