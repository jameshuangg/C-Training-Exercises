#include <iostream>

using namespace std;

int main() {
	
	for (int i = 0; i < 10; i++) {
		cout << "Enter an integer: ";
		cin >> store;
		store += store;
	}
	cout << store;
}