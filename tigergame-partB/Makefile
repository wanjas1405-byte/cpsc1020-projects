CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98

TARGET = program
OBJS = main.o Student.o Course.o RecommendationSystem.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp RecommendationSystem.h Student.h Course.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Student.o: Student.cpp Student.h
	$(CXX) $(CXXFLAGS) -c Student.cpp

Course.o: Course.cpp Course.h
	$(CXX) $(CXXFLAGS) -c Course.cpp

RecommendationSystem.o: RecommendationSystem.cpp RecommendationSystem.h Student.h Course.h
	$(CXX) $(CXXFLAGS) -c RecommendationSystem.cpp

clean:
	rm -f *.o $(TARGET)
