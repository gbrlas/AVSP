#include <stdio.h>
#include <utility>
#include <algorithm>

int isPrime(int x)
{
	for(int i = 2; i * i <= x; ++i)
	{
		if(x % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ++ca)
	{
		printf("Case #%d: ", ca);
		int N;
		scanf("%d", &N);
		int minn = 0;
		int maxx = 1;
		for(int i = 2; i <= N; ++i)
		{
			if(isPrime(i))
			{
				++minn;
				int t = i;
				while(t <= N)
				{
					++maxx;
					t *= i;
				}
			}
		}
		if(N == 1) minn = 1;
		printf("%d\n", maxx - minn);
	}
}
