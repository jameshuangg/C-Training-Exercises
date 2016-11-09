#include <iostream>

using namespace std;

int main() {
	
	int x = 0;
	int y = 0;
	int average = 0;
	cout << "Please provide the first number " << endl;
	cin >> x;

	cout << "Please provide the second number" << endl;
	cin >> y;

	average = (x + y) / 2;  

	cout << "The average of the two numbers is " << average << endl;

	return 0;
}