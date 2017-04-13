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

vector<int> s;
int n;

void Solve()
{
	int res = 0;
	cin >> n;
	s.clear();
	for(int i = 0; i < n; i++)
	{
		string ss;
		cin >> ss;
		int p = ss.size() - 1;
		while(p > 0 && ss[p] == '0')
			p--;
		s.push_back(p);
	}
	for(int i = 0; i < n - 1; i++)
	{
		int p = i;
		while(s[p] >= i + 1)
			p++;
		if(p > i)
		{
			for(int j = p - 1; j >= i; j--)
			{
				int tt = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tt;
				res++;
			}
		}
	}
	cout << res << endl;
}

int main()
{
#ifndef DEBUG
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	int w;
	cin >> w;
	for(int t = 1; t <= w; t++)
	{
		cout << "Case #" << t << ": ";
		Solve();
	}
	return 0;
}