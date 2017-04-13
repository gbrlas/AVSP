#include <stdio.h>

#define FORN(i, t) for(i = 1; i<=t; ++i)
#define READFROMFILE 1
#define WRITEFILE 1
#define MAX 10000000

void solve(int casenum);
void cleararray();

int count[MAX];

int main()
{
	int i, n;

#if READFROMFILE
	freopen("input.txt", "r", stdin);
#endif

#if WRITEFILE
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d\n", &n);

	FORN(i, n)
	{
		solve(i);
	}

	return 0;
}

void cleararray()
{
	int i = 0;
	for(;i < MAX; ++i)
		count[i] = 0;
}

void solve(int casenum)
{
	int a, b, digits = 0, temp, i, j, mul, mul2 = 1;
	int k2, k1, result = 0;

	scanf("%d %d", &a, &b);

	cleararray();

	temp = a;
	while(temp > 0)
	{
		++digits;
		temp /= 10;
		mul2 *= 10;
	}

	for(j = a; j<=b; ++j)
	{
		int max = -1;

		mul = 10;
		for(i = 1; i<=digits; ++i)
		{
			int res;

			k2 = j % mul;
			k1 = j - k2;

			if((k2 * 10) / mul > 0)
			{
				res = ((k1 / mul)) + ((k2 * mul2) / mul);

				if(res > max)
					max = res;
			}
			

			mul *= 10;
		}

		if(max > -1)
			count[max-1]++;
	}

	for(i = 0;i < MAX; ++i)
	{
		if(count[i] > 1)
		{
			result += (count[i] * (count[i] - 1)) / 2;
		}
	}
	
	printf("Case #%d: %d\n", casenum, result);
}