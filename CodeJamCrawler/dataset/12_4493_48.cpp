/*
Title: A
Data: 2012-5-26
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

#define InputFileName		"A-large.in"
#define OutputFileName		"A-large.out"

#define Min(a, b)			(a < b ? a : b)

using namespace std;

const int MaxN = 11000;

int TestCase, n, d;
pair<int, int> a[MaxN];
int f[MaxN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(InputFileName, "r", stdin);
	freopen(OutputFileName, "w", stdout);
	#endif
	cin.sync_with_stdio(0);
	cin >> TestCase;
	for (int T = 1; T <= TestCase; ++T)
	{
		cerr << "==========" << T << "==========" << endl;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i].first >> a[i].second;
		cin >> d;
		sort(a+1, a+n+1);
		memset(f, 192, sizeof(f));
		if (a[1].first <= a[1].second)
			f[1] = a[1].first;
		bool Ans = 0;
		for (int i = 1, j; i <= n && ! Ans; ++i)
		{
			cerr << i << endl;
			if (f[i]+a[i].first >= d)
				Ans = 1;
			for (j = i+1; j <= n && a[j].first <= a[i].first+f[i]; ++j)
				f[j] = max(f[j], Min(a[j].first-a[i].first, a[j].second));
		}
		cout << "Case #" << T << ": " << (Ans ? "YES" : "NO") << endl;
	}
	return 0;
}
