#include "Triangle.h"

// Constructor
Triangle::Triangle(size_t b, char ch = '*', const string name = "Triangle") : Shape (name, ch), base {b} {};

// Virtual Methods:

// 12. Width Calculation (get_width()) Computes and returns the length of the horizontal
// attribute of the shape.
size_t Triangle::get_width() const {
    return base;
};