#include <cstdio>
long long gcd(long long a, long long b)
{
	while(a*b)
	{
		if(a>b) a %= b;
		else b %= a;
	}
	return a+b;
}
int main()
{
	long long n, pd, pg;
	int t;
	scanf("%d\n",  &t);
	for(int tnum = 1; tnum <= t; tnum++)
	{
		scanf("%lld %lld %lld", &n, &pd, &pg);
		long long facd = 100/gcd(pd, 100), facg = 100/gcd(pg, 100);
//		printf("%lld %lld...\n", facd, facg);
		bool NIE = 0;
		if(pd != 0)
		{
			if(facd > n)
				NIE = 1;
			
			if(pg == 0 || (pg == 100 && pd < 100))
				NIE = 1;
		}
		else if(pg == 100)
			NIE = 1;
		printf("Case #%d: ", tnum);
		printf(NIE? "Broken\n" : "Possible\n");
	}
}
