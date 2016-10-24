#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << setprecision(20) << fixed;
	double A;
	double B;

	cout << "Enter two numbers (each separated by a space): ";
	cin >> A >> B;
	cout << "A/B = " << A/B << endl;

	return 0;
}