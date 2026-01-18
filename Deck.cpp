// -------------------------------
// File: Deck.cpp
// -------------------------------

// -------------------------------
// Include Headers
// -------------------------------
// Lines: 1-3
// Purpose: Include Deck class declaration and necessary libraries
// Why: Deck.cpp needs to define the member functions declared in Deck.h
#include "Deck.h"
#include <cstdlib> // For rand()
#include <ctime>   // For time()

// -------------------------------
// Deck Constructor
// -------------------------------
// Lines: 6-18
// Function: Deck::Deck()
// Purpose: Populate the deck with all 30 TigerGame cards
// Why: Ensures deck has the correct number of cards with proper ranks and colors
// How: Loops through the ranges for each color and creates Card objects
Deck::Deck() {
    // Create 15 purple cards (rank 1-15)
    for (int i = 1; i <= 15; i++) {
        deck.push_back(Card(i, Card::purple)); // Call Card constructor
        // Justification: Ensures all purple cards are included in deck
    }

    // Create 10 orange cards (rank 1-10)
    for (int i = 1; i <= 10; i++) {
        deck.push_back(Card(i, Card::orange)); // Call Card constructor
        // Justification: Ensures all orange cards are included in deck
    }

    // Create 5 black cards (rank 6-10)
    for (int i = 6; i <= 10; i++) {
        deck.push_back(Card(i, Card::black)); // Call Card constructor
        // Justification: Ensures all black cards are included in deck
    }
}

// -------------------------------
// shuffle()
// -------------------------------
// Lines: 21-31
// Function: void Deck::shuffle()
// Purpose: Randomly rearrange the cards in the deck
// Why: Simulates shuffling for fair gameplay
// How: Iterates through each card and swaps it with a random card
void Deck::shuffle() {
    int n = deck.size(); // Number of cards in deck
    for (int i = 0; i < n; i++) {
        int j = rand() % n; // Random index from 0 to n-1

        // Swap deck[i] and deck[j]
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// -------------------------------
// drawCard()
// -------------------------------
// Lines: 34-39
// Function: Card Deck::drawCard()
// Purpose: Remove and return the top card from the deck
// Why: Used to deal cards to players during setup or gameplay
// How: Returns deck[0] and removes it from the vector using erase
Card Deck::drawCard() {
    Card c = deck[0];       // Store top card to return
    deck.erase(deck.begin()); // Remove the card from the deck
    return c;               // Return the card to caller
}

// -------------------------------
// getDeckSize()
// -------------------------------
// Lines: 42-45
// Function: int Deck::getDeckSize()
// Purpose: Return number of cards remaining in the deck
// Why: Prevents drawing when deck is empty and tracks game progress
int Deck::getDeckSize() {
    return deck.size(); // Return current vector size
}