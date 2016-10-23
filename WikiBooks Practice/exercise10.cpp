// Author: James Huang
// Date: October 23, 2016
// Objective: Compute operations on an integer
#include <iostream>

using namespace std;

int main() {
	// Declarations
	int input;
	int actionInput;

	//Initializations
	cout << "Please enter an input to manipulate: ";
	cin >> input;

	do {
		cout << "1. Add 1" << endl;
		cout << "2. Multiply by 2" << endl;
		cout << "3. Subtract 4" << endl;
		cout << "4. Quit" << endl;
		cout << "Type in value between 1 and 4 for "
		"corresponding operation: ";
		cin >> actionInput;
		switch (actionInput) {
			case 1:
				input += 1;
				cout << "Integer: " << input << endl;
				break;
			case 2:
				input *= 2;
				cout << "Integer: " << input << endl;
				break;
			case 3:
				input -= 4;
				cout << "Integer: " << input << endl;
				break;
			case 4:
				cout << "Quitting..." << endl;
				break;
		}
	} while (actionInput != 4);

	return 0;
}