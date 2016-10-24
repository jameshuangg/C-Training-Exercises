#include <iostream>

using namespace std;

int main() {
	unsigned int input;
	int shiftAmount;

	cout << "Enter an integer you want to operate on: ";
	cin >> input;
	cout << "Enter the amount you want to shift by: ";
	cin >> shiftAmount;

	input = input >> shiftAmount;
	cout << "Your new integer is: " << input << endl;

}