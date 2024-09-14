#include "Canvas.h"
using std::cout;

// Default constructor
Canvas::Canvas() : Canvas(10,10) {};

// Parameterized Constructor
Canvas::Canvas(size_t rows, size_t columns, char fill) 
    : fillChar{fill} {
    // To ensure minimum size of 1x1
    if (rows == 0) rows = 1;
    if (columns == 0) columns = 1;
    grid = std::vector<std::vector<char>>(rows, std::vector<char>(columns, fill));
}

// validates row r and column c, 0-based
bool Canvas::check(int r, int c)const { 
    return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
};

// getter and setter methods
char Canvas::getFillChar()const {return fillChar;};
void Canvas::setFillChar(char ch) {fillChar = ch;};

char Canvas::getFrame_ver() const {return frame_ver;};
void Canvas::setFrame_ver(char ch) {frame_ver = ch;};

char Canvas::getFrame_hor() const {return frame_hor;};
void Canvas::setFrame_hor(char ch) {frame_hor = ch;};

char Canvas::getFrame_cor() const {return frame_cor;};
void Canvas::setFrame_cor(char ch) {frame_cor = ch;};

// returns height of this Canvas object
size_t Canvas::getRows()const {return grid.size();}; 

// returns width of this Canvas object
size_t Canvas::getColumns()const {return grid[0].size();};

// flips this canvas horizontally
Canvas Canvas::flip_horizontal()const {
    Canvas result {grid.size(), grid[0].size()};
    for (int row = 0; row < grid.size(); ++row) {
        for (int col = 0; col < grid[0].size(); ++col) {
            result.grid[row][col] = grid[row][grid[0].size() - 1 - col];
        }
    }
    return result;
};

// flips this canvas vertically
Canvas Canvas::flip_vertical()const {
    Canvas result {grid.size(), grid[0].size()};
    for (int row = 0; row < grid.size(); ++row) {
        for (int col = 0; col < grid[0].size(); ++col) {
            result.grid[row][col] = grid[grid.size() - 1 - row][col];
        }
    }
    return result;
};

// prints this Canvas to ostream
void Canvas::print(ostream& os) const {
    // First line
    os << getFrame_cor();
    for (int col {}; col < grid[0].size(); col++) {
        os << getFrame_hor();
    } 
    os << getFrame_cor() << "\n";

    // Body
    for (int row{}; row < grid.size(); row++) {
        os << getFrame_ver();
        for (int col{}; col < grid[0].size(); col++) {
            os << grid[row][col];
        }
        os << getFrame_ver() << "\n";
    }

    // Last line
    os << getFrame_cor();
    for (int col {}; col < grid[0].size(); col++) {
        os << getFrame_hor();
    } 
    os << getFrame_cor() << "\n";
};

// returns char at row r and column c, 0-based;
// throws std::out_of_range{ "Canvas index out of range" }
// if r or c is invalid.
char Canvas::get(int r, int c) const {
    if (check(r,c)) {
        return grid[r][c];
    } else {
        throw std::out_of_range{"Canvas index out of range"};
    }
};    

// puts ch at row r and column c, 0-based;                                    
// the only function used by a shape's draw functon;
// throws std::out_of_range{ "Canvas index out of range" }
// if r or c is invalid.
void Canvas::put(int r, int c, char ch) {
    if (check(r,c)) {
        grid[r][c] = ch;
    } else {
        throw std::out_of_range{"Canvas index out of range"};
    }
}; 

// use blank as default fill character
void Canvas::fill(char ch) {
    for (int row {}; row < grid.size(); row++) {
        for (int col{}; col < grid[0].size(); col++) {
            grid[row][col] = ch;
        }
    }
};

// Write the given 'text' horizontally, starting at row 'r' and column 'c' on this canvas.
// Any writes outside the canvas region are ignored. Rows and columns are 1-based
void Canvas::write_horizontal(int r, int c, const std::string text) {
    // Adjust to 0-based indexing
    --r;
    --c;

    int length = text.size();
    int counter {};
    while (check(r,c) && counter < length) {
        grid[r][c++] = text.at(counter++);
    }
};

// Write the given 'text' vertically, starting at row 'r' and column 'c' on this canvas.
// Any writes outside the canvas region are ignored. Rows and columns are 1-based
void Canvas::write_vertical(int r, int c, const std::string text) {
    // Adjust to 0-based indexing
    --r;
    --c;

    int length = text.size();
    int counter {};
    while (check(r,c) && counter < length) {
        grid[r++][c] = text.at(counter++);
    }
};

// copies (overlays) the non-fill characters of "can" onto the invoking Canvas object;
// maps can's origin to row r and column c on the invoking Canvas object;
// Rows and columns are 1-based.
void Canvas::overlay(const Canvas& can, size_t r, size_t c) {
    // Adjust to 0-based indexing
    r--;
    c--;

    // Iterate over each cell of the input canvas
    for (int i = 0; i < can.grid.size(); ++i) {
        for (int j = 0; j < can.grid[0].size(); ++j) {
            // Calculate the corresponding position on the invoking canvas
            int targetRow = r + i;
            int targetCol = c + j;

            // Check if the position is within bounds and if the character is not the fill character
            if (check(targetRow, targetCol) && can.grid[i][j] != can.fillChar) {
                grid[targetRow][targetCol] = can.grid[i][j];
            }
        }
    }
}

// uses concat below
Canvas& Canvas::operator+=(const Canvas& right_can) {
    *this = this->concat(right_can);
    
    return *this;
}; 

// returns a canvas of minimal size
// storing *this on the left and 'can' on the right;
// here we might try to get artsy decorating 
// two canvases side by side, making them visually appealing;
// hopefully, separating them with least one space claracter.
Canvas Canvas::concat(const Canvas& can) {
    // Create new result canvas and resize if necessary
    Canvas result {getRows(), getColumns() + can.getColumns() +2, getFillChar()};
    result.resizeRows(can.getRows());

    // Copy first and second canvas
    result.overlay(*this,1,1);
    result.overlay(can,1,this->getColumns()+2);

    return result;
}; 

// used by concat to equalize the height of the
// supplied canvases before placing them side by side.
void Canvas::resizeRows(size_t n) {
    // Get current number of rows
    size_t currentRows = getRows();

    // If n is greater, resize. Otherwise do nothing
    if (n > currentRows) {
        grid.resize(n, std::vector<char>(grid[0].size(), fillChar));
    } 
};        

Canvas operator+(const Canvas& left_can, const Canvas& right_can) {
    Canvas result {left_can};
    result += right_can;
    return result;
};

ostream& operator<< (ostream& sout, const Canvas& can) {
    can.print(sout);
    return sout;
};