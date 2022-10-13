#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdexcept>
#include <math.h>

using namespace std;

class Calculator
{
public:
    Calculator(string);
    void toStringQueue();
    double calculate();
    double multDiv(string);
    double trigonometric(string);
    void printConversion();

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

double Calculator::trigonometric(string trig)
{
    double tempNum;
    double num;
    if (trig == "sin")
    {
        num = stod(equationQueue.front()) * 3.14159 / 180;
        tempNum = sin(num);
    }
    else if (trig == "cos")
    {
        num = stod(equationQueue.front()) * 3.14159 / 180;
        tempNum = cos(num);
    }
    else if (trig == "tan")
    {
        num = stod(equationQueue.front()) * 3.14159 / 180;
        tempNum = tan(num);
    }
    equationQueue.pop();
    return tempNum;
}

//@Definition:
void Calculator::toStringQueue()
{
    string tempNum = "", tempSymbol = "";
    int decimal = 0, bracketed = 0;

    for (int i = 0; i < inputEquation.size(); i++)
    {
        char current_index = inputEquation[i];
        if (i == 0)
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
        else if (current_index == 's' || current_index == 'c' || current_index == 't')
        {
            for (int j = 0; j < 3; j++)
            {
                tempSymbol += inputEquation[i + j];
            }
            equationQueue.push(tempSymbol);
            tempSymbol = "";
            i += 2;
        }

        if (current_index == '(')
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
            bracketed--;
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
    printConversion();
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
            if (first_number[0] == '/' || first_number[0] == '*')
            {
                string tempString = to_string(result);
                // cout << tempString + first_number << endl;
                result = multDiv(tempString + first_number);
            }
            else
            {
                result += multDiv(first_number);
            }
        }
        //  case 4: trigonometry
        else if (first_number == "sin" || first_number == "cos" || first_number == "tan")
        {
            result += trigonometric(first_number);
        }
        //  base case: addition of number
        else
        {
            result += stod(first_number);
        }
    }
    return result;
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