//
// Created by will on 9/10/25.
//

#ifndef INTERVALIAN_ASTNODE_H
#define INTERVALIAN_ASTNODE_H

#include "../visitor/AstVisitor.h"
#include "../interval/Interval.h"

class AstNode {
public:
    /*
     * Constructors
     */
    explicit AstNode(Interval _value);
    virtual ~AstNode();

    Interval value();
    /**
     * @brief Accept a visitor, guiding it through the subtree.
     */
    virtual void accept(AstVisitor *visitor) = 0;

protected:
    Interval _value;

// Visitors have access to internal value field.
friend class EvaluationVisitor;
};


#endif //INTERVALIAN_ASTNODE_H