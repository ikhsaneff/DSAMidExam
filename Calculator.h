#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Calculator {
public:
    string inputEquation;
    queue<string> equationQueue;
    void toStringQueue(string inputEquation);
    double finalResult;
    double calculate(string inputEquation);
};

void Calculator::toStringQueue(string inputEquation) {
    
    string tempNum = "";

    while (!inputEquation.empty()) {
        if (inputEquation.front() == ' ' || inputEquation.front() == '+') {
            inputEquation.erase (inputEquation.begin());
        } else if (isdigit(inputEquation.front()) || inputEquation.front() == '-') {
            tempNum += inputEquation.front();
            inputEquation.erase (inputEquation.begin());
        }

        if (inputEquation.front() == '-' || inputEquation.front() == '+' || inputEquation.empty()) {
            equationQueue.push(tempNum);
            tempNum = "";
        }
    }
}

double Calculator::calculate(string inputEquation) {

    toStringQueue(inputEquation);

    while (!equationQueue.empty()) {
        finalResult += stod(equationQueue.front());
        equationQueue.pop();
    }

    return finalResult;
}

#endif