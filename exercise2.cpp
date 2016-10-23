#include <iostream>

using namespace std;

int main() {
	for (int i = 8; i >= 8 && i <= 23; i++) {
		int input;

		cout << "Please type integers 8 to 23: ";
		cin >> input;
		if (input == i) {
			cout << "Great! Continue\n";
		} else {
			cout << "Whoops, wrong number!\n";
			break;
		}
	}
}