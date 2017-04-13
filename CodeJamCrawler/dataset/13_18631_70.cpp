#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cassert>
using namespace std;

#ifdef moskupols 
    #define debug(...) fprintf(stderr, __VA_ARGS__) // thank Skird it's friday!
#else
    #define debug(...) 
#endif

const int maxn = 105;

int mc[maxn], mr[maxn], a[maxn][maxn];

string solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];

	for (int i = 0; i < n; ++i)
		mr[i] = *max_element(a[i], a[i]+m);

	for (int i = 0; i < m; ++i)
	{
		mc[i] = 0;
		for (int j = 0; j < n; ++j)
			mc[i] = max(mc[i], a[j][i]);
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (a[i][j] < mc[j] &&  a[i][j] < mr[i])
				return "NO";

	return "YES";
}

int main()
{
	cin.sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i+1 << ": " << solve() << endl;
	}

	return 0;
}
