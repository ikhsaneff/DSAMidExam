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
    double calculate();
    void printConversion();
    bool isNumber(string);

private:
    string inputEquation;
    queue<string> equationQueue;
};

bool isNumber(string toCheck)
{
    for (int i = 0; i < toCheck.size(); i++)
    {
        if (!isdigit(toCheck[i]))
        {
            return false;
        }
    }
    return true;
}

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
        // if (!isNumber(equationQueue.front()))
        // {
        //     cout << equationQueue.front() << endl;
        // }
        equationQueue.pop();
    }
}

// Calculate bracket recursive
double Calculator::calculate()
{
    double result;
    while (!equationQueue.empty())
    {
        string temp = equationQueue.front();
        // case 1: finds an open bracket
        if (temp == "(")
        {
            equationQueue.pop();
            result += calculate();
        }
        // case 2: finds a close bracket
        else if (temp == ")")
        {
            equationQueue.pop();
            return result;
        }
        // base case: addition of number
        else
        {
            equationQueue.pop();
            // if (!isNumber(temp))
            // {
            //     cout << temp << endl;
            // }
            result += stod(temp);
        }
    }
    return result;
}

#endif