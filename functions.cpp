fFUNCTIONS:


FUNCTION A: GPA Converter



double myGWA() {
    
    GWA = (Math_grade + Science_grade + History_grade + English_grade + Art_grade) / 5;
    
    return GWA;

}




FUNCTION B: DL Check


string directorsListCheck(double gwa) {
   
 if (gwa >= 1.5) {
        return "Congratulations! You are a DL!";
} 
    else { 
        return "Sorry, you are not a DL this time.";
}



FUNCTION C: Input Validation



float getValidGrade() {
    float grade;

    cout << "Enter grade (0–100): ";
    cin >> grade;

    while (grade < 0 || grade > 100) {
        cout << "Invalid. Enter grade (0–100): ";
        cin >> grade;
    }

    return grade;
}


  cout << "Please enter first number" << endl;
   if (cin >> firstNumber) {
       
        cout << "Choose a symbol (+, -, *, /)" << endl;
       
        if (cin >> operationSymbol) {
           
            cout << "Please enter your second number below:" << endl;
           
            if (cin >> secondNumber) {
            program(firstNumber, secondNumber, operationSymbol);
            } else { cout << "Invalid"; while_thing = 1;};
           
        } else { cout << "Invalid"; while_thing = 1;};
           
    }  else { cout << "Invalid"; while_thing = 1;};    
     



