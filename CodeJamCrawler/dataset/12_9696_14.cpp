#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;


vector < pair < int, int > > a;
int t, n, x, y, D;
int m, j;
int f[10002][10002];
bool ok;
int s[1000001];


int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	cin >> t;
	
	for (int z = 0; z < t; z++)
	{
		cin >> n;
		
		a.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			a.push_back(make_pair(x, y));
		}
		
		cin >> D;
		
		a[0].second = min(a[0].first, a[0].second);
		a.push_back(make_pair(D, 0));
		
		x = 0;
		
		cout << "Case #" << z + 1 << ": ";
		
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				f[i][j] = 0;
				
		for (int i = 0; i <= n; i++)
			s[i] = 0;
		
		f[0][0] = 1;
		
		for (int i = 1; i <= n; i++)
			if (a[0].second >= a[i].first - a[0].first)
			{
				f[i][0] = 1;
				s[i] = min(a[i].second, a[i].first - a[0].first);
			}
				
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				x = s[j];
				
				if (x >= a[i].first - a[j].first)
				{
					f[i][j] = 1;
					
					s[i] = max(s[i], min(a[i].second, a[i].first - a[j].first));
				}
			}
			
		}
				
		ok = 0;
		
		for (int i = 0; i <= n; i++)
			if (f[n][i])
				ok = 1;
				
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
