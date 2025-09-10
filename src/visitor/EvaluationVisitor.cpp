//
// Created by will on 9/10/25.
//

#include "EvaluationVisitor.h"

#include <iostream>
#include <ostream>

#include "../ast/binaryops/BinaryOpNode.h"
#include "../ast/unaryops/UnaryOpNode.h"

/*
 * Constructors
 */
EvaluationVisitor::EvaluationVisitor() = default;
EvaluationVisitor::~EvaluationVisitor() = default;

/*
 * Visit functions
 */
void EvaluationVisitor::visit(BinaryOpNode *node) {
    switch (node->optype()) {
        case BinaryOpNode::ADD: {
            node->_value =
                Interval(node->_left->value().min() + node->_right->value().min(),
                    node->_left->value().max() + node->_right->value().max());
            break;
        }
        default: {
            std::cerr << "Not yet implemented." << std::endl;
            break;
        }
    }
}

void EvaluationVisitor::visit(UnaryOpNode *node) {
    switch (node->optype()) {
        default: {
            std::cerr << "Not yet implemented." << std::endl;
            break;
        }
    }
}

void EvaluationVisitor::visit(AstNode* node) {
    // If this function is invoked, we've visited a leaf node -- no op.
}
