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
    double multDiv(string);
    void printConversion();
    void remakeQueue(string);
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
        if (bracketed == 0)
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

        if (current_index == ')' && (tempNum.find('/') < tempNum.length() || tempNum.find('*') < tempNum.length()))
        {
            // bracketed--;
            continue;
        }

        if ((inputEquation[i + 1] == '-' || current_index == '+' || current_index == ')' || i + 1 == inputEquation.size()) && tempNum != "")
        {
            equationQueue.push(tempNum);
            tempNum = "";
            decimal = 0;
        }

        if (current_index == ')')
        {
            equationQueue.push(")");
            bracketed--;
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
    queue<string> printQ = equationQueue;
    while (!printQ.empty())
    {
        cout << printQ.front() << " ";
        printQ.pop();
    }
    cout << endl;
}

// Calculate bracket recursive
double Calculator::calculate()
{
    double result;
    while (!equationQueue.empty())
    {
        string first_number = equationQueue.front();
        equationQueue.pop();
        // case 1: finds an open bracket
        if (first_number == "(")
        {
            result += calculate();
        }
        // case 2: finds a close bracket
        else if (first_number == ")")
        {
            return result;
        }
        // case 3: multiplication/divison of number
        else if (first_number.find('/') < first_number.length() || first_number.find('*') < first_number.length())
        {
            result += multDiv(first_number);
        }
        //  base case: addition of number
        else
        {
            result += stod(first_number);
        }
    }
    return result;
}
//(20*3)/5+20+(20*4)+1
void Calculator::remakeQueue(string front)
{
    queue<string> newQueue;
    newQueue.push(front);
    while (!equationQueue.empty())
    {
        newQueue.push(equationQueue.front());
        equationQueue.pop();
    }
    equationQueue = newQueue;
}

double Calculator::multDiv(string equation)
{
    string tempNum = "";
    queue<string> tempResult;
    for (int i = 0; i < equation.size(); i++)
    {
        if (isdigit(equation[i]) || equation[i] == '.')
        {
            tempNum += equation[i];
        }

        if (equation[i] == '/' || equation[i] == '*')
        {
            tempResult.push(tempNum);
            tempNum = "";
            string temp(1, equation[i]);
            tempResult.push(temp);
        }

        if (tempNum != "" && i + 1 == equation.size())
        {
            tempResult.push(tempNum);
            tempNum = "";
        }
    }

    double result;
    result = stod(tempResult.front());
    tempResult.pop();
    while (!tempResult.empty())
    {
        if (tempResult.front() == "/")
        {
            tempResult.pop();
            result /= stod(tempResult.front());
        }
        else if (tempResult.front() == "*")
        {
            tempResult.pop();
            result *= stod(tempResult.front());
        }
        tempResult.pop();
    }
    return result;
}
#endif