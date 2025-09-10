//
// Created by will on 9/10/25.
//

#ifndef INTERVALIAN_INTERVALNODE_H
#define INTERVALIAN_INTERVALNODE_H

class IntervalNode {
public:
    /*
     * Constructors
     */
    IntervalNode(double min, double max);
    ~IntervalNode();

    /*
     * Accessors
     */
    double min() const;
    double max() const;

private:
    double _min;
    double _max;
};

#endif //INTERVALIAN_INTERVALNODE_H