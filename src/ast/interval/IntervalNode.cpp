//
// Created by will on 9/10/25.
//

#include "IntervalNode.h"

#include <iostream>
#include <ostream>

/*
 * Constructors
 */
IntervalNode::IntervalNode(double min, double max): _min(min), _max(max) {
    if (_min > _max) {
        std::cerr << "Invalid interval min: " << _min << " max: " << _max << std::endl;
        exit(1);
    }
}
IntervalNode::~IntervalNode() = default;

/*
 * Accessors
 */
double IntervalNode::min() const {
    return _min;
}
double IntervalNode::max() const {
    return _max;
}