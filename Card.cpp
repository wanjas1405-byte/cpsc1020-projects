// -------------------------------
// File: Card.cpp
// -------------------------------

// -------------------------------
// Include Card Header
// -------------------------------
// Lines: 1-3
// Purpose: Provides declaration of Card class and its members
// Why: Needed to define actual behavior of Card functions outside class
#include "Card.h"

// -------------------------------
// Include stringstream library
// -------------------------------
// Lines: 5-6
// Purpose: For constructing formatted strings representing cards
// Why: Safer and easier than manual string concatenation
#include <sstream>

// -------------------------------
// Default Constructor
// -------------------------------
// Lines: 9-16
// Function: Card::Card()
// Purpose: Create a default "blank" card
// Why: Ensures objects are always initialized to safe state
// How: rank=0, color=purple, value=0
Card::Card() {
    rank = 0;        // Default rank
    color = purple;  // Default color
    value = 0;       // Default value
}

// -------------------------------
// Parameterized Constructor
// -------------------------------
// Lines: 19-32
// Function: Card::Card(int r, Color c)
// Purpose: Create a specific card with given rank and color
// Why: Used to populate deck with all cards according to game rules
// How: Sets rank and color, then computes value based on color
Card::Card(int r, Color c) {
    rank = r;      // Store rank
    color = c;     // Store color

    // Compute value based on color rules
    if (color == purple)
        value = rank;        // Purple: value = rank
    else if (color == orange)
        value = rank * 2;    // Orange: value = rank*2
    else if (color == black)
        value = rank * 3;    // Black: value = rank*3
}

// -------------------------------
// strCard()
// -------------------------------
// Lines: 35-52
// Function: string Card::strCard()
// Purpose: Return human-readable string for card (format "color:rank")
// Why: Allows player to see cards during game
// How: Converts enum color to string, concatenates with rank
string Card::strCard() {
    string colorStr;  // Temporary string for color

    if (color == purple)
        colorStr = "purple";   // Map enum to string
    else if (color == orange)
        colorStr = "orange";
    else
        colorStr = "black";

    stringstream ss;       // String builder
    ss << colorStr << ":" << rank;  // Combine color and rank
    return ss.str();       // Return formatted string
}

// -------------------------------
// getRank()
// -------------------------------
// Lines: 55-58
// Purpose: Return card's rank
// Why: Used in comparisons and scoring
int Card::getRank() {
    return rank;
}

// -------------------------------
// getColor()
// -------------------------------
// Lines: 61-64
// Purpose: Return card's color
// Why: Useful for display and color-based rules
Card::Color Card::getColor() {
    return color;
}

// -------------------------------
// getValue()
// -------------------------------
// Lines: 67-70
// Purpose: Return card's precomputed value
// Why: Determines round winner and points earned
int Card::getValue() {
    return value;
}