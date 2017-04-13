#include <stdio.h>

int main ()
{
	//freopen("C-large.in", "r", stdin);
	//freopen("C-large.out", "w", stdout);
	int ca;
	scanf("%d", &ca);
	int n, v;
	for (int k = 1; k <= ca; k++)
	{
		scanf("%d", &n);
		int sum = 0, xsum = 0;
		int minv = -1;
		while (n--)
		{
			scanf("%d", &v);
			xsum ^= v; sum += v;
			if (minv == -1 || v < minv) minv = v;
		}
		printf("Case #%d: ", k);
		if (xsum == 0) printf("%d\n", sum - minv);
		else printf("NO\n");
	}
	return 0;
}
			
