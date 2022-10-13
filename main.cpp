#include "calculator.h"

int main()
{
    string inputEquation;
    double result;
    int command;
    char prompt;

    cout << "Enter the equation: ";
    getline(cin, inputEquation);
    Calculator calculator(inputEquation);
    // cout << "Result: " << calculator.calculate();
    cout << "Result: ";
    calculator.printConversion();
}
