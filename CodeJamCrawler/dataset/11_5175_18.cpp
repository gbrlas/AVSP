/*
Title: A
Data: 2011-6-4
*/

#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define InputFileName		"A-large.in"
#define OutputFileName		"A-large.out"

using namespace std;

const int MaxN = 11000;

int X, S, R, n, Total;
double t;
double Ans;
pair<int, int> b[MaxN];
struct TSeg
{
	int first, second, speed;
}a[MaxN];

inline bool operator <(TSeg a, TSeg b)
{
	return a.first < b.first || a.first == b.first && a.second < b.second;
}

void Init()
{
	cin >> X >> S >> R >> t >> n;
	Total = 0;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second >> a[i].speed;
	sort(a+1, a+n+1);
	int Prev = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i].first > Prev)
			b[++Total] = make_pair(0, a[i].first-Prev);
		b[++Total] = make_pair(a[i].speed, a[i].second-a[i].first);
		Prev = a[i].second;
	}
	if (X > Prev)
		b[++Total] = make_pair(0, X-Prev);
	sort(b+1, b+Total+1);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(InputFileName, "r", stdin);
	freopen(OutputFileName, "w", stdout);
	#endif
	int TestCase;
	cin >> TestCase;
	cout << setprecision(10) << fixed;
	for (int T = 1; T <= TestCase; ++T)
	{
		Init();
		Ans = 0;
		for (int i = 1; i <= Total; ++i)
			if ((double)b[i].second/(b[i].first+R) <= t)
			{
				Ans += (double)b[i].second/(b[i].first+R);
				t -= (double)b[i].second/(b[i].first+R);
			}
			else
			{
				Ans += t+((double)b[i].second-t*(b[i].first+R))/(b[i].first+S);
				t = 0;
			}
		cout << "Case #" << T << ": " << Ans << endl;
	}
	return 0;
}
