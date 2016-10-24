#include <iostream>

using namespace std;

int main() {
	unsigned int input;
	int count;

	cout << "Enter an unsigned integer: ";
	cin >> input;

	while(input != 0) {
		input = input >> 1;
		++count;
	}
	cout << "Your integer is " << count << " bits long." << endl;

	return 0;
}