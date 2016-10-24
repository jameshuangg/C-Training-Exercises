#include <iostream>
#include <string>

using namespace std;


int addition (int a, int b) {
	int r;
	r = a + b;
	return r;
}

int main() {
	int input1;
	int input2;
	int sum;
	cout << "Please enter two integers separated by a space: ";
	cin >> input1 >> input2;
	sum = addition(input1, input2);
	cout << "The sum of the two integers is: " << sum << endl;

	return 0;

}