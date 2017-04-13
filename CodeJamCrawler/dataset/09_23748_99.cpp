#include <stdio.h>
#include <string.h>
#include <cstdlib>

#define MAX (128)

int mrc[MAX][MAX];
int mat[MAX][MAX];

char dic[MAX];
int h, w;
int basins;

int pode(int a, int b)
{
	if (a < 0 || a >= h)
	{
		return 0;
	}
	if (b < 0 || b >= w)
	{
		return 0;
	}
	return 1;
}


void vai(int a, int b)
{
	int i, j;

	if (mrc[a][b]!= -1)
	{
		return;
	}

	int menor = 20000;
	int qx, qy;

	for (i=-1; i<=1; i++)
	{
		for (j=-1; j<=1; j++)
		{
			if (abs(i)+abs(j) == 1 && pode(a+i, b+j))
			{
				if (mat[a+i][b+j] < mat[a][b] && mat[a+i][b+j] < menor)
				{
					menor = mat[a+i][b+j];
					qx = a+i;
					qy = b+j;
				}
			}
		}
	}

	if (menor == 20000)
	{
		mrc[a][b] = basins;
		basins++;
		return;
	}
	vai(qx, qy);
	mrc[a][b] = mrc[qx][qy];
}



int main()
{
	int cas, casos;

	scanf("%d", &casos);
	int i, j;
	char c;
	for (cas=1; cas<=casos; cas++)
	{
		printf("Case #%d:\n", cas);
		memset(mrc, -1, sizeof(mrc));
		basins = 0;

		scanf("%d %d", &h, &w);

		for (i=0; i<h; i++)
		{
			for (j=0; j<w; j++)
			{
				scanf(" %d", &mat[i][j]);
			}
		}
		for (i=0; i<h; i++)
		{
			for (j=0; j<w; j++)
			{
				vai(i, j);
			}
		}

		memset(dic, -1, sizeof(dic));

		c = 'a';
		for (i=0; i<h; i++)
		{
			for (j=0; j<w; j++)
			{
				if (dic[mrc[i][j]] == -1)
				{
					dic[mrc[i][j]] = c;
					c++;
				}
				if (j)
				{
					putchar(' ');
				}
				putchar(dic[mrc[i][j]]);
			}
			putchar('\n');
		}


	}

	return 0;
}
