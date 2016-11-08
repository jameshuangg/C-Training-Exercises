// Author: James Huang
// Date: October 24,2016
// Objective: Finds prime numbers less than or equal to an input

/* Approach to the problem: I want to loop through each number preceeding
the input and check if it is a prime number. If it is a prime number
I will increase a counter by 1. */

/* A number will be a prime number if there are no numbers
that will % it to 0 */
#include <iostream>

using namespace std;

// I can start by making a function that checks if a number is prime
// Incorrect !!
int primeCheck(int a){
	bool valid = true;
	for (int j = 2; j < a; j++) {
		if (a % j == 0) {
			valid = false;
		}
	}
	if (valid) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	// Declarations
	int input;
	int primeCount = 0;

	// Initializations
	cout << "Please enter an integer: ";
	cin >> input;

	for (int i = 1; i <= input; i++) {
		primeCount += primeCheck(i);
	}
	cout << "Your integer has: " << primeCount << " prime numbers "
	"less than or equal to it." << endl;

	return 0;
}