// -------------------------------
// File: Makefile
// -------------------------------
// Purpose: Automate compilation and linking of TigerGame project
// Why: Ensures all source files are compiled and linked correctly into a single executable
// How: Defines compiler, flags, object files, and build rules for each source file

// -------------------------------
// Compiler and Flags
// -------------------------------
// Purpose: Specify which compiler to use and set compilation options
// Why: Ensures warnings are shown and optimizations are applied
CXX = g++             // Compiler: g++ for C++ files
CXXFLAGS = -Wall -O2  // Flags: -Wall for all warnings, -O2 for optimization

// -------------------------------
// Object Files
// -------------------------------
// Purpose: List all .o files required to build the executable
// Why: Each source file is compiled into an object file before linking
OBJS = main.o Card.o Deck.o Hand.o Player.o

// -------------------------------
// Default Target: Build TigerGame executable
// -------------------------------
// Purpose: Define default target when running 'make' with no arguments
// Why: Ensures Makefile builds the executable automatically
all: TigerGame
// How: Depends on TigerGame target defined below

// -------------------------------
// Link Object Files into Executable
// -------------------------------
// Purpose: Create the final TigerGame executable
// Why: Combines all compiled object files into a single program
TigerGame: $(OBJS)
	$(CXX) $(CXXFLAGS) -o TigerGame $(OBJS)
    // How: g++ links all .o files with the specified flags into executable TigerGame

// -------------------------------
// Compile main.cpp
// -------------------------------
// Purpose: Generate main.o object file from main.cpp
// Why: Separates compilation to handle dependencies individually
main.o: main.cpp Card.h Deck.h Hand.h Player.h
	$(CXX) $(CXXFLAGS) -c main.cpp
    // How: -c flag compiles source without linking

// -------------------------------
// Compile Card.cpp
// -------------------------------
// Purpose: Generate Card.o object file from Card.cpp
// Why: Needed for linking into final executable
Card.o: Card.cpp Card.h
	$(CXX) $(CXXFLAGS) -c Card.cpp
    // How: Compiles Card.cpp into Card.o

// -------------------------------
// Compile Deck.cpp
// -------------------------------
// Purpose: Generate Deck.o object file from Deck.cpp
// Why: Needed for linking into final executable
Deck.o: Deck.cpp Deck.h Card.h
	$(CXX) $(CXXFLAGS) -c Deck.cpp
    // How: Compiles Deck.cpp into Deck.o

// -------------------------------
// Compile Hand.cpp
// -------------------------------
// Purpose: Generate Hand.o object file from Hand.cpp
// Why: Needed for linking into final executable
Hand.o: Hand.cpp Hand.h Deck.h Card.h
	$(CXX) $(CXXFLAGS) -c Hand.cpp
    // How: Compiles Hand.cpp into Hand.o

// -------------------------------
// Compile Player.cpp
// -------------------------------
// Purpose: Generate Player.o object file from Player.cpp
// Why: Needed for linking into final executable
Player.o: Player.cpp Player.h Hand.h Deck.h
	$(CXX) $(CXXFLAGS) -c Player.cpp
    // How: Compiles Player.cpp into Player.o

// -------------------------------
// Clean Build
// -------------------------------
// Purpose: Remove all compiled object files and executable
// Why: Allows fresh rebuild without stale objects
clean:
	rm -f *.o TigerGame
    // How: 'rm -f' forces deletion of all .o files and TigerGame executable
