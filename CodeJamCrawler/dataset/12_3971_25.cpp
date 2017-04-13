// CodeJam2012.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int indexof(char c, string s)
{
	int i=0;
	while(s[i])
	{
		if(c == s[i])
		{
			return i;
		}
		i++;
	}
	return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ofstream outputFile;
	ifstream inputFile;
	int numberOfText,codeToOriginIndex;
	string processedString;
	string decodedString;

	string coded="abcdefghijklmnopqrstuvwxyz ";
	string original="yhesocvxduiglbkrztnwjpfmaq ";

	inputFile.open("A-small-attempt1.in");
	outputFile.open("debug.out");

	inputFile >> numberOfText;
	getline(inputFile,processedString);
	for(int i=0;i<numberOfText;i++)
	{
		getline(inputFile,processedString);
		decodedString=processedString;
		
		for(int k=0;k<processedString.length();k++)
		{
			codeToOriginIndex = indexof(processedString[k],coded);
			decodedString[k] = original[codeToOriginIndex];
		}

		outputFile << "Case #"<< i+1 << ": " << decodedString;
		if(i<numberOfText-1) outputFile << "\n";
	}
	


	inputFile.close();
	outputFile.close();

	return 0;
}

