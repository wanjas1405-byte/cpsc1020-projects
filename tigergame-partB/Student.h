#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;


class Student {
private:
    string name;                       
    vector<string> enrolledCourses;    
    vector<string> recommendedCourses;  

public:
    Student();                  
    Student(const string& n);    

    string getName() const;

    void addEnrolledCourse(const string& course);   
    const vector<string>& getEnrolledCourses() const;

    void addRecommendation(const string& course);   
    vector<string> getRecommendations() const;

    bool hasCourse(const string& course) const;     
};

#endif
