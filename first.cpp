#include <iostream>
#include <map>
using namespace std;

int main() {
    int numCourses;
    float totalGradePoints = 0, totalCredits = 0;

    // Grade mapping (can be modified as per institution scale)
    map<string, float> gradeMap = {
        {"A", 10}, {"B", 8}, {"C", 6}, {"D", 4}, {"F", 0}
    };

    cout << "Enter number of courses: ";
    cin >> numCourses;

    for (int i = 1; i <= numCourses; ++i) {
        string grade;
        float credits;
        cout << "\nCourse " << i << ":\n";
        cout << "Enter grade (A/B/C/D/F): ";
        cin >> grade;
        cout << "Enter credit hours: ";
        cin >> credits;

        if (gradeMap.find(grade) == gradeMap.end()) {
            cout << "Invalid grade! Skipping this course.\n";
            continue;
        }

        totalGradePoints += gradeMap[grade] * credits;
        totalCredits += credits;
    }

    if (totalCredits > 0) {
        float cgpa = totalGradePoints / totalCredits;
        cout << "\nTotal Credits: " << totalCredits;
        cout << "\nFinal CGPA: " << cgpa << endl;
    } else {
        cout << "No valid courses entered.\n";
    }

    return 0;
}
