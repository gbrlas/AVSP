/*
Title: Problem A. Bot Trust
Data: 2011-5-7
*/

#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#define Min(a, b)			(a < b ? a : b)

#define InputFileName		"A-small-attempt0.in"
#define OutputFileName		"A-small-attempt0.out"

using namespace std;

const int MaxN = 110;

pair<char, int> a[MaxN];
int Ans, n;

void Init()
{
	scanf("%d ", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%c %d ", &a[i].first, &a[i].second);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(InputFileName, "r", stdin);
	freopen(OutputFileName, "w", stdout);
	#endif
	int TestCase;
	scanf("%d", &TestCase);
	for (int T = 1; T <= TestCase; ++T)
	{
		Init();
		Ans = 0;
		a[0].second = 1;
		for (int i = 0, j, k, x = 1, y = 1, t; i < n; ++i)
		{
			for (j = i+1; j <= n && a[j].first != 'O'; ++j);
			for (k = i+1; k <= n && a[k].first != 'B'; ++k);
			t = a[i+1].first == 'O' ? abs(a[i+1].second-x) : abs(a[i+1].second-y);
			if (j <= n && a[j].second-x)
				x += (a[j].second-x)/abs(a[j].second-x)*Min(t+(int)(a[i+1].first != 'O'), abs(a[j].second-x));
			if (k <= n && a[k].second-y)
				y += (a[k].second-y)/abs(a[k].second-y)*Min(t+(int)(a[i+1].first != 'B'), abs(a[k].second-y));
			Ans += t+1;
		}
		printf("Case #%d: %d\n", T, Ans); 
	}
	return 0;
}
