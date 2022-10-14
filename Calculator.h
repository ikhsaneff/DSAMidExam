#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

class Calculator {
public:
    Calculator(string);
    string inputEquation;
    queue<string> equationQueue;
    double  tempResult;
    double finalResult;

    void toStringQueue();
    double calculate();
    void printConversion();
    void trigonometric();
    void logarithmic();
    bool isNumber(string);
    void exponent();
    void multDiv();
}; 

Calculator::Calculator(string inputEquation)
{
    this->inputEquation = inputEquation;
    toStringQueue();
}

bool Calculator::isNumber(string toCheck)
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

void Calculator::toStringQueue() {
    
    string tempNum = "", tempSymbol = "", tempBase = "";

    while (!inputEquation.empty()) {
        if (inputEquation.front() == ' ' || inputEquation.front() == '+') 
        {
            inputEquation.erase (inputEquation.begin());
        } 
        else if (isdigit(inputEquation.front()) || inputEquation.front() == '-') 
        {
            tempNum += inputEquation.front();
            inputEquation.erase (inputEquation.begin());
        } 
        else if (inputEquation.front() == '(' || inputEquation.front() == '^' || inputEquation.front() == 'V' || inputEquation.front() == '*' || inputEquation.front() == '/')
        {
            tempSymbol += inputEquation.front();
            equationQueue.push(tempSymbol);
            inputEquation.erase (inputEquation.begin());
            tempSymbol = "";
        } 
        else if (inputEquation.front() == 's' || inputEquation.front() == 'c' || inputEquation.front() == 't') 
        {
            for (int i = 0; i < 3; i++) 
            {
                tempSymbol += inputEquation.front();
                inputEquation.erase (inputEquation.begin());
            }

            equationQueue.push(tempSymbol);
            tempSymbol = "";
        }
        else if (inputEquation.front() == 'l')
        {
            tempSymbol += inputEquation.front();
            inputEquation.erase (inputEquation.begin());
            if (inputEquation.front() == 'o') 
            {
                tempSymbol += inputEquation.front();
                inputEquation.erase (inputEquation.begin());
                tempSymbol += inputEquation.front();
                inputEquation.erase (inputEquation.begin());
                equationQueue.push(tempSymbol);
                tempSymbol = "";

                if (isdigit(inputEquation.front()))
                {
                    while (!(inputEquation.front() == '('))
                    {
                        tempBase += inputEquation.front();
                        inputEquation.erase (inputEquation.begin());
                    }

                    if (!(tempBase == ""))
                    {
                        equationQueue.push(tempBase);
                        tempBase = "";
                    } else 
                        continue;
                }
                else
                    continue;
                
                
            } 
            else if (inputEquation.front() == 'n')
            {
                tempSymbol += inputEquation.front();
                inputEquation.erase (inputEquation.begin());
                equationQueue.push(tempSymbol);
                tempSymbol = "";
            }

        }

        if (inputEquation.front() == '-' || inputEquation.front() == '+' || inputEquation.front() == '*' || inputEquation.front() == '/' || inputEquation.front() == '^' || inputEquation.front() == 'V' || inputEquation.empty()) 
        {
            if (!(tempNum == ""))
            {
                equationQueue.push(tempNum);
                tempNum = "";
            }
        } 
        else if (inputEquation.front() == ')') 
        {   
            if (!(tempNum == ""))
            {
                equationQueue.push(tempNum);
                tempNum = "";
            }
            
            tempSymbol += inputEquation.front();
            equationQueue.push(tempSymbol);
            inputEquation.erase (inputEquation.begin());
            tempSymbol = "";
        }
    }
}

void Calculator::exponent()
{
    string Num1, tempResult;
    queue<string> tempEquation;

    for (int i = 0; i < equationQueue.size(); i++)
    {   
        Num1 += equationQueue.front();

        if (isNumber(Num1))
        {
            equationQueue.pop(); // delete Num1
            if (equationQueue.front() == "^")
            {
                equationQueue.pop(); //delete symbol
                tempResult += to_string(pow(stod(Num1), stod(equationQueue.front())));
                equationQueue.pop(); //delete Num2
                tempEquation.push(tempResult);
                tempResult = "";
                Num1 = "";
            }
            else
            {
                tempEquation.push(Num1);
                Num1 = "";
            }  
        }
        else if (Num1 == "V")
        {
            equationQueue.pop(); //delete Num1 from queue
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
            equationQueue.pop(); //delete Num1 from queue
        }   
    }

    while (!tempEquation.empty()) 
    {
        equationQueue.push(tempEquation.front());
        tempEquation.pop();
    }

}

