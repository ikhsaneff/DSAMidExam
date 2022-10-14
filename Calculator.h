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
    queue<string> exponent();
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
    int decimal = 0;

    for (int i = 0; i < inputEquation.size(); i++)
    {
        char current_index = inputEquation[i];

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
        else if (current_index == '^' || current_index == 'V')
        {
            string temp(1, current_index);
            equationQueue.push(temp);
        }

        else if (current_index == 'l')
        {
            if (inputEquation[i + 1] == 'o')
            {
                // berarti log
            }
            else if (inputEquation[i + 1] == 'n')
            {
                // berartiln
            }
        }

        if (decimal > 1)
        {
            throw invalid_argument("Invalid number, too many . in one number");
        }

        if ((inputEquation[i + 1] == '-' || inputEquation[i + 1] == '^' || current_index == '+' || i + 1 == inputEquation.size()) && tempNum != "")
        {
            equationQueue.push(tempNum);
            tempNum = "";
            decimal = 0;
        }
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
        // case 1: multiplication/divison of number
        if (first_number.find('/') < first_number.length() || first_number.find('*') < first_number.length())
            result += multDiv(first_number);
        //  case 2: trigonometry
        else if (first_number == "sin" || first_number == "cos" || first_number == "tan")
            result += trigonometric(first_number);
        // case 3: exponent
        else if (equationQueue.front() == '^')
        {
            exponent();
        }
        //  base case: addition of number
        else
            result += stod(first_number);
    }
    return result;
}

queue<string> Calculator::exponent()
{
    string Num1, Num2, tempResult;
    queue<string> tempEquation;

    while (!equationQueue.empty())
    {
        Num1 += equationQueue.front();
        equationQueue.pop(); // delete Num1 from queue

        if (equationQueue.front() == "^")
        {
            equationQueue.pop();
            tempResult += to_string(pow(stod(Num1), stod(equationQueue.front())));
            equationQueue.pop();
            tempEquation.push(tempResult);
            tempResult = "";
            Num1 = "";
        }
        else if (Num1 == "V")
        {
            Num1 = "";
            tempResult += to_string(sqrt(stod(equationQueue.front())));
            equationQueue.pop();
            tempEquation.push(tempResult);
            tempResult = "";
        }
        else
        {
            tempEquation.push(Num1);
            Num1 = "";
        }
    }

    while (!tempEquation.empty())
    {
        equationQueue.push(tempEquation.front());
        tempEquation.pop();
    }

    // while (!equationQueue.empty())
    // {
    //     cout << equationQueue.front() << "|";
    //     equationQueue.pop();
    // }

    return equationQueue;
}

double Calculator::multDiv(string equation)
{
    string tempNum = "";
    queue<string> tempResult;
    for (int i = 0; i < equation.size(); i++)
    {
        if (isdigit(equation[i]) || equation[i] == '.')
            tempNum += equation[i];

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