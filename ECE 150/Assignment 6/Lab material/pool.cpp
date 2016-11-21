#include <iostream>
#include <fstream>
#include <cmath>
#include "pool.h"

using namespace std;
/*
fin.get() reads the individual characters. Whitespace and newline does not
count as a character.
*/

/*
This function should open the input file and check if it is opened 
correctly. If not, output an error message and return false. 
If so, read the data from the file to the 2D array and return true.
*/

bool readPool(char* filename, float pool[20][10])
{
	ifstream fin(filename);
	if(fin.fail()) {
		cerr << "Error: File not opened." << endl;
		return false;
	}
	int rows, cols;
	// Reads the first character
	fin >> rows;
	// cout << rows << endl;
	char x;
	x = fin.get();
	// fin.get() will read if the proceeding number is a comma, if so it will
	// remove it
	while(x == ',') {
		x= fin.get();
	}
	fin >> cols;
	// fin.get() will read if the proceeding number is a comma, if so it will
	// remove it
	while(x == ',') {
		x= fin.get();
	}
	// cout << cols << endl;
	// Checks to see if the amount of rows and cols are as anticipated
	if(rows != 20 || cols != 10) {
		cerr << "Error: The row or column is not of anticipated size." << endl;
		return false;
	}
	for(int i = 0; i < 20; i++) {
		for(int k = 0; k < 10; k++) {
			fin >> pool[i][k];
			// This part ges rid of the comma inbetween each desired value
			x = fin.get();
		}
	}
	return true;
}

/*
This function should print the data from the 2D array to
an output file.
*/

void printPool(ofstream& fileOut, float pool[20][10])
{
	for(int i = 0; i < 20; i++) {
		for(int k = 0; k < 10; k++) {
			fileOut << pool[i][k] << ",";
		}
		fileOut << endl;
	}
}

/*
This function should find the faulty data and print out 
the row and column number of the faulty locations.
*/
void findFaulty(float pool[20][10])
{
	float avg = 0;
	for(int i = 0; i < 20; i++) {
		for(int k = 0; k < 10; k++) {
			if(pool[i][k] < 0 && pool[i-1][k] < 0 && pool[i+1][k] < 0 && 
				pool[i][k-1] < 0 && pool[i][k+1] < 0) {
				avg = (pool[i-1][k] + pool[i+1][k] +
					pool[i][k-1] + pool[i][k+1])/4;
			}
			if(fabs(pool[i][k] - avg) >= 2) {
				cout << "Row index: " << i << " and col index: " << k
				<< " is faulty." << endl;
			}
		}	
	}
}