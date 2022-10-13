#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdexcept>

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
    void multiply(string);
};

void Calculator::bracketDetect(queue<string> equationQueue)
{
}

//@Definition:
void Calculator::toStringQueue(string inputEquation)
{

    string tempNum = "";
    int decimal = 0, bracketed = 0;

    for (int i = 0; i < inputEquation.size(); i++)
    {
        char current_index = inputEquation[i];
        if (bracketed == 0 && inputEquation[0] != '(')
        {
            equationQueue.push("(");
            bracketed++;
        }

        if (isdigit(current_index) || current_index == '-' || current_index == '/' || current_index == '*')
        {
            tempNum += current_index;
        }
        else if (current_index == '.')
        {
            decimal++;
            tempNum += current_index;
        }
        else if (current_index == '(')
        {
            equationQueue.push("(");
            bracketed++;
        }

        if (decimal > 1)
        {
            throw invalid_argument("Invalid number, too many . in one number");
        }

        if (inputEquation[i + 1] == '-' || current_index == '+' || current_index == ')' || i + 1 == inputEquation.size())
        {
            equationQueue.push(tempNum);
            tempNum = "";
            decimal = 0;
            if (current_index == ')' || i + 1 == inputEquation.size())
            {
                equationQueue.push(")");
                bracketed--;
            }
        }
    }
    for (int i = 0; i < bracketed; i++)
    {
        equationQueue.push(")");
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

// For testing purpose
void Calculator::multiply(string inputEquation)
{
}
// Calculate
double Calculator::calculate(string inputEquation)
{

    toStringQueue(inputEquation);
    while (!equationQueue.empty())
    {
        string temp = equationQueue.front();

        finalResult += stod(temp);
        equationQueue.pop();
    }

    return finalResult;
}

#endif