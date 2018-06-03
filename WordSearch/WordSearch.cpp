// WordSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define N_WORDS 10
const int MAX_WORDS = 1024;

void main()
{
	ifstream inputFile1("inputfile1.txt");
	ifstream inputFile2("inputfile2.txt");
	ofstream outputFile("outputfile.txt");
	string word[MAX_WORDS];
	string word2[MAX_WORDS];
	int numOccured = 0;
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
			inputFile2.clear();
			inputFile2.seekg(0, ios::beg);
			outputFile << word[i] << " - Found " << numOccured << " times." << endl;
			numOccured = 0;
		}
	}
	inputFile1.close();
	inputFile2.close();
	outputFile.close();
	system("pause");
}