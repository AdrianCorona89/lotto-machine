#include "AcuteTriangle.h"

// Parameterized Constructor
AcuteTriangle::AcuteTriangle(size_t base, char ch, const string name) : Triangle(base, ch, name) {
    // If base is even, we increment by one to make it odd.
    if (base % 2 == 0) {
        base = base + 1;
    }
}

// ------------------------------------------------------------------------------------
// Virtual Methods:
// ------------------------------------------------------------------------------------
// 6. Geometric Area Calculation (areaGeo()): Computes and returns the shape’s geometric
// area.
double AcuteTriangle::areaGeo() const {
    return ((double)base * (double)get_height()) / 2.0;
};

// 7. Geometric Perimeter Calculation (perimeterGeo()): Computes and returns the shape’s
// geometric perimeter.
double AcuteTriangle::perimeterGeo() const {
    return (double)base + sqrt((base * base) + (4 * (get_height() * get_height()))); 
};

// 8. Textual Area Calculation (areaTxt()): Determines the number of characters forming the
// textual image of the shape.
int AcuteTriangle::areaTxt() const {
    double height {(double)get_height()};
    return height * height;
};

// 9. Textual Perimeter Calculation (perimeterTxt()): Counts the characters on the borders
// of the textual image of the shape.
int AcuteTriangle::perimeterTxt() const {
    if (get_height() > 1 && get_width() > 1) return 4 * ((double)get_height() -1);
    else return 1;
};

// 10. Drawing on Canvas (draw()): A member function that renders a textual image of the
// shape on a Canvas object using the shape’s pen character.
// To draw we use the logic of the pyramid. We use a lower and upper limit.
// And increment/decrement them as rows advance.
Canvas AcuteTriangle::draw() const {
    // Create instance of canvas with correct measures
    Canvas result {get_height(), get_width()};

    // Populate canvas
    int lower_limit {(int)base / 2}, upper_limit {(int)base / 2};
    for (int row {}; row < get_height(); ++row) {
        for (int col {}; col < get_width(); ++col) {
            if (col >= lower_limit && col <= upper_limit) result.put(row, col, getPen());
        }
        --lower_limit;
        ++upper_limit;
    }

    // Return canvas
    return result;
};

// 11. Height Calculation (get_height()) Computes and returns the length of the vertical
// attribute of the shape.
size_t AcuteTriangle::get_height() const {
    return (base + 1) / 2;
};