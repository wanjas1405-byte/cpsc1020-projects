// -------------------------------
// File: Deck.h
// -------------------------------

// -------------------------------
// Header Guard
// -------------------------------
// Lines: 1-3
// Purpose: Prevent multiple inclusions of this header file
// Why: Without this, including Deck.h in multiple files could cause redefinition errors
#ifndef DECK_H
#define DECK_H

// -------------------------------
// Include Dependencies
// -------------------------------
// Lines: 5-7
// Purpose: To use vector container and Card class
// Why: Deck stores Card objects in a vector for easy dynamic resizing
#include <vector>
#include "Card.h"
using namespace std;

// -------------------------------
// Deck Class Declaration
// -------------------------------
// Lines: 9-20
// Purpose: Represents a full deck of TigerGame cards
// Why: Encapsulates all operations on the deck (shuffle, draw, size)
class Deck {
private:
    vector<Card> deck;  // Stores all cards in the deck
                        // Purpose: Holds the Card objects for drawing and shuffling
                        // Why: Vector allows dynamic addition/removal of cards

public:
    // -------------------------------
    // Constructor
    // -------------------------------
    // Lines: 13
    // Purpose: Initialize deck with all 30 TigerGame cards
    // Why: Automatically populate deck at creation
    Deck();

    // -------------------------------
    // shuffle()
    // -------------------------------
    // Lines: 16
    // Purpose: Randomly rearrange the cards in the deck
    // Why: Ensures fair gameplay
    void shuffle();

    // -------------------------------
    // drawCard()
    // -------------------------------
    // Lines: 19
    // Purpose: Remove and return the top card from the deck
    // Why: Used when giving cards to players or playing rounds
    Card drawCard();

    // -------------------------------
    // getDeckSize()
    // -------------------------------
    // Lines: 22
    // Purpose: Return number of cards left in deck
    // Why: Prevents drawing from an empty deck
    int getDeckSize();
};

// -------------------------------
// End Header Guard
// -------------------------------
// Lines: 26
#endif