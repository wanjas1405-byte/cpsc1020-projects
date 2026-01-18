// Include standard input/output library to print messages to console
#include <iostream>  // what it does: allows using std::cout and std::cin
                   // why it’s used: needed to display questions, results, and prompts

// Include file stream library to read input files (database.txt)
#include <fstream>   // what it does: allows reading files with std::ifstream
                   // why it’s used: needed to read questions and answers from database.txt

// Include vector library to store multiple QA objects dynamically
#include <vector>    // what it does: provides the std::vector container
                   // why it’s used: stores all QA objects so we can iterate and shuffle

// Include ctime library to get the current time for random seed
#include <ctime>     // what it does: provides time() function
                   // why it’s used: used to seed the random number generator for shuffling

// Include cstdlib library for rand() and srand() to generate random numbers
#include <cstdlib>   // what it does: provides rand() and srand()
                   // why it’s used: allows shuffling questions randomly

// Include QA class header to create QA objects and use its member functions
#include "QA.h"      // what it does: includes the QA class
                   // why it’s used: needed to create QA objects and access getAnswer(), getQuestion(), etc.

// Include buildResultString function to construct the final quiz result string
#include "buildResultString.h" // what it does: declares buildResultString()
                            // why it’s used: used to format and print final results with score

// Program entry point
int main(int argc, char* argv[]) { // what it does: main function executed when program runs
                                   // why it’s used: starting point of program execution

    // Check if the user has provided the input database file as a command-line argument
    if (argc < 2) {
        // what it does: checks if less than 2 arguments (program name + file)
        // why it’s used: ensures the program has a file to read, otherwise exits

        // If not, print usage instructions and exit
        std::cout << "Usage: " << argv[0] << " [database file]\n"; 
        return 1; // exit program if no file is provided
    }

    // Open the database file provided by the user
    std::ifstream inputFile(argv[1]); // what it does: opens the file using filename from argv[1]
                                     // why it’s used: to read questions and answers from the input file

    // Check if the file was successfully opened
    if (!inputFile) {
        // what it does: checks if file failed to open
        // why it’s used: prevents program from continuing with an invalid file

        // Print an error message if the file cannot be opened and exit
        std::cout << "Error opening file: " << argv[1] << "\n";
        return 1;
    }

    // Vector to store all QA objects (each question-answer pair)
    std::vector<QA> quizVector; // what it does: creates dynamic array of QA objects
                                // why it’s used: store all questions and answers to iterate and shuffle

    // Temporary variables to store each line read, the question, and the answer
    std::string line, question, answer; // what it does: store file lines, current question, and current answer
                                        // why it’s used: needed to parse the file and create QA objects

    // Read the file line by line
    while (std::getline(inputFile, line)) { // what it does: reads each line from the file
                                            // why it’s used: to detect "Question:" and "Answer:" lines

        // Check if the line starts with "Question:"
        if (line.find("Question:") == 0) {
            // Extract the question text (everything after "Question:")
            question = line.substr(9);  // what it does: removes "Question:" from the line
                                        // why it’s used: only the actual question text is needed for QA object
        } 
        // Check if the line starts with "Answer:"
        else if (line.find("Answer:") == 0) {
            // Extract the answer text (everything after "Answer:")
            answer = line.substr(7);    // what it does: removes "Answer:" from the line
                                        // why it’s used: only the answer text is needed for QA object

            // Create a QA object using the parameterized constructor with member initializer
            quizVector.push_back(QA(question, answer)); 
            // what it does: constructs QA object and adds it to vector
            // why it’s used: stores each question-answer pair for later use
        }
    }

    // Close the input file after reading all questions and answers
    inputFile.close(); // what it does: closes the file
                       // why it’s used: good practice to release file resources

    // Initialize the random number generator using current time
    srand(unsigned(time(0))); 
    // what it does: seeds the random number generator with current time
    // why it’s used: ensures the shuffle produces different results each run

    // Shuffle the questions to randomly select question order
    for (size_t i = 0; i < quizVector.size(); i++) {
        // Generate a random index within the bounds of the vector
        size_t randomIndex = rand() % quizVector.size(); // what it does: selects random index
                                                         // why it’s used: allows swapping for random order

        // Swap the current question with the randomly chosen question
        QA temp = quizVector[i];                  
        quizVector[i] = quizVector[randomIndex]; 
        quizVector[randomIndex] = temp;         
        // what it does: performs the swap
        // why it’s used: shuffles vector to randomize question order
    }

    // Initialize counters for correct and wrong answers
    int correctCount = 0; // what it does: counts correct answers
    int wrongCount = 0;   // what it does: counts wrong answers
                          // why it’s used: needed for final result display

    // Variable to store the player's answer
    std::string playerAnswer; // what it does: stores user input
                               // why it’s used: needed to compare with correct answer

    // Loop through all QA objects in the shuffled quiz vector
    for (size_t i = 0; i < quizVector.size(); i++) {
        QA& currentQA = quizVector[i]; // what it does: reference current QA object
                                       // why it’s used: makes accessing question and answer easier

        // Display the current question
        std::cout << quizVector[i].getQuestion() << "\n"; 
        // what it does: prints question to console
        // why it’s used: shows player what to answer

        // Prompt the player to input their answer
        std::cout << "Type in your answer: ";
        std::getline(std::cin, playerAnswer); // what it does: reads full line input
                                               // why it’s used: allows answers with spaces

        // Check if player's answer matches the correct answer (case-sensitive)
        if (playerAnswer == quizVector[i].getAnswer()) {
            std::cout << "Correct!\n"; // what it does: informs player
                                        // why it’s used: feedback for correct answer

            QA::updateScore(1); // what it does: increments static score
                                 // why it’s used: correct answer increases score

            correctCount++;      // what it does: increment correct counter
                                 // why it’s used: needed for result summary
        } else {
            std::cout << "Wrong! Correct answer: " << quizVector[i].getAnswer() << "\n"; 
            // what it does: informs player of wrong answer and shows correct answer
            // why it’s used: feedback for wrong answer

            QA::updateScore(-1); // what it does: decrements static score but not below zero
                                  // why it’s used: incorrect answer decreases score

            wrongCount++;         // what it does: increment wrong counter
                                  // why it’s used: needed for result summary
        }

        // Display the current score after each question
        std::cout << "Current score: " << QA::getScore() << "\n\n"; 
        // what it does: prints score
        // why it’s used: lets player track progress
    }

    // After all questions are answered, build the result string using buildResultString
    std::cout << buildResultString(quizVector.size(), correctCount, wrongCount) << "\n"; 
    // what it does: constructs final summary string with total questions, correct, wrong, and score
    // why it’s used: clean output and meets assignment requirement

    // Exit the program successfully
    return 0; // what it does: terminates main function
              // why it’s used: indicates program ran successfully
