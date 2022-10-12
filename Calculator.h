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
    void printConversion(string inputEquation);
    void bracketDetect(queue<string> equationQueue);
};

void Calculator::bracketDetect(queue<string> equationQueue) {
    
} 

void Calculator::toStringQueue(string inputEquation) {
    
    string tempNum = "", tempSymbol = "";

    while (!inputEquation.empty()) {
        if (inputEquation.front() == ' ' || inputEquation.front() == '+') {
            inputEquation.erase (inputEquation.begin());
        } else if (isdigit(inputEquation.front()) || inputEquation.front() == '-') {
            tempNum += inputEquation.front();
            inputEquation.erase (inputEquation.begin());
        } else if (inputEquation.front() == '('){
            tempSymbol += inputEquation.front();
            equationQueue.push(tempSymbol);
            inputEquation.erase (inputEquation.begin());
            tempSymbol = "";
        }

        if (inputEquation.front() == '-' || inputEquation.front() == '+' || inputEquation.empty()) {
            equationQueue.push(tempNum);
            tempNum = "";
        } else if (inputEquation.front() == ')') {
            equationQueue.push(tempNum);
            tempNum = "";
            tempSymbol += inputEquation.front();
            equationQueue.push(tempSymbol);
            inputEquation.erase (inputEquation.begin());
            tempSymbol = "";
        }
    }
}

// For testing purpose
void Calculator::printConversion(string inputEquation) {
    
    toStringQueue(inputEquation);
    
    while (!equationQueue.empty()) {
        cout << equationQueue.front() << " ";
        equationQueue.pop();
    }
}

// double Calculator::calculate(string inputEquation) {

//     toStringQueue(inputEquation);

//     while (!equationQueue.empty()) {
//         finalResult += stod(equationQueue.front());
//         equationQueue.pop();
//     }

//     return finalResult;
// }

#endif