#ifndef RECOMMENDATIONSYSTEM_H
#define RECOMMENDATIONSYSTEM_H

#include "Student.h"
#include "Course.h"
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


class RecommendationSystem {
private:
    map<string, Student> students; 
    set<string> courses;         

public:
    RecommendationSystem();

    void loadData(const string& filename);
    vector<string> generateRecommendationsForStudent(const string& studentName) const;
    void outputRecommendations(ostream& out) const;

    int getTotalStudents() const;
    int getTotalCourses() const;
    int getTotalRecommendations() const;
};

#endif