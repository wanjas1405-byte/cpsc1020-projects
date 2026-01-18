// Include the header file for this function
#include "buildResultString.h"  
// what it does: includes the declaration of buildResultString
// why it’s used: ensures the compiler knows the function signature before defining it

// Include QA class to access static score
#include "QA.h"                  
// what it does: includes the QA class definition
// why it’s used: buildResultString uses QA::getScore() to display the final score

// Include stringstream library to build string efficiently
#include <sstream>               
// what it does: includes std::ostringstream
// why it’s used: allows building strings piece by piece efficiently

// Function that constructs a formatted result string for the quiz
// Inputs: total questions, correct answers, wrong answers
std::string buildResultString(int questions, int correct, int wrong) {
    
    // Create a string stream to build the result string
    std::ostringstream result;  
    // what it does: creates an empty string stream object
    // why it’s used: allows concatenating multiple pieces of text and numbers into one string

    // Add number of questions to the result string
    result << "Number of questions: " << questions << "\n";  
    // what it does: appends total questions to the string
    // why it’s used: informs the player how many questions were asked

    // Add number of correct answers to the result string
    result << "Number correct answers: " << correct << "\n"; 
    // what it does: appends correct answers count
    // why it’s used: shows the player their correct responses

    // Add number of wrong answers to the result string
    result << "Number wrong answers: " << wrong << "\n";     
    // what it does: appends wrong answers count
    // why it’s used: shows the player their incorrect responses

    // Add the final score (from QA static score) to the result string
    result << "Final score: " << QA::getScore();             
    // what it does: appends the current static score from QA class
    // why it’s used: gives the player their final score at the end of the quiz

    // Convert the string stream to a standard string and return it
    return result.str();                                       
    // what it does: converts the string stream to a std::string
    // why it’s used: allows returning the final formatted result to main for printing
}
