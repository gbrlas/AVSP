#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
int getStartIndexOfTokenSet (string testCase, int tokenSet)
{
	bool startToken = false;
	int indexToReturn = 0;
	int numOfTokens = 0;

	for(int i = 0; i < testCase.length(); i++)
	{
		if(testCase[i] == '(')
		{
			numOfTokens++;
			startToken = true;
		}
		else if(testCase[i] == ')')
		{
			startToken = false;
		}
		else
		{
			if(!startToken)
			{
				numOfTokens++;
			}
		}
		
		if(numOfTokens == tokenSet)
		{
			indexToReturn = i;
			i = testCase.length() + 1;
		}	
	}
	
	return indexToReturn;
}

string getTokens (string testCase, int tokenSet)
{
	string stringToReturn  = "";
	int startIndex = getStartIndexOfTokenSet(testCase, tokenSet);
	
	for(int i = startIndex; i < testCase.length(); i++)
	{
		if(i == startIndex && testCase[i] != '(')
		{
			stringToReturn = testCase[i];
			i = testCase.length() + 1;
		}
		else if(testCase[i] == ')')
		{
			i = testCase.length() + 1;
		}
		else if(i > startIndex)
		{
			stringToReturn+=testCase[i];
		}
	}
	
	return stringToReturn;
}

int getNumberOfPossibles(vector<string> dictionary, vector<string>tokenSets)
{
	int numOfPossibles = 0;
	vector<string> possibleHits;
	
	for(int i = 0; i < tokenSets.size(); i++)
	{
		for(int j = 0; j < tokenSets[i].length(); j++)
		{
			for(int k = 0; k < dictionary.size(); k++)
			{
				if((dictionary[k])[i] == (tokenSets[i])[j])
				{
					possibleHits.push_back(dictionary[k]);
				}
			}
		}
	}
	
	int numberOfSameHit = 0;
	
	for(int i = 0; i < dictionary.size(); i++)
	{
		for(int j = 0; j < possibleHits.size(); j++)
		{
			if(dictionary[i] == possibleHits[j])
			{
				numberOfSameHit++;
			}
		}
		if(numberOfSameHit == tokenSets.size())
		{
			numOfPossibles++;
		}
		numberOfSameHit = 0;
	}
	
	return numOfPossibles;
}

int main(int argc, char *argv[])
{
	vector<string> alienDictionary;
	vector<string> tokenSets;
	int numOfAlienWords;
	int alienWordLength;
	int numOfTestCases;
	ifstream theInFile;
	ofstream theOutFile;
	string fileLine;
	
	theInFile.open(argv[1]);
	theOutFile.open("A-small.out");
	
	if(theInFile.good())
	{
		theInFile >> alienWordLength;
		theInFile >> numOfAlienWords;
		theInFile >> numOfTestCases;
	}
	
	theInFile.ignore(1);
	
	for (int i = 0; i < numOfAlienWords; i++)
	{
		getline(theInFile, fileLine);
		alienDictionary.push_back(fileLine);
		cout << alienDictionary[i] << endl;
	}
	
	for (int i = 0; i < numOfTestCases; i++)
	{
		getline(theInFile, fileLine);
		cout << fileLine << endl;
		for (int j = 1; j <= alienWordLength; j++)
		{
			tokenSets.push_back(getTokens(fileLine, j));
			cout << tokenSets[j-1] << " : ";
		}
		cout << "Case #"<< i << " possibles: "<< 
			getNumberOfPossibles(alienDictionary, tokenSets) << endl;
		
		theOutFile << "Case #" << i+1 << ": " << 
				getNumberOfPossibles(alienDictionary, tokenSets) << endl;
		
		tokenSets.clear();
	}

	theOutFile.close();
	theInFile.close();


	return 0;
}