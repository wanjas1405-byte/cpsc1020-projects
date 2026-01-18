#include "RecommendationSystem.h"

RecommendationSystem::RecommendationSystem() {}

void RecommendationSystem::loadData(const string& filename) {
    ifstream file(filename.c_str());
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string studentName;
        getline(ss, studentName, ':');

        Student s(studentName);

        string rest;
        getline(ss, rest);
        stringstream ssCourses(rest);
        string course;

        while (getline(ssCourses, course, ',')) {
            if (!course.empty() && course[0] == ' ') course = course.substr(1);
            s.addEnrolledCourse(course);
            courses.insert(course);
        }

        students[studentName] = s;
    }

    file.close();
}


vector<string> RecommendationSystem::generateRecommendationsForStudent(const string& studentName) const {
    vector<string> recommendations;

    map<string,int> popularity; 

    map<string, Student>::const_iterator it = students.find(studentName);
    if (it == students.end()) return recommendations;

    const Student& student = it->second;
    const vector<string>& studentCourses = student.getEnrolledCourses();

    map<string, Student>::const_iterator otherIt;
    for (otherIt = students.begin(); otherIt != students.end(); ++otherIt) {
        if (otherIt->first == studentName) continue;

        const vector<string>& otherCourses = otherIt->second.getEnrolledCourses();

        bool overlap = false;
        for (int i = 0; i < (int)studentCourses.size(); i++) {
            for (int j = 0; j < (int)otherCourses.size(); j++) {
                if (studentCourses[i] == otherCourses[j]) {
                    overlap = true;
                    break;
                }
            }
            if (overlap) break;
        }

        if (overlap) {
            for (int i = 0; i < (int)otherCourses.size(); i++) {
                if (!student.hasCourse(otherCourses[i])) {
                    popularity[otherCourses[i]]++;
                }
            }
        }
    }

    vector<pair<string,int> > popVec;
    map<string,int>::const_iterator mit;
    for (mit = popularity.begin(); mit != popularity.end(); ++mit) {
        popVec.push_back(make_pair(mit->first, mit->second));
    }

    for (int i = 0; i < (int)popVec.size()-1; i++) {
        for (int j = i+1; j < (int)popVec.size(); j++) {
            if (popVec[i].second < popVec[j].second ||
               (popVec[i].second == popVec[j].second && popVec[i].first > popVec[j].first)) {
                pair<string,int> temp = popVec[i];
                popVec[i] = popVec[j];
                popVec[j] = temp;
            }
        }
    }

    for (int i = 0; i < (int)popVec.size() && i < 3; i++) {
        recommendations.push_back(popVec[i].first);
    }

    return recommendations;
}

void RecommendationSystem::outputRecommendations(ostream& out) const {
    int totalRecommendations = 0;

    map<string, Student>::const_iterator it;
    for (it = students.begin(); it != students.end(); ++it) {
        out << it->first << ": [";

        vector<string> recs = generateRecommendationsForStudent(it->first);
        for (int i = 0; i < (int)recs.size(); i++) {
            out << recs[i];
            if (i != (int)recs.size()-1) out << ", ";
        }
        totalRecommendations += recs.size();
        out << "]" << endl;
    }

    out << "\nTotal Students: " << getTotalStudents() << endl;
    out << "Total Courses: " << getTotalCourses() << endl;
    out << "Total Recommendations: " << totalRecommendations << endl;
}

int RecommendationSystem::getTotalStudents() const {
    return (int)students.size();
}

int RecommendationSystem::getTotalCourses() const {
    return (int)courses.size();
}

int RecommendationSystem::getTotalRecommendations() const {
    int total = 0;
    map<string, Student>::const_iterator it;
    for (it = students.begin(); it != students.end(); ++it) {
        total += generateRecommendationsForStudent(it->first).size();
    }
    return total;
}