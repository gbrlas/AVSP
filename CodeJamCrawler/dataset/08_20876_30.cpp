#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

#define NMAX 101
#define LMAX 101

int T;
int TT;
int N, M;

char Ti1[ NMAX ][ LMAX ];
char Ti2[ NMAX ][ LMAX ];

int Time[ 2 * NMAX ][ 3 ];
int Index[ 2 * NMAX ];

int Check[ 2 * NMAX ];

int A, B;

void Init()
{
	memset(Ti1, NULL, sizeof(Ti1));
	memset(Ti2, NULL, sizeof(Ti2));
	memset(Check, NULL, sizeof(Check));
	A = 0; B = 0;
}

int sortf(const void *a,const void *b)
{
	int *p=(int *)a;
	int *q=(int *)b;
	if(Time[ *p ][ 0 ] == Time[ *q ][ 0 ])
		return Time[ *p ][ 1 ] - Time[ *q ][ 1 ];
	return Time[ *p ][ 0 ] - Time[ *q ][ 0 ];
}

void Init_Time()
{
	int i;
	for(i = 0; i < N; i++)
	{
		Time[ i ][ 0 ] = (((Ti1[ i ][ 0 ] - '0') * 10) + (Ti1[ i ][ 1 ] - '0')) * 60;
		Time[ i ][ 0 ] += ((Ti1[ i ][ 3 ] - '0') * 10) + (Ti1[ i ][ 4 ] - '0');
		Time[ i ][ 1 ] = (((Ti1[ i ][ 6 ] - '0') * 10) + (Ti1[ i ][ 7 ] - '0')) * 60;
		Time[ i ][ 1 ] += ((Ti1[ i ][ 9 ] - '0') * 10) + (Ti1[ i ][ 10 ] - '0');
		Time[ i ][ 2 ] = 1;
	}
	for(i = 0; i < M; i++)
	{
		Time[ i + N ][ 0 ] = (((Ti2[ i ][ 0 ] - '0') * 10) + Ti2[ i ][ 1 ] - '0') * 60;
		Time[ i + N ][ 0 ] += ((Ti2[ i ][ 3 ] - '0') * 10) + Ti2[ i ][ 4 ] - '0';
		Time[ i + N ][ 1 ] = (((Ti2[ i ][ 6 ] - '0') * 10) + Ti2[ i ][ 7 ] - '0') * 60;
		Time[ i + N ][ 1 ] += ((Ti2[ i ][ 9 ] - '0') * 10) + Ti2[ i ][ 10 ] - '0';
		Time[ i + N ][ 2 ] = 2;
	}
	for(i = 0; i < (N + M); i++)
		Index[ i ] = i;
	qsort(Index, (N + M), sizeof(int), sortf);
}

void Process()
{
	int i, j;
	for(i = 0; i < (N + M); i++)
	{
		for(j = 0; j < i; j++)
		{
			if(Check[ Index[ j ] ] == 0 
				&& Time[ Index[ i ] ][ 2 ] != Time[ Index[ j ] ][ 2 ]
				&& (Time[ Index[ j ] ][ 1 ] + TT) <= Time[ Index[ i ] ][ 0 ])
			{
				Check[ Index[ j ] ] = 1;
				//Check[ Index[ i ] ] = 1;
				break;
			}
		}
		if(j == i)
		{
			if(Time[ Index[ i ] ][ 2 ] == 1)
				A ++;
			else
				B ++;
		}
	}
}

int main()
{
	int i, j;

	FILE *in = fopen("B.in", "r");
	FILE *out = fopen("B.out", "w");

	fscanf(in, "%d\n", &T);

	for(i = 0; i < T; i++)
	{
		Init();

		fscanf(in, "%d\n", &TT);
		fscanf(in, "%d %d\n", &N, &M);
		for(j = 0; j < N; j++)
		{
			fgets(Ti1[ j ], 100, in);
		}
		for(j = 0; j < M; j++)
		{
			fgets(Ti2[ j ], 100, in);
		}
		
		Init_Time();
		Process();

		fprintf(out, "Case #%d: %d %d\n", i + 1, A, B);
	}

	fclose( in );
	fclose( out );
	return 0;
}
