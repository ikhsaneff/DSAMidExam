#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Calculator
{
public:
    string inputEquation;
    queue<string> equationQueue;
    void toStringQueue(string inputEquation);
    double finalResult;
    double calculate(string inputEquation);
    void printConversion(string inputEquation);
    void bracketDetect(queue<string> equationQueue);
};

void Calculator::bracketDetect(queue<string> equationQueue)
{
}

//@Definition:
void Calculator::toStringQueue(string inputEquation)
{

    string tempNum = "", tempSymbol = "";

    for (int i = 0; i < inputEquation.size(); i++)
    {
        char current_index = inputEquation[i];
        if (isdigit(current_index) || current_index == '-')
        {
            tempNum += current_index;
        }
        else if (current_index == '(')
        {
            string temp(1, current_index);
            equationQueue.push(temp);
        }

        if (inputEquation[i + 1] == '-' || current_index == '+')
        {
            equationQueue.push(tempNum);
            tempNum = "";
        }
        else if (current_index == ')')
        {
            equationQueue.push(tempNum);
            tempNum = "";
            string temp(1, current_index);
            equationQueue.push(temp);
        }
    }
}

// For testing purpose
void Calculator::printConversion(string inputEquation)
{

    toStringQueue(inputEquation);

    while (!equationQueue.empty())
    {
        cout << equationQueue.front() << " ";
        equationQueue.pop();
    }
}

// Addition and Subtraction
double Calculator::calculate(string inputEquation)
{

    toStringQueue(inputEquation);

    while (!equationQueue.empty())
    {
        finalResult += stod(equationQueue.front());
        equationQueue.pop();
    }

    return finalResult;
}

#endif