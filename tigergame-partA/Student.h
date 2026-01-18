#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    vector<string> enrolledCourses;

public:
    Student();
    Student(const string& studentName);

    string getName() const;
    void addEnrolledCourse(const string& course);
    const vector<string>& getEnrolledCourses() const;

    bool hasCourse(const string& course) const;
};

#endif
