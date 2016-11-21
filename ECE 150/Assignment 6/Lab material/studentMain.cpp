#include <iostream>
#include <fstream>

#include "student.h"

using namespace std;

int read(ifstream & fin, Student ece150[])
{
	int i = 0;
	
	while (i < 20 && fin >> ece150[i].studentNum)
	{
		fin >> ece150[i].userId >> ece150[i].mark ;
		i++;
	}
	return i;
}


int main() 
{
  ifstream fin ("midterm.txt");
  if (fin.fail()) 
  {
      cerr << "Error: file not open.\n";
      return -1;
  }
  
  Student ece150[20];
  int numStudent = read(fin, ece150);
  cout << "Before Sorting:\n\n";
  displayStudents(numStudent, ece150);
  
  bubbleSort(numStudent, ece150);
  
  cout << "\n\nAfter Sorting:\n\n";
  displayStudents(numStudent, ece150);
	
  return 0;
}

