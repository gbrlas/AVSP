#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;
set<string> dictionary[15];
struct charachter
{
	char x[26];
	int size;
};

charachter word[15];

int getNumOfWords(int total, int pos, string s)
{
	if(pos == total)
	{	if(dictionary[pos].find(s) != dictionary[pos].end())
			return 1;
		return 0;
	}
	if (dictionary[pos].find(s) == dictionary[pos].end())
		return 0;
	int n = 0;
	for (int i = 0; i < word[pos].size; i++)
		n += getNumOfWords(total, pos+1, s+word[pos].x[i]);

	return n;
}
int solve(string s)
{
	int i = 0, order;
	for(int k = 0; k < s.length(); k++)
	{
		order = 0;
		if(s.at(k) == '(')
		{
			while(s.at(++k) != ')')
				word[i].x[order++] = s.at(k);
			word[i].size = order;
		}
		else
		{
			word[i].x[order] = s.at(k);
			word[i].size = 1;
		}
//			cout << word[i].size << endl;
		i++;
	}


	return getNumOfWords(i, 0,"");
}
int main()
{
	ifstream cin("A-small-attempt1.in");
//	ifstream cin("1.txt");
	ofstream cout("2.txt");
	int L, D, N, counter = 1;
	string s;


	cin >> L >> D >> N;
	dictionary[0].insert("");
	for (int i = 0; i < D; i++)
	{
		cin >> s;
		for (int k = L; k >= 1; k--)
			dictionary[k].insert(s.erase(k, 1));
	}

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		cout << "Case #" << counter++ << ": " << solve(s) << endl;
	}

	return 0;
}