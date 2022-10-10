#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Calculator {
    public:
        int index, end, digitCount1;
        queue<char> firstResult;
        queue<string> result;
        string firstNum, secondNum;

        double calcAll(string result);
        queue<string> calculate(queue<char> equation);
        queue<char> stringToCharQ(string equation);

};

queue<char> Calculator::stringToCharQ(string equation) {
    
    queue<char> equationChar;

    for (int i = 0; i < equation.size(); i++) {
        equationChar.push(equation[i]);
    }
    
    return equationChar;
} 

queue<string> Calculator::calculate(queue<char> equation) {
    
    queue<char> tempNumQueue;
    queue<string> result;
    string tempNum = "";

    while (!equation.empty()) {
        if (equation.front() == ' ' || equation.front() == '+') {
            equation.pop();
        } else if (isdigit(equation.front()) || equation.front() == '-') {
            tempNum += equation.front();
            equation.pop();
        }

        if (equation.front() == '-' || equation.front() == '+' || equation.empty()) {
            result.push(tempNum);
            tempNum = "";
        }
    }
    
    return result;
}

double Calculator::calcAll(string equation) {
    
    double finalResult;

    queue<string> result = calculate(stringToCharQ(equation));

    while (!result.empty()) {
        finalResult += stod(result.front());
        result.pop();
    }

    return finalResult;
}

#endif