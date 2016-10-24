#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	
	cout << "Please enter an integer number" << endl;
	int n = 0;
	cin >> n;
	
	//check if number is palindrome
	
	int n_copy = n;
	float n_reverse = 0;
	int num_digits = round(log10(n)) + 1;
	
	for(int i = 1; i <= num_digits; i++)
	{
		int r = n % 10;
		n = round(n / 10);
		n_reverse += r * pow(10, num_digits - i);
	}
	
	
	if(n_copy == n_reverse)
	{
		cout << "Your number is palindromic" << endl;
	}
	else
	{
		cout << "Your number is NOT palindromic" << endl;
	}
	
	
}





