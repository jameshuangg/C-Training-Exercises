#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << setprecision(2) << fixed;
	float listPrice;
	float discountRate;
	float salesTax;
	float netPrice;


	cout << "Enter the offer price of the item: ";
	cin >> listPrice;
	cout << "Discount rate (%): ";
	cin >> discountRate;
	cout << "Tax rate (%): ";
	cin >> salesTax;

	netPrice = listPrice - (listPrice * (discountRate / 100));
	netPrice += netPrice * (salesTax / 100);

	cout << "The net price of the item is: ";
	cout << netPrice << endl;
}