#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Course {
    string courseNumber;
    string title;
    vector<string> prerequisites;
};

// Algorithm to Print All Courses in Alphanumeric Order (Vector)
void printCourses(vector<Course>& courses) {
    // Sort the vector of course objects based on course number
    sort(courses.begin(), courses.end(), [](Course a, Course b) {
        return a.courseNumber < b.courseNumber;
    });
    
    // For each course object in the vector, print the course information
    for (Course c : courses) {
        cout << c.courseNumber << ", " << c.title;
        if (c.prerequisites.size() > 0) {
            cout << endl << "Prerequisites: ";
            for (string p : c.prerequisites) {
                cout << p << " ";
            }
        }
        cout << endl;
    }
}

// Algorithm to Print a Given Course's Title and Prerequisites (Vector)
void printCourseInfo(string courseNumber, vector<Course>& courses) {
    bool found = false;
    // Use a for loop to iterate through the vector of course objects
    for (Course c : courses) {
        // Within the for loop, use an if statement to check if the course number of the current course object matches the given course number
        if (c.courseNumber == courseNumber) {
            // If the course number matches, print the course title and prerequisites
            cout << c.courseNumber << ", " << c.title << endl;
            if (c.prerequisites.size() > 0) {
                cout << "Prerequisites: ";
                for (string p : c.prerequisites) {
                    cout << p << " ";
                }
            }
            cout << endl;
            found = true;
            break;
        }
    }
    // If the course is not found, print "Course not found"
    if (!found) {
        cout << "Course not found" << endl;
    }
}

int main() {
    vector<Course> courses = {
        {"CSCI100", "Introduction to Computer Science", {"", ""}},
        {"CSCI101", "Introduction to Programming in C++", {"CSCI100"}},
        {"CSCI200", "Data Structures", {"CSCI101"}},
        {"MATH201", "Discrete Mathematics", {"", ""}},
        {"CSCI300", "Introduction to Algorithms", {"CSCI200", "MATH201"}},
        {"CSCI301", "Advanced Programming in C++", {"CSCI101"}},
        {"CSCI350", "Operating Systems", {"CSCI300"}},
        {"CSCI400", "Large Software Development", {"CSCI301", "CSCI350"}}
    };
    
    printCourses(courses);
    printCourseInfo("CSCI400", courses);
    
    return 0;
}
