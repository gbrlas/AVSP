#include <stdio.h>
#include <stdlib.h>

static int
intcompare(const void *p1, const void *p2)
{
 int i = *((int *)p1);
 int j = *((int *)p2);

 if (i > j)
     return (1);
 if (i < j)
     return (-1);
 return (0);
}


int main(int argc, char**argv)
{
	int T, n;
	int i, j, k;
	int X[800], Y[800], P;
	FILE *fp;
	char *input = argv[1];
	char dummy[10];

	fp = fopen(input, "r");
	fscanf(fp, "%d\n", &T);
	for ( i=0; i < T; i++)
	{
		P = 0;
		memset(X, 0, 800 * sizeof(int));	
		memset(Y, 0, 800 * sizeof(int));	
		fscanf(fp, "%d\n", &n);
		for (j=0; j < n; j++)
			fscanf(fp, "%d ", &X[j]);
		fscanf(fp, "\n", dummy);
		for (j=0; j < n; j++)
			fscanf(fp, "%d ", &Y[j]);
		fscanf(fp, "\n", dummy);

		qsort((void *)X, n, sizeof(int), intcompare);
		qsort((void *)Y, n, sizeof(int), intcompare);

		for (j=0; j < n; j++)
			P = P + (X[j] * Y[n-1-j]);

		printf("Case #%d: %d\n", i+1, P);
	}
}
