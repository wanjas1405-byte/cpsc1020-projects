#include "Student.h"


Student::Student() {}
Student::Student(const string& studentName) : name(studentName) {}


string Student::getName() const {
    return name;
}


void Student::addEnrolledCourse(const string& course) {
    enrolledCourses.push_back(course);
}


const vector<string>& Student::getEnrolledCourses() const {
    return enrolledCourses;
}


bool Student::hasCourse(const string& course) const {
    for (int i = 0; i < (int)enrolledCourses.size(); i++) {
        if (enrolledCourses[i] == course) return true;
    }
    return false;
}
