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
    Calculator(string);
    void toStringQueue();
    double finalResult;
    double calculate();
    void printConversion();
    double calculateBracket();
    void multiply(string);

private:
    string inputEquation;
    queue<string> equationQueue;
};

//@Definition: Default Constructor
Calculator::Calculator(string inputEquation)
{
    this->inputEquation = inputEquation;
    toStringQueue();
}

//@Definition:
void Calculator::toStringQueue()
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
void Calculator::printConversion()
{
    while (!equationQueue.empty())
    {
        cout << equationQueue.front() << " ";
        equationQueue.pop();
    }
}

// Calculate
double Calculator::calculate()
{
    while (!equationQueue.empty())
    {
        string temp = equationQueue.front();
        finalResult += stod(temp);
        equationQueue.pop();
    }

    return finalResult;
}

#endif