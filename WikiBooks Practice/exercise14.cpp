// Author: James Huang
// Date: October 24, 2016
/* Objective: Create a program that calculates the factorial of
an integer */

#include <iostream>

using namespace std;

int main() {

	// Declarations && Initializations
	int N;
	cout << "Please enter the integer you wish to find the " 
	"factorial for: ";
	cin >> N;
	int factorial = 1;

	// Algorithm for a factorial
	for (int i = 0; i < N; i++) {
		factorial *= (N-i);
	}

	cout << "The factorial of " << N << " is: " << factorial << endl;

}