void Calculator::multDiv()
{
    string Num1, tempResult;
    double tempEqn;
    queue<string> tempEquation;

    for (int i = 0; i < equationQueue.size(); i++)
    {   
        Num1 += equationQueue.front();

        if (isNumber(Num1))
        {
            equationQueue.pop(); // delete Num1
            if (equationQueue.front() == "*")
            {
                equationQueue.pop(); //delete symbol
                tempEqn = stod(Num1) * stod(equationQueue.front());
                tempResult += to_string(tempEqn);
                equationQueue.pop(); //delete Num2
                tempEquation.push(tempResult);
                tempResult = "";
                Num1 = "";
            }
            else if (equationQueue.front() == "/")
            {
                equationQueue.pop(); //delete symbol
                tempEqn = stod(Num1) / stod(equationQueue.front());
                tempResult += to_string(tempEqn);
                equationQueue.pop(); //delete Num2
                tempEquation.push(tempResult);
                tempResult = "";
                Num1 = "";
            }
            else
            {
                tempEquation.push(Num1);
                Num1 = "";
            }  
        }
        else 
        {
            tempEquation.push(Num1);
            Num1 = "";
            equationQueue.pop(); //delete Num1 from queue
        }   
    }

    while (!tempEquation.empty()) 
    {
        equationQueue.push(tempEquation.front());
        tempEquation.pop();
    }

}

void Calculator::logarithmic()
{
    queue<string> tempEquation;

    while (!equationQueue.empty())
    {
        string tempNum = ""; 
        double num;
        
        if (equationQueue.front() == "log" || equationQueue.front() == "ln") 
        {
            string base = "";
            
            if (equationQueue.front() == "log") 
            {
                equationQueue.pop();
                if (equationQueue.front() == "(")
                {
                    equationQueue.pop();
                    tempNum = to_string(log10(stod(equationQueue.front())));
                    tempEquation.push(tempNum);
                }
                else if (isNumber(equationQueue.front()))
                {
                    base += equationQueue.front();
                    equationQueue.pop();
                    equationQueue.pop();
                    tempNum = to_string(log(stod(equationQueue.front())) / log(stod(base)));
                    tempEquation.push(tempNum);
                }
            }
            else if (equationQueue.front() == "ln")
            {
                equationQueue.pop();
                equationQueue.pop();
                tempNum = to_string(log(stod(equationQueue.front())));
                tempEquation.push(tempNum);
            }

            equationQueue.pop();
            equationQueue.pop();
        }
        else
        {
            tempEquation.push(equationQueue.front());
            equationQueue.pop();
        }
    }

    while (!tempEquation.empty()) 
    {
        equationQueue.push(tempEquation.front());
        tempEquation.pop();
    }
}

void Calculator::trigonometric() 
{
    queue<string> tempEquation, tempEquation0;

    while (!equationQueue.empty())
    {
        string tempNum = ""; 
        double num;
        
        if (equationQueue.front() == "sin") 
        {
            equationQueue.pop();
            num = stod(equationQueue.front())*3.14159/180;
            tempNum = to_string(sin(num));
            tempEquation.push(tempNum);
        }
        else if (equationQueue.front() == "cos")
        {
            equationQueue.pop();
            num = stod(equationQueue.front())*3.14159/180;
            tempNum = to_string(cos(num));
            tempEquation.push(tempNum);
        }
        else if (equationQueue.front() == "tan")
        {
            equationQueue.pop();
            num = stod(equationQueue.front())*3.14159/180;
            tempNum = to_string(tan(num));
            tempEquation.push(tempNum);
        }
        else 
        {
        tempEquation.push(equationQueue.front());
        }

        equationQueue.pop();
    }

    while (!tempEquation.empty()) 
    {
        equationQueue.push(tempEquation.front());
        tempEquation.pop();
    }
    
    // return equationQueue;
}

// void Calculator::printConversion() {

//     logarithmic();
//     trigonometric();
//     exponent();   
//     multDiv();
//     cout << equationQueue.size() << "\n";

//     while (!equationQueue.empty()) {
//         cout << equationQueue.front();
//         cout  << "|";
//         equationQueue.pop();
//     }
// }

double Calculator::calculate() {

    logarithmic();
    trigonometric();
    exponent();
    multDiv();

    while (!equationQueue.empty()) {
        finalResult += stod(equationQueue.front());
        equationQueue.pop();
    }

    return finalResult;
}

#endif