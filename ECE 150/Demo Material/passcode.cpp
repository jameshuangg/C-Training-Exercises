#include <iostream>

using namespace std;

int main() {
	char firstChar;
	char secondChar;
	char thirdChar;
	int passcode;

	cout << "Enter three characters consecutively without space: ";
	cin >> firstChar >> secondChar >> thirdChar;

	passcode = 1000000*firstChar + 1000*secondChar + thirdChar;
	cout << "The corresponding passcode is: " << passcode << endl;

	return 0;
}