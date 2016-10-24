#include <iostream>

using namespace std;

int main() {
	int wallLength;
	int snakeLength;
	int wallToSnakeDistance;

	cout << "Wall-to-wall dimension: ";
	cin >> wallLength;
	cout << "Snake length: ";
	cin >> snakeLength;
	cout << "Wall-to-snake tail distance: ";
	cin >> wallToSnakeDistance;

	if (wallToSnakeDistance + snakeLength < wallLength - 1) {
		for (int i = 0; i < wallLength; i++) {
			if (i == 0) {
				cout << '|';
			} else if (i == wallLength - 1) {
				cout << '|' << endl;
			} else if (i > wallToSnakeDistance && i < wallToSnakeDistance
				+ snakeLength) {
				cout << '*';
			} else if (i == wallToSnakeDistance + snakeLength && snakeLength != 0) {
				cout << 'O';
			} else {
				cout << ' ';
			}
		}

	} else {
		cerr << "Error: Invalid input." << endl;
	}


	return 0;
}