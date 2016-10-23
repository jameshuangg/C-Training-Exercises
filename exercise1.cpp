#include <iostream>

using namespace std;

int main() {
	int userInput;

	cout << "Please enter an integer between 0 and 100: ";
	cin >> userInput;

	if (userInput >= 56 && userInput <= 78) {
		cout << "YOU WIN!" << endl;
	} else {
		cout << "YOU LOSE!" << endl;
	}

	return 0;
}