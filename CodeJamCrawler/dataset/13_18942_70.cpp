#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int solve()
{
	int i, i2;
	int flag = 0;
	int kusa[101][101] = {0};
	int masu[101][101] = {0};
	int N, M;
	int max = 0;
	int hoge;

	
	scanf("%d", &N);
	scanf("%d", &M);
//	printf("%d,%d\n", N, M);
	for(i = 0; i < N; i++)
	{
		for(i2 = 0; i2 < M; i2++)
		{
			scanf("%d", &kusa[i][i2]);
			if(kusa[i][i2] > max)
			{
				max = kusa[i][i2];
			}
//			printf("%d", kusa[i][i2]);
		}
//		printf("\n");
	}
	hoge = max;
	while(hoge != 0)
	{
		for(i = 0; i < N; i++)
		{
			for(i2 = 0; i2 < M; i2++)
			{
				if(kusa[i][i2] > hoge)
				{
					break;
				}
			}
			if(i2 == M)
			{
				for(i2 = 0; i2 < M; i2++)
				{
					masu[i][i2] = hoge;
				}
			}
		}
		for(i = 0; i < M; i++)
		{
			for(i2 = 0; i2 < N; i2++)
			{
				if(kusa[i2][i] > hoge)
				{
					break;
				}
			}
			if(i2 == N)
			{
				for(i2 = 0; i2 < N; i2++)
				{
					masu[i2][i] = hoge;
				}
			}
		}
		hoge--;
	}
/*	for(i = 0; i < N; i++)
	{
		for(i2 = 0; i2 < M; i2++)
		{
			printf("%d", masu[i][i2]);
		}
		printf("\n");
	}*/
	for(i = 0; i < N; i++)
	{
		for(i2 = 0; i2 < M; i2++)
		{
			if(masu[i][i2] != kusa[i][i2])
			{
				return 1;
			}
		}
	}

	return 0;
}



void main()
{
	int i;
	int m;
//	char s[10];

	scanf("%d", &m);
//	printf("%d\n", m);
//	fflush(stdin);//ƒSƒ~
//	fgets(s, 10, stdin);
//	m = atoi(s);

	for(i = 0; i < m; i++)
	{
		switch(solve())
		{
			case 0:
				printf("Case #%d: YES\n", (i + 1));
				break;
			case 1:
				printf("Case #%d: NO\n", (i + 1));
				break;
			default:
				printf("‚È‚ñ‚©‚¨‚©‚µ‚­‚ËH\n");
				break;
		}
	}
}