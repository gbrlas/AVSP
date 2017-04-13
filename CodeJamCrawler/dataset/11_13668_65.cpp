#include <stdio.h>

const int N = 105;
int a[N];

int main ()
{
	//freopen("C-small-attempt0 (3).in", "r", stdin);
	//freopen("C-small-attempt0 (3).out", "w", stdout);
	int ca;
	scanf("%d", &ca);
	int cas = 0;
	while (ca--)
	{
		int n, l, h;
		scanf("%d%d%d", &n, &l, &h);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
		}
		int res, flag;
		for (int i = l; i <= h; i++)
		{
			flag = 1;
			for (int j = 0; j < n; j++)
			{
				if (!(i % a[j] == 0 || a[j] % i ==0))
				{
					flag = 0;
					break;
				}
			}
			if (flag) 
			{
				res = i;
				break;
			}
		}
		printf("Case #%d: ", ++cas);
		if (flag)
			printf("%d\n", res);
		else 
			printf("NO\n");
	}
	return 0;
}
