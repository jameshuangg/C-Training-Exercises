#include <iostream>

using namespace std;

int main(){

	int a;
	int k = 2;
	
	cout << "Give me a number and I will see whether this is a prime number...";
	cin >> a;
	
	while(k != a){
		if((a % k) == 0){
			cout << "The number " << a << " IS a prime number!";
			return 0;
		}
		k++;
	}

	cout << "The number " << a << " is NOT a prime number!";
	return 0;

}
