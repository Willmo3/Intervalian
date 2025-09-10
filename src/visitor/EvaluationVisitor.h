//
// Created by will on 9/10/25.
//

#ifndef INTERVALIAN_EVALUATIONVISITOR_H
#define INTERVALIAN_EVALUATIONVISITOR_H
#include "AstVisitor.h"

class EvaluationVisitor: public AstVisitor {
public:
    /*
     * Constructors
     */
    EvaluationVisitor();
    ~EvaluationVisitor() override;

    /*
     * Visit functions
     */
    void visit(AstNode* node) override;
    void visit(UnaryOpNode* node) override;
    void visit(BinaryOpNode* node) override;
};


#endif //INTERVALIAN_EVALUATIONVISITOR_H