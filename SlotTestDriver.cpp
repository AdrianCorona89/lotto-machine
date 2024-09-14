// #include "Canvas.h"
// #include "Rectangle.h"
// #include "Rhombus.h"
// #include "RightTriangle.h"
// #include "AcuteTriangle.h"
// #include "Slot.h"
// #include <cassert>

// using namespace std;

// // Main method starts in line 132

// // These methods are for testing only. I figured it would be better to leave them in case you want to
// // test specific classes. 
// // Test Triangles
// void testTriangles() {
//     // Test for Right Triangle
//     RightTriangle rt{ 10, 'L'};
//     cout << rt << endl;
//     Canvas rtCan {rt.draw()};
//     cout << rtCan << endl;

//     RightTriangle rt2{5, 'X'};
//     cout << rt2 << endl;
//     Canvas rt2Can {rt2.draw()};
//     cout << rt2Can << endl;

//     // Test for Acute Triangle
//     AcuteTriangle at{17, '^', "Pyramid"};
//     cout << at << endl;

//     Canvas atCan{ at.draw() };
//     cout << atCan << endl;
//     Canvas atVertical {atCan.flip_vertical()};
//     cout << atVertical << endl;

//     Canvas rtHorizontal {rt2Can.flip_horizontal()};
//     cout << rtHorizontal << endl;

// }

// // Test Rectangle and Rhombus
// void testRectangle() {
//     // For Rectangle
//     Rectangle rec1 {5,7};
//     Canvas rectCan {rec1.draw()};
//     cout << rectCan << endl;
//     cout << rec1 << endl;
    
//     // For Rhombus
//     Rhombus ace{16, 'v', "Ace of diamond"};
//     cout << ace << endl;
//     Canvas aceCan{ ace.draw() }; // or, Canvas aceCan = ace.draw();
//     cout << aceCan << endl;
    
// }

// // Test Canvas Default Constructor
// void testDefaultConstructor() {
//     Canvas canvas1;
//     assert(canvas1.getRows() == 10);
//     assert(canvas1.getColumns() == 10);
//     for (int row = 0; row < 10; ++row) {
//         for (int col = 0; col < 10; ++col) {
//             assert(canvas1.get(row, col) == ' ');
//         }
//     }
//     canvas1.print(cout);
//     cout << "Default constructor test passed!" << endl;
// }

// // Test Canvas Parameterized Constructor
// void testParameterizedConstructor() {
//     Canvas canvas(8, 5, '*');
//     assert(canvas.getRows() == 8);
//     assert(canvas.getColumns() == 5);
//     for (int row = 0; row < 8; ++row) {
//         for (int col = 0; col < 5; ++col) {
//             assert(canvas.get(row, col) == '*');
//         }
//     }
//     canvas.print(cout);
//     cout << "Parameterized constructor test passed!" << endl;
// }

// // Test Canvas Flipping
// void testFlipHorizontal() {
//     Canvas canvas(2, 3, ' ');
//     canvas.put(0, 0, 'a');
//     canvas.put(0, 1, 'b');
//     canvas.put(0, 2, 'c');
//     canvas.put(1, 0, 'd');
//     canvas.put(1, 1, 'e');
//     canvas.put(1, 2, 'f');

//     Canvas flipped = canvas.flip_horizontal();
//     assert(flipped.get(0, 0) == 'c');
//     assert(flipped.get(0, 1) == 'b');
//     assert(flipped.get(0, 2) == 'a');
//     assert(flipped.get(1, 0) == 'f');
//     assert(flipped.get(1, 1) == 'e');
//     assert(flipped.get(1, 2) == 'd');

//     canvas.print(cout);
//     flipped.print(cout);
//     cout << "Horizontal flip test passed!" << endl;
// }

// // Test Canvas Flipping
// void testFlipVertical() {
//     Canvas canvas(2, 3, ' ');
//     canvas.put(0, 0, 'a');
//     canvas.put(0, 1, 'b');
//     canvas.put(0, 2, 'c');
//     canvas.put(1, 0, 'd');
//     canvas.put(1, 1, 'e');
//     canvas.put(1, 2, 'f');

//     Canvas flipped = canvas.flip_vertical();
//     assert(flipped.get(0, 0) == 'd');
//     assert(flipped.get(0, 1) == 'e');
//     assert(flipped.get(0, 2) == 'f');
//     assert(flipped.get(1, 0) == 'a');
//     assert(flipped.get(1, 1) == 'b');
//     assert(flipped.get(1, 2) == 'c');

//     canvas.print(cout);
//     flipped.print(cout);
//     cout << "Vertical flip test passed!" << endl;
// }

// int main(){
//     // testDefaultConstructor();
//     // testParameterizedConstructor();
//     // testFlipHorizontal();
//     // testFlipVertical();
//     // testRectangle();
//     // testTriangles();
//     // cout << "All tests passed!" << endl << endl << endl;
    
//     Slot slotMachine;
//     slotMachine.run();


//     return 0;
// }
