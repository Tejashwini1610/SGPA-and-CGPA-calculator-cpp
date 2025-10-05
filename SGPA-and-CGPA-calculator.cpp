#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// ---------- Function to calculate SGPA ----------
double calculateSGPA() {
    int numCourses;
    cout << "\nEnter the number of courses: ";
    cin >> numCourses;

    vector<double> credits(numCourses), grades(numCourses);
    double totalCredits = 0, totalGradePoints = 0;

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << i + 1 << " details:\n";
        cout << "Enter credit points: ";
        cin >> credits[i];

        cout << "Enter grade point (0 - 10): ";
        cin >> grades[i];

        totalCredits += credits[i];
        totalGradePoints += credits[i] * grades[i];
    }

    cout << "\n\n---------------- Results ----------------\n";
    cout << left << setw(10) << "Course"
         << setw(15) << "Credits"
         << setw(15) << "Grade Point"
         << setw(15) << "Credit Point" << endl;

    for (int i = 0; i < numCourses; ++i) {
        cout << left << setw(10) << (i + 1)
             << setw(15) << credits[i]
             << setw(15) << grades[i]
             << setw(15) << credits[i] * grades[i] << endl;
    }

    double sgpa = (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0;

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Semester GPA (SGPA): " << fixed << setprecision(2) << sgpa << endl;

    return sgpa;
}



// ---------- Function to calculate CGPA ----------
double calculateCGPA() {
    int semesters;
    cout << "\nEnter the number of semesters: ";
    cin >> semesters;

    double totalPoints = 0;
    int totalCredits = 0;

    for (int i = 1; i <= semesters; ++i) {
        double sgpa;
        int credits;

        cout << "\nSemester " << i << " details:\n";
        cout << "Enter SGPA: ";
        cin >> sgpa;
        cout << "Enter total credit points for this semester: ";
        cin >> credits;

        totalPoints += sgpa * credits;
        totalCredits += credits;
    }

    double cgpa = (totalCredits > 0) ? (totalPoints / totalCredits) : 0;

    cout << "\nCumulative GPA (CGPA): " << fixed << setprecision(2) << cgpa << endl;

    return cgpa;
}



// ---------- Main Function with Menu ----------
int main() {
    int choice;

    do {
        cout << "\n\n========== GPA and CGPA Calculator ==========\n";
        cout << "1. Calculate Semester Grade Point Average (SGPA)\n";
        cout << "2. Calculate Cumulative Grade Point Average (CGPA)\n";
        cout << "3. Exit\n";
        cout << "--------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                calculateSGPA();
                break;
            case 2:
                calculateCGPA();
                break;
            case 3:
                cout << "\nThank you for using the GPA & CGPA Calculator!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 3);

    cout << "--------------------------------------------\n";
    cout << "Program ended successfully.\n";
    return 0;
}
