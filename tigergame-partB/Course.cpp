#include "Course.h"


Course::Course() {}
Course::Course(const string& courseId) : id(courseId) {}

string Course::getId() const {
    return id;
}

bool Course::operator==(const Course& other) const {
    return id == other.id;
}

bool Course::operator<(const Course& other) const {
    return id < other.id;
}
