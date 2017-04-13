#include <stdio.h>

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w",stdout);

	int t, tcase;
	long long n, k, res;

	scanf("%d",&t);
	for(tcase = 1; tcase <= t; tcase++)
	{
		scanf("%lld %lld",&n, &k);
		res = 1;
		res <<= n;
		k++;

		if(k % res == 0)
			printf("Case #%d: ON\n",tcase);
		else
			printf("Case #%d: OFF\n",tcase);
	}
	return 0;
}
