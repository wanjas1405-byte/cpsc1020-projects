// -------------------------------
// File: Card.h
// -------------------------------

// -------------------------------
// Header Guard
// -------------------------------
// Lines: 1-3
// Purpose: Prevents multiple inclusion of Card.h
// Why: If included in multiple files (Deck, Hand, Player), compiler would see duplicate definitions
#ifndef CARD_H
#define CARD_H

// -------------------------------
// Include string library
// -------------------------------
// Lines: 5-6
// Purpose: Allows use of std::string type
// Why: Needed for strCard() function, which returns card information as string
#include <string>

// -------------------------------
// Use standard namespace
// -------------------------------
// Lines: 7-8
// Purpose: Avoid writing std:: everywhere
// Why: Cleaner code when using string and other standard library features
using namespace std;

// -------------------------------
// Card Class Declaration
// -------------------------------
// Lines: 10-50
// Purpose: Represents a single card in TigerGame
// Why: Each card stores rank, color, and value for game logic
class Card {
public:
    // -------------------------------
    // Enum Color
    // -------------------------------
    // Lines: 13-15
    // Purpose: Defines valid colors for a card
    // Why: Ensures only valid colors are used (purple, orange, black)
    enum Color { purple, orange, black };

private:
    // -------------------------------
    // Member Variables
    // -------------------------------
    // Lines: 18-25
    int rank;      // Card rank (1-15 depending on color)
                   // Purpose: Determines card strength
                   // Why: Used in scoring and comparing cards
    Color color;   // Card color
                   // Purpose: Determines value multiplier and display
                   // Why: TigerGame rules assign different multipliers per color
    int value;     // Precomputed value of the card
                   // Purpose: Determines points earned in a round
                   // Why: Avoids recalculating every time value is needed

public:
    // -------------------------------
    // Constructors
    // -------------------------------
    // Lines: 28-35
    Card();                     
    // Default constructor
    // Purpose: Creates a "blank" card with safe defaults
    // Why: Ensures all Card objects are initialized
    // How: rank=0, color=purple, value=0

    Card(int r, Color c);      
    // Parameterized constructor
    // Purpose: Creates card with specific rank and color
    // Why: Used to populate deck with cards according to TigerGame rules
    // How: Sets rank and color, computes value based on color

    // -------------------------------
    // Member Functions
    // -------------------------------
    string strCard();         
    // Purpose: Convert card to string format "color:rank"
    // Why: Allows display of cards in human-readable format
    // How: Converts enum to string, concatenates with rank

    int getRank();
    // Purpose: Return card rank
    // Why: Needed for comparisons, scoring, display

    Color getColor();
    // Purpose: Return card color
    // Why: Useful for display or game logic

    int getValue();
    // Purpose: Return card value
    // Why: Determines round winner and calculates points
};

// -------------------------------
// End Header Guard
// -------------------------------
// Lines: 50-52
// Purpose: Ensures Card.h is only included once in any file
#endif
