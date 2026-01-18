# Compiler
CXX = g++
# what it does: sets the C++ compiler to use (g++)
# why it’s used: tells make which compiler to invoke

CXXFLAGS = -std=c++11 -Wall
# what it does: sets compiler flags
# why it’s used: -std=c++11 enables C++11 standard features
# why it’s used: -Wall turns on all compiler warnings to catch potential issues

# Target executable
TARGET = main.out
# what it does: defines the name of the final compiled program
# why it’s used: allows easy reference to the executable in build rules

# Source files
SRC = main.cpp QA.cpp buildResultString.cpp
# what it does: lists all the source files needed to compile the program
# why it’s used: ensures all relevant files are compiled and linked together

# Header files
HEADERS = QA.h buildResultString.h
# what it does: lists all the header files
# why it’s used: so that make knows the executable depends on these headers

# Default rule
all: $(TARGET)
# what it does: defines the default target to build when "make" is run
# why it’s used: ensures that running "make" builds the main.out executable

# Compile the executable
$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)
# what it does: rule to compile the source files into the target executable
# why it’s used: ensures proper compilation order and linking of sources and headers

# Clean object files and executable
clean:
	rm -f $(TARGET)
# what it does: deletes the executable (and any object files if present)
# why it’s used: allows a clean rebuild without old binaries interfering
