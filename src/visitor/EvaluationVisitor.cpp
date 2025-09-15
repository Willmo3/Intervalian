//
// Created by will on 9/10/25.
//

#include "EvaluationVisitor.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <ostream>

#include "../ast/binaryops/BinaryOpNode.h"
#include "../ast/unaryops/UnaryOpNode.h"
#include "../ast/unaryops/PowNode.h"

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
    double min, max;
    const auto a = node->_left->value();
    const auto b = node->_right->value();

    switch (node->optype()) {
        case BinaryOpNode::ADD: {
            min = a.min() + b.min();
            max = a.max() + b.max();
            break;
        }
        case BinaryOpNode::SUB: {
            min = a.min() - b.max();
            max = a.max() - b.min();
            break;
        }
        case BinaryOpNode::MULT: {
            double values[4];
            values[0] = a.min() * b.min();
            values[1] = a.max() * b.min();
            values[2] = a.min() * b.max();
            values[3] = a.max() * b.max();

            min = *std::ranges::min_element(values, values + 4);
            max = *std::ranges::max_element(values, values + 4);
            break;
        }
        case BinaryOpNode::DIV: {
            std::vector<double> candidate_values;

            // Edge case: [0,0] defines only the value 0 -- not one infinitesimal more.
            // We return the interval 0, 0 in this case.
            if (b.min() == b.max() && b.min() == 0) {
                min = 0;
                max = 0;
                break;
            }

            // First, check if 0 in interval.
            if (b.max() == 0) {
                // if max = 0, approaching from left -- negative infinitesimal
                // negative / -inf = inf
                if (a.min() < 0) {
                    candidate_values.push_back(INFINITY);
                }
                // positive / -inf = -inf
                if (a.max() > 0) {
                    candidate_values.push_back(-INFINITY);
                }
            } else if (b.contains(0)) {
                // negative / inf = -inf
                if (a.min() < 0) {
                    candidate_values.push_back(-INFINITY);
                }
                // positive / inf = inf
                if (a.max() > 0) {
                    candidate_values.push_back(INFINITY);
                }
            }

            // We now add the boundaries of a / the boundaries of b to the interval, as with multiplication.
            // Skip zero boundaries, as we will have already covered this.
            if (b.min() != 0) {
                candidate_values.push_back(a.min() / b.min());
                candidate_values.push_back(a.max() / b.min());
            } else if (b.max() != 0) {
                candidate_values.push_back(a.min() / b.max());
                candidate_values.push_back(a.max() / b.max());
            }

            min = *std::ranges::min_element(candidate_values);
            max = *std::ranges::max_element(candidate_values);
            break;
        }
        default: {
            std::cerr << "Not yet implemented." << std::endl;
            exit(1);
        }
    }
    node->_value = Interval(min, max);
}

void EvaluationVisitor::visit(UnaryOpNode *node) {
    switch (node->optype()) {
        case UnaryOpNode::POW: {
            node->_value = pow(node->_child->value(), dynamic_cast<PowNode *>(node)->pow());
            break;
        }
        case UnaryOpNode::TANH: {
            // NOTE: tanh is monotonic, so can simply apply to left, right.
            node->_value = Interval(tanh(node->_child->value().min()), tanh(node->_child->value().max()));
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
