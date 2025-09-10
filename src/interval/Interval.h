//
// Created by will on 9/10/25.
//

#ifndef INTERVALIAN_INTERVAL_H
#define INTERVALIAN_INTERVAL_H
#include <string>

class Interval {
public:
    /*
     * Constructors
     */
    Interval(double min, double max);
    ~Interval();
    /*
     * Accessors
     */
    double min() const;
    double max() const;

    std::string to_string() const;

private:
    double _min;
    double _max;
};

#endif //INTERVALIAN_INTERVAL_H