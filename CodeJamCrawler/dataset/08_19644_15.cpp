#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include <stdlib.h>


int compare (const void * a, const void * b)
{
  return -( *(long long*)a - *(long long*)b );
}


int main()
{
	int N;
	FILE *fileIn;

	fileIn = fopen("a.in", "r");

	fscanf(fileIn, "%d", &N);

	long long nn, i, n, p, k, l, count;
	long long freq[10000];


	for (nn = 0; nn < N; nn++)
	{
		fscanf(fileIn, "%llu %llu %llu", &p, &k, &l);

		for (i = 0; i < l; i++)
		{
			fscanf(fileIn, "%llu", &freq[i]);
			//freq[i][1] = i;
		}

		qsort (freq, l, sizeof(long long), compare);

		count = 0;

		for (i = 0; i < l; i++)
		{
			count += (i / k + 1) * freq[i];
		}


		printf("Case #%llu: %llu\n", nn + 1, count);
	}

	fclose(fileIn);

	return 0;
}

