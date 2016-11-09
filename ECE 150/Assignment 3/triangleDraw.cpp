#include <iostream>

using namespace std;

int main() {
	//Declarations
	int base;
	int height;
	//Initialization & input error check
	cout << "Please enter an odd size for the base of the triangle: ";
	cin >> base;
	if (base > 0 && base % 2 == 1) {
		height = (base / 2) + 1;

		//Drawing Algorithm
		for (int i = 0; i < height; i++) {
			// Draws the base of the triangle
			if (i == 0) {
				for (int j = 0; j < 2 * height - 1; j++) {
					cout << '*';
				}
				cout << endl;
			// Draws the rest of the triangle
			} else {
				for (int j = 0; j < 2 * height - 1; j++) {
					if (j > i - 1 && j < base - i) {
						cout << '*';
					} else {
						cout << ' ';
					}
				}
				cout << endl;
			}
		}
	} else {
		cerr << "Error: Invalid Input." << endl;
	}

	return 0;
}