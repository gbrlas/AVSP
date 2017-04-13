#include <stdio.h>

int mas[501][501];
int cx[501][501];
int cy[501][501];
int tot[501][501];

int main()
{
	int T;
	scanf("%d", &T);

	for (int tst = 1; tst <= T; tst++)
	{
		int sx, sy, d;
		scanf("%d %d %d", &sy, &sx, &d);

		for (int y = 1; y <= sy; y++)
		{
			char buf[1024];
			scanf("%s", buf);

			for (int x = 1; x <= sx; x++)
			{
				mas[x][y] = buf[x-1] - '0';
				cx[x][y] = cx[x-1][y] + cx[x][y-1] - cx[x-1][y-1] + x*mas[x][y];

				cy[x][y] = cy[x-1][y] + cy[x][y-1] - cy[x-1][y-1] + y*mas[x][y];

				tot[x][y] = tot[x-1][y] + tot[x][y-1] - tot[x-1][y-1] + mas[x][y];
			}
		}

		int go = 1;
		int res = 0;

		for (int s = ((sx < sy) ? sx : sy); s >= 3 && go; s--)
		{
			for (int y = s; y <= sy && go; y++)
			{
				for (int x = s; x <= sx && go; x++)
				{
					int totmas = tot[x][y] - tot[x-s][y] - tot[x][y-s] + tot[x-s][y-s] 
						- mas[x][y] - mas[x-s+1][y] - mas[x][y-s+1] - mas[x-s+1][y-s+1];

					int cenX = cx[x][y] - cx[x-s][y] - cx[x][y-s] + cx[x-s][y-s] 
						- (mas[x][y] * x) - (mas[x-s+1][y] * (x-s+1)) - (mas[x][y-s+1] * x) - (mas[x-s+1][y-s+1] * (x-s+1));

					int cenY = cy[x][y] - cy[x-s][y] - cy[x][y-s] + cy[x-s][y-s] 
						- (mas[x][y] * y) - (mas[x-s+1][y] * y) - (mas[x][y-s+1] * (y-s+1)) - (mas[x-s+1][y-s+1] * (y-s+1));

					cenX *= 2;
					cenY *= 2;

					int exCx = (x + (x-s+1)) * totmas;
					int exCy = (y + (y-s+1)) * totmas;

					if (cenX == exCx && cenY == exCy)
					{
						res = s;
						go = 0;
					}
				}
			}
		}

		if (res)
			printf("Case #%d: %d\n", tst, res);
		else
			printf("Case #%d: IMPOSSIBLE\n", tst);
	}
	
	return 0;
}
