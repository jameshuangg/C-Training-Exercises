#include <iostream>

using namespace std;

int convertString_Int(char* c) {
	char* ptr = c;
	int a = 0;
	while(*ptr != '\0') {
		if (*ptr >= 48 && *ptr <= 57) {
			a = (a*10) + (*ptr - 48);
			ptr++;
		}
	}
	return a;
}

int main(int argc, char* argv[]) {
	int a = convertString_Int(argv[1]);
	int b = convertString_Int(argv[2]);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}