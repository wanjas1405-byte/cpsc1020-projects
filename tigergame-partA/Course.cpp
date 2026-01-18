#include "Course.h"

Course::Course() {}
Course::Course(const string& courseId) : id(courseId) {}

string Course::getId() const {
    return id;
}
