// Author: James Huang
// Date: October 23
// Objetive: Create a recursive function of form u(n+1)=u(n)+u(n-1)
#include <iostream>

using namespace std;

// Recursive function
int recursive(int a) {
	if (a == 0 || a == 1) {
		return 1;
	} else {
		return recursive(a-1) + recursive(a-2);
	}
}

int main() {
	// Declaraions
	int input;
	bool valid;

	// Initializations
	cout << "Please enter an integer: ";
	cin >> input;
	valid = cin.good();

	// Input testing
	if (valid) {
		cout << "u(" << input << ") = " << recursive(input) << endl;
	} else {
		cerr << "The input you have entered is invalid." << endl;
	}



}