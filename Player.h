// -------------------------------
// PLAYER.H
// -------------------------------
// File: Player.h
// Purpose: Declaration of Player class for TigerGame
// Why: Represents each participant (human or computer) in the game

#ifndef PLAYER_H
#define PLAYER_H

// -------------------------------
// Include Hand and Deck Headers
// -------------------------------
// Purpose: Provides the declaration of Hand and Deck classes
// Why: Player has a Hand, which is initialized from a Deck
#include "Hand.h"
#include "Deck.h"

// -------------------------------
// Player Class Declaration
// -------------------------------
// Purpose: Encapsulate a player's hand and score
// Why: Needed to track cards and points for gameplay
class Player {
public:
    // -------------------------------
    // Member Variables
    // -------------------------------
    Hand hand; // Stores the player's current hand of cards
    // Purpose: Hold cards a player can play during rounds
    // Why: Enables playing, displaying, and dealing cards

    int score; // Player's current score
    // Purpose: Track points earned across rounds
    // Why: Needed for determining the winner

    // -------------------------------
    // Constructor
    // -------------------------------
    Player(Deck &deck, int N) : hand(deck, N), score(0) {}
    // Line(s): 26-27
    // Purpose: Initialize a player with N cards drawn from deck and score 0
    // Why: Ensures every player starts with proper hand and score
    // How: Hand constructor handles card drawing; score initialized to 0
};

#endif // PLAYER_H