#include <iostream>

using namespace std;

int main() {
	char textInput[100];
	char textResult[100];
	int startIndex;
	int endIndex;

	cout << "Please input a word: ";
	cin >> textInput;
	cout << "Please input the starting index: ";
	cin >> startIndex;
	cout << "Please input the ending index: ";
	cin >> endIndex;

	if (startIndex < endIndex) {
		for (int i = startIndex; i <= endIndex; i++) {
			textResult[i-startIndex] = textInput[i];
		}

		cout << "The extracted word is: " << textResult << endl;
		return 0;
	} else {
		cerr << "You have entered a starting index greater than ending index.\nPlease enter another number." << endl;
	}
}