// Author: James Huang
// Date: October 26, 2016
/* Objective: Create a program that uses bubble sort to sort
through an array */
#include <iostream>

using namespace std;

int main() {
	// Declarations
	int num_Of_Sets = 5;
	int input[num_Of_Sets];
	int swapCount = 0;

	// Take input and store into respective array index
	cout << "Enter 5 ID: ";
	for (int i = 0; i < num_Of_Sets; i++) {
		bool valid;
		cin >> input[i];
		valid = cin.fail();
		if (input[i] < 10000000) {
			cerr << "Error: Invalid Input." << endl;
			return 1;
		}
		if (valid) {
			cerr << "Error: Invalid Input." << endl;
			return 1;
		}
	}

	// Input Error Checking
	// Number of times sort loop is run
	for (int k = 0; k < num_Of_Sets - 1; k++) {
		// Sort Decending (biggest to smallest)
		for (int j = 0; j < num_Of_Sets - 1; j++) {
			if (input[j] < input[j+1]) {
				int holder;
				holder = input[j];
				input[j] = input[j+1];
				input[j+1] = holder;
				swapCount++;
			}
		}
	}

	// Outputs the sorted ID
	cout << "Sorted ID: ";
	for (int n = 0; n < num_Of_Sets; n++) {
		cout << input[n] << " ";
		if (n == num_Of_Sets - 1)
			cout << endl;
	}
	cout << "Swap Count: " << swapCount << endl;
	/* We want to add another input into our array, sort it
	and identify the position */
	int position;
	bool valid2;
	/* Declares a new array, such that the new is in the front
	so we only need one sort */
	int secondArray[6] = {0, input[0], input[1], input[2], input[3], input[4]};
	cout << "Enter another input: ";
	cin >> secondArray[0];
	valid2 = cin.fail();
	if (secondArray[0] < 10000000) {
		cerr << "Error: Invalid Input." << endl;
		return 1;
	}
	if (valid2) {
		cerr << "Error: Invalid Input." << endl;
		return 1;
	}

	// Checks if the new input already exists
	for (int i = 0; i < num_Of_Sets; i++) {
		if (secondArray[0] == input[i]) {
			cerr << "Error: This ID exists." << endl;
			return 1;
		}
	}

	// Makes one pass through the array and tracks where the new input is
	for (int j = 0; j < num_Of_Sets; j++) {
		if (secondArray[j] < secondArray[j+1]) {
			int holder;
			position = j + 1;
			holder = secondArray[j];
			secondArray[j] = secondArray[j+1];
			secondArray[j+1] = holder;
		}
	}

	// Prints out the position of the new input in the new sorted array
	cout << "The value " << secondArray[position] << 
	" is in position " << position << endl;
	return 0;

}