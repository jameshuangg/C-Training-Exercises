// Author: James Huang
// Date: November 21, 2016
/* Objective: Create a program that recieves data from an excel file
and outputs the resulting statistics */
#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;
float convertToFloat(char* temporaryCellChars) {
	int charCount = 0;
	float sum = 0;
	bool isNegative = false;
	bool isFloat = false;
	// cout << temporaryCellChars << endl;
	// sum = (temporaryCellChars[charCount] - 48);
	// cout << sum << endl;
	while(temporaryCellChars[charCount] != '\0') {
		if(temporaryCellChars[charCount] == '-') {
			isNegative = true;
			charCount++;
		}
		// If the temporaryCellChars[charCount] stumbles upon a . skip it
		if(temporaryCellChars[charCount] == '.') {
			isFloat = true;
			charCount++;
		}
		// If the temporaryCellChars[charCount] stumbles upon a , skip it
		if(temporaryCellChars[charCount] == ',') {
			break;
		}
		sum = (sum * 10) + (temporaryCellChars[charCount] - 48);
		charCount++;
	}
	sum = (isNegative) ? -sum : sum;
	sum = (isFloat) ? (sum/10) : sum;
	return sum;
}

bool readTahoeData(char* filename, float lake[420][210]) {
	// Opens up the excel file
	ifstream infile(filename);
	// Read the first two pieces of data to confirm it is of size 420x210
	char height[3];
	infile >> height;
	char width[3];
	infile >> width;
	bool correctDimensions = false;
	if(height[0] == '4' && height[1] == '2' && height[2] == '0' &&
	   width[0] == '2' && width[1] == '1' && width[2] == '0') {
	   	// If the if statement is correct, the dimensions work.
		correctDimensions = true;
	}
	/* now I need to create a loop that reads all the data and 
	converts to floating point numbers */
	if(!correctDimensions) {
		cerr << "Error: Dimensions are incorrect." << endl;
		return -1;
	}

	// This for loop is the height
	for(int i = 0; i < 420; i++) {
		// This for loop is the width
		for(int j = 0; j < 210; j++) {
			/*******************************************************
			It can be either a floating point number of int number,
			so I need to check if the contents of the cell is a 
			floating point number or int by checking to see if there
			is a .
			*******************************************************/
			/*******************************************************
			infile will either get XX.X, or XX.X or ,
			in characters so i need to convert to a floating point
			and put it into the lake arrray
			*******************************************************/
			char temporaryCellChars[100];
			// Saves the entire contents of a cell into temporaryCellChars
			do {
				infile >> temporaryCellChars;
				// Convert temporaryCellChars to floating point numbers here
				// If the first char of the temporaryCellChars is a , skip it
				// Else I will run the function to convert the char to a float
				if(temporaryCellChars[0] == ',') {
					temporaryCellChars[0] = temporaryCellChars[0];
				} else {
					//lake[i][j] = convertToFloat(temporaryCellChars);
					lake[i][j] = convertToFloat(temporaryCellChars);
				}
			} while(temporaryCellChars[0] == ',');

		}
	}
	return true;
}

/****************************************
				CLEAN DATA
				1	2	3
1				*	*	*
2				*	*	*
3				*	*	*
****************************************/
void cleanData(float lake[420][210]) {
	// Take 1 to 419 and 1 to 209 because 
	// Create a new array to store the new values
	float tempLake[420][210];
	// First copy the data into the temp 2D array
	for(int m = 0; m < 420; m++) {
		for(int n = 0; n < 210; n++) {
			tempLake[m][n] = lake[m][n];
		}
	}
	// Now check the outlier on the temp array and changed on original
	// i = row, j = column
	for(int i = 1; i < 419; i++) {
		for(int j = 1; j < 209; j++) {
			// Average the cells absolute around the desired cell and
			float average = 0;
			average = (tempLake[i-1][j-1] + tempLake[i-1][j] + 
				tempLake[i-1][j+1] + tempLake[i][j-1] + tempLake[i][j+1] +
				tempLake[i+1][j-1] + tempLake[i+1][j] + tempLake[i+1][j+1])/8;
			// Check the difference to determine if outlier or not
			if(abs(tempLake[i][j] - average) > 100) {
				lake[i][j] = (floor(average * 10 + 0.5))/10;
			}
		}
	}
}

/************************************************************
				CALCULATE AREA OF LAKE
- Reads through the data with a for loop and if the number
is negative, up a counter
************************************************************/

float area(float lake[420][210]) {
	float areaWater = 0;
	for(int i = 0; i < 420; i++) {
		for(int j = 0; j < 210; j++) {
			if(lake[i][j] < 0) {
				areaWater += 10000.0;
			}
		}
	}
	return areaWater;
}

/************************************************************
				CALCULATE VOLUME OF LAKE
- Reads through the data with a for loop and if the number
is negative, can take data for volume
************************************************************/
float volume(float lake[420][210]) {
	float sum = 0.0;
	for(int i = 0; i < 420; i++) {
		for(int j = 0; j < 210; j++) {
			if(lake[i][j] < 0) {
				sum += (lake[i][j] * 10000) * -1;
			}
		}
	}
	return sum;
}


// int main(int argc, char* argv[]) {
// 	float lake[420][210];
// 	readTahoeData(argv[1], lake);
// 	cleanData(lake);
// 	for(int i = 0; i < 420; i++) {
// 		for(int j = 0; j < 210; j++) {
// 			cout << lake[i][j] << endl;
// 		}
// 	}
// 	cout << "Area of the land is: " << area(lake) << endl;
// 	cout << "Volume of the lake is: " << volume(lake) << endl;
// }