// Include the QA class header file
#include "QA.h"  
// what it does: includes the class declaration of QA
// why it’s used: allows defining all member functions and accessing private members

// Include cctype for character classification functions like isalpha()
#include <cctype>  
// what it does: provides functions to check character types
// why it’s used: used in letterCount() to count only alphabetic letters

// Initialize static score variable for all QA objects to 0
int QA::score = 0;  
// what it does: defines the static variable score shared by all QA objects
// why it’s used: keeps track of the total score across all quiz questions

// Default constructor: sets question and answer to empty strings
QA::QA() {  
    question = "";  
    answer = "";  
}  
// what it does: initializes a QA object with empty question and answer
// why it’s used: ensures QA objects start with valid empty strings, avoids uninitialized data

// Parameterized constructor: sets question and answer to provided strings
QA::QA(const std::string& q, const std::string& a) {  
    question = q;  
    answer = a;  
}  
// what it does: initializes a QA object with specific question and answer
// why it’s used: allows creating a QA object directly from a file line

// Getter for question text
std::string QA::getQuestion() const {  
    return question;  
}  
// what it does: returns the question string of the object
// why it’s used: allows main program to access question text safely

// Getter for answer text
std::string QA::getAnswer() const {  
    return answer;  
}  
// what it does: returns the answer string of the object
// why it’s used: allows main program to check user input against the correct answer

// Static function to return current score
int QA::getScore() {  
    return score;  
}  
// what it does: returns the current value of the static score
// why it’s used: allows main program and buildResultString to access the current score

// Function to count letters in question and answer
int QA::letterCount() const {  
    int count = 0; // initialize letter count to 0

    // Loop through question string
    for (size_t i = 0; i < question.length(); i++) {  
        if (isalpha(question[i])) count++;  
        // what it does: checks if character is a letter, increments count
        // why it’s used: only letters are counted, ignoring spaces/punctuation
    }

    // Loop through answer string
    for (size_t i = 0; i < answer.length(); i++) {  
        if (isalpha(answer[i])) count++;  
        // same purpose as above for the answer string
    }

    return count; // return total number of letters
    // what it does: gives the total count of letters in question and answer
    // why it’s used: can be used to analyze question complexity or scoring metrics
}

// Static function to update score by a given value
void QA::updateScore(int val) {  
    score += val; // add val to score
    // what it does: changes score by val (positive or negative)
    // why it’s used: updates score after each question

    if (score < 0) { // ensure score does not go negative
        score = 0;   // set score to 0 if negative
        // what it does: prevents score from being negative
        // why it’s used: ensures score logic matches assignment specification
    }
}