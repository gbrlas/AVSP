/*
Title: B
Data: 2012-4-15
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define InputFileName		"B-large.in"
#define OutputFileName		"B-large.out"

using namespace std;

const int MaxN = 110;

int TestCase, a[MaxN], s[MaxN][2], f[MaxN][MaxN], n, m, p;

void Init()
{
	cin >> n >> m >> p;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		s[i][0] = a[i]-p-max(p-1, 0)*2 >= 0;
		s[i][1] = a[i]-p-max(p-2, 0)*2 >= 0;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(InputFileName, "r", stdin);
	freopen(OutputFileName, "w", stdout);
	#endif
	cin >> TestCase;
	for (int T = 1; T <= TestCase; ++T)
	{
		Init();
		memset(f, 192, sizeof(f));
		f[0][0] = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j <= m; ++j)
			{
				f[i][j] = f[i-1][j]+s[i][0];
				if (j)
					f[i][j] = max(f[i][j], f[i-1][j-1]+s[i][1]);
			}
		cout << "Case #" << T << ": " << f[n][m] << endl;
	}
	return 0;
}
