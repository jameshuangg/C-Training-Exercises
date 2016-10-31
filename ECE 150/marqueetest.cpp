// Author: James Huang
// Date: October 26, 2016
// Objective: Create a program that sends a marquee element across the screen

#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int charPosition[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	char marqueeArray[8] = {'!', 'E', 'C', 'E', '1', '5', '0', '!'};

	for (int k = 0; k < 5; k++) {
		// i less than 3 because there is 3 rows
		for (int i = 0; i < 3; i++) {
			// j less than 60 because 60 is our screen size
			// j represents the column
			for (int j = 0; j < 60; j++) {
				// If the rows are 1st or 3rd it will printout 60 ='s
				if (i == 0 || i == 2) {
					cout << "=";
				// else if in 2nd row, it will printout the marquee element
				} else if (i == 1) {
					// this statement is invaid, charPosition
					// will always be greater than j after 1st iteration

						if (j == charPosition[j]) {
							cout << marqueeArray[j];
						}

				}
			}
			cout << endl;

		}
		// Testing
		for (int l = 0; l < 8; l++) {
			charPosition[l] = (charPosition[l] + 1) % 60;
		}
		for (int i = 0; i < 8; i++) {
			cout << charPosition[i] << endl;
		}
	}
}