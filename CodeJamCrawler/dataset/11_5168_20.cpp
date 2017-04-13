/*
Title: A
Data: 2011-5-21
*/

#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#define InputFileName		"A-large.in"
#define OutputFileName		"A-large.out"

using namespace std;

long long n, D, G, k;

inline long long gcd(long long a, long long b)
{
	for (long long c; b; c = a, a = b, b = c % b);
	return a;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(InputFileName, "r", stdin);
	freopen(OutputFileName, "w", stdout);
	#endif
	int TestCase;
	cin >> TestCase;
	for (int T = 1; T <= TestCase; ++T)
	{
		cin >> n >> D >> G;
		k = 100ll/gcd(D, 100ll);
		if (G == 100ll && D < 100ll || G == 0ll && D > 0ll)
		{
			printf("Case #%d: Broken\n", T);
			continue;
		}
		k <= n ? printf("Case #%d: Possible\n", T) : printf("Case #%d: Broken\n", T);
	}
	return 0;
}
