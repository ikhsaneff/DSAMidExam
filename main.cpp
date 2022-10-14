#include "Calculator.h"
#include "LinkedList.h"
#include <conio.h>

int main ()
{
    string inputEquation;
    double result;
    int command;
    int prompt = 1;
    Node* head = NULL;
    int test;
    string tempHistory;

    while (prompt != 0)
    {
            cout
        << "  |||  |||  ||    ||| || || ||    |||  ||||||  |||  ||||  \n"
        << " ||   || || ||   ||   || || ||   || ||   ||   || || || || \n"
        << " ||   ||||| ||   ||   || || ||   |||||   ||   || || ||||  \n"
        << "  ||| || || ||||  |||  |||  |||| || ||   ||    |||  || || \n"
        << "by Pieter Timothy (2021390031) and M. Ikhsan E. (2021400006)\n"
        << "Instructions to calculate:\n"
        << " - trigonomentry do sinN or cosN or tanN where N is degree\n"
        << " - logarithmic do logN(I) or ln(I) where N is the base and I is a number\n"
        << " - exponent do N^J where N and J are numbers\n"
        << " - square root do VN where N is number\n"
        << " - multiply/divide/add/sub do N*J or N/J or N+j or N-J where N and J are numbers\n"
        << "\nConstraints of operation:\n"
        << " - multiplication can't come after other operations (Ex. sin30*2 not possible, 2*sin30 possible)\n"
        << " - division can't come after other operations (Ex. sin30/2 not possible, 2/sin30 possible)\n"
		<< "\nWe try using these equations:"
		<< "\n - log(100) + sin90 + 1 + tan45 = 5"
		<< "\n - 2^2 + V49 + 2 = 13\n"
		<< "\n - V81 - 7 + log(100) = 4\n";
        cout << "Welcome!\n";
        cout << "Command: \n"
		     << " 1: Calculate\n"
		     << " 2: Show History\n"
		     << " 0: Exit Program\n"
             << "Enter... ";
		cin >> prompt;
        system("cls");
	
		//to do a calculation
		if (prompt == 1)
        {
            cout << "Enter the equation: ";
            cin.ignore();
            getline(cin, inputEquation);
            Calculator calculator(inputEquation);
            result = calculator.calculate(); // input equation result after testing
            cout << "Result: " << result << endl;  
			
			string calcResult = to_string(result);
			tempHistory = inputEquation + " = " + calcResult;
			push(&head, tempHistory);
						
			prompt = 3;
            cout << "Continue...";
            getche();
            system("cls");
		}
        else if (prompt == 2) //to look at history
        {
			int historyPrompt = 3;
			
            while (historyPrompt != 0)
            {
				printHistory(head);
				
                cout << "Command: \n"
					 << " 1: Delete History\n"
					 << " 0: Go back to Main Menu\n"
                     << "Enter... ";	
				cin >> historyPrompt;
				system("cls");
                
				if(historyPrompt == 1) //delete history
                {
    				int index = 0;
                    printHistory(head);

                    cout << "Enter the position: ";
                    cin >> index;

					deleteNode(&head, index);
					historyPrompt = 3;
                    system("cls");
				}
				else if(historyPrompt == 0){
                    system("cls");
					continue;
				}
			}
			
		}
		else if (prompt == 0)
			return 0;

        
	}

}