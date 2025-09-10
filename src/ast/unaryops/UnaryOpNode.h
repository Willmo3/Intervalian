//
// Created by will on 9/10/25.
//

#ifndef INTERVALIAN_UNARYOPNODE_H
#define INTERVALIAN_UNARYOPNODE_H
#include "../AstNode.h"

class UnaryOpNode: public AstNode {
public:
    enum UnaryOpType {
        POW,
        TANH,
    };

    /*
     * Constructors
     */
    UnaryOpNode(UnaryOpType op, AstNode *child);
    ~UnaryOpNode() override;
    /*
     * Accessors
     */
    UnaryOpType optype() const;
    /*
     * Traversers
     */
    void accept(AstVisitor *visitor) override;
private:
    UnaryOpType _op;
    AstNode *_child;

// Visitors will have access to value so that they may change it.
friend class EvaluationVisitor;
};

#endif //INTERVALIAN_UNARYOPNODE_H