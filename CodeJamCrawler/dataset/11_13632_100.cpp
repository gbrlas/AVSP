#include <stdio.h>

int main ()
{
	//freopen("D-small-attempt0.in", "r", stdin);
	//freopen("D-small-attempt0.out", "w", stdout);
	int ca;
	scanf("%d", &ca);
	int cas = 0;
	int n;
	while (ca--)
	{
		scanf("%d", &n);
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x != i + 1) res++;
		}
		printf("Case #%d: %d.000000\n", ++cas, res);
	}
	return 0;
}
