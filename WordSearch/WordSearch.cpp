// Read in a file that contains a list of 10 words.
//
// Then, scan another file that contains at least 3 paragraphs from your favorite book.
// Count the number of the words from the first file that are contained in the second.
// Write the results to a file in the format of :
//
// Word1 – Found x times
// Word2 – Found y times
// (repeat for all 10 words)

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_WORDS = 1024;

void main()
{
	// Input Files
	ifstream inputFile1("inputfile1.txt");
	ifstream inputFile2("inputfile2.txt");
	// Output Files
	ofstream outputFile("outputfile.txt");
	// Arrays to hold words
	string word[MAX_WORDS];
	string word2[MAX_WORDS];
	// Number of times a word occured
	int numOccured = 0;
	// Compare inputFile1 word 1 with all of inputFile2 words and increase numOccured by 1 every time they're the same.
	for (int i = 0; i < MAX_WORDS; i++)
	{
		if (!inputFile1.eof())
		{
			inputFile1 >> word[i];
			for (int j = 0; j < MAX_WORDS; j++)
			{
				if (!inputFile2.eof())
				{
					inputFile2 >> word2[j];
					 if (word[i] == word2[j])
					 {
						numOccured++;
					 }
				}
			}
			// Restart inputFile2, so we can go to the next word
			inputFile2.clear();
			inputFile2.seekg(0, ios::beg);
			// output to the outputFile
			outputFile << word[i] << " - Found " << numOccured << " times." << endl;
			// reset the counter to 0
			numOccured = 0;
		}
	}

	// Close all opened files
	inputFile1.close();
	inputFile2.close();
	outputFile.close();
	system("pause");
}