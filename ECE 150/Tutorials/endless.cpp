/********************************************
Everytime we use the keyword (new)
We are allocating data into the heap vs the stack
********************************************/
#include <iostream>

using namespace std;

int main() {
	// int Array[10000];
	// int elements = 0;
	// cout << "Input: " << endl;
	// // 1st part **************************
		// while(true) {
		// 	cin >> Array[elements];
		// 	++elements;

		// 	if (Array[elements-1] == 0) {
		// 		--elements;
		// 		break;
		// 	}
		// }

		// // Print Elements
		// cout << "Your list: " << endl;
		// for (int i =0; i <= elements - 1; ++i) {
		// 	cout << Array[i] << endl;
		// }
	// // end 1st part************************

	// 2nd part ******************************
		// for (int i =1; true; i++) {
		// 	int arrayPointer[i];
		// 	cerr << "\nArray size;"
		// }
	// end of 2nd part ***********************

	// 3rd part ****************************
	// Uses heap memory
		// for (int i =1; true; i+=10000) {
		// 	int* my_Array = new int[i];

		// 	for (int j = 0; j < i; ++j)
		// 		my_Array[j] = j;

		// 	delete[] my_Array;
		// 	cerr << "\nArray Size: " << i;
		// }
	// end of 3rd part

	// 4th part ***************************
		// int elements;
		// int count = 0;
		// cout << "Please enter maximum size:" << endl;
		// cin >> elements;
		// int* arr = new int[elements];
		// cout << "Please input numbers: " << endl;
		// while(count < elements) {
		// 	cin >> arr[count];
		// 	++count;
		// }
		// for
	// end of 4th part *********************

	// assignment 3 ************************

	// end of assignment 3 *****************
}