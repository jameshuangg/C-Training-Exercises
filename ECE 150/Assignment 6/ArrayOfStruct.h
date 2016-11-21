#ifndef ARRAYOFSTRUCT_H
#define ARRAYOFSTRUCT_H

struct Person {
  char firstName[20];
  char lastName[20];
  int age;
};

void bubbleSort(int numPeople, Person people[]);
void displayNames(int numPeople, Person people[]);
int stringCmp(char str1[], char str2[]);
void peopleSwap(Person &people1, Person &people2);

#endif
