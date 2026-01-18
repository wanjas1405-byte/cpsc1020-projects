#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course {
private:
    string id;

public:
    Course();
    Course(const string& courseId);

    string getId() const;
};

#endif