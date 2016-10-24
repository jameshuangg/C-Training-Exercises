// Author: James Huang
// Date: October 24, 2016
// Objective: Prime number check

/* A number is a prime number when it is only divisible by one
and itself, I can loop an increasing modulo and if at any point
it becomes 0 then its a factor, check the factor */

#include <iostream>

using namespace std;

int main() {
	int input;
	bool prime = true;

	cout << "Please enter a number: ";
	cin >> input;

	/* Will check all of the numbers inbetween 1 and input number 
	and see if there are any factors, if so change boolean */
	for (int i = 2; i < input; i++) {
		if (input % i == 0) {
			prime = false;
		}
	}

	// Depending on value of boolean, will output corresponding sentence
	if (prime) {
		cout << input << " is a prime number." << endl;
	} else {
		cout << input << " is not a prime number." << endl;
	}

	return 0;
}