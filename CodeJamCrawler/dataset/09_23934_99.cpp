#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
	ifstream in("A.in");
	ofstream out("A.out");

	int length, words, tests;
	in >> length >> words >> tests;

	vector<string> dataset;
	string word;
	while (words--)
	{
		in >> word;
		dataset.push_back(word);
	}

	string pattern;
	for (int i=1; i<=tests; i++)
	{
		vector<string> poss[2];
		int prevVect, curVect = 0;

		poss[0].assign(dataset.begin(), dataset.end());

		char ch;
		for (int l=0; l<length; l++)
		{
			prevVect = curVect;
			curVect = (curVect + 1) % 2;
			poss[curVect].clear();

			in >> ch;
			if (ch == '(')
			{
				set<char> var;
				in >> ch;
				while (ch != ')')
				{
					var.insert(ch);
					in >> ch;
				}

				for (int j=0; j<poss[prevVect].size(); j++)
					if (var.find(poss[prevVect][j][l]) != var.end())
						poss[curVect].push_back(poss[prevVect][j]);
			}
			else
			{
				for (int j=0; j<poss[prevVect].size(); j++)
					if (poss[prevVect][j][l] == ch)
						poss[curVect].push_back(poss[prevVect][j]);
			}
		}

		out << "Case #" << i << ": " << poss[curVect].size() << endl;
	}

	return 0;
}