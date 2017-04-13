#include <stdio.h>
#include <stdlib.h>
#define MAXT 100
#define MAXN 1000

typedef unsigned long int ulint;
typedef unsigned char uchar;


ulint patrick_addition(ulint *A, ulint n)
{
	int i;
	ulint acc = A[0];
	for (i=1; i < n; i++)
		acc ^= A[i];
	return acc;
}

ulint normal_addition(ulint *A, ulint n)
{
	int i;
	ulint acc = 0;
	for (i=0; i < n; i++)
		acc += A[i];
	return acc;
}

int comparison(const void *a, const void *b)
{
	if (*(ulint *)a == *(ulint *)b)
		return 0;
	if (*(ulint *)a > *(ulint *)b)
		return 1;
	return -1;
}

/* Returns -1 if the answer is NO. */
long int sean_optimal(ulint *A, ulint n)
{
	ulint truesum, patsum[2];
	ulint ts[2];
	int i;
	truesum = 0;
	
	for(i=1; i < n; i++)
	{
		patsum[0] = patrick_addition(A, i);
		patsum[1] = patrick_addition(&A[i], n-i);
		if(patsum[0] == patsum[1])
		{
			ts[0] = normal_addition(A, i);
			ts[1] = normal_addition(&A[i], n-i);
			if(ts[0] > truesum || ts[1] > truesum)
			{
				if(ts[0] > ts[1])
					truesum = ts[0];
				else
					truesum = ts[1];
			}
		}
	}
	if(truesum == 0)
		return -1;
	return truesum;
}

int main(int argc, char *argv[])
{
	int N, T;
	int i, j;
	long int optimal;
	ulint candyvals[MAXN];
	fscanf(stdin, "%i", &T);
	for(i=0; i < T; i++)
	{
		fscanf(stdin, "%i", &N);
		for(j=0; j < N; j++)
		{
			fscanf(stdin, "%li", &candyvals[j]);
		}
		qsort(candyvals, N, sizeof(ulint), comparison);
		optimal = sean_optimal(candyvals, N);
		if(optimal >= 0)
			printf("Case #%i: %li\n", i+1, optimal);
		else
			printf("Case #%i: NO\n", i+1);
	}
	return 0;
}
