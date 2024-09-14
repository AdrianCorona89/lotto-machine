#include "Slot.h"
#include <cctype>

// Parameterized Constructor
Slot::Slot(int t) : tokens{t} {};

// Getter for number of tokens
int Slot::getTokens() const { return tokens;};

// Generation of random integer between lower and higher
int Slot::generateRandom(int lower, int higher) const {
    // Random device to seed the random number generator
    std::random_device seed;
    // Create a Mersenne Twister random number generator
    std::mt19937 gen(seed());
    // Define the range for the random integers
    std::uniform_int_distribution<int> intDist(lower, higher);
    // Generate and return a random integer
    return intDist(gen);
}

// To check if the string represents a number or not.
// Mainly used as a validation mechanism for user input.
bool Slot::isNumber(const string& s) const {
    // Verifies each char and checks if it's digit.
    for (char c : s) {
        if (!std::isdigit(c)) {
            return false; // If any character is not a digit, return false
        }
    }
    return !s.empty(); // Ensure the string is not empty
}

// Method to print the menu
void Slot::printMenu() const {
    cout << "\nWelcome to the 3-Reel Lucky Slot Machine Game! Let's dive in:\n"
    << "1. Each reel will randomly display one of four shapes,\n"
    << "each available in 25 different sizes.\n"
    << "2. To win 3 times your bet:\n"
    << "Get two similar shapes AND two shapes with equal Textual Areas.\n"
    << "3. To win 2 times your bet:\n"
    << "Get three similar shapes.\n"
    << "4. To win 1 time your bet:\n"
    << "Ensure that the Textual Area of the middle shape is greater\n"
    << "than the combined Textual Areas of the left and right shapes.\n"
    << "5. If you get the same shapes on the left and right, you neither win nor lose.\n"
    << "6. Otherwise, unfortunately, you lose your bet.\n"
    << "7. You start with 10 free slot tokens!\n\n";
};

void Slot::run() {
    // Initialization of relevant variables. 
    array<Canvas, 3> reel {}; // Represents array with the three shapes
    array<unique_ptr<Shape>, 3> shapePtr {}; // Array with smart pointers to the three shapes
    bool toPlay {true}; // Boolean validation mechanism
    
    // Print the menu just once
    printMenu();
    // Initial loop. This runs the system and continues as long as the user wants to continue.
    while (tokens > 0 && toPlay) {
        // Variables used inside the gameplay. Need an inputNumber for the user's selection.
        // Need also string input for validation.
        int inputNumber {1};
        string input {};
        bool valid {false};

        // Second loop. This is to prompt the user and for validation of input.
        while (!valid && toPlay) {
            cout  << "How much would you like to bet (enter 0 to quit)?\n";
            getline(cin, input);
            

            // First validation. Confirm the input is a number.
            if (!isNumber(input)) {
                cout << "Invalid input. Please enter a positive integer.\n";
                // If it's not, it will skip the remainding section.
                continue;
            }

            // Second validation. Confirm the number is higher than 0 and lower than current tokens.
            inputNumber = std::stoi(input);
            if (inputNumber < 0) {
                cout << "Invalid input. Please enter a positive integer.\n";
            } else if (inputNumber > tokens) {
                cout << "You do not have enough tokens. Please enter a valid amount!\n";
            } else if (inputNumber == 0) {
                // If user enters 0, user does not want to play. It will break the loop.
                toPlay = false;
                break;
            } else {
                // Otherwise the token value is valid. We continue with this affirmation.
                valid = true;
            }
        }

        // After second validation. We proceed only if the user decided to continue playing
        if (toPlay == false) break;

        // We start generating the shapes.
        for (int k {}; k < 3; k++) {
            // We create random numbers for shape and size
            int randomShap {generateRandom(0, 3)};
            int randomWidth {generateRandom(1, 25)};
            int randomHeight {generateRandom(1, 25)};

            // Switch statement with the possible shapes and sizes.
            switch(randomShap) {
                case 0:
                shapePtr[k].reset(new Rhombus(randomWidth));
                break;

                case 1:
                shapePtr[k].reset(new AcuteTriangle(randomWidth));
                break;

                case 2:
                shapePtr[k].reset(new RightTriangle(randomWidth));
                break;

                case 3:
                shapePtr[k].reset(new Rectangle(randomWidth, randomHeight));
                break;

                default:
                break;
            }

            // Draw the newly created shape into the corresponding canvas.
            reel[k] = shapePtr[k]->draw();
        }

        // We create the payline, arranging and displaying the canvases horizontally.
        Canvas payline {reel[0]};
        payline += reel[1];
        payline += reel[2];

        cout << "Left Shape:\n\n" << *shapePtr[0] << std::endl;
        cout << "Middle Shape:\n\n" << *shapePtr[1] << std::endl;
        cout << "Right Shape:\n\n" << *shapePtr[2] << std::endl;

        cout << "Payline:\n\n" << payline << std::endl;
        

        // We compute the prize payout in tokens based on the shapes on the payline.
        int result {};

        // This if-else statements is done based on the professor's rules.
        if ((shapePtr[0]->getName() == shapePtr[1]->getName() || 
        shapePtr[0]->getName() == shapePtr[2]->getName() || 
        shapePtr[1]->getName() == shapePtr[2]->getName()) 
        && (shapePtr[0]->areaTxt() == shapePtr[1]->areaTxt() ||
        shapePtr[0]->areaTxt() == shapePtr[2]->areaTxt() ||
        shapePtr[1]->areaTxt() == shapePtr[2]->areaTxt())) {
            result = 3;
        } else if (shapePtr[0]->getName() == shapePtr[1]->getName() 
        && shapePtr[0]->getName() == shapePtr[2]->getName()) {
            result = 2;
        } else if (shapePtr[1]->areaTxt() 
        > (shapePtr[0]->areaGeo() + shapePtr[2]->areaGeo())) {
            result = 1;
        } else if (shapePtr[0]->getName() == shapePtr[2]->getName()) {
            result = 0;
        } else {
            result = -1;
        }

        // Update the player's current tokens and display corresponding result.
        switch (result) {
            case 3:
            tokens += (inputNumber * result);
            cout << "Two shapes are similar and two shapes match in textual areas\n"
            << "Congratulations! You win three times your bet: " << (inputNumber * result) << "\n";

            break;

            case 2:
            tokens += (inputNumber * result);
            cout << "All three shapes are similar\n"
            << "Congratulations! You win twice your bet: " << (inputNumber * result) << "\n";

            break;

            case 1:
            tokens += (inputNumber * result);
            cout << "Middle > Left + Right, in Textual Areas\n" 
            << "Congratulations! You win your bet: " << inputNumber << "\n";
            break;

            case 0:
            cout << "Lucky this time!\nYou don't win, you don't lose, you are safe!\n";
            break;

            case -1:
            tokens += (inputNumber * result);
            cout << "Oh No!\nYou lose your bet\n";
            break;

            default:
            break;
        }
        // Display whether player won, lost or neither.
        cout << "You now have " << tokens << " tokens!\n";

    }

    // Display appropriate message thanking the player.
    cout << "Game Over!\n\nThank you for playing!\n";
};