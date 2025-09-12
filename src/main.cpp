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

void test_tanh() {
    auto visitor = EvaluationVisitor();

    auto base = IntervalNode(Interval(-1, 4));
    auto tanh = UnaryOpNode(UnaryOpNode::TANH, &base);

    tanh.accept(&visitor);
    std::cout << tanh.value().to_string() << std::endl;
}

int main() {
    auto visitor = EvaluationVisitor();

    test_div();
    return 0;
}
