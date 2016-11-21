#include <iostream>
#include <fstream>

using namespace std;

int numWords(ifstream &infile) {
	int wordCount = 1;
	while(infile.peek() != EOF) {
		// Start wordCount at one because the condition is unable to
		// satisfy the last word in the file.
		char c = infile.get();
		if (c == ' ') {
			wordCount++;
		}
	}
	return wordCount;
}

int maxWordLength(ifstream &infile) {
	int maxLength = 0;
	int lengthCounter = 0;
	while(infile.peek() != EOF) {
		char c = infile.get();
		if ((c > 64 && c < 90) || (c > 96 && c < 123)) {
			lengthCounter++;
			if(lengthCounter > maxLength) {
				maxLength = lengthCounter;
			}
		} else if(c == ' ' || c == '\n') {
			lengthCounter = 0;
		}
	}
	return maxLength;
}

int main(int argc, char* argv[]) {
	int wordCount = 0;
	int maxLength = 0;
	ifstream infile(argv[1]);
	wordCount = numWords(infile);
	infile.seekg(0, infile.beg);
	maxLength = maxWordLength(infile);
	cout << "Word Count : " << wordCount << endl;
	cout << "Max length: " << maxLength << endl;
}