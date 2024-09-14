#ifndef SLOT_H
#define SLOT_H
#include "Canvas.h"
#include "Shape.h"
#include "Rhombus.h"
#include "Rectangle.h"
#include "AcuteTriangle.h"
#include "RightTriangle.h"

#include <memory>
#include <array>
#include <random>
using std::array;
using std::unique_ptr;
using std::cout;
using std::cin;

/**
 * @class Slot
 * @brief A class representing a slot machine or game interface with shapes.
 *
 * The Slot class manages a collection of shapes and tokens, provides functionality for
 * generating random numbers, and interacts with the user through a menu system.
 */
class Slot {
    private:
    int tokens; // Number of tokens available in the slot machine.

    public:
    /**
     * @brief Constructs a Slot with the specified number of tokens.
     * @param t The initial number of tokens (default is 10).
     */
    Slot(int t = 10);

    /**
     * @brief Gets the number of tokens currently available in the slot.
     * @return The number of tokens.
     */
    int getTokens() const;

    /**
     * @brief Prints the menu options for the slot interface.
     */
    void printMenu() const;

    /**
     * @brief Checks if the provided string represents a valid number.
     * @param str The string to check.
     * @return True if the string represents a number, false otherwise.
     */
    bool isNumber(const string &) const;

    /**
     * @brief Runs the main logic of the slot machine or game interface.
     */
    void run();

    /**
     * @brief Generates a random integer within the specified range.
     * @param lower The lower bound of the range (inclusive).
     * @param higher The upper bound of the range (inclusive).
     * @return A randomly generated integer between lower and higher.
     */
    int generateRandom(int lower, int higher) const;
};

#endif