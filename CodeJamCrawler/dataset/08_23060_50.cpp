#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXI(a,b) ((a)>(b)?(a):(b))
#define MINI(a,b) ((a)<(b)?(a):(b))

int fc(const void *e1, const void *e2)
{
	return 0;
}

#define MAXC 128
#define MAXS 12

char gosta[MAXC][MAXS][2];

int casos;
int n, m;
int v[MAXS];

int bt(int prof)
{
	if (prof == n)
	{
		int i, j;
		for (i=0; i<m; i++)
		{
			for (j=0; j<n; j++)
			{
				if (gosta[i][j][v[j]])
					break;
			}
			if (j==n)
				return 0;
		}
		return 1;
	}

	v[prof] = 0;
	if (bt(prof+1))
		return 1;

	v[prof] = 1;
	if (bt(prof+1))
		return 1;
	return 0;
}


int main()
{
	int cas;

	scanf("%d",&casos);
	int t;
	int i, j, a, b;

	for (cas=0; cas<casos; cas++)
	{
		scanf("%d %d",&n, &m);

		memset(gosta, 0, sizeof(gosta));

		for (j=0; j<m; j++)
		{

			scanf("%d", &t);
			for (i=0; i<t; i++)
			{
				scanf("%d %d",&a, &b);
				a--;
				gosta[j][a][b] = 1;
			}
		}
		printf("Case #%d:", cas+1);

		if (bt(0))
		{
			for (i=0; i<n; i++)
			{
				printf(" %d",v[i]);
			}
			printf("\n");
		}
		else
		{
			printf(" IMPOSSIBLE\n");
		}

	}

	return 0;
}
