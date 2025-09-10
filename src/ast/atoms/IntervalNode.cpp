//
// Created by will on 9/10/25.
//

#include "IntervalNode.h"

/*
 * Constructors
 */
IntervalNode::IntervalNode(Interval i): AstNode(i) {}
IntervalNode::~IntervalNode() = default;

/*
 * Traversers
 */
void IntervalNode::accept(AstVisitor *visitor) {
    // No children for interval root.
    visitor->visit(this);
}
