#include <iostream>

using namespace std;

int main() {
	unsigned int p;
	int k;
	int holder1;
	int holder2;
	int i;
	int j;

	cout << "Enter an odd prime: ";
	cin >> p;
	k = (p-1)/4;

	if (p == k * 4 + 1) {
		for (i = 0; i*i < p ; ++i) {
			holder1 = i;
		}
		for (j = 0; i*i + j*j <= p; ++j) {
			holder2 = j;
		}
		cout << "a = " << i << ", b = " << j << endl;
	} else {
		cerr << "Error: Condition not met." << endl;
	}
	
}