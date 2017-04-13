#include <stdio.h>

int a[10001][2];
int val[10001];
int ch[10001];

int min(int a, int b) { return a<b?a:b; }

int main()
{
	int n;
	scanf("%d", &n);
	for (int c=1; c<=n; c++)
	{
		int m,v;
		scanf("%d %d", &m, &v);
		for (int i=1; i<=(m-1)/2; i++)
			scanf("%d %d", &val[i], &ch[i]);
		for (int i=(m+1)/2; i<=m; i++)
			scanf("%d", &val[i]);

		for (int i=m; i>=(m-1)/2; i--)
			a[i][0] = (val[i] == 0) ? 0 : 12345;
		for (int i=m; i>=(m-1)/2; i--)
			a[i][1] = (val[i] == 1) ? 0 : 12345;
		for (int i=(m-1)/2; i>=1; i--)
		{
			if (val[i] == 0)
			{
				a[i][0] = a[2*i][0] + a[2*i+1][0];
				a[i][1] = min(a[2*i][1], a[2*i+1][1]);
			}
			else
			{
				a[i][0] = min(a[2*i][0], a[2*i+1][0]);
				a[i][1] = a[2*i][1] + a[2*i+1][1];
			}
			if (ch[i])
			{
				if (val[i] == 0)
				{
					a[i][0] = min(a[i][0], 1+min(a[2*i][0], a[2*i+1][0]));
					a[i][1] = min(a[i][1], 1+a[2*i][1]+a[2*i+1][1]);
				}
				else
				{
					a[i][0] = min(a[i][0], 1+a[2*i][0]+a[2*i+1][0]);
					a[i][1] = min(a[i][1], 1+min(a[2*i][1], a[2*i+1][1]));
				}
			}
		}
		printf("Case #%d: ", c);
		if (a[1][v] > m) printf("IMPOSSIBLE\n");
		else printf("%d\n", a[1][v]);
	}
	return 0;
}
