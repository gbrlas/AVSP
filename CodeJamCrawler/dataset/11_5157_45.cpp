/*
Title: Problem C. Candy Splitting
Data: 2011-5-8
*/

#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstdlib>

#define InputFileName		"C-large.in"
#define OutputFileName		"C-large.out"

using namespace std;

const int MaxN = 1100;

int n, a[MaxN], Xor, Sum;

void Init()
{
	scanf("%d", &n);
	Xor = Sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		Xor ^= a[i];
		Sum += a[i];
	}
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
		if (Xor)
			printf("Case #%d: NO\n", T);
		else
		{
			sort(a+1, a+n+1);
			printf("Case #%d: %d\n", T, Sum-a[1]);
		}
	}
	return 0;
}
