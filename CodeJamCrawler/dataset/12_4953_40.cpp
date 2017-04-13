/*
 * problem-a_main.cpp
 *
 *  Created on: Apr 14, 2012
 *      Author: Robert
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

char decryptionMap[26][26];

void buildMap()
{
	string input[5] = {"q", "a zoo", "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	string output[5] = {"z", "y qee", "our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < input[i].length(); j++)
		{
			if(input[i][j] != ' ')
			{
				decryptionMap[input[i][j] - 97][0] = output[i][j];
				decryptionMap[input[i][j] - 97][1] = input[i][j];
			}
		}
	}

//	cout << "DECRYPTION MAP:" << endl;
//	for(int i = 0; i < 26; i++)
//	{
//		cout << decryptionMap[i][0] << " " << decryptionMap[i][1] << endl;
//	}
}

int main(int argc, char **argv)
{
	if(argc <= 2)
	{
		cout << "Usage: ./problem-a <input file> <output file>" << endl;
		return -1;
	}

	buildMap();

	string inputFilename = argv[1], outputFilename = argv[2], line;
	ifstream inputFile(inputFilename.c_str());
	ofstream outputFile(outputFilename.c_str());

	int T;

	if(inputFile.is_open())
	{
		if(inputFile.good())
		{
			getline(inputFile, line);
			T = atoi(line.c_str());
			cout << "T: " << T << endl;
		}

		for(int i = 0; i < T; i++)
		{
			getline(inputFile, line);
			for(int j = 0; j < line.length(); j++)
			{
				if(line[j] == ' ')
					continue;
				line[j] = decryptionMap[line[j] - 97][0];
			}

			stringstream ss;
			ss << "Case #" << i + 1<< ": " << line;

			cout << ss.str() << endl;

			if(outputFile.is_open())
				outputFile << ss.str() << endl;
		}

		inputFile.close();
	}
}


