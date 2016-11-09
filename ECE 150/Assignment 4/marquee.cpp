#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	// Declare and Initialize
	// Create an array that carries all of the marquee elements
	// Need 9 elements here because the last one needs to be null character 
	char marquee[8] = {'!', 'E', 'C', 'E', '1', '5', '0', '!'};
	char location[60];
	int cycles;

	cout << "Enter desired amount of cycles: ";
	cin >> cycles;
	/* I need to take each individual marquee element and put it into
	the location array */
	// This for loop represnts the amount of cycles
		// This for loop represents the frames
	for (int wrap = 0; wrap < cycles; wrap++) {
		for (int j = 0; j < 60; j++) {
			cout << "=============================="
			"==============================" << endl;
			// Resets the array to a blank
			for (int k = 0; k < 60; k++) {
				location[k] = ' ';
			}

			if (j > 52) {
				for (int m = 0; m < 60 - j; m++) {
					location[j+m] = marquee[m];
				}
				int p = 8 - (60 - j);
				for (int n = 0; n < 8 - (60 - j); n++) {
					location[n] = marquee[8-p];
					p--;
				}
			} else {
				// Prints the marquee elements at the location
				for (int i = 0; i < 8; i++) {
					location[i+j] = marquee[i];
				}
			}

			cout << location << endl;
			cout << "=============================="
			"==============================" << endl;
			for (int downer = 0; downer < 10000000; downer++) {
				downer += 1;
			}
			system("clear");
		}
	}
	cout << "=============================="
	"==============================" << endl;
	for (int i = 0; i < 8; i++) {
		location[i] = marquee[i];
	}
	location[59] = ' ';
	cout << location << endl;
	cout << "=============================="
	"==============================" << endl;
	return 0;
}