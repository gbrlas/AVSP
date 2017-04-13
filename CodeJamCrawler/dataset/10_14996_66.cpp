#include <stdio.h>

int que[2][105];

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);

	int r, k, n, i, j, m, ind, sum = 0, res, tcase, t;

	scanf("%d",&t);

	for(tcase = 1; tcase <= t; tcase++)
	{
		scanf("%d %d %d",&r, &k, &n);
		for(i = 0; i < n; i++)
			scanf(" %d",&que[0][i]);
		
		res = 0;
		ind = 1;
		for(i = 0; i < r; i++)
		{
			sum = 0;
			for(j = 0; j < n; j++)
			{
				if((sum + que[1-ind][j]) <= k)
					sum += que[1-ind][j];
				else	break;
			}

			res += sum;
			for(m = j; m < n; m++)
				que[ind][m-j] = que[1-ind][m];
			for(m = 0; m < j; m++)
				que[ind][m+(n-j)] = que[1-ind][m];

			ind = 1 - ind;
		}
		
		printf("Case #%d: %d\n",tcase, res);

	}

	return 0;
}