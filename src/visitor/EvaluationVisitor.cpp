//
// Created by will on 9/10/25.
//

#include "EvaluationVisitor.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <ostream>

#include "../ast/binaryops/BinaryOpNode.h"
#include "../ast/unaryops/UnaryOpNode.h"
#include "../ast/unaryops/PowNode.h"

/*
 * Atomic computations
 */
double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double divide (double a, double b) {
    if (b == 0) {
        return 0;
    }
    return a / b;
}

/*
 * Compound computations.
 */
/**
 * Take the power of an interval by repeatedly multiplying it by other intervals.
 *
 * @param base Interval to exponentiate.
 * @param exp Power to raise the interval to.
 * @return A new interval, multiplied by itself n times.
 */
Interval pow(Interval base, uint32_t exp) {
    Interval accumulator = base;
    for (auto i = 0; i < exp; i++) {
        double values[4];
        values[0] = accumulator.min() * base.min();
        values[1] = accumulator.min() * base.max();
        values[2] = accumulator.max() * base.min();
        values[3] = accumulator.max() * base.max();

        double min = *std::ranges::min_element(values, values + 4);
        double max = *std::ranges::max_element(values, values + 4);

        accumulator = Interval(min, max);
    }
    return accumulator;
}

/*
 * Constructors
 */
EvaluationVisitor::EvaluationVisitor() = default;
EvaluationVisitor::~EvaluationVisitor() = default;

/*
 * Visit functions
 */

// Binary visitors
void EvaluationVisitor::visit(BinaryOpNode *node) {
    std::function<double(double, double)> operation = nullptr;

    switch (node->optype()) {
        case BinaryOpNode::ADD: operation = add; break;
        case BinaryOpNode::SUB: operation = sub; break;
        case BinaryOpNode::MULT: operation = mul; break;
        case BinaryOpNode::DIV: operation = divide; break;
        default: {
            std::cerr << "Not yet implemented." << std::endl;
            break;
        }
    }

    // Test all combinations of values to find min, max.
    double values[4];
    values[0] = operation(node->_left->value().min(), node->_right->value().min());
    values[1] = operation(node->_left->value().max(), node->_right->value().min());
    values[2] = operation(node->_left->value().min(), node->_right->value().max());
    values[3] = operation(node->_left->value().max(), node->_right->value().max());

    double min = *std::ranges::min_element(values, values + 4);
    double max = *std::ranges::max_element(values, values + 4);

    node->_value = Interval(min, max);
}

void EvaluationVisitor::visit(UnaryOpNode *node) {
    switch (node->optype()) {
        case UnaryOpNode::POW: {
            node->_value = pow(node->_child->value(), dynamic_cast<PowNode *>(node)->pow());
            break;
        }
        default: {
            std::cerr << "Not yet implemented." << std::endl;
            break;
        }
    }
}

void EvaluationVisitor::visit(AstNode* node) {
    // If this function is invoked, we've visited a leaf node -- no op.
}
