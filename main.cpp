#include <iostream>
#include <string>
#include <queue>
#include "Calculator.h"

using namespace std;

int main () {

    Calculator calc;
    string inputEquation;
    double result;
    int command;
    char prompt;

    cout << "Enter the equation: ";
    getline(cin, inputEquation);
    cout << "Result: " << calc.calcAll(inputEquation);  

}
