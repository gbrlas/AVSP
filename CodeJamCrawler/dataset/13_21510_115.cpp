#include <stdio.h>

#define MAX 200

int T, M, N;
int map[MAX][MAX], max = 0;

// default h = 1
int stillLeft(int h)
{
	for (int m = 0; m < M; m++)
		for (int n = 0; n < N; n++)
		{
			if (map[m][n] == h)
				return 0;
		}
	return 1;
}

int isPossible()
{
	for (int h = max-1; h >= 1; h--)
	{
		// Check at border
		// 0, 0 -> 0, N		
		for (int n = 0; n < N; n++)
			if (map[0][n] <= h)
			{
				int count = 0;				
				for (int m = 0; m < M; m++)
				{
					if (map[m][n] <= h)
						count += 1;
				}
				if (count == M)
					for (int m = 0; m < M; m++)
					{
						if (map[m][n] == h)
							map[m][n] = 0;
					}
			}		
		// 0, 0 -> M, 0
		for (int m = 0; m < M; m++)
			if (map[m][0] <= h)
			{
				int count = 0;
				for (int n = 0; n < N; n++)
				{
					if (map[m][n] <= h)
						count += 1;
				}
				if (count == N)
					for (int n = 0; n < N; n++)
					{
						if (map[m][n] == h)
							map[m][n] = 0;
					}
			}
		
		// print
		/*printf ("\n");
		for (int m = 0;m < M; m++)
		{
			for (int n = 0; n < N; n++)
				printf ("%d", map[m][n]);
			printf ("\n");
		}*/
		
		if (stillLeft(h) == 0)
		{
			return 0;
		}
		for (int m = 0;m < M; m++)
			for (int n = 0; n < N; n++)
				if (map[m][n] == 0)
					map[m][n] = h;
	}
	return 1;
}

int main()
{
	//freopen("b.in", "rt", stdin);
	freopen("B-small-attempt1.in", "rt", stdin);
	freopen("B-small-attempt1.out", "wt", stdout);
	
	scanf ("%d", &T);
	for (int t = 0; t < T; t++)
	{
		scanf ("%d %d\n", &M, &N);
		for (int m = 0;m < M; m++)
		{
			for (int n = 0; n < N; n++)
			{
				scanf ("%d", &map[m][n]);
				if (max < map[m][n])
					max = map[m][n];
			}
		}
		/*for (int m = 0;m < M; m++)
		{
			for (int n = 0; n < N; n++)
				printf ("%d", map[m][n]);
			printf ("\n");
		}*/
		
		
		if (isPossible())
			printf ("Case #%d: YES\n", t+1);
		else
			printf ("Case #%d: NO\n", t+1);
	}
	return 0;
}