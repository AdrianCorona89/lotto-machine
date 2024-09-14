#ifndef SHAPE_H
#define SHAPE_H
#include "Canvas.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <typeinfo>
#include <cmath>
using std::string;

/**
 * @class Shape
 * @brief Abstract base class representing a geometric shape.
 */
class Shape 
{
    protected:
    string name; // Name of the shape
    char pen; // Character used for drawing
    size_t identity; // Unique identifier for the shape
    // Static variable to have unique identities
    static size_t nextIdentity; // Static variable to keep track of identities

    public:
   // all special members are defaulted
   virtual ~Shape()                = default; 
   Shape(const Shape&)            = default;
   Shape(Shape&&)                 = default;
   Shape& operator=(const Shape&) = default;
   Shape& operator=(Shape&&)      = default;

    // 1. Constructor: Accepts initial values for name and pen data members, providing optional
    // values for both.
    Shape(const string name, char ch);

    // 2. Accessor (Getter) Functions: Three member functions, each retrieving one of the name,
    // pen, and identity attributes.
    string getName() const;
    char getPen() const;
    size_t getIdentity() const;

    // 3. Mutator (Setter) Functions: Two member functions for setting the name and pen
    // attributes.
    void setName(const string& newName);
    void setPen(char newPen);

    // 4. toString(): A member function returning a std::string representation of the invoking
    // shape object.
    string toString() const;

    // ------------------------------------------------------------------------------------
    // Virtual Methods:
    // ------------------------------------------------------------------------------------
    // 6. Geometric Area Calculation (areaGeo()): Computes and returns the shape’s geometric
    // area.
    virtual double areaGeo() const = 0;

    // 7. Geometric Perimeter Calculation (perimeterGeo()): Computes and returns the shape’s
    // geometric perimeter.
    virtual double perimeterGeo() const = 0;

    // 8. Textual Area Calculation (areaTxt()): Determines the number of characters forming the
    // textual image of the shape.
    virtual int areaTxt() const = 0;

    // 9. Textual Perimeter Calculation (perimeterTxt()): Counts the characters on the borders
    // of the textual image of the shape.
    virtual int perimeterTxt() const = 0;

    // 10. Drawing on Canvas (draw()): A member function that renders a textual image of the
    // shape on a Canvas object using the shape’s pen character.
    virtual Canvas draw() const = 0;

    // 11. Height Calculation (get_height()) Computes and returns the length of the vertical
    // attribute of the shape.
    virtual size_t get_height() const = 0;

    // 12. Width Calculation (get_width()) Computes and returns the length of the horizontal
    // attribute of the shape.
    virtual size_t get_width() const = 0;

};

// ------------------------------------------------------------------------------------
// Non Member Methods:
// ------------------------------------------------------------------------------------
// 5. Overloaded Polymorphic Output Operator (<<): Allows customized output when
// printing the shape.

std::ostream& operator<<(std::ostream& os, const Shape& object);



#endif