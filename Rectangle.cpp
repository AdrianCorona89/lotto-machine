#include "Rectangle.h"

// Constructor taking 2 parameters
Rectangle::Rectangle(size_t h, size_t w, char ch, const string name) : Shape{name, ch}, height{h}, width{w} {};

// Virtual Methods:
// 6. Geometric Area Calculation (areaGeo()): Computes and returns the shape’s geometric
// area.
double Rectangle::areaGeo() const {
    return (((double)height) * ((double)width));
};

// 7. Geometric Perimeter Calculation (perimeterGeo()): Computes and returns the shape’s
// geometric perimeter.
double Rectangle::perimeterGeo() const {
    return 2.0 * static_cast<double>(height + width);
};

// 8. Textual Area Calculation (areaTxt()): Determines the number of characters forming the
// textual image of the shape.
int Rectangle::areaTxt() const {
    return areaGeo();
};

// 9. Textual Perimeter Calculation (perimeterTxt()): Counts the characters on the borders
// of the textual image of the shape.
int Rectangle::perimeterTxt() const {
    int result {-1};
    // Using formula provided by the professor
    if (height > 1 && width > 1) {
        result = 2 * (height + width) - 4;
    } else if (height == 0 || width == 0) {
        result = height*width;
    }
    return result;
};

// 10. Drawing on Canvas (draw()): A member function that renders a textual image of the
// shape on a Canvas object using the shape’s pen character.
// Draw() will simply place the pen character in all the spaces.
Canvas Rectangle::draw() const {
    Canvas can {get_height(), get_width()};
    for (int row {}; row < get_height(); ++row) {
        for (int col {}; col < get_width(); ++col) {
            can.put(row, col, getPen());
        }
    }
    return can;
};

// 11. Height Calculation (get_height()) Computes and returns the length of the vertical
// attribute of the shape.
size_t Rectangle::get_height() const {
    return height;
};

// 12. Width Calculation (get_width()) Computes and returns the length of the horizontal
// attribute of the shape.
size_t Rectangle::get_width() const {
    return width;
};