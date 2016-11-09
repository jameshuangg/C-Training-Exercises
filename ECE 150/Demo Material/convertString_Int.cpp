#include <iostream>

using namespace std;

int convertString_Int(char* c) {
	// Assigns the pointer address of c to variable ptr
	char* ptr = c;
	int a = 0;
	// While the value of the pointer address is not the null character
	// Run the while loop
	while(*ptr != '\0') {
		// Here we use 48 because it represents 0 in ascii
		if (*ptr >= 48 && *ptr <= 57) {
			a = (a*10) + (*ptr - 48);
			ptr++;
		}
	}
	return a;
}

// This prints the individual array elements given a number of inputs
void printIntArray(int n, int intArray[]) {
	for (int i = 0; i < n; i++) {
		cout << intArray[i] << endl;
	}
}

//******************************
// MAIN FUNCTION
//******************************
int main(int argc, char* argv[]) {
	int intArray[20] = {0};
	for (int i = 1; i < argc; i++) {
		intArray[i-1] = convertString_Int(argv[i]);
	}
	cout << "After conversion, this is from an int array." << endl;
	// Here we use argc because we don't want to include the first argument
	// which is the name of the program
	printIntArray(argc-1, intArray);
	return 0;
}