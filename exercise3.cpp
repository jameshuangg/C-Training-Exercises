#include <iostream>

using namespace std;

int main() {
	int userInput;
	int i = 8;
	cout << "Please type numbers from 8 to 23: ";
	cin >> userInput;

	while (userInput == i) {
		cout << "Correct! Continue.";
		i++;
	}
	
	return 0;
}