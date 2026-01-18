#include "Student.h"


Student::Student() {}
Student::Student(const string& n) : name(n) {}


string Student::getName() const {
    return name;
}


void Student::addEnrolledCourse(const string& course) {
    enrolledCourses.push_back(course);
}


const vector<string>& Student::getEnrolledCourses() const {
    return enrolledCourses;
}


void Student::addRecommendation(const string& course) {
    recommendedCourses.push_back(course);
    if (recommendedCourses.size() > 3) {
        recommendedCourses.resize(3);
    }
}


vector<string> Student::getRecommendations() const {
    return recommendedCourses;
}


bool Student::hasCourse(const string& course) const {
    for (int i = 0; i < (int)enrolledCourses.size(); i++) {
        if (enrolledCourses[i] == course) return true;
    }
    return false;
}