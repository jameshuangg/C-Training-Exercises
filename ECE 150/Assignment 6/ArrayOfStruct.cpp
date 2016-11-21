// Author: James Huang
// Date: November 15, 2016
/************************************************************
Instead of individually swapping three separate arrays for 1
person. We can create a struct such that once something needs
to be switched, we just need to switch the person. This
automatically switches the firstName/Lastname/Age.
************************************************************/
#include <iostream>
#include "ArrayOfStruct.h"

using namespace std;

// Checks the last name first, then first, then age
void displayNames(int numPeople, Person people[]) {
	for(int i = 0; i < numPeople; i++) {
		cout << people[i].firstName << ' ' << people[i].lastName << ' ' <<
		people[i].age << endl;
	}
}

int stringCmp(char str1[], char str2[]) {
	// If need to swap, return -1
	// If already in order return 1
	// If equal return 0
	int charCount = 0;
	// I change everything to capital letters
	// Check if str1 ends and str2 goes on
	// Check if str2 ends and str1 goes on
	while(str1[charCount] != '\0' || str2[charCount] != '\0') {
		if(str1[charCount] > 90) {
			str1[charCount] -= 32;
		}
		if(str2[charCount] > 90) {
			str2[charCount] -= 32;
		}
		if(str1[charCount] == '\0' && str2[charCount] != '\0') {
			return 1;
		} else if(str1[charCount] != '\0' && str2[charCount] == '\0') {
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

void peopleSwap(Person &people1, Person &people2) {
	Person temp = people1;
	people1 = people2;
	people2 = temp;
}

void bubbleSort(int numPeople, Person people[]) {
	for (int j = 0; j < numPeople; j++) {
		for (int i = 0; i < numPeople - 1; i++) {
			if(stringCmp(people[i].lastName, people[i+1].lastName) == -1) {
				peopleSwap(people[i], people[i+1]);
			} else if(stringCmp(people[i].lastName, people[i+1].lastName) == 0) {
				if(stringCmp(people[i].firstName, people[i+1].firstName) == -1) {
					peopleSwap(people[i], people[i+1]);
				} else if(stringCmp(people[i].firstName, people[i+1].firstName) == 0) {
					if(people[i].age > people[i+1].age)
						peopleSwap(people[i], people[i+1]);
				}
			}
		}
	}
}