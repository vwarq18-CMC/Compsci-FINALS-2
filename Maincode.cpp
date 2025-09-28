#include <iostream>
#include <string>
#include <algorithm> // for max and min
#include <iomanip>   // for setprecision
using namespace std;

// Function A : GPA Converter
double myGWA(double Math_grade, double Science_grade,
             double History_grade, double English_grade,
             double Art_grade) {
    double GWA = (Math_grade + Science_grade + History_grade +
                  English_grade + Art_grade) / 5.0;
    return GWA;
}

// Function B : Directors List Check
string directorsListCheck(double gwa) {
    if (gwa <= 1.5) {  // DL means GWA 1.5 or better
        return "Congratulations! You are a DL!";
    } else {
        return "Sorry, you are not a DL this time.";
    }
}

// Function C : Input Validation
float getValidGrade() {
    float grade;
    cout << "Enter grade (0-100): ";
    cin >> grade;
    while (grade < 0 || grade > 100 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid. Enter grade (0-100): ";
        cin >> grade;
    }
    return grade; // properly closed
}

// ---------------- AB Evaluator (for grade equivalent) ----------------
float ab_Evaluator(int grade) {
    if (grade > 95) return 1.00;
    else if (grade >= 94) return 1.25;
    else if (grade >= 92) return 1.50;
    else if (grade >= 90) return 1.75;
    else if (grade >= 88) return 2.00;
    else if (grade >= 86) return 2.25;
    else if (grade >= 84) return 2.50;
    else if (grade >= 82) return 2.75;
    else if (grade >= 80) return 3.00;
    else return 5.00;
}

// ---------------- Student Class ----------------
class Student {
public:
    // Background info
    string Name;
    string first_Name;
    string middle_Name;
    string last_Name;
    string section;

    int ID;
    int age;
    int grade_level;

    // Grades
    float Math_grade, Math;
    float Science_grade, Science;
    float History_grade, History;
    float English_grade, English;
    float Art_grade, Art;

    // Grade statistics
    float average_grade;
    float highest_grade;
    float lowest_grade;
    int passing_subjects;

    // --- Input Functions ---
    void ask_name() {
        cout << "First Name: ";
        cin >> first_Name;
        cout << "Middle Name: ";
        cin >> middle_Name;
        cout << "Last Name: ";
        cin >> last_Name;
        Name = first_Name + " " + middle_Name + " " + last_Name;
    }

    void ask_ID() {
        cout << "Enter student ID: ";
        while (!(cin >> ID) || ID <= 0) {
            cout << "Invalid input. ID must be a positive number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter student ID: ";
        }
    }

    void ask_age() {
        cout << "Enter student age: ";
        while (!(cin >> age) || age <= 0 || age > 120) {
            cout << "Invalid input. Age must be 1-120.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter student age: ";
        }
    }

    void ask_grade_level() {
        cout << "Enter grade level: ";
        while (!(cin >> grade_level) || grade_level <= 0 || grade_level > 12) {
            cout << "Invalid input. Grade level must be 1-12.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter grade level: ";
        }
    }

    void ask_grades() {
        cout << "Math Grade: ";
        Math_grade = getValidGrade();
        Math = ab_Evaluator(Math_grade);

        cout << "Science Grade: ";
        Science_grade = getValidGrade();
        Science = ab_Evaluator(Science_grade);

        cout << "History Grade: ";
        History_grade = getValidGrade();
        History = ab_Evaluator(History_grade);

        cout << "English Grade: ";
        English_grade = getValidGrade();
        English = ab_Evaluator(English_grade);

        cout << "Art Grade: ";
        Art_grade = getValidGrade();
        Art = ab_Evaluator(Art_grade);
    }

    void calculateStats() {
        highest_grade = max({Math_grade, Science_grade, History_grade, English_grade, Art_grade});
        lowest_grade  = min({Math_grade, Science_grade, History_grade, English_grade, Art_grade});

        passing_subjects = 0;
        float grades[5] = {Math_grade, Science_grade, History_grade, English_grade, Art_grade};
        for (float g : grades)
            if (g >= 60) passing_subjects++;
    }

    int getBirthYear() {
        return 2025 - age;
    }

    // --- Optional: find subject name for highest/lowest ---
    string getHighestSubject() {
        if (highest_grade == Math_grade) return "Math";
        if (highest_grade == Science_grade) return "Science";
        if (highest_grade == History_grade) return "History";
        if (highest_grade == English_grade) return "English";
        if (highest_grade == Art_grade) return "Art";
        return "";
    }

    string getLowestSubject() {
        if (lowest_grade == Math_grade) return "Math";
        if (lowest_grade == Science_grade) return "Science";
        if (lowest_grade == History_grade) return "History";
        if (lowest_grade == English_grade) return "English";
        if (lowest_grade == Art_grade) return "Art";
        return "";
    }
};

// ---------------- Main ----------------
int main() {
    Student Jake;

    cout << "========================================\n";
    cout << "         STUDENT GRADE CALCULATOR\n";
    cout << "========================================\n\n";

    cout << "=== STUDENT PROFILE SETUP ===\n";
    Jake.ask_name();
    Jake.ask_ID();
    Jake.ask_age();
    Jake.ask_grade_level();
    cout << "\nProfile created successfully!\n\n";

    cout << "=== GRADE ENTRY ===\n";
    Jake.ask_grades();
    cout << "\nGrades recorded successfully!\n";

    Jake.calculateStats();
    double gwa = myGWA(Jake.Math, Jake.Science, Jake.History, Jake.English, Jake.Art);

    cout << "\n========================================\n";
    cout << "           STUDENT REPORT CARD\n";
    cout << "========================================\n\n";

    cout << "STUDENT INFORMATION:\n";
    cout << "Name: " << Jake.Name << endl;
    cout << "ID: " << Jake.ID << endl;
    cout << "Age: " << Jake.age << " years old\n";
    cout << "Grade Level: " << Jake.grade_level << endl;
    cout << "Birth Year: " << Jake.getBirthYear() << endl;

    cout << "\nSUBJECT GRADES:\n";
    cout << "Math: " << Jake.Math_grade << "%\n";
    cout << "Science: " << Jake.Science_grade << "%\n";
    cout << "History: " << Jake.History_grade << "%\n";
    cout << "English: " << Jake.English_grade << "%\n";
    cout << "Art: " << Jake.Art_grade << "%\n";

    cout << "\nGRADE STATISTICS:\n";
    cout << "Average Grade: " << gwa << "%\n";
    cout << "Highest Grade: " << Jake.highest_grade << " (" << Jake.getHighestSubject() << ")\n";
    cout << "Lowest Grade: " << Jake.lowest_grade << " (" << Jake.getLowestSubject() << ")\n";
    cout << "Subjects Passing: " << Jake.passing_subjects << " out of 5\n";

    cout << "\nGWA: " << gwa << endl;
    cout << "Director's List Status: " << directorsListCheck(gwa) << endl;

    return 0;
}
