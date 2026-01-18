# Jason Wan
# 9/7/25
# Makefile for COVID Self Test Program
# Purpose: Compile and link main.cpp, Date.cpp, and calcDays.cpp into an executable

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target executable name
TARGET = covidTest

# Source files
SRC = main.cpp Date.cpp calcDays.cpp

# Object files (one .o per .cpp)
OBJ = $(SRC:.cpp=.o)

# ------------------------------------------------------
# all: Default target to build the program
# 1. Compile source files into object files
# 2. Link object files into the executable $(TARGET)
all: $(TARGET)

# Target to link object files into the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
# Removes all .o files and the executable
clean:
	rm -f $(OBJ) $(TARGET)