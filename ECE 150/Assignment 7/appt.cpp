#include <iostream>
using namespace std;

struct Student
{
	char name[20];
	int  studentNum;  	
	int  time;		//in 24 hour format, e.g. 1400 means 2 p.m.
};
 
struct Appointment 
{
     const Student*    std;
     Appointment* next;
};

//Ex.3: Code the print function that prints the node contents of the priority queue
void print(Appointment*& a)
{
	cout << endl;
	if(a == NULL) {
		cout << "Empty appointment list.\n";
		return;
	}
	Appointment* temp = a;
	while(temp != NULL) {
		cout << temp -> std -> name << " "
			 << temp -> std -> studentNum << " "
			 << temp -> std -> time << endl;
		temp = temp -> next;
	}
	cout << endl;
}

int main()
{
	const Student s1 = { "Helen", 20114532, 1430 };
	const Student s2 = { "Jo", 20142879, 1300 };
	const Student s3 = { "Ahmed", 20126409, 1625 };
	
	//Ex.1: Make an appointment node for each student
	Appointment* node1 = new Appointment;
	const Student* s = &s2;
	node1->std = s;
	node1->next = NULL;

	Appointment* node2 = new Appointment;
	s = &s1;
	node2->std = s;
	node2->next = NULL;

	Appointment* node3 = new Appointment;
	s = &s3;
	node3->std = s;
	node3->next = NULL;

	//Ex.2: Declare an appointment type pointer called a, link the nodes 
	// to make a list and make a point to the first node 
	Appointment* a = node1;
	node1->next = node2;
	node2->next = node3;
		
	//Ex.3: Code the print function and use it to print out the list of appointments
	print(a);
	
	
	//Ex.4: dequeue the list one by one
	if(a == 0) {
		cout << " Empty appointment list. Nothing to delete." << endl;
	} else {
		Appointment* temp = a;
		while(temp != NULL) {
			s = a->std;
			a = a->next;
			delete temp;
			cout << s->name << " with studentNum " << s->studentNum
				 << " is removed from the appointment list. \n";
			temp = a;
		}
	}
	//print the list again to see if nodes of the list are deleted
	print(a);
	
	return 0;
}
/*
Output on the console if coded properly:

Jo 20142879 1300
Helen 20114532 1430
Ahmed 20126409 1625

Jo with studentNum 20142879 is removed from the appointment list.
Helen with studentNum 20114532 is removed from the appointment list.
Ahmed with studentNum 20126409 is removed from the appointment list.

Empty appointment list.

--------------------------------
Process exited after 0.06866 seconds with return value 0
Press any key to continue . . .
*/

