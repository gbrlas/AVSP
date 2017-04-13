#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define NMAX 1000

int T, N;
int Vec1[ NMAX ], Vec2[ NMAX ];

__int64 Sum;

void Init()
{
	N = 0;
	memset(Vec1, 0, sizeof( Vec1 ));
	memset(Vec2, 0, sizeof( Vec2 ));
	Sum = 0;
}

int sortf1(const void *a,const void *b)
{
	int p=*(int *)a;
	int q=*(int *)b;
	return p - q;
}

int sortf2(const void *a,const void *b)
{
	int p=*(int *)a;
	int q=*(int *)b;
	return q - p;
}

void Process()
{
	int i;
	qsort(Vec1, N, sizeof( int ), sortf1);
	qsort(Vec2, N, sizeof( int ), sortf2);

	for(i = 0; i < N; i ++)
	{
		Sum += ((__int64)Vec1[ i ] * (__int64)Vec2[ i ]);
	}
}

int main()
{
	FILE *in = fopen("A.in", "r");
	FILE *out = fopen("A.txt", "w");

	int i, j;

	fscanf(in, "%d", &T);

	for(i = 0; i < T; i ++)
	{
		Init();
		fscanf(in, "%d", &N);
		for(j = 0; j < N; j ++)
			fscanf(in, "%d" ,&Vec1[ j ] );
		for(j = 0; j < N; j ++)
			fscanf(in, "%d", &Vec2[ j ] );
		Process();
		fprintf(out, "Case #%d: %I64d\n", i + 1, Sum);
	}

	fclose( in );
	fclose( out );
	return 0;
}
