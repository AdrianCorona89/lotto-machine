#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

/**
 * @class Triangle
 * @brief Abstract base class representing a geometric triangle.
 */
class Triangle : public Shape {
    protected:
    size_t base; // Length of the base

    public:
    // Constructor
    Triangle(size_t b, char ch, const string name);

    // 12. Width Calculation (get_width()) Computes and returns the length of the horizontal
    // attribute of the shape.
    virtual size_t get_width() const override;
};

#endif