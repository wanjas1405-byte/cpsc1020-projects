// -------------------------------
// MAIN.CPP
// -------------------------------
// File: main.cpp
// Purpose: Implements the gameplay loop for TigerGame
// Why: Drives the game by handling deck creation, shuffling, player setup, gameplay rounds, score calculation, and final results

// -------------------------------
// Include Libraries and Headers
// -------------------------------
// Purpose: Provide necessary functionality for input/output, random numbers, and class usage
#include <iostream>   // For console input/output operations (cin, cout)
#include <cstdlib>    // For rand() and srand() functions (random number generation)
#include <ctime>      // For time() function to seed random generator
#include "Deck.h"     // Include the Deck class definition for creating and manipulating the deck
#include "Hand.h"     // Include the Hand class definition for managing a player's hand of cards
#include "Player.h"   // Include the Player class definition for human and computer players
using namespace std;

// -------------------------------
// Main Function
// -------------------------------
// Function: int main()
// Lines: 14-93
// Purpose: Orchestrates the entire TigerGame program
// Why: Handles game initialization, turn-based gameplay, scoring logic, and final result output
int main() {
    // -------------------------------
    // Seed Random Number Generator
    // -------------------------------
    srand(time(0)); 
    // Purpose: Seed the random number generator with the current system time
    // Why: Ensures that each execution of the program produces a different random sequence for shuffling and computer card selection
    // How: time(0) returns the current time in seconds, srand initializes rand() with that value

    // -------------------------------
    // Display Welcome Message
    // -------------------------------
    cout << "Welcome to TigerGame!" << endl;
    // Purpose: Provide a friendly message to the player at the start of the game
    // Why: Improves user experience and signals that the game is ready to start

    // -------------------------------
    // Create and Shuffle Deck
    // -------------------------------
    Deck deckOfCards;        // Instantiate a Deck object containing all 30 TigerGame cards
    deckOfCards.shuffle();   // Shuffle the deck using the Deck::shuffle() method
    // Purpose: Randomize the order of cards in the deck to ensure fairness
    // Why: Without shuffling, the cards would always be in the same order and gameplay would be predictable

    // -------------------------------
    // Initialize Players
    // -------------------------------
    Player human(deckOfCards, 6);      // Create human Player object, draw 6 cards from deck
    Player computer(deckOfCards, 6);   // Create computer Player object, draw 6 cards from deck
    int numRounds = 6;                 // Total number of rounds, equal to number of cards per hand
    // Purpose: Set up both players with their starting hands
    // Why: The game rules require each player to start with 6 cards

    // -------------------------------
    // Gameplay Loop
    // -------------------------------
    for (int round = 1; round <= numRounds; round++) {
        cout << "Round " << round << "\n-------" << endl;
        // Purpose: Loop through each round of the game, displaying round number and separator for readability

        // -------------------------------
        // Computer Plays a Card
        // -------------------------------
        int compHandSize = computer.hand.getHandSize();      // Get current number of cards in computer's hand
        int compIndex = rand() % compHandSize + 1;           // Select a random card index (1-based)
        Card compCard = computer.hand.dealCard(compIndex);   // Remove the chosen card from computer's hand and store it
        cout << "The computer plays: " << compCard.strCard() << endl;
        // Purpose: Simulate the computer's turn by playing a random card
        // Why: Ensures the computer plays fairly and unpredictably
        // How: dealCard(num) removes the card from the hand vector, preventing reuse

        // -------------------------------
        // Display Human Hand
        // -------------------------------
        cout << "Your hand: " << human.hand.strHand() << endl;
        // Purpose: Show the human player's current hand
        // Why: The player needs to see which cards are available to make an informed decision

        // -------------------------------
        // Human Plays a Card
        // -------------------------------
        int choice;                        // Store the player's chosen card index
        int humanHandSize = human.hand.getHandSize(); // Get number of cards left in human hand
        do {
            cout << "Which card do you want to play? ";
            cin >> choice;                  // Read player input
        } while (choice < 1 || choice > humanHandSize); // Validate input
        // Purpose: Ensure that the player selects a valid card index
        // Why: Prevents runtime errors and invalid card selection
        // How: Loop repeats until valid input is entered

        Card humanCard = human.hand.dealCard(choice);   // Remove selected card from hand and store it
        cout << "You played: " << humanCard.strCard() << endl;
        // Purpose: Execute the player's move
        // Why: Updates the game state by removing the card from the human hand

        // -------------------------------
        // Compare Cards and Update Scores
        // -------------------------------
        int humanValue = humanCard.getValue();  // Retrieve point value of human's card
        int compValue = compCard.getValue();    // Retrieve point value of computer's card

        if (humanValue > compValue) {
            human.score += humanValue + compValue; // Add total points to human score
            cout << "You win this round!" << endl;
        } else if (humanValue < compValue) {
            computer.score += humanValue + compValue; // Add total points to computer score
            cout << "The computer wins this round!" << endl;
        } else {
            cout << "Tie!" << endl; // No points awarded if values are equal
        }
        // Purpose: Determine round winner based on card values and update scores accordingly
        // Why: TigerGame scoring rules depend on the sum of played card values

        // -------------------------------
        // Display Current Scores
        // -------------------------------
        cout << "Current scores:\nHuman: " << human.score
             << "\nComputer: " << computer.score << endl << endl;
        // Purpose: Provide feedback to players after each round
        // Why: Keeps track of progress and motivates the player
    }

    // -------------------------------
    // Display Final Results
    // -------------------------------
    cout << "FINAL SCORE:\nHuman: " << human.score
         << "\nComputer: " << computer.score << endl;

    if (human.score > computer.score)
        cout << "You win!" << endl;
    else if (human.score < computer.score)
        cout << "Computer has won!" << endl;
    else
        cout << "It's a tie!" << endl;
    // Purpose: Announce the overall winner of the game
    // Why: Concludes the game and informs the player of results

    return 0; // Exit program
    // Purpose: Signal successful completion to operating system
}