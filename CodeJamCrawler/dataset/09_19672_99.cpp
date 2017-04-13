#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

int main()
{
#ifndef DEBUG
	freopen("A-small.in", "rt", stdin);
	freopen("A-small.out", "wt", stdout);
#endif
	int l, d, n;
	string s[6000];
	string p;
	vector<string> pat;
	cin >> l >> d >> n;
	for(int i = 0; i < d; i++)
		cin >> s[i];
	for(int t = 1; t <= n; t++)
	{
		cin >> p;
		pat.clear();
		int pos = 0;
		while(pos < p.size())
		{
			if(p[pos] == '(')
			{
				pat.push_back(p.substr(pos + 1, p.find(')', pos) - pos - 1));
				pos = p.find(')', pos) + 1;
			}
			else
			{
				string tmp;
				tmp = p[pos];
				pat.push_back(tmp);
				pos++;
			}
		}
		int k = 0;
		for(int i = 0; i < d; i++)
		{
			bool f = 1;
			for(int j = 0; j < l; j++)
			{
				int r = 0;
				while(r < pat[j].size() && pat[j][r] != s[i][j])
					r++;
				if(r == pat[j].size())
				{
					f = 0;
					break;
				}
			}
			if(f)
				k++;
		}
		cout << "Case #" << t << ": " << k << endl;
	}
	return 0;
}