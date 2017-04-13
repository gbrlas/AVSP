#include <cstdio>
using namespace std;
char delta[505][505];
int sumh[505][505];
int sumv[505][505];

int check(int x, int y, int R, int C)
{
//	printf("Czeking %d,%d.\n", x, y);
	int mozna = -1;
	int k = 3;
	while(x+k/2<=R && y+k/2<=C && x-(k-1)/2>0 && y-(k-1)/2>0)
	{
		if(k&1)
		{
			int H = 0, V = 0;
			H = H + (k/2)*((sumh[x-k/2][y+k/2-1]-sumh[x-k/2][y-k/2]) - (sumh[x+k/2][y+k/2-1]-sumh[x+k/2][y-k/2]));
			V = V + (k/2)*((sumv[x+k/2-1][y-k/2]-sumv[x-k/2][y-k/2]) - (sumv[x+k/2-1][y+k/2]-sumv[x-k/2][y+k/2]));
			for(int i = 1; i < k/2; i++)
			{
				H = H + i*((sumh[x-i][y+k/2]-sumh[x-i][y-k/2-1]) - (sumh[x+i][y+k/2]-sumh[x+i][y-k/2-1]));
				V = V + i*((sumv[x+k/2][y-i]-sumv[x-k/2-1][y-i]) - (sumv[x+k/2][y+i]-sumv[x-k/2-1][y+i]));
			}
			if(!H && !V)
				mozna = k;

		}
		else
		{
			int H = 0, V = 0;
			H = H + (k/2)*((sumh[x-k/2+1][y+k/2-1]-sumh[x-k/2+1][y-k/2+1]) - (sumh[x+k/2][y+k/2-1]-sumh[x+k/2][y-k/2+1]));
			V = V + (k/2)*((sumv[x+k/2-1][y-k/2+1]-sumv[x-k/2+1][y-k/2+1]) - (sumv[x+k/2-1][y+k/2]-sumv[x-k/2+1][y+k/2]));
			for(int i = 1; i < k/2; i++)
			{
				H = H + i*((sumh[x-i+1][y+k/2]-sumh[x-i+1][y-k/2]) - (sumh[x+i][y+k/2]-sumh[x+i][y-k/2]));
				V = V + i*((sumv[x+k/2][y-i+1]-sumv[x-k/2][y-i+1]) - (sumv[x+k/2][y+i]-sumv[x-k/2][y+i]));
			}
			if(!H && !V)
				mozna = k;

		}
		k++;
	}
	return mozna;
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int R, C, D;
		scanf("%d %d %d", &R, &C, &D);
		for(int i = 1; i <= R; i++)
			scanf(" %s", delta[i]);
//sumh
		for(int i = 1; i <= R; i++)
		{
			int pop = 0;
			for(int j = 1; j <= C; j++)
			{
				sumh[i][j] = pop + D + delta[i][j-1];
				pop = sumh[i][j];
			}
		}
//sumv
		for(int i = 1; i <= C; i++)
		{
			int pop = 0;
			for(int j = 1; j <= R; j++)
			{
				sumv[j][i] = pop + D + delta[j][i-1];
				pop = sumv[j][i];
			}
		}
		int maximum = -1;
		for(int i = 2; i < R; i++)
			for(int j = 2; j < C; j++)
			{
				int biez = check(i,j, R,C);
				maximum = maximum>biez? maximum : biez;
			}
//print out
		printf("Case #%d: ", t);
		if(maximum > -1)
			printf("%d\n", maximum);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
