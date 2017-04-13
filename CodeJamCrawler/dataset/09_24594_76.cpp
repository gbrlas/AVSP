// string constructor
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool MatchPattern (std::string word, std::string pattern)
{
	int wptr = 0;
	bool flag = false;

	for (unsigned int pptr = 0; pptr < pattern.length(); pptr ++)
	{
		if (pattern.at(pptr) == '(')
		{
			flag = true;
			continue;
		}
		else if (pattern.at(pptr) == ')')
		{
			flag = false;
			continue;
		}
		else if (pattern.at(pptr) == word.at (wptr))
		{
			wptr += 1;
			if (wptr == word.length())
				return true;

			if (flag != false)
			{
				while (pattern.at(pptr) != ')')
					pptr ++;
				flag = false;
			}
		}
		else if (flag == false)
			return false;
	}
	return false;
}

int main (int argc, char *argv[])
{	
	int len = 0;
	int wordsCnt = 0;
	int patternCnt = 0;

	fstream infile("A-large.in", ios::in);
	fstream outfile("Ouput.txt", ios::out);

	infile >> len >> wordsCnt >> patternCnt;

	std::string line;
	vector<std::string> words;
	vector<std::string> patterns;
	int *results = (int *)calloc (wordsCnt, sizeof(int));	

	getline (infile, line);

	for (int i = 0; i < wordsCnt; i++)
	{
		getline (infile, line);
		words.push_back(line);		
	}

	for (int i = 0; i < patternCnt; i++)
	{
		getline (infile, line);
		patterns.push_back(line);
		
	}
	

	for (int i = 0; i < wordsCnt; i ++)
	{
		for (int j = 0; j < patternCnt; j++)
		{
			if (MatchPattern (words.at(i), patterns.at(j)))
				results[j] ++;
		}
	}

	for (int j = 0; j < patternCnt; j++)
	{
		outfile << "Case #" << j+1 << ": "<< results[j] << endl;
	}

	outfile.close();
	infile.close();

	return 0;
}