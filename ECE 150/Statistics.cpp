// Author: James Huang
// Date: Nov 2, 2016
/* Objective: Create a program that takes no more than 20 integers
and outputs, the min, the max, and the average */
#include <iostream>
#include <climits>

using namespace std;


int convertToIntArray(int argc, char* argv[], int array[]) {
	/* Get each string individually from command line except for 1st
	and convert to an int */
	for(int i = 1; i < argc; i++) {
		// Declare intermediate holder
		// Declare string digit counter
		unsigned int number = 0;
		int currentDigit = 0;
		// Checks if 1st char is negative sign
		bool minusSign = (argv[i][0] == '-');
		// Used 21 because the 1st one is the name
		// Tests whether there are too many inputs
		if(argc > 21) {
			cerr << "Error: Too many input arguments; maximum 20 permitted."
			<< endl;
			return -21;
		}

		// Skips the first char if the number is negative
		if (minusSign) {
			currentDigit++;
		}

		while(argv[i][currentDigit] != '\0') {
			// Tests whether or not the character is a number 0 - 9
			if(argv[i][currentDigit] < '0' || argv[i][currentDigit] > '9') {
				cerr << "Error: Argument " << i << " is not an integer."
				<< endl;
				return -i;
			}
			number = (number * 10) + (argv[i][currentDigit] - '0');
			// Program will fail if number is larger than expected
			if (number > INT_MAX) {
				cerr << "Error: Numerical value of text string is beyond "
				"integer limit" << endl;
				return INT_MIN;
			} else {
				currentDigit++;			
			}
		}

		// If 1st char is negative sign, number is negative
		number = minusSign ? (-number) : number;
		array[i-1] = number;
	}
	return 0;
}

int findMax(int array[], int numElements) {
	int maxNumber = INT_MIN;
	for (int i = 0; i < numElements; i++) {
		if (array[i] > maxNumber) {
			maxNumber = array[i];
		}
	}
	return maxNumber;
}

int findMin(int array[], int numElements) {
	int minNumber = INT_MAX;
	for (int i = 0; i < numElements; i++) {
		if (array[i] < minNumber) {
			minNumber = array[i];
		}
	}
	return minNumber;
}

float average(int array[], int numElements) {
	float sum = 0;
	for(int i = 0; i < numElements; i++) {
		sum += array[i];
	}
	return sum / numElements;
}

int main(int argc, char* argv[]) {
	int intHolder[argc - 1];
	bool status = convertToIntArray(argc, argv, intHolder);
	int maxNum = findMax(intHolder, argc - 1);
	int minNum = findMin(intHolder, argc - 1);
	float averageNum = average(intHolder, argc -1);
	if (argc == 1) {
		cerr << "Error: No arguments." << endl;
		return -1;
	}
	if(status == 0) {
		cout << "Maximum: " << maxNum << endl;
		cout << "Minimum: " << minNum << endl;
		cout << "Average: " << averageNum << endl;
	}
	return 0;
}