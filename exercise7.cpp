#include <iostream>

using namespace std;

// using functions
/**********************************************
Key learning concept
When coding recursive functions, it makes it much easier
if you use the functions within itself. This makes it recursive.
***********************************************/
double recursive(double a) {
	if (a == 0) {
		return 3;
	} else {
		return (3*recursive(a-1)+4);
	}
}

int main() {
	// Declarations
	int input;
	bool valid;

	// Initializiations
	cout << "Please enter an integer: ";
	cin >> input;
	valid = cin.good();

	// Input testing
	if (valid) {
		cout << "u(" << input << ") = " << recursive(input) << endl;
	} else {
		cerr << "You have entered an incorrect input, try again." << endl;
	}

	return 0;
}
