// Author: James Huang
// Date: Nov 7, 2016
// Objective: Create a program that is able to sort names
#include "Sorting.h"
#include <iostream>

using namespace std;

void bubbleSort(int numNames, char* firstName[], char* lastName[], int age[]) {
	for(int j = 0; j < numNames - 1; j++) {
		for(int i = 0; i < numNames - 1; i++) {
			if(stringCmp(lastName[i], lastName[i+1]) == -1) {
				stringSwap(lastName[i], lastName[i+1]);
				stringSwap(firstName[i], firstName[i+1]);
				int temp = age[i];
				age[i] = age[i+1];
				age[i+1] = temp;
			} else if(stringCmp(lastName[i], lastName[i+1]) == 0) {
				if(stringCmp(firstName[i], firstName[i+1]) == -1) {
					stringSwap(lastName[i], lastName[i+1]);
					stringSwap(firstName[i], firstName[i+1]);
					int temp = age[i];
					age[i] = age[i+1];
					age[i+1] = temp;
				}
			}
		}
	}
}

void displayNames(int numNames, char* firstName[], char* lastName[], int age[]) {
	// Each iteration displays a person's full name and corresponding age
	for(int i = 0; i < numNames; i++) {
		cout << firstName[i] << " " << lastName[i] << " " << age[i] << endl;
	}
}

int stringCmp(char str1[], char str2[]) {
	// Check if str1 ends and str2 goes on
	// Check if str2 ends and str1 goes on
	// Check if str1 capital and str2 lowercase
	// Check if str2 capital and str1 lowercase
	// now just compare ascii values
	// If need to swap, return -1
	// If already in order return 1
	// If equal return 0
	int charCount = 0;
	while(str1[charCount] != '\0' || str2[charCount] != '\0') {
		if(str1[charCount] == '\0' && str2[charCount] != '\0') {
			return 1;
		} else if(str1[charCount] != '\0' && str2[charCount] == '\0') {
			return -1;
		} else if(str1[charCount] < 96 && str2[charCount] > 96) {
			return 1;
		} else if(str1[charCount] > 96 && str2[charCount] < 96) {
			return -1;
		} else if(str1[charCount] < str2[charCount]) {
			return 1;
		} else if(str1[charCount] > str2[charCount]) {
			return -1;
		}
		charCount++;
	}
	return 0;
}

void stringSwap(char* &str1, char* &str2) {
	char* temp = str1;
	str1 = str2;
	str2 = temp;
}
