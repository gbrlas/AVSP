#include <stdio.h>
#include <memory.h>

#define NMAX 2100

int T;
int A, B;

int N[ NMAX ];
int Data[ NMAX ][ 3500 ][ 2 ];

int Stat[NMAX];
int FF;

void Init()
{
	FF = 0;
	memset(Stat, 0, sizeof(Stat));
}

int Check()
{
	int i,j;
	int Flag = 0;
	for(i=0;i<B;i++)
	{
		for(j=0;j<N[i];j++)
		{
			if(Stat[Data[i][j][0]-1] == Data[i][j][1])
			{
				break;
			}
		}
		if(j==N[i])
		{
			Flag = 1;
			break;
		}
	}
	return Flag;
}

void Process(int K)
{
	if(K == A)
	{
		if(Check() == 0)
		{
			FF = 1;
		}
		return;
	}
	Stat[ K ] = 0;
	Process(K + 1);
	if(FF)	return;

	Stat[ K ] = 1;
	Process(K + 1);
	if(FF)	return;
}

int main()
{
	int i, j, k;
	FILE *in = fopen("B.in","r");
	FILE *out = fopen("B.txt","w");
	fscanf(in,"%d",&T);
	for(i=0;i<T;i++)
	{
		Init();
		fscanf(in,"%d",&A);
		fscanf(in,"%d",&B);
		for(j=0;j<B;j++)
		{
			fscanf(in,"%d",&N[j]);
			for(k=0;k<N[j];k++)
				fscanf(in,"%d %d",&Data[j][k][0], &Data[j][k][1]);
		}
		Process(0);
		fprintf(out, "Case #%d: ", i+1);
		if(FF == 0)
			fprintf(out,"IMPOSSIBLE\n");
		else
		{
			for(j=0;j<A;j++)
				fprintf(out,"%d ", Stat[j]);
			fprintf(out,"\n");
		}
	}
	fclose(out);
	fclose(in);
	return 0;
}
