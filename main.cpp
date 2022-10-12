#include "calculator.h"

int main () {

    Calculator calc;
    string inputEquation;
    double result;
    int command;
    char prompt;

    cout << "Enter the equation: ";
    getline(cin, inputEquation);
    cout << "Result: " << calc.calculate(inputEquation);  

}
