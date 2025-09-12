//
// Created by will on 9/10/25.
//

#include "Interval.h"

#include <iostream>
#include <ostream>

/*
 * Constructors
 */
Interval::Interval(double min, double max): _min(min), _max(max) {
    if (_min > _max) {
        std::cerr << "Invalid interval min: " << _min << " max: " << _max << std::endl;
        exit(1);
    }
}
Interval::~Interval() = default;

/*
 * Accessors
 */
double Interval::min() const {
    return _min;
}
double Interval::max() const {
    return _max;
}

/*
 * Helpers
 */
std::string Interval::to_string() const {
    return std::to_string(_min) + " " + std::to_string(_max);
}

/*
 * Predicates
 */
bool Interval::contains(double value) const {
    return value >= _min && value <= _max;
}

