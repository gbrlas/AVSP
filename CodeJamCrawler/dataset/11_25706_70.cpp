#include <cstdio>
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int n;
		scanf("%d", &n);
		int ksor = 0, min = 100000000, sum = 0;
		for(int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			min = min<x ? min : x;
			sum += x;
			ksor ^= x;
		}
		printf("Case #%d: ", t);
		if(ksor)
			printf("NO\n");
		else
			printf("%d\n", sum - min);
	}
	return 0;
}
