// Prevent multiple inclusions of this header file
#ifndef BUILDRESULTSTRING_H  // what it does: starts a header guard
                             // why it’s used: prevents double inclusion errors during compilation
#define BUILDRESULTSTRING_H  // what it does: defines the header guard

// Include the string library for using std::string
#include <string>            // what it does: allows using std::string type
                             // why it’s used: buildResultString returns a string

// Include QA class to access score (friend function will use private members if needed)
#include "QA.h"              // what it does: includes the QA class
                             // why it’s used: buildResultString is declared as a friend of QA, so it can access the static score

// Declare a function that builds a result string summarizing quiz outcomes
// Takes total questions, correct answers, and wrong answers as parameters
std::string buildResultString(int questions, int correct, int wrong); 
// what it does: declares a function to generate a formatted string with quiz results
// why it’s used: provides a single reusable function to display final results

// End the header guard
#endif                       // what it does: closes the header guard
                             // why it’s used: ensures the file content is included only once