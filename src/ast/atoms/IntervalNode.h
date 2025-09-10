//
// Created by will on 9/10/25.
//

#ifndef INTERVALIAN_INTERVALNODE_H
#define INTERVALIAN_INTERVALNODE_H

#include "../AstNode.h"
#include "../../interval/Interval.h"

class IntervalNode final: public AstNode {
public:
    /*
     * Constructors
     */
    explicit IntervalNode(Interval i);
    ~IntervalNode() override;
    /*
     * Traversers
     */
    void accept(AstVisitor *visitor) override;
};


#endif //INTERVALIAN_INTERVALNODE_H