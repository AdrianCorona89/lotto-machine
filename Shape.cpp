#include "Shape.h"

// Initialize the static member variable
size_t Shape::nextIdentity = 0;

// 1. Constructor: Accepts initial values for name and pen data members, providing optional
// values for both.
Shape::Shape(const string n, char ch) : name{n}, pen {ch}, identity{++nextIdentity} {};

// 2. Accessor (Getter) Functions: Three member functions, each retrieving one of the name,
// pen, and identity attributes.
string Shape::getName() const {
    return name;
};
char Shape::getPen() const {
    return pen;
};
size_t Shape::getIdentity() const {
    return identity;
};

// 3. Mutator (Setter) Functions: Two member functions for setting the name and pen
// attributes.
void Shape::setName(const string& newName) {
    name = newName;
};
void Shape::setPen(char newPen) {
    pen = newPen;
};

// 4. toString(): A member function returning a std::string representation of the invoking
// shape object.
string Shape::toString() const {
    std::ostringstream oss;
    oss << std::left; // Left-align the labels
    oss << "Shape Information\n-----------------\n";
    oss << std::left << "Id:                 " << std::right << std::setw(10) << identity << "\n";
    oss << std::left << "Shape name:         " << std::right << std::setw(10) << name << "\n";
    oss << std::left << "Pen character:      " << std::right << std::setw(10) << pen << "\n";
    oss << std::left << "Height:             " << std::right << std::setw(10) << get_height() << "\n";
    oss << std::left << "Width:              " << std::right << std::setw(10) << get_width() << "\n";
    oss << std::left << "Textual area:       " << std::right << std::setw(10) << areaTxt() << "\n";
    oss << std::left << "Geometric area:     " << std::right << std::fixed << std::setprecision(2) << std::setw(10) << areaGeo() << "\n";
    oss << std::left << "Textual perimeter:  " << std::right << std::setw(10) << perimeterTxt() << "\n";
    oss << std::left << "Geometric perimeter:" << std::right << std::fixed << std::setprecision(2) << std::setw(10) << perimeterGeo() << "\n";
    oss << std::left << "Static type:        " << std::right << std::setw(10) << typeid(this).name() << "\n";
    oss << std::left << "Dynamic type:       " << std::right << std::setw(10) << typeid(*this).name() << "\n";
    return oss.str();
};

// 5. Overloaded Polymorphic Output Operator (<<): Allows customized output when
// printing the shape.
std::ostream& operator<<(std::ostream& os, const Shape& object) {
    os << object.toString();
    return os;
};