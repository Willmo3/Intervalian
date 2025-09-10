//
// Created by will on 9/10/25.
//

#ifndef INTERVALIAN_BINARYOPNODE_H
#define INTERVALIAN_BINARYOPNODE_H
#include "../AstNode.h"

class BinaryOpNode: public AstNode {
public:
    enum BinaryOpType {
        ADD = 0,
        SUB,
        MULT,
        DIV,
    };

    /*
     * Constructors
     */
    BinaryOpNode(BinaryOpType op, AstNode *left, AstNode *right);
    ~BinaryOpNode() override;
    /*
     * Accessors
     */
    BinaryOpType optype() const;
    /*
     * Traversers
     */
    void accept(AstVisitor *visitor) override;

private:
    BinaryOpType _op;
    AstNode *_left;
    AstNode *_right;

// Visitors may need access to subtree values.
friend class EvaluationVisitor;
};


#endif //INTERVALIAN_BINARYOPNODE_H