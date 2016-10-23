// Author: James Huang
// Date: October 23
// Objetive: Create a recursive function of form u(n+1)=u(n)+u(n-1)
#include <iostream>

using namespace std;

int recursive(int a) {
	if (a == 0 || a == 1) {
		return 1;
	} else {
		return recursive(a-1) + recursive(a-2);
	}
}

int main() {
	int input;
	cout << "Please enter an integer: ";
	cin >> 

}