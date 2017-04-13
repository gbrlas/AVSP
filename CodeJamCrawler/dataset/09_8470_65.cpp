/*
	雛形(GCJ仕様)
 */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;
static const double EPS = 1e-9;
typedef long long ll;

int main()
{
	string filename, infile, outfile;
	cin >> filename;
	infile = filename + ".in";
	outfile = filename + ".out";
	ifstream ifs;
	ofstream ofs;
	ifs.open(infile.c_str(), ios::in);
	ofs.open(outfile.c_str(), ios::out);
	int Casenum;
	ifs >> Casenum;
	for(int Casecount = 0; Casecount < Casenum; Casecount++)
	{
		string str;
		ifs >> str;
		int used[40] = {0};
		int ss[100] = {0};
		int tab[40];
		memset(tab, -1, sizeof(tab));
		ll base = 0;
		for(int i = 0; i < str.length(); i++)
		{
			char c = str[i];
			if(c >= '0' && c <= '9')
			{
				used[c - '0' + 26] = 1;
				ss[i] = c - '0' + 26;
			}
			else if(c >= 'a' && c <= 'z')
			{
				used[c - 'a'] = 1;
				ss[i] = c - 'a';
			}
		}
		for(int i = 0; i < 36; i++) base += used[i];
		int w = 0;
		ll res = 0;
		if(base == 1) base = 2;
		for(int i = 0; i < str.length(); i++)
		{
			int ch = ss[i];
			if(i == 0) tab[ch] = 1;
			else if(tab[ch] < 0)
			{
				if(w == 0)
				{
					tab[ch] = w;
					w = 2;
				}
				else
					tab[ch] = w++;
			}
			res = res * base + tab[ch];
		}
		ofs << "Case #" << (Casecount + 1) << ": " << res << endl;
		cout << "Case #" << (Casecount + 1) << " done." << endl;
	}
}
