#include <iostream>

#include "ast/interval/IntervalNode.h"

int main() {
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

    auto interval = IntervalNode(0, 2);
    std::cout << "Min: " << interval.min() << " Max: " << interval.max() << std::endl;
    return 0;
}
