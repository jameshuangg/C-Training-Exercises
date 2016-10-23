// Author: James Huang
// Date: October 23, 2016
// Objective: Error checking exercise

/* Learned: For you to separate long lines of strings, you can
have them under the same cout but separate the strings into 
different quotation marks */

#include <iostream>

using namespace std;

int main() {
	// Declarations
	int input;
	bool valid;

	// Initialization
	cout << "Please type in an integer between 0 and 20: ";
	cin >> input;
	valid = cin.good();

	// Integer check
	if (valid) {
		// Bounds check
		if (input >=0 && input <= 20) {
			cout << "You entered: " << input << " which outputs "
			<< input + 17 << endl;
			return 0;
		} else {
			cerr << "You have not entered an integer within bounds. "
			"Try again" << endl;
			return 1;
		}
	} else {
		cerr << "You have not entered an integer. Try again." << endl;
		return 1;
	}
}