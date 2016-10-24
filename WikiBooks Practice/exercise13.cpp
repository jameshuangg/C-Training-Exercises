// Author: James Huang
// Date: October 24, 2016
/* Objective: Create a program takes 10 integers and counts the
number of occurances of the biggest number */

#include <iostream>
#include <climits>

using namespace std;

int main() {
	// Declarations && Initializations
	int occurances = 0;
	int input;
	int max = INT_MIN;

	// Repeat the input prompt
	for (int i = 0; i < 10; i++) {
		cout << "Please enter an integer: ";
		cin >> input;
		// Determines if input is bigger than preceeding number
		if (input > max) {
			max = input;
		}
		// Adds 1 to a counter
		if (input == max) {
			occurances++;
		}
	}

	cout << "The biggest number is: " << max << " which showed up "
	<< occurances << " times." << endl;
	return 0;
}