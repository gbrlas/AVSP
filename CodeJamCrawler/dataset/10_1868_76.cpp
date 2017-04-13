#include <stdio.h>
#include <string.h>

int p1[1000], p2[1000];

int main()
{
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; c++)
	{
		int res = 0;
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%d %d", &p1[i], &p2[i]);
		for (int a=0; a<n; a++)
			for (int b=a+1; b<n; b++)
				if ((p1[a] < p1[b] && p2[a] > p2[b]) || (p1[a] > p1[b] && p2[a] < p2[b]))
					res++;
		printf("Case #%d: %d\n", c, res);
	}
}
