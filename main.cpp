#include <iostream>
#include <string>

using namespace std;

int main () {

    string inputEquation;
    string result;
    int command = 1;
    char prompt;

    while (command != 0) {
		cout << "What do you want to do?\n";
        cout << "1) Do Calculation\n";
        cout << "2) Show History\n";
        cout << "3) Delete History\n";
        cout << "0) Exit Program\n";
        cout << "Enter: ";
        cin >> command;
        
        if (command == 1) {
            cout << "Enter the equation: ";
            cin >> inputEquation;
            cout << "Result: " << inputEquation;
        } else if (command == 2) {
            // Fill with show history function
        } else if (command == 3) {
            // Fill with delete history function
        }
  		
  		cout << "\nContinue.. (y/n)";
  		cin >> prompt;
  		
  		if (prompt == 'n') {
  			command = 0;
		}
		
		system("cls"); 
    }
    
    

}
