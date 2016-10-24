// Author: James Huang
// Date: October 24, 2016
/* Objective: Create a program that takes many inputs and finds
the average of the values */

#include <iostream>

using namespace std;

int main() {
	// Declarations
	int input;
	int count = 0;
	double summation;

	/* Loops a user input to determine summation of values
	and increase count */
	do {
		cout << "Please type in a positive integer: ";
		cin >> input;
		if (input > 0) {
			summation += input;
			count++;
		} else if (input < 0) {
			cerr << "Error: Invalid integer." << endl;
		}
	} while(input != 0);

	// Outputs the corresponding messages
	if (input == 0 && count == 0) {
		cerr << "NO AVERAGE" << endl;
	} else {
		cout << "The average of the values given is: "
		<< summation / count << endl;	}

	return 0;
}