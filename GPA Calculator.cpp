#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Course {
    string name;
    int creditHours;
    char grade;
    double gradePoint;
};

// Function to convert grade to grade point
double getGradePoint(char grade) {
    switch (toupper(grade)) {
    case 'A': return 4.0;
    case 'B': return 3.0;
    case 'C': return 2.0;
    case 'D': return 1.0;
    case 'F': return 0.0;
    default: return -1; // Invalid grade
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    cin.ignore(); // Ignore the newline character

    vector<Course> courses(numCourses);
    double totalGradePoints = 0.0, totalCredits = 0.0;

    for (int i = 0; i < numCourses; i++) {
        system("CLS");
        cout << "Enter course " << i + 1 << " name: ";
        getline(cin, courses[i].name);

        do {
            cout << "Enter credit hours for " << courses[i].name << " (1-3): ";
            cin >> courses[i].creditHours;
            if (courses[i].creditHours < 1 || courses[i].creditHours > 3) {
                cout << "Invalid credit hours! Please enter a value between 1 and 3.\n";
            }
        } while (courses[i].creditHours < 1 || courses[i].creditHours > 3);

        do {
            cout << "Enter grade (A, B, C, D, F) for " << courses[i].name << ": ";
            cin >> courses[i].grade;
            cin.ignore(); // Ignore the newline character

            courses[i].gradePoint = getGradePoint(courses[i].grade);
            if (courses[i].gradePoint == -1) {
                cout << "Invalid grade! Please enter a valid grade (A, B, C, D, F).\n";
            }
        } while (courses[i].gradePoint == -1);

        totalGradePoints += courses[i].gradePoint * courses[i].creditHours;
        totalCredits += courses[i].creditHours;
    }

    double GPA = totalGradePoints / totalCredits;

    system("CLS");
    cout << "\nCourse Details:\n";
    cout << left << setw(15) << "Course" << setw(10) << "Credits" << setw(10) << "Grade" << "Grade Point\n";
    cout << "------------------------------------------------\n";
    for (const auto& course : courses) {
        cout << left << setw(15) << course.name << setw(10) << course.creditHours << setw(10) << course.grade << course.gradePoint << "\n";
    }
    cout << "------------------------------------------------\n";
    cout << "Total Credits: " << totalCredits << "\n";
    cout << "Total Grade Points: " << totalGradePoints << "\n";
    cout << fixed << setprecision(2) << "Semester GPA: " << GPA << "\n";
    return 0;
}