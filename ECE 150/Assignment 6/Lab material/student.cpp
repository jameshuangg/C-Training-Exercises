#include <iostream>
#include <fstream>
#include <cstdlib>

#include "student.h"

using namespace std;

//write a function to swap two students
void studentSwap(Student &student1, Student &student2) {
	Student temp = student1;
	student1 = student2;
	student2 = temp;
}

// sort students' marks in ascending order
void bubbleSort(int numStudents, Student ece150[])
{
	for(int i = 0; i < numStudents; i++)
	{
		for(int k = 0; k < numStudents - 1; k++)
		{
			if(ece150[k].mark > ece150[k+1].mark)
			{
				//use the Swap function above
				studentSwap(ece150[k], ece150[k+1]);
			}
		}
	}
}


//write a function to convert the userId to either 
//all lower case or all upper case 
void convert(int numStudents, Student s[], bool lower)
{
	for(int i = 0; i < numStudents; i++)
	{
		
		int k = 0;
		//convert each character to either lower or upper
		//case until the end of the string
		while(s[i].userId[k] != '\0')
		{
			if (lower)//if lower == true
				//convert this character to lower case
				s[i].userId[k] = tolower(s[i].userId[k]);
			else
				//convert this character to upper case
				s[i].userId[k] = toupper(s[i].userId[k]);
			k++;
		}
	}
}


//write a function to print to the console student's 
//number, userid, and mark
void displayStudents(int numStudents, Student ece150[])
{
	//use the helper function to convert userId to be either 
	//all lower or all upper
	convert(numStudents, ece150, true);
	
	for(int i = 0; i < numStudents; i++)
	{
		cout << ece150[i].studentNum << " " 
		     << ece150[i].userId << " " 
			 << ece150[i].mark << endl;
	}
}
