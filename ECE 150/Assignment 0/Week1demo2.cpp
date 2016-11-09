#include <iostream>

using namespace std;

int main() {

	int n;

	//1. Take input, n, a non-negative interger
	cout << "Which Fibonacci number you'd like to see?";
	cin >> n;

	//2. If n = 0, output 0 and stop
	if(n == 0) {
		cout << "Fibonacci Number #" << n << " is 0" << endl;
	}

	//3. If n = 1, output 1 and stop
	else if(n == 1) {
		cout << "Fibonacci Number #" << n << " is 1" << endl;
	}

	//4. Otherwise, introduce a new variable, k, and initialize it to 1
	else {

	//5. Introduce two other variables, Fk01 = 0, Fk = 1
		int Fk = 1; // F1 = 1
		int Fkm1 = 0 // F0 = 0
		int Fk_old;

		int k = 1;

		while(k != n) {
	//6. Set:
	// New value of k = (old value of k) + 1
			k = k + 1;
	// New vale of Fk = (old value of Fk) + (old value of Fk-1)
			Fk_old = Fk;
			Fk = Fk + Fkm1;
	// New value of Fk- 1 = old value of Fk
			Fkm1 = Fk_old;
			Fk_old = Fk;
		}

		cout << "Result" << Fk << endl;
	}
}