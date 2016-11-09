#include <iostream>

namespace myFriend{
	int alice;
	int bob;
}

namespace MyEnemy{
	int alice;
	int frank;
}

// std is a namespace under the library <iostream>.
using namespace std;
// Delete the following namespaces in order to get the first 2 lines in main to work.
using namespace myEnemy;
using namespace myFriend;

int main(){

	cin >> myFriend::alice;
	cin >> myEnemy::alice;

// This won't work because we are using both namespaces
// Here we are calling alice, but the computer doesn't know whether it is from the myEnemy namespace
// or the myFriend namespace
	cin >> alice;
	cin >> bob;
	cin >> frank;

	return 0;
}