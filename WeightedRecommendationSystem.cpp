#include "WeightedRecommendationSystem.h"
#include <fstream>
#include <sstream>

WeightedRecommendationSystem::WeightedRecommendationSystem() {}

void WeightedRecommendationSystem::loadData(const string& filename) {
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
        string courseAndWeight;

        while (getline(ssCourses, courseAndWeight, ',')) {
        
            if (!courseAndWeight.empty() && courseAndWeight[0] == ' ')
                courseAndWeight = courseAndWeight.substr(1);

    
            int colonPos = -1;
            for (int i = 0; i < (int)courseAndWeight.size(); i++) {
                if (courseAndWeight[i] == ':') {
                    colonPos = i;
                    break;
                }
            }

            string course = courseAndWeight.substr(0, colonPos);
            s.addEnrolledCourse(course);

   
            bool found = false;
            for (int i = 0; i < (int)allCourses.size(); i++) {
                if (allCourses[i] == course) { found = true; break; }
            }
            if (!found) allCourses.push_back(course);
        }

        students.push_back(s);
    }

    file.close();
}

vector<pair<string,int> > WeightedRecommendationSystem::generateRecommendationsForStudent(const Student& s) const {
    vector<pair<string,int> > recs;

    for (int i = 0; i < (int)allCourses.size(); i++) {
        string course = allCourses[i];

      
        if (s.hasCourse(course)) continue;

        int score = 0;

        for (int j = 0; j < (int)students.size(); j++) {
            if (students[j].getName() == s.getName()) continue;

            const vector<string>& otherCourses = students[j].getEnrolledCourses();
            bool overlap = false;
            for (int k = 0; k < (int)otherCourses.size(); k++) {
                for (int l = 0; l < (int)s.getEnrolledCourses().size(); l++) {
                    if (otherCourses[k] == s.getEnrolledCourses()[l]) {
                        overlap = true;
                        break;
                    }
                }
                if (overlap) break;
            }

            if (overlap) {
                for (int w = 0; w < (int)otherCourses.size(); w++) {
                    if (otherCourses[w] == course) {
                        
                        score += 1;
                    }
                }
            }
        }

        recs.push_back(make_pair(course, score));
    }


    for (int i = 0; i < (int)recs.size() - 1; i++) {
        for (int j = i+1; j < (int)recs.size(); j++) {
            if (recs[i].second < recs[j].second ||
               (recs[i].second == recs[j].second && recs[i].first > recs[j].first)) {
                pair<string,int> temp = recs[i];
                recs[i] = recs[j];
                recs[j] = temp;
            }
        }
    }

    return recs;
}

void WeightedRecommendationSystem::outputRecommendations(ostream& out) const {
    int totalRecs = 0;

    for (int i = 0; i < (int)students.size(); i++) {
        out << students[i].getName() << ": [";
        vector<pair<string,int> > recs = generateRecommendationsForStudent(students[i]);

        for (int j = 0; j < (int)recs.size(); j++) {
            out << recs[j].first << ":" << recs[j].second;
            if (j != (int)recs.size()-1) out << ", ";
            totalRecs++;
        }
        out << "]" << endl;
    }

    out << "\nTotal Students: " << getTotalStudents() << endl;
    out << "Total Courses: " << getTotalCourses() << endl;
    out << "Total Recommendations: " << totalRecs << endl;
}

int WeightedRecommendationSystem::getTotalStudents() const {
    return (int)students.size();
}

int WeightedRecommendationSystem::getTotalCourses() const {
    return (int)allCourses.size();
}

int WeightedRecommendationSystem::getTotalRecommendations() const {
    int total = 0;
    for (int i = 0; i < (int)students.size(); i++) {
        total += generateRecommendationsForStudent(students[i]).size();
    }
    return total;
}