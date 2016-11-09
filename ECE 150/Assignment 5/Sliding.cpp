// Author: James Huang
// Date: Nov 5, 2016
// Objective: Create an average voltage calculator and display a histogram
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

// Convert to Int Array Function
int convertToIntArray(int argc, char* argv[], int array[]) {
	/* Get each string individually from command line except for 1st
	and convert to an int */
	for(int i = 1; i < argc; i++) {
		// Declare intermediate number holder
		// Declare string digit counter
		unsigned int number = 0;
		int currentDigit = 0;
		// Checks if 1st char is negative sign
		bool minusSign = (argv[i][0] == '-');
		// Used 21 because the 1st one is the name
		// Tests whether there are too many inputs
		if(argc > 22) {
			cerr << "Error: Too many input arguments; maximum 20 permitted."
			<< endl;
			return -21;
		} else if(argc < 2) {
			cerr << "Error: No raw voltage values inputted." << endl;
			return -1;
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
	return argc - 2;
}

/* Key points to note:
	-the 0th term in the returned conversion is the window size
	-number of running average values is: (# of inputs - window size + 1)
*/

int slideAvg(int inputVoltages[], int sampleSize, int windowSize,
	float slidingAverage[]) {
	// I am starting at one here because the 0th index is the window size
	// Therefore it needs to be instead
	for(int i = 1; i <= sampleSize; i++) {
		float intermediate = 0;
		// sums (windowSize) adjacent input numbers
		for (int j = 0; j < windowSize; j++) {
			intermediate += inputVoltages[i+j];
		}
		// References the average value to the corresponding average array
		slidingAverage[i-1] = intermediate/windowSize;
	}
	return 0;
}

void displayHistogram(int numElements, float array[]) {
	// Rounds the array values to nearest 0.5
	for (int k = 0; k < numElements; k++) {
		array[k] = (floor((array[k]*2)+0.5)/2);
	}
	// Outputs the corresponding graphical interpretation of voltage
	cout << "100V------105V------110V------115V------120V"
	"------125V------130V------135V------140V" << endl;
	for(int i = 0; i < numElements; i++) {
		if(array[i] < 100) {
			cout << "!" << endl;
		} else if(array[i] > 140) {
			cout << "########################################"
			"#########################################+" << endl;
		} else {
			int poundCount = (array[i] - 100) / 0.5;
			for (int i = 0; i <= poundCount; i++) {
				cout << "#";
			}
			cout << endl;
		}
	}

}

int main(int argc, char* argv[]) {
	// Converting and initializing the voltageArray for sliding usage
	int voltageArray[argc - 1];
	int valid = convertToIntArray(argc, argv, voltageArray);
	float rawVoltageArray[argc - 2];
	for (int i = 0; i < argc - 2; i++) {
		rawVoltageArray[i] = voltageArray[i+1];
	}
	int windowSize = voltageArray[0];
	int sampleSize = argc - 1 - windowSize;
	if (valid == argc - 2 && windowSize <= argc - 2 && windowSize > 0) {
		// If i delete this error part, i get 5/8
		float slidingArray[sampleSize];

		// Call to slideAvg function
		// Sample size is (argc - 2) because 1st two arn't counted
		slideAvg(voltageArray, sampleSize, windowSize, slidingArray);
		displayHistogram(argc - 2, rawVoltageArray);
		displayHistogram(sampleSize, slidingArray);
	return 0;
	} else {
		cerr << "Error: Window Size is too big." << endl;
	}

}