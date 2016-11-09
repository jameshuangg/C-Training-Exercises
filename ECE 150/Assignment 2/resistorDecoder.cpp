#include <iostream>

using namespace std;

int main() {
	// Declarations
	char bandColors[4];
	double resistanceSum = 0;
	double resistanceTolerance = 0;
	bool failFlag = false;

	// Initialization corresponding to user input
	cout << "Enter the 4 resistor color codes: ";
	cin >> bandColors;

	// If statements testing the 1st band
	if (bandColors[0] == 'k') {
		resistanceSum += 0;
	} else if (bandColors[0] == 'n') {
		resistanceSum += 10;
	} else if (bandColors[0] == 'R') {
		resistanceSum += 20;
	} else if (bandColors[0] == 'O') {
		resistanceSum += 30;
	} else if (bandColors[0] == 'Y') {
		resistanceSum += 40;
	} else if (bandColors[0] == 'G') {
		resistanceSum += 50;
	} else if (bandColors[0] == 'B') {
		resistanceSum += 60;
	} else if (bandColors[0] == 'V') {
		resistanceSum += 70;
	} else if (bandColors[0] == 'y') {
		resistanceSum += 80;
	} else if (bandColors[0] == 'W') {
		resistanceSum += 90;
	} else {
		failFlag = true;
	}

	// If statements testing the 2nd band
	if (bandColors[1] == 'k') {
		resistanceSum += 0;
	} else if (bandColors[1] == 'n') {
		resistanceSum += 1;
	} else if (bandColors[1] == 'R') {
		resistanceSum += 2;
	} else if (bandColors[1] == 'O') {
		resistanceSum += 3;
	} else if (bandColors[1] == 'Y') {
		resistanceSum += 4;
	} else if (bandColors[1] == 'G') {
		resistanceSum += 5;
	} else if (bandColors[1] == 'B') {
		resistanceSum += 6;
	} else if (bandColors[1] == 'V') {
		resistanceSum += 7;
	} else if (bandColors[1] == 'y') {
		resistanceSum += 8;
	} else if (bandColors[1] == 'W') {
		resistanceSum += 9;
	} else {
		failFlag = true;
	}

	// If statements testing the 3rd band
	if (bandColors[2] == 'k') {
		resistanceSum *= 1;
	} else if (bandColors[2] == 'n') {
		resistanceSum *= 10;
	} else if (bandColors[2] == 'R') {
		resistanceSum *= 100;
	} else if (bandColors[2] == 'O') {
		resistanceSum *= 1000;
	} else if (bandColors[2] == 'Y') {
		resistanceSum *= 10000;
	} else if (bandColors[2] == 'G') {
		resistanceSum *= 100000;
	} else if (bandColors[2] == 'B') {
		resistanceSum *= 1000000;
	} else if (bandColors[2] == 'V') {
		resistanceSum *= 10000000;
	} else if (bandColors[2] == 'y') {
		resistanceSum *= 100000000;
	} else if (bandColors[2] == 'W') {
		resistanceSum *= 1000000000;
	} else if (bandColors[2] == 'd') {
		resistanceSum *= 0.1;
	} else if (bandColors[2] == 'S') {
		resistanceSum *= 0.01;
	} else {
		failFlag = true;
	}

	// If statements testing the fourth band
	if (bandColors[3] == 'k') {
		failFlag = true;
	} else if (bandColors[3] == 'n') {
		resistanceTolerance = resistanceSum * 0.01;
	} else if (bandColors[3] == 'R') {
		resistanceTolerance = resistanceSum * 0.02;
	} else if (bandColors[3] == 'O') {
		failFlag = true;
	} else if (bandColors[3] == 'Y') {
		failFlag = true;
	} else if (bandColors[3] == 'G') {
		resistanceTolerance = resistanceSum * 0.005;
	} else if (bandColors[3] == 'B') {
		resistanceTolerance = resistanceSum * 0.0025;
	} else if (bandColors[3] == 'V') {
		resistanceTolerance = resistanceSum * 0.001;
	} else if (bandColors[3] == 'y') {
		resistanceTolerance = resistanceSum * 0.0005;
	} else if (bandColors[3] == 'W') {
		failFlag = true;
	} else if (bandColors[3] == 'd') {
		resistanceTolerance = resistanceSum * 0.05;
	} else if (bandColors[3] == 'S') {
		resistanceTolerance = resistanceSum * 0.1;
	} else if (bandColors[3] == 'N') {
		resistanceTolerance = resistanceSum * 0.2;
	} else {
		failFlag = true;
	}

	// If failFlag is false, it will printout the result
	// If failFlag is true is will not printout
	if (failFlag) {
		cerr << "Error: Invalid color code entered!" << endl;
	} else {
		cout << "Resistance is " << resistanceSum << " ohms (+/-" 
		<< resistanceTolerance << " ohms tolerance)" << endl;
	}
}