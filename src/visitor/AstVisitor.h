//
// Created by will on 9/10/25.
//

#ifndef INTERVALIAN_ASTVISITOR_H
#define INTERVALIAN_ASTVISITOR_H

// Forward definitions used to avoid circular imports.
class AstNode;
class UnaryOpNode;
class BinaryOpNode;

class AstVisitor {
public:
    virtual ~AstVisitor() = default;

    virtual void visit(AstNode *node) = 0;
    virtual void visit(BinaryOpNode *node) = 0;
    virtual void visit(UnaryOpNode *node) = 0;
};

#endif //INTERVALIAN_ASTVISITOR_H