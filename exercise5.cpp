#include <iostream>

using namespace std;

int main() {
	int input;
	int holder = ;
	for (int i = 0; i < 10; i++) {
		cout << "Please type in an integer: ";
		cin >> input;

		if (input < holder) {
			holder = input;
		}
	}
	cout << "The smallest integer that you entered is: ";
	cout << holder << endl;
}