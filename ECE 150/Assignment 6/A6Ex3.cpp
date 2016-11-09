#include <iostream>  
// fstream is the library to import files
#include <fstream>
#include <cstdlib>	 
using namespace std;  

void wordCount(ifstream & fileIn, ofstream& fileOut)
{
	//count the number of words separated by space in the input file
	//print to the output file the number of word counts 
	char word[100];
	int count = 0;
	// Reading from the file so you can use >>
	// cin means to read from the keyboard
	while(fileIn >> word) {
		count++;
	}

	// Outputs to the ouput file
	fileOut << "count = " << count << endl;
	//print result to the output file
	
	
}	
	
int main(int argc, char* argv[]) 	
{	
	//the program is run by:
	//A6Ex3a.exe inputFileName.txt outputFileName.txt
	

	//do your usual error checking
	// Has only the program name
	if(argc < 2) {
		cerr << "Error: No input and output files." << endl;
		return -1;
	}
	// No Output file name
	if(argc == 2) {
		cerr << "Error: No ouput file." << endl;
		return -1;
	}
	// Have both input and output files
	// to open the input files
	ifstream fin (argv[1]);
	// to open the output files
	ofstream fout (argv[2]);
	// to check if input file is opened correctly
	if(fin.fail()) {
		cerr << "Error: input file cannot be opened." << endl;
	}

	//call the function here
	wordCount(fin, fout);
	return 0;
}