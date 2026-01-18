// Prevent multiple inclusions of this header file
#ifndef QA_H
#define QA_H
// what it does: ensures the compiler includes this file only once to avoid redefinition errors
// why it’s used: standard practice for header files to prevent multiple inclusion issues

// Include the string library for using std::string
#include <string>
// what it does: allows use of the std::string type in the class
// why it’s used: questions and answers are stored as strings

// Declare a class named QA for quiz question-answer pairs
class QA {
private:
    // Private member to store the text of the question
    std::string question;
    // what it does: holds the question text for the object
    // why it’s used: encapsulates question text, accessible only through member functions

    // Private member to store the text of the answer
    std::string answer;
    // what it does: holds the answer text for the object
    // why it’s used: encapsulates answer text, accessible only through member functions

    // Private static member shared by all QA objects to track score
    static int score;
    // what it does: stores the quiz score shared by all QA objects
    // why it’s used: allows the score to be updated globally across all questions

public:
    // Default constructor: initializes question and answer to empty strings
    QA();
    // what it does: creates a QA object with empty question and answer
    // why it’s used: ensures objects are initialized safely without garbage values

    // Constructor with parameters: initializes question and answer with provided strings
    QA(const std::string& q, const std::string& a);
    // what it does: creates a QA object with specific question and answer
    // why it’s used: allows constructing QA objects directly from input file data

    // Getter function to retrieve the question text
    std::string getQuestion() const;
    // what it does: returns the question text of the object
    // why it’s used: provides safe access to private question member

    // Getter function to retrieve the answer text
    std::string getAnswer() const;
    // what it does: returns the answer text of the object
    // why it’s used: provides safe access to private answer member

    // Static function to get the current score
    static int getScore();
    // what it does: returns the current value of the static score
    // why it’s used: allows main program and result function to read the score

    // Function to count the number of letters in question and answer
    int letterCount() const;
    // what it does: counts alphabetic letters in question and answer
    // why it’s used: helps analyze text, ignoring numbers, spaces, and punctuation

    // Static function to update the score by a given value
    static void updateScore(int val);
    // what it does: adds or subtracts val from the score, never allowing it to go below zero
    // why it’s used: updates the score after each correct or wrong answer

    // Friend function declaration: allows buildResultString to access private members
    friend std::string buildResultString(int questions, int correct, int wrong);
    // what it does: grants buildResultString access to private score
    // why it’s used: enables the function to include the final score in the output
};

// End the header guard
#endif
// what it does: closes the #ifndef check
// why it’s used: ensures proper compilation and avoids multiple inclusion
