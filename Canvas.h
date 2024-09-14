#ifndef CANVAS_H
#define CANVAS_H

#include<iostream>
#include<vector>
using std::vector;
using std::ostream;

/**
 * @class Canvas
 * @brief A class that represents a 2D canvas for drawing characters.
 */
class Canvas
{
public:
   // all special members are defaulted because 'grid',
   // a 2D std::vector, is self-sufficient and efficient,
   // designed to handle the corresponding special operations efficiently
   virtual ~Canvas()                = default; // why is the destructor virtual?
   Canvas(const Canvas&)            = default;
   Canvas(Canvas&&)                 = default;
   Canvas& operator=(const Canvas&) = default;
   Canvas& operator=(Canvas&&)      = default;

protected:
   vector<vector<char> > grid;           // a 2D vector representing a canvas
   char fillChar{};                      // fill or clear character
   char frame_ver = '|';
   char frame_hor = '-';
   char frame_cor = '+';

   bool check(int r, int c)const;          // validates row r and column c, 0-based

public:
   Canvas();  // delegates to Canvas(10, 10) below

   // creates this rows x columns canvas filled with fillChar;
   // fillChar is optional and is the space character if not supplied
   Canvas(size_t rows, size_t columns, char fillChar = ' ');

   // getter and setter methods
   char getFillChar()const;
   void setFillChar(char ch);

   char getFrame_ver() const;
   void setFrame_ver(char ch);

   char getFrame_hor() const;
   void setFrame_hor(char ch);

   char getFrame_cor() const;
   void setFrame_cor(char ch);

   size_t getRows()const;              // returns height of this Canvas object
   size_t getColumns()const;           // returns width of this Canvas object
   Canvas flip_horizontal()const;   // flips this canvas horizontally
   Canvas flip_vertical()const;     // flips this canvas vertically
   void print(ostream&) const;      // prints this Canvas to ostream
   char get(int r, int c) const;    // returns char at row r and column c, 0-based;
                                    // throws std::out_of_range{ "Canvas index out of range" }
                                    // if r or c is invalid.
   void put(int r, int c, char ch); // puts ch at row r and column c, 0-based;
                                    // the only function used by a shape's draw functon;
                                    // throws std::out_of_range{ "Canvas index out of range" }
                                    // if r or c is invalid.
   void fill(char ch = ' ');        // use blank as default fill character

   // Write the given 'text' horizontally, starting at row 'r' and column 'c' on this canvas.
   // Any writes outside the canvas region are ignored. Rows and columns are 1-based
   void write_horizontal(int r, int c, const std::string text); 

   // Write the given 'text' vertically, starting at row 'r' and column 'c' on this canvas.
   // Any writes outside the canvas region are ignored. Rows and columns are 1-based
   void write_vertical(int r, int c, const std::string text);

   // copies (overlays) the non-fill characters of "can" onto the invoking Canvas object;
   // maps can's origin to row r and column c on the invoking Canvas object;
   // Rows and columns are 1-based.
   void overlay(const Canvas& can, size_t r, size_t c);

   Canvas& operator+=(const Canvas& right_can); // uses concat below
   Canvas concat(const Canvas& can); // returns a canvas of minimal size
                                     // storing *this on the left and 'can' on the right;
                                     // here we might try to get artsy decorating 
                                     // two canvases side by side, making them visually appealing;
                                     // hopefully, separating them with least one space claracter.

   void resizeRows(size_t n);        // used by concat to equalize the height of the
                                     // supplied canvases before placing them side by side.
   void clear() { fill(fillChar); }
};

Canvas operator+(const Canvas& left_can, const Canvas& right_can);
ostream& operator<< (ostream& sout, const Canvas& can);
#endif
