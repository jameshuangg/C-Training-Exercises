// Author: James Huang
// Date: November 20, 2016
/* Objective: Create a program that reads a file given its name and produces
document statistics */

#include <iostream>
#include <fstream>
#include <climits>
#include <iomanip>

using namespace std;

/*******************************************************
This function will take the input file name:
- Returns 1 if the file has the txt extension, get rid of ext
- Returns 0 if the file does not have the txt extension
- Returns -1 if the file file has a different extension
*******************************************************/
bool inputFileValid(int &inputFileCharCount, char argv[]) {
	// Check to see if argument has .txt extension yet
	while (argv[inputFileCharCount] != '\0') {
		if(argv[inputFileCharCount] == '.') {
			if(argv[inputFileCharCount + 1] == 't' && 
				argv[inputFileCharCount + 2] == 'x' && 
				argv[inputFileCharCount + 3] == 't') {
				return true;
			} else {
				return false;
			}
		}
		inputFileCharCount++;
	}
	return true;
}

/* Adds the .txt extension to make the file name valid */
void inputFileAppend(int inputFileCharCount, char argv[], char fileName[]) {
	for(int i = 0; i < inputFileCharCount; i++) {
		fileName[i] = argv[i];
	}
	fileName[inputFileCharCount] = '.';
	fileName[inputFileCharCount + 1] = 't';
	fileName[inputFileCharCount + 2] = 'x';
	fileName[inputFileCharCount + 3] = 't';
	fileName[inputFileCharCount + 4] = '\0';
}
/* Adds the .anl extension to make the output name */
void outputFileAppend(int inputFileCharCount, char argv[], char fileName[]) {
	for(int i = 0; i < inputFileCharCount; i++) {
		fileName[i] = argv[i];
	}
	fileName[inputFileCharCount] = '.';
	fileName[inputFileCharCount + 1] = 'a';
	fileName[inputFileCharCount + 2] = 'n';
	fileName[inputFileCharCount + 3] = 'l';
	fileName[inputFileCharCount + 4] = '\0';
}

/*****************************************************************
This function will analyze the input file:
- Count the number of words separated by whitespace or punctuation
- Determine the longest word
- Determine the shortest word
- Determine the average word length (total letters / numWords)
*****************************************************************/
void analyzeFile(ifstream &infile, int &numWords, int &longestWord, 
	int &shortestWord, float &averageWordLength) {
	float totalCharacters = 0;
	// Goes through the entire document
	while(infile.peek() != EOF) {
		int letterCounter = 0;
		// skips to next char if its not a letter
		while((infile.peek() < 65 || (infile.peek() > 90 &&
		 	infile.peek() < 97) || (infile.peek() > 122))) {
			if(infile.peek() == EOF) {
				return;
			}
			infile.get();
		}
		// when it gets to letter
		while((infile.peek() > 64 && infile.peek() < 91) ||
		 	(infile.peek() > 96 && infile.peek() <123)) {
			letterCounter++;
			totalCharacters++;
			infile.get();
		}
		if(letterCounter > longestWord) {
				longestWord = letterCounter;
			}
		if(letterCounter < shortestWord) {
			shortestWord = letterCounter;
		}
		numWords++;
		averageWordLength = totalCharacters/numWords;
	}
}

/********************************************************************
This function will analyze the input file for argument occurances by: 
********************************************************************/
int argumentOccurance(ifstream &infile, char argument[]) {
	// Reinitialze the infile
	infile.clear();
	infile.seekg(0, infile.beg);

	// Declare variables
	int occurances = 0;
	int letters = 0;
	while(argument[letters] != '\0') {
		letters++;
	}

	while(infile.peek() != EOF) {
		// Skips to the next char if not a letter
		while(infile.peek() < 65 || infile.peek() > 122 ||
			(infile.peek() > 90 && infile.peek() < 97)) {
			if(infile.peek() == EOF) {
				return occurances;
			}
			infile.get();
		}

		// When the peek encounters letters it will run through here
		while((infile.peek() > 64 && infile.peek() < 91) || 
			(infile.peek() > 96 && infile.peek() < 123)) {
			// This part is not running
			char temp = infile.peek();
			if(temp == argument[0] || temp + 32 == argument[0] ||
				temp - 32 == argument[0]) {
				int argumentLetters = 0;
				bool occuranceStatus = true;
				while(argument[argumentLetters] != '\0' && (occuranceStatus)) {
					if(infile.peek() == argument[argumentLetters] - 32) {
						argument[argumentLetters] -= 32;
					} else if(infile.peek() == argument[argumentLetters] + 32) {
						argument[argumentLetters] += 32;
					}
					if(infile.peek() == argument[argumentLetters]) {
						infile.get();
						argumentLetters++;
					} else {
						occuranceStatus = false;
					}
				}

				argumentLetters == letters? occurances++ : occurances = occurances;
			} else {
				infile.get();
			}
		}
	}
	return occurances;
}

// Main running function
int main(int argc, char* argv[]) {
	// Error Checking
	if (argc < 2) {
		cerr << "Error: No input file." << endl;
		return -1;
	}
	// Declarations & initializations
	int inputFileCharCount = 0;
	bool inputFileStatus = inputFileValid(inputFileCharCount, argv[1]);
	char fileName[inputFileCharCount + 5];
	char outputName[inputFileCharCount + 5];
	// Statistic Declarations
	// Start it at one because there is no space at the end
	int numWords = 0;
	int longestWord = 0;
	int shortestWord = INT_MAX;
	float averageWordLength = 0;
	int occurances;
	// Algorithm
	if (inputFileStatus) {
		// Handling the file Name
		inputFileAppend(inputFileCharCount, argv[1], fileName);
		outputFileAppend(inputFileCharCount, argv[1], outputName);
		// Opening input and outfiles
		ifstream infile;
		infile.open(fileName);
		if(!infile.is_open()) {
			cerr << "Error: No file of name " << fileName << " found." << endl;
			return -1;
		}
		ofstream outfile;
		outfile.open(outputName);
		// Analyzing the input file
		analyzeFile(infile, numWords, longestWord, shortestWord, averageWordLength);
		// Output resulting statistics
		outfile << "Number of words: " << numWords << endl;
		outfile << "Longest word: " << longestWord << endl;
		outfile << "Shortest word: " << shortestWord << endl;
		outfile << setprecision(2) << fixed <<
		"Average word length: " << averageWordLength << endl;
		// Output resulting statistics on arguments
		if(argc > 2) {
			for(int i = 2; i < argc; i++) {
				occurances = argumentOccurance(infile, argv[i]);
				outfile << "Number of occurances of " << argv[i] << ": " 
				<< occurances << endl;
			}
		}
		// Close the opened files
		infile.close();
		outfile.close();
	} else {
		cerr << "Error: Invalid input file." << endl;
		return -1;
	}
	return 0;
}