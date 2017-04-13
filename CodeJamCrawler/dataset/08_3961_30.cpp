#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 101
#define QEMAX 101
#define LMAX 101

int T;
int N1, N2;

char Name[ NMAX ][ LMAX ];
char Quere[ QEMAX ][ LMAX ];

int L1[ NMAX ], L2[ NMAX ];

int M[ NMAX ];
int Place[ NMAX ][ QEMAX ];

int Now;
int Count;

void Init()
{
	memset(Name, NULL, sizeof(Name));
	memset(Quere, NULL, sizeof(Quere));
	memset(M, 0, sizeof(M));
	memset(Place, 0, sizeof(Place));
	Now = -1;
	Count = 0;
}

void Find()
{
	int i, j, k;
	int Flag;
	for(i = 0; i < N2; i++)
	{
		for(j = 0 ; j < N1; j ++)
		{
			Flag = 0;
			for(k = 0; k < L1[ j ]; k++)
			{
				if(k >= L1[ j ])
				{
					Flag = 1;
					break;
				}
				if(Name[ j ][ k ] != Quere[ i ][ k ])
				{
					Flag = 1;
					break;
				}
			}
			if(Flag == 0 && (L1[ j ] == L2[ i ]))
			{
				Place[ j ][ M[ j ] ] = i;
				M[ j ] ++;
				break;
			}
		}
	}
	for(i = 0; i< N1; i++)
	{
		Place[ i ][ M[ i ]] = 99999999;
		M[ i ] ++;
	}
}

void Process()
{
	int i, j;
	int Max;
	while( Now < N2 )
	{
		Max = -1;
		for(i = 0; i < N1; i ++)
		{
			for(j = 0; j < M[ i ]; j++)
			{
				if( Place[ i ][ j ] > Now)
				{
					if( Place[ i ][ j ] > Max )
						Max = Place[ i ][ j ];
					break;
				}
			}
		}
		Now = (Max - 1);
		Count ++;
	}
}

int main()
{
	int i, j, k;
	FILE *in = fopen("A.in", "r");
	FILE *out = fopen("A.out", "w");
	fscanf(in, "%d", &T);
	for(i = 0;i < T; i++)
	{
		Init();

		// Input
		fscanf(in, "%d\n", &N1);
		for(j = 0; j < N1; j ++)
		{
			fgets(Name[ j ], LMAX, in);
			for(k = 100; k >= 0; k--)
			{
				if(Name[ j ][ k ] != NULL)
				{
					L1[ j ] = k;
					break;
				}
			}
		}
		fscanf(in, "%d\n", &N2);
		for(j = 0; j < N2; j ++)
		{
			fgets(Quere[ j ], LMAX, in);
			for(k = 100; k >= 0; k--)
			{
				if(Quere[ j ][ k ] != NULL)
				{
					L2[ j ] = k;
					break;
				}
			}
		}

		Find();
		Process();

		fprintf(out, "Case #%d: %d\n", i + 1, Count - 1);
	}
	fclose(out);
	fclose(in);
	return 0;
}
