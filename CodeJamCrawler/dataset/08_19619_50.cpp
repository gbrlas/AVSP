#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"

typedef struct mapastrtag
{
	int dist, visit;
} mapastr;

int mapa[102][1002];
mapastr mapa2[1002];
int S, Q, globDist;

int rek(int i, int dist)
{
	if (i == 0) 
	{
		if (dist < globDist) globDist = dist;
		return dist;
	}

	if (dist > globDist) return dist;
	if (dist > mapa2[i].dist) return 10000;

	int j = 0, l;
	int cur, min = 10000;

	for (j = 0; j < S; j++)
	{
		
		if (mapa[i][j] != 0) 
		{
			for (l = i; l > i - mapa[i][j]; l--)
			{
				if (mapa2[l].dist > dist) mapa2[l].dist = dist;
			}
			cur = rek(i - mapa[i][j], dist + 1);

			if (cur < min) min = cur;
		}
	}

	return min;
}

int main()
{
	char N;
	FILE *fileIn;

	fileIn = fopen("a.in", "r");

	fscanf(fileIn, "%d", &N);


	char names[102][102];
	char query[102];

	int n, i, j;

	for (n = 0; n < N; n++)
	{
		fscanf(fileIn, "%d\n", &S);

		for (i = 0; i < S; i++)
		{
			fgets(names[i], 102, fileIn);
			//fscanf(fileIn, "%s", names[i]);
		}

		fscanf(fileIn, "%d\n", &Q);

		for (j = 0; j < S; j++)
		{
			mapa[0][j] = 0;
			mapa2[0].dist = 0;
			mapa2[0].visit = 0;
		}			

		for (i = 0; i < Q; i++)
		{
			//fscanf(fileIn, "%s", query);
			fgets(query, 102, fileIn);

			
			for (j = 0; j < S; j++)
			{
				if (strcmp(names[j], query) == 0)
				{
					mapa[i + 1][j] = 0;
				}
				else
				{
					mapa[i + 1][j] = mapa[i][j] + 1;
				}

				mapa2[i].dist = 10000;
				mapa2[i].visit = 0;
			}			
		}

		//dijkstra
		globDist = 10000;
		if (Q == 0) printf("Case #%d: %d\n", n + 1, 0);
		else printf("Case #%d: %d\n", n + 1, rek(Q, -1));
	}

	return 0;
}

