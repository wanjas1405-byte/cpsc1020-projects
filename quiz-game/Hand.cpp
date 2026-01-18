// -------------------------------
// File: Hand.cpp
// -------------------------------

// -------------------------------
// Include Hand Header
// -------------------------------
// Lines: 1-3
// Purpose: Provides declaration of Hand class and its members
// Why: Hand.cpp needs to define the member functions declared in Hand.h
#include "Hand.h"

// -------------------------------
// Include Libraries
// -------------------------------
// Lines: 5-7
// Purpose: Provides input/output and string formatting functionality
// Why: Required for strHand() to convert hand contents to readable strings
#include <iostream>
#include <sstream>
using namespace std;

// -------------------------------
// Constructor
// -------------------------------
// Lines: 10-19
// Function: Hand::Hand(Deck &deck, int N)
// Purpose: Initialize a hand of N cards drawn from the provided deck
// Why: Each player starts the game with a fixed number of cards
// How: Loops from 1 to N, draws a card from the deck, and stores it in the hand vector
Hand::Hand(Deck &deck, int N) {
    for (int i = 1; i <= N; i++) {
        Card c = deck.drawCard();  // Draw a card from the deck
        hand.push_back(c);         // Add the drawn card to the hand
        // Justification: Ensures each player starts with the correct number of cards
    }
}

// -------------------------------
// strHand()
// -------------------------------
// Lines: 22-34
// Function: string Hand::strHand()
// Purpose: Convert the entire hand into a human-readable string
// Why: Allows the player to see which cards are in their hand
// How: Loops through each card, formats it with its index, and concatenates into a single string
string Hand::strHand() {
    string s = "";  // Initialize empty string to store hand representation

    for (size_t i = 0; i < hand.size(); i++) {
        stringstream ss;                    // Temporary stringstream for formatting
        ss << "(" << i + 1 << ") "          // Display 1-based index for user clarity
           << hand[i].strCard();           // Add card representation (color:rank)
        s += ss.str() + "\n";               // Append formatted card and newline
    }

    return s;  // Return the full string representing the hand
}

// -------------------------------
// dealCard()
// -------------------------------
// Lines: 37-57
// Function: Card Hand::dealCard(int num)
// Purpose: Remove and return a card from the hand at a given 1-based index
// Why: Lets the player or computer play a card in a round
// How: Validates input, adjusts for 0-based indexing, shifts remaining cards, returns selected card
Card Hand::dealCard(int num) {
    // Validate input
    if (num < 1 || num > static_cast<int>(hand.size())) {
        cout << "Oops, try again!" << endl;  // Inform user of invalid selection
        return Card();                        // Return default card if invalid
    }

    Card c = hand[num - 1];  // Store the selected card (adjust index to 0-based)
    // Purpose: Ensure correct card is retrieved from vector

    // Shift remaining cards forward to maintain contiguous vector
    for (size_t i = num - 1; i < hand.size() - 1; i++) {
        hand[i] = hand[i + 1];  // Move next card into current slot
    }

    hand.pop_back();  // Remove last element, which is now duplicate after shifting
    // Justification: Keeps vector size consistent and prevents "empty slot" at end

    return c;  // Return the selected card to the caller
}

// -------------------------------
// getHandSize()
// -------------------------------
// Lines: 60-64
// Function: int Hand::getHandSize()
// Purpose: Return the number of cards remaining in the hand
// Why: Used to limit player input and track hand size
// How: Returns current vector size
int Hand::getHandSize() {
    return hand.size();  // Vector stores current number of cards
}
