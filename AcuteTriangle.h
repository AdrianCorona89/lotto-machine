#ifndef ACUTETRIANGLE_H
#define ACUTETRIANGLE_H
#include "Triangle.h"

/**
 * @class AcuteTriangle
 * @brief A class representing an acute-angled triangle geometric shape.
 */
class AcuteTriangle : public Triangle {
    public:
    // Parameterized Constructor
    AcuteTriangle(size_t base, char ch = '*', const string name = "Wedge");

    // ------------------------------------------------------------------------------------
    // Virtual Methods:
    // ------------------------------------------------------------------------------------
    // 6. Geometric Area Calculation (areaGeo()): Computes and returns the shape’s geometric
    // area.
    virtual double areaGeo() const override;

    // 7. Geometric Perimeter Calculation (perimeterGeo()): Computes and returns the shape’s
    // geometric perimeter.
    virtual double perimeterGeo() const override;

    // 8. Textual Area Calculation (areaTxt()): Determines the number of characters forming the
    // textual image of the shape.
    virtual int areaTxt() const override;

    // 9. Textual Perimeter Calculation (perimeterTxt()): Counts the characters on the borders
    // of the textual image of the shape.
    virtual int perimeterTxt() const override;

    // 10. Drawing on Canvas (draw()): A member function that renders a textual image of the
    // shape on a Canvas object using the shape’s pen character.
    virtual Canvas draw() const override;

    // 11. Height Calculation (get_height()) Computes and returns the length of the vertical
    // attribute of the shape.
    virtual size_t get_height() const override;
};

#endif