#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Print(int num, FILE* file, int a)
{
	switch(a)
	{
	case 1:
		fprintf(file, "Case #%d: YES\n", num+1);
		break;
	case 0:
		fprintf(file, "Case #%d: NO\n", num+1);
		break;
	}
}


int main()
{
	int TotalCount, i, j, k, q, IsOk;
	int **temp;
	long double k1;
	int *biggest;
	int N, M;
	FILE* input, *output;
	input = fopen("B-small-attempt1.in", "r");
	output = fopen("B-small-attempt1.out", "w");
	fscanf(input, "%d", &TotalCount);
	for(i = 0; i < TotalCount; i++)
	{
		IsOk = 1;
		fscanf(input, "%d %d", &N, &M);
		temp = (int**)malloc(sizeof(int*) * N);
		biggest = (int*)malloc(sizeof(int) * N);
		memset(biggest, 0,N*sizeof(int));
		for(j = 0; j < N; j++)
		{
			temp[j] = (int*)malloc(sizeof(int) * M);
			for(k = 0; k < M; k++)
			{
				fscanf(input, "%d", &temp[j][k]);
				if(temp[j][k] > biggest[j])
					biggest[j] = temp[j][k];
			}
		}
		for(j = 0; j < N & IsOk; j++)
		{
			for(k = 0; k < M & IsOk; k++)
			{
				if(temp[j][k] < biggest[j])
				{
					for(q = 0; q < N; q++)
					{
						if(q == j)
							continue;
						if(temp[j][k] < temp[q][k])
						{
							IsOk = 0;
							break;
						}
					}
				}
			}
		}
		Print(i, output, IsOk);
	}
	fclose(input);
	fclose(output);
	return 0;
}
