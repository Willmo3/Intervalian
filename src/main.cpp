#include <iostream>

#include "ast/atoms/IntervalNode.h"
#include "ast/binaryops/BinaryOpNode.h"
#include "ast/unaryops/PowNode.h"
#include "ast/unaryops/UnaryOpNode.h"
#include "interval/Interval.h"
#include "visitor/EvaluationVisitor.h"

void test_add() {
    auto visitor = EvaluationVisitor();

    auto left = IntervalNode(Interval(0, 2));
    auto right = IntervalNode(Interval(1, 2));
    auto add = BinaryOpNode(BinaryOpNode::ADD, &left, &right);

    add.accept(&visitor);
    std::cout << add.value().to_string() << std::endl;
}

void test_sub() {
    auto visitor = EvaluationVisitor();

    auto left = IntervalNode(Interval(0, 2));
    auto right = IntervalNode(Interval(-1, 2));
    auto sub = BinaryOpNode(BinaryOpNode::SUB, &left, &right);

    sub.accept(&visitor);
    std::cout << sub.value().to_string() << std::endl;
}

void test_mul() {
    auto visitor = EvaluationVisitor();

    auto left = IntervalNode(Interval(0, 2));
    auto right = IntervalNode(Interval(-2, 1));
    auto mul = BinaryOpNode(BinaryOpNode::MULT, &left, &right);

    mul.accept(&visitor);
    std::cout << mul.value().to_string() << std::endl;
}

void test_div() {
    auto visitor = EvaluationVisitor();

    auto left = IntervalNode(Interval(0, 2));
    auto right = IntervalNode(Interval(-2, 1));
    auto div = BinaryOpNode(BinaryOpNode::DIV, &left, &right);

    div.accept(&visitor);
    std::cout << div.value().to_string() << std::endl;
}

void test_pow() {
    auto visitor = EvaluationVisitor();

    auto base = IntervalNode(Interval(-1, 4));
    auto exp = PowNode(&base, 4);

    exp.accept(&visitor);
    // Expect: -256, 1024
    std::cout << exp.value().to_string() << std::endl;
}

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

    test_pow();
    return 0;
}
