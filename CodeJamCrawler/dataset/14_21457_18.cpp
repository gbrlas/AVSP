//============================================================================
// Name        : Jam.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

bool toCompare(pair<int, int>a, pair<int, int>b)
{
	return a.second<b.second;
}

class StringRepeater
{
	int testCases;
	vector<string> characters;
	vector< vector<int> > characterCounts;
public:
	void start()
	{
		std::cin>>testCases;
		for(int i=0; i<testCases; i++)
		{
			readAllWords();
			prepareAllWords();
			//printAll();
			std::cout<<"Case #"<<i+1<<": ";
			solve();
		}
	}
private:
	void readAllWords()
	{
		characters.clear();
		characterCounts.clear();
		int wordCount;

		std::cin>>wordCount;
		string ToPush="";
		for(int i=0; i<wordCount; i++)
		{
			std::cin>>ToPush;
			characters.push_back(ToPush);
		}
	}

	void prepareAllWords()
	{
		for(int i=0; i<characters.size(); i++)
		{
			prepareWord(i);
		}
	}

	void prepareWord(int i)
	{
		char lastChar=characters[i][0];
		std::string NewWord="";
		NewWord+=characters[i][0];

		int count=1;
		vector<int> ToPush;
        ToPush.clear();

		for(int j=1; j<characters[i].size(); j++)
		{
			if(characters[i][j]==lastChar)
			{
				++count;
			}
			else
			{
				lastChar=characters[i][j];
				NewWord+=characters[i][j];
				ToPush.push_back(count);
				count=1;
			}
		}
		ToPush.push_back(count);
		characterCounts.push_back(ToPush);

		characters[i]=NewWord;
	}

	void printAll()
	{
		for(int i=0; i<characters.size(); i++)
		{
			std::cout<<characters[i]<<endl;
		}
		for(int i=0; i<characterCounts.size(); i++)
		{
			for(int j=0; j<characterCounts[i].size(); j++)
			{
				std::cout<<characterCounts[i][j];
			}
			std::cout<<endl;
		}
	}


	void solve()
	{
		if(cannotSolve())
		{
			std::cout<<"Fegla Won"<<endl;
			return;
		}
		int changesCount=0;

		for(int i=0; i<characters[0].size(); i++)
		{
			vector< pair<int, int> >PairList;
			for(int j=0; j<characters.size(); j++)
			{
				PairList.push_back( pair<int, int>(1, characterCounts[j][i]) );
			}

            std::sort(PairList.begin(), PairList.end(), toCompare);
            /*for(int i=0; i<PairList.size(); i++)
            {
            	std::cout<<PairList[i].second<<" ";
            }*/

			int first=0;
			int last=PairList.size()-1;
			while(first!=last)
			{
				changesCount+=lookForSmalestChange(PairList, first, last);
			}
		}

		std::cout<<changesCount<<endl;
	}

	int lookForSmalestChange(vector< pair<int, int> > & PairList, int& first, int& last)
	{
		int firstChange = (PairList[first+1].second-PairList[first].second)*PairList[first].first;
		int lastChange = (PairList[last].second-PairList[last-1].second)*PairList[last].first;

		if(firstChange<lastChange)
		{
			PairList[first+1].first+=PairList[first].first;
			first++;
			return firstChange;
		}
		else
		{
			PairList[last-1].first+=PairList[last].first;
			last--;
			return lastChange;
		}
		return 0;
	}
	bool cannotSolve()
	{
		for(int i=0; i<characters.size()-1; i++)
		{
			if(characters[i]!=characters[i+1])
				return true;
		}
		return false;
	}
};

int main() {
	StringRepeater SR;
	SR.start();
	return 0;
}
