#ifndef STUDENT_H
#define STUDENT_H

struct Student
{
  char userId[20];
  int studentNum;
  float mark;
};

void bubbleSort(int numStudent, Student ece150[]);
void displayStudents(int numStudent, Student ece150[]);

#endif
