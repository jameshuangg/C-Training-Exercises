#include <iostream>

using namespace std;

int main() {
	//Declarations
	int base;
	int height;
	//Initialization & input error check
	cout << "Please enter an odd size for the base of the hourglass: ";
	cin >> base;
	if (base > 0 && base % 2 == 1) {
		height = base;

		//Drawing Algorithm
		for (int i = 0; i < height; i++) {
			// Draws the base of the hourglass
			if (i == 0 || i == height - 1) {
				for (int j = 0; j < base; j++) {
					cout << '*';
				}
			// Draws body of hourglass
			} else {
				if (i < height / 2) {
					for (int j = 0; j < base; j++) {
						if (j > i - 1 && j < base - i) {
							cout << '*';
						} else {
							cout << ' ';
						}
					}
				} else if (i >= height / 2) {
					for (int j = 0; j < base; j++) {
						if (j < height - i - 1 || j > i) {
							cout << ' ';
						} else {
							cout << '*';
						}
					}
				}
			}
			cout << endl;
		}
	} else {
		cerr << "Error: Invalid Input." << endl;
	}

	return 0;
}