#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <string>
#include <memory> 
#include <iostream>

using namespace std;

const int maxd = 5100;
const int maxl = 20;

int cases = 0;
ifstream fin("a.in");
ofstream fout("a.out");
char words[maxd][maxl];
bool match[maxl][30];
int l, d, n;

void process(const string& s)
{
	int p = 0;
	memset(match, 0, sizeof match);
	for (int i=0; i<l; i++)
	{
		if (s[p] == '(')
		{
			p++;
			while (s[p] != ')')
			{
				match[i][s[p]-'a'] = true;
				p++;
			}
			p++;
		}
		else 
		{
			match[i][s[p]-'a'] = true;
			p++;
		}
	}
}

int main()
{
	fin >> l >> d >> n;
	string pat;
	for (int i=0; i<d; i++) fin >> words[i];
	while (cases++ < n)
	{
		int ans = 0;
		fin >> pat;
//		cout << pat;
		process(pat);
		for (int i=0; i<d; i++)
		{
			bool flag = true;
			for (int j=0; j<l; j++)
			{
			//cout << words[i] << endl;
				if (!match[j][words[i][j]-'a'])
				{
					flag = false;
					break;
				}
			}
			if (flag) ans++;
		}
		fout << "Case #" << cases << ": " << ans << endl;
	}
	return 0;
}