#include "Calculator.h"
#include "LinkedList.h"
#include <conio.h>

int main()
{
    string inputEquation;
    double result;
    int command;
    int prompt = 1;
    Node *head = NULL;
    int test;
    string tempHistory;

    getline(cin, inputEquation);
    Calculator calculator(inputEquation);
    result = calculator.calculate();
    cout << "Result: " << result << endl;
    calculator.printConversion();

    // while (prompt != 0)
    // {
    //     cout << "Welcome!\n";
    //     cout << "Command: \n"
    //          << " 1: Calculate\n"
    //          << " 2: Show History\n"
    //          << " 0: Exit Program\n"
    //          << "Enter... ";
    //     cin >> prompt;
    //     system("cls");
        // to do a calculation
        if (prompt == 1)
        {
             cin.ignore();
            cout << "Enter the equation: ";
            cin >> inputEquation;
            Calculator calculator(inputEquation);
            // result = calc.calculate(inputEquation); // input equation result after testing
            cout << "Result: "; calculator.printConversion();

    //         string calcResult = to_string(result);
    //         tempHistory = inputEquation + " = " + calcResult;
    //         push(&head, tempHistory);

    //         prompt = 3;
    //         cout << "Continue...";
    //         getche();
    //         system("cls");
    //     }
    //     else if (prompt == 2) // to look at history
    //     {
    //         int historyPrompt = 3;

    //         while (historyPrompt != 0)
    //         {
    //             printHistory(head);

    //             cout << "Command: \n"
    //                  << " 1: Delete History\n"
    //                  << " 0: Go back to Main Menu\n"
    //                  << "Enter... ";
    //             cin >> historyPrompt;
    //             system("cls");

    //             if (historyPrompt == 1) // delete history
    //             {
    //                 int index = 0;
    //                 printHistory(head);

    //                 cout << "Enter the position: ";
    //                 cin >> index;

    //                 deleteNode(&head, index);
    //                 historyPrompt = 3;
    //                 system("cls");
    //             }
    //             else if (historyPrompt == 0)
    //             {
    //                 system("cls");
    //                 continue;
    //             }
    //         }
    //     }
    //     else if (prompt == 0)
    //         return 0;
    // }
}
