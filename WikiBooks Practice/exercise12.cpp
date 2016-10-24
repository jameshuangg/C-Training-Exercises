// Author: James Huang
// Date: October 24, 2016
// Objective: Create a program that computes a recursive formula
#include <iostream>

using namespace std;

// Defining the recursive function
int recursive(int a) {
	if (a == 0) {
		return 3;
	} else if (a == 1) {
		return 2;
	} else {
		return a*(recursive(a-1))+(a+1)*(recursive(a-2))+a;
	}
}

int main() {
	// Declaring variables
	int input;

	// Initializing user input
	cout << "Enter an integer: ";
	cin >> input;
	cout << "u(" << input << ") = " << recursive(input) << endl;

	return 0;
}