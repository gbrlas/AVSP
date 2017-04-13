// CodeJam2014.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t;
long long p, q;

long long gcd(long long a, long long b)
{
	int g;
	if (b == 0)
		g = a;
	else
		g = gcd(b, a%b);
	return g;
}

bool judge(long long tmp)
{
	while (true)
	{
		if (tmp % 2 == 0)
		{
			tmp /= 2;
			if (tmp == 1)
				return true;
		}
		else return false;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%I64d/%I64d", &p, &q);

		long long tmp = gcd(p, q);
		p /= tmp;
		q /= tmp;

		if (!judge(q))
		{
			printf("Case #%d: impossible\n", i + 1);
			continue;
		}

		int count = 0;
		while (p < q)
		{
			p *= 2;
			long long tt = gcd(p, q);
			p /= tt;
			q /= tt;
			count++;
		}
		printf("Case #%d: %d\n", i+1, count);
	}
}