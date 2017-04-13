#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector <string> decode (string s)
{
	vector <string> ans;
	string strTemp;
	for (int i = 0; i < s.length(); i++)
	{
		strTemp = "";
		if (s[i] == '(')
		{
			i++;
			while (s[i] != ')')
			{
				strTemp = strTemp + s[i];
				i++;
			}
			ans.push_back(strTemp);
			continue;
		}
		ans.push_back(s.substr(i,1));
	}
	return ans;
}


bool isWordPresent(string word, vector <string> pat)
{
	for (int i = 0; i < word.length(); i ++)
	{
		if (pat[i].find(word[i]) == string::npos)
			return false;
	}
	return true;
}
int main()
{
	ifstream fin ("a.in");
	ofstream fout ("a.txt");
	int L, D, N;
	fin >> L >> D >> N;
	vector <string> dict;
	vector <vector<string> > pattern;
	string strTemp;
	for (int i = 0; i < D; i++)
	{
		fin >> strTemp;
		dict.push_back(strTemp);
	}

	for (int i = 0; i < N; i ++)
	{
		fin >> strTemp;
		pattern.push_back(decode (strTemp));
	}

	//Debugging
	cout << "Debugging\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < pattern[i].size(); j++)
			cout << pattern[i][j] << endl;
	}

	for (int i = 0; i < N; i ++)
	{
		int K = 0;
		for (int j = 0; j < D; j++)
		{
			if(isWordPresent(dict[j], pattern[i]))
				K++;
		}
		cout << "Case #" << i + 1 << ": " << K << endl;
		fout << "Case #" << i + 1 << ": " << K << endl;
	}
	return 0;
}
