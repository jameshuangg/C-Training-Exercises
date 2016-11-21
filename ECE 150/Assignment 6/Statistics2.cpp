#include <iostream>
#include <climits>

using namespace std;

int convertToIntArray(int argc, char* argv[], int array[]) {
	/* Get each array of char individually from command line except for 1st
	and convert to an int */
	if (argc == 1) {
		return 0;
	}
	for(int i = 1; i < argc; i++) {
		// Declare intermediate number holder
		// Declare array of char digit counter
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
		if (argv[i][0] == '+') {
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
				cerr << "Error: Numerical value of text is beyond "
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

bool findMaxMinAvg(int array[], int numElements, int& max, int& min, float& avg) {
	int calcMax = INT_MIN;
	int calcMin = INT_MAX;
	float sum = 0;
	if (numElements < 1) {
		return false;
	}
	for (int i = 0; i < numElements; i++) {
		sum += array[i];
		if(array[i] > calcMax) {
			calcMax = array[i];
		}
		if(array[i] < calcMin) {
			calcMin = array[i];
		}
	}
	max = calcMax;
	min = calcMin;
	avg = sum/numElements;
	return true;
}

int main(int argc, char* argv[]) {
	// Create an array with the neccesarry amount of space
	int numElements = argc - 1;
	int intArray[numElements];
	int max = 0;
	int min = 0;
	float average = 0;
	convertToIntArray(argc, argv, intArray);
	bool status = findMaxMinAvg(intArray, numElements, max, min, average);
	if(status) {
		cout << "Computation successful:" << endl;
		cout << "Max = " << max << endl;
		cout << "Min = " << min << endl;
		cout << "Average = " << average << endl;
	} else {
		cerr << "Computation failed: No elements." << endl;
	}
}