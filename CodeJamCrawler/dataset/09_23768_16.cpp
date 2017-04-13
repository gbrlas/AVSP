#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

#define MAXN (64)

char v[MAXN][MAXN];
int t[MAXN];

int main()
{
	int cas, casos;
	int i, j, n;
	scanf("%d", &casos);
		int resp = 0;
	for (cas=1; cas<=casos; cas++)
	{
		printf("Case #%d: ", cas);


		scanf("%d", &n);

		for (i=1; i<=n; i++)
		{
			scanf("%s", v[i]);
		}

		for (i=1; i<=n; i++)
		{
			for (j=n-1; j>=0; j--)
			{
				if (v[i][j] == '1')
				{
					break;
				}
			}
			t[i] = j+1;
		}

		resp = 0;
		int q;//, temp;
		int k;

		for (i=1; i<=n; i++)
		{
//			for (j=1; j<=n; j++)
//			{
//				printf("[%d]", t[j]);
//			}
//			printf("\n");
			if (t[i] > i)
			{
				for (j=i+1; t[j] > i; j++)
				{

				}

				q = t[j];

				for (k=j; k>i; k--)
				{
					t[k] = t[k-1];
				}
				t[i] = q;
				
				resp+=j-i;
			}
		}
		printf("%d\n", resp);
	}

	return 0;
}


