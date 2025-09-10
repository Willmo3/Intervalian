#include <iostream>

#include "ast/atoms/IntervalNode.h"
#include "ast/binaryops/BinaryOpNode.h"
#include "interval/Interval.h"
#include "visitor/EvaluationVisitor.h"

int main() {
    auto visitor = EvaluationVisitor();
    // TODO: ast
    // -- binary, unary, atoms
    // -- only atom type: interval
    //      -- simpler to implement -- may not need atom abstract class.
    // -- standard binary operations
    //      -- Key concern: specialize for intervals. Implement addition first.
    // -- Unary ops
    //      -- What does tanh look like for an interval?
    //          -- Insight: if the upper bound is now lower, it must be made lower.
    // -- Power: dangerous.
    //      -- TODO: edge cases in exponentiating intervals.

    // TODO: execution
    // -- For now, simple approach -- test cases in main.
    //      -- Can rely on prior knowledge to implement test suite for larger projects.

    auto left = IntervalNode(Interval(0, 2));
    auto right = IntervalNode(Interval(1, 2));
    auto add = BinaryOpNode(BinaryOpNode::ADD, &left, &right);

    add.accept(&visitor);

    std::cout << add.value().to_string() << std::endl;
    return 0;
}
