
#include <iostream>
using namespace std;


float ab_Evaluator(int grade) {
    

    int grade;
    cout << "Input a numerical grade: ";
    cin >> grade;
    
    
    if (grade > 95) {
        return 1.00;
    }

    else if (grade < 96 && grade > 93) {
        return 1.25;
    }
    
    else if (grade < 94 && grade > 91) {
        return 1.50;
    }
    
    else if (grade < 92 && grade > 89) {
        return 1.75;
    }
    
    else if (grade < 90 && grade > 87) {
        return 2.00;
    }
    
    else if (grade < 88 && grade > 85) {
        return 2.25;
    }
    
    else if (grade < 86 && grade > 83) {
        return 2.50;
    }
    
    else if (grade < 84 && grade > 81) {
        return 2.75;
    }
    
    else if (grade < 82 && grade > 79) {
        return 3.00;
    }
    
    else if (grade < 80) {
        return 5.00;
    }
    
    else {
        return 0;
    };
    
}

int main() {
    
    cout << gradeConverter() << endl;
    return 0;

}

}


void verify_num() {
    
    
    
}

class Student {
    
    public:
    
    //background info
    
    string Name;
    string first_Name;
    string middle_Name;
    string last_Name;
    string section;
    
    int ID;
    int grade_level;
    int age;
    
    //Grades
    float Math_grade;    float Math;
    float Science_grade; float Science;
    float History_grade; float History;
    float English_grade; float English;
    float Art_grade;     float Art;
    
    //Grade statistics
    
    float average_grade;
    float highest_grade;
    float lowest_grade;
    
    int passing_subjects;
    
    
    void ask_name() { 
        
        cout<< "First Name: "; 
        cin >> first_Name; 
        cout<< "Middle Name: "; 
        cin >> middle_Name;
        cout<< "Last Name: "; 
        cin >> last_Name; 
    
        Name = first_Name + " " + middle_Name + " " + last_Name;
    }
    
    void ask_grades() {
        
        cout << "Math Grade: ";
        cin >> Math_grade;
        Math = ab_Evaluator(Math_grade);
        
        cout << "Science Grade: ";
        cin >> Science_grade;
        Science = ab_Evaluator(Science_grade);
        
        cout << "History Grade: ";
        cin >> History_grade;
        History = ab_Evaluator(History_grade);
        
        cout << "English: ";
        cin >> English_grade;
        English = ab_Evaluator(English_grade);
        
        cout << "Art: ";
        cin >> Art_grade;
        Art = ab_Evaluator(Art_grade);
    }
    
    
    
};


int main()
{
    Student Jake;
    
    Jake.ask_name();
    Jake.ask_grades();
    
    cout << "Name: " << Jake.Name << Jake.Art;
}
