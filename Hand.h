// -------------------------------
// File: Hand.h
// -------------------------------
// Purpose: Declaration of Hand class for TigerGame
// Why: Represents a player's collection of cards and provides interface for playing and displaying cards

#ifndef HAND_H
#define HAND_H

// -------------------------------
// Include Libraries
// -------------------------------
// Purpose: Provides std::vector for dynamic storage of Card objects
// Why: Hand needs a container to store cards dynamically as they are drawn or played
#include <vector>

// -------------------------------
// Include Dependencies
// -------------------------------
// Purpose: Include Card and Deck class declarations
// Why: Hand stores Card objects and is initialized using a Deck
#include "Deck.h"
#include "Card.h"

// -------------------------------
// Use Standard Namespace
// -------------------------------
// Purpose: Avoid writing std:: everywhere
// Why: Cleaner code for vector, string, etc.
using namespace std;

// -------------------------------
// Hand Class Declaration
// -------------------------------
// Purpose: Represents a collection of cards belonging to a player
// Why: Encapsulates all hand-related functionality like displaying, dealing, and counting cards
class Hand {
private:
    // -------------------------------
    // Member Variables
    // -------------------------------
    vector<Card> hand;  
    // Purpose: Store cards in the player's hand
    // Why: Vector allows dynamic resizing as cards are drawn or played
    // How: Cards are pushed when drawn from Deck and removed when played

public:
    // -------------------------------
    // Constructor
    // -------------------------------
    Hand(Deck &deck, int N);
    // Purpose: Initialize hand with N cards drawn from deck
    // Why: Ensures each player starts with the correct number of cards
    // How: Calls deck.drawCard() N times to populate the vector

    // -------------------------------
    // Member Functions
    // -------------------------------
    string strHand();
    // Purpose: Return a formatted string of the hand for display
    // Why: Player can see all cards in human-readable form
    // How: Loops through hand vector, calls strCard() for each Card, adds index for player selection

    Card dealCard(int num);
    // Purpose: Remove and return a card from hand at position num
    // Why: Implements player choosing a card to play in a round
    // How: Validates input, retrieves card, shifts remaining cards forward to fill the gap

    int getHandSize();
    // Purpose: Return number of cards currently in hand
    // Why: Limits player input to valid range and tracks game progress
    // How: Returns hand.size() to indicate how many cards are left to play
};

#endif // HAND_H