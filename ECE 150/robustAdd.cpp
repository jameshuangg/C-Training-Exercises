#include <iostream>
#include <climits>

using namespace std;

int main() {
	signed int input1;
	signed int input2;
	
	cout << "Enter two integers to add: ";
	cin >> input1;
	bool valid1 = cin.good();
	char next1 = cin.get();
	cin >> input2;
	bool valid2 = cin.good();
	char next2 = cin.get();

	if ((next1 == '\n' || next1 == ' ') && (next2 == '\n' || next2 == ' ')
		&& (valid1 == true && valid2 == true)){
		if ((input1 < INT_MAX && input1 > INT_MIN) && (input2 < INT_MAX && input2 > INT_MIN)) {
			if (input1 > 0 && input2 > 0) {
				unsigned int positiveSum;
				positiveSum = input1 + input2;
				if (positiveSum > INT_MAX) {
					cerr << "Error: Summed value out of the signed int range." << endl;
				} else {
					cout << "Sum of two numbers is: " << positiveSum << endl;
				}
			} else if (input1 < 0 && input2 < 0) {
				unsigned int negativeSum;
				negativeSum = -input1 - input2;
				if (negativeSum > INT_MAX) {
					cerr << "Error: Summed value out of the signed int range." << endl;
				} else {
					cout << "Sum of two numbers is: " << -negativeSum << endl;
				}
			} else {
				signed sum;
				sum = input1 + input2;
				cout << "Sum of two numbers is: " << sum << endl;
			}
		} else {
			cerr << "Error: Invalid input. Non-integer detected." << endl;
		}
	} else {
		cerr << "Error: Invalid input. Non-integer detected." << endl;
	}
}
