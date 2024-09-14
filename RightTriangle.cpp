#include "RightTriangle.h"

// Parameterized Constructor
RightTriangle::RightTriangle(size_t base, char ch, const string name) : Triangle(base, ch, name) {
    // If base is even, then increment by one.
    if (base == 0) {
        base = 1;
    }
}

// ------------------------------------------------------------------------------------
// Virtual Methods:
// ------------------------------------------------------------------------------------
// 6. Geometric Area Calculation (areaGeo()): Computes and returns the shape’s geometric
// area.
double RightTriangle::areaGeo() const {
    return ((double)base * (double)get_height()) / 2.0;
};

// 7. Geometric Perimeter Calculation (perimeterGeo()): Computes and returns the shape’s
// geometric perimeter.
double RightTriangle::perimeterGeo() const {
    return (2.0 + sqrt(2.0)) * get_height();
};

// 8. Textual Area Calculation (areaTxt()): Determines the number of characters forming the
// textual image of the shape.
int RightTriangle::areaTxt() const {
    double height {(double)get_height()};
    return height * (height + 1) / 2.0;
};

// 9. Textual Perimeter Calculation (perimeterTxt()): Counts the characters on the borders
// of the textual image of the shape.
int RightTriangle::perimeterTxt() const {
    if (get_height() > 1 && get_width() > 1) return 3 * ((double)get_height() -1);
    else return 1;
};

// 10. Drawing on Canvas (draw()): A member function that renders a textual image of the
// shape on a Canvas object using the shape’s pen character.
// To draw, we simply use a counter and draw on all rows and columns < than the counter.
Canvas RightTriangle::draw() const {
    // Create instance of canvas with correct measures
    Canvas result {get_height(), get_width()};

    // Populate canvas
    size_t counter {1};
    for (int row {}; row < get_height(); ++row) {
        for (int col {}; col < get_width(); ++col) {
            if (row < counter && col < counter) result.put(row, col, getPen());
        }
        ++counter;
    }

    // Return canvas
    return result;
};

// 11. Height Calculation (get_height()) Computes and returns the length of the vertical
// attribute of the shape.
size_t RightTriangle::get_height() const {
    return base;
};