#include "Rhombus.h"

// Constructor taking 1 parameter
Rhombus::Rhombus(size_t b, char ch, const string name) : Shape{name, ch}, base{b} {
    // If the base is even, increment by one to make it odd.
    if (base % 2 == 0) {
        ++base;
    }
};

// ------------------------------------------------------------------------------------
// Virtual Methods:
// ------------------------------------------------------------------------------------
// 6. Geometric Area Calculation (areaGeo()): Computes and returns the shape’s geometric
// area.
double Rhombus::areaGeo() const {
    return ( ((double)base)*((double)base) / 2.0);
};

// 7. Geometric Perimeter Calculation (perimeterGeo()): Computes and returns the shape’s
// geometric perimeter.
double Rhombus::perimeterGeo() const {
    return (2.0 * sqrt(2.0)) * (double)base;
};

// 8. Textual Area Calculation (areaTxt()): Determines the number of characters forming the
// textual image of the shape.
int Rhombus::areaTxt() const {
    int n = floor(base/2);
    return 2 * n * ( n + 1) + 1;
};

// 9. Textual Perimeter Calculation (perimeterTxt()): Counts the characters on the borders
// of the textual image of the shape.
int Rhombus::perimeterTxt() const {
    int result {};
    if (base == 1) result = 1;
    else if (base > 1) result = 2 * (base - 1);
    return result;
};

// 10. Drawing on Canvas (draw()): A member function that renders a textual image of the
// shape on a Canvas object using the shape’s pen character.
// The idea is to start with a lower limit and upper limit.
// On each row, the limits increment, allowing the construction of the upper pyramid.
// When the lower limit is less than 0, it changes the logic to draw an inverse pyramid.
Canvas Rhombus::draw() const {
    // Create canvas with the size
    Canvas result {get_height(), get_width()};

    // Populate Rhombus shape
    int lower_limit {(int)base / 2}, upper_limit {(int)base / 2};
    bool toReduce {false};

    // First we draw the pyramid. Then when lower limit < 0, we change the logic 
    // to print an inverse pyramid
    for (int row {}; row < result.getRows(); ++row) {
        for (int col {}; col < result.getColumns(); ++col) {
            if (col >= lower_limit && col <= upper_limit) {
                result.put(row, col, getPen());
            }
        }
        if (lower_limit < 0 || upper_limit == (base - 1) || toReduce) {
            ++lower_limit;
            --upper_limit;
            toReduce = true;
        } else {
            --lower_limit;
            ++upper_limit;
        }
    }

    // Return canvas
    return result;
};

// 11. Height Calculation (get_height()) Computes and returns the length of the vertical
// attribute of the shape.
size_t Rhombus::get_height() const {
    return base;
};

// 12. Width Calculation (get_width()) Computes and returns the length of the horizontal
// attribute of the shape.
size_t Rhombus::get_width() const {
    return base;
};