#ifndef WEIGHTEDRECOMMENDATIONSYSTEM_H
#define WEIGHTEDRECOMMENDATIONSYSTEM_H

#include "Student.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class WeightedRecommendationSystem {
private:
    vector<Student> students;
    vector<string> allCourses;

public:
    WeightedRecommendationSystem();

    void loadData(const string& filename);
    vector<pair<string,int> > generateRecommendationsForStudent(const Student& s) const;
    void outputRecommendations(ostream& out) const;

    int getTotalStudents() const;
    int getTotalCourses() const;
    int getTotalRecommendations() const;
};

#endif
