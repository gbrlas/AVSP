#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"


int main()
{
	int N;
	FILE *fileIn;

	fileIn = fopen("a.in", "r");

	fscanf(fileIn, "%d", &N);

	long long nn, i, j, k, count;
	long long n, A, B, C, D, x0, y0, M;
	long long X[200], Y[200];

	for (nn = 0; nn < N; nn++)
	{
		fscanf(fileIn, "%llu %llu %llu %llu %llu %llu %llu %llu", &n, &A, &B, &C, &D, &x0, &y0, &M);

		X[0] = x0;
		Y[0] = y0;
		for (i = 1; i < n; i++)
		{
			X[i] = (A * X[i - 1] + B) % M;
			Y[i] = (C * Y[i - 1] + D) % M;
		}
		
		count = 0;
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				for (k = j + 1; k < n; k++)
				{
					if (((X[i] + X[j] + X[k]) % 3 == 0) && ((Y[i] + Y[j] + Y[k]) % 3 == 0)) count++;
				}

		printf("Case #%llu: %llu\n", nn + 1, count);
	}

	fclose(fileIn);

	return 0;
}

