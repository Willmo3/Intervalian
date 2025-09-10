//
// Created by will on 9/10/25.
//

#ifndef INTERVALIAN_POWNODE_H
#define INTERVALIAN_POWNODE_H
#include <cstdint>

#include "UnaryOpNode.h"


class PowNode: public UnaryOpNode {
public:
    /*
     * Constructors
     */
    PowNode(AstNode *child, uint32_t pow);
    ~PowNode() override;

    /*
     * Accessors
     */
    uint32_t pow() const;
private:
    uint32_t _pow;
};


#endif //INTERVALIAN_POWNODE_H