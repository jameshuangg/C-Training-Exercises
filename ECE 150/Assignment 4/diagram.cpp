// Author: James Huang
// Date: October 26, 2016
// Objective: Create a console based screen saver

#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	// Let i represent the frame number (start at 0)
	for (int i = 0; i < 60; i++) {
		cout << "=============================="
		"==============================" << endl;
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		cout << "O" << endl;
		cout << "=============================="
		"==============================" << endl;
		for(int i = 0; i < 5000000; i++) i = (i + i) / 2;
		// The system("cls") command does not work on MAC
		// For MAC's you have to use system("clear")
		system("clear");
	}

	return 0;
}