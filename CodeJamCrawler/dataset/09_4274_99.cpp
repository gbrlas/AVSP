#include <stdio.h>
#include <string.h>

#define NMAX 101
#define LMAX 510

int n;

int leng[NMAX];
char string[NMAX][LMAX];

int dy[NMAX][LMAX][20];

char word[19];

int sum[NMAX];

void Input()
{
	int i;
	FILE *in = fopen("input.txt","r");
	strcpy(word,"welcome to code jam");

	fscanf(in,"%d\n", &n);

	for(i = 0; i < n; i ++)
	{
		fgets(string[i], 509, in);
		leng[i] = strlen(string[i]);
	}

	fclose(in);
}

void Process()
{
	int i, j, k, t;

	for(i = 0; i < n; i ++)
	{
		for(j = 0; j < leng[i]; j ++)
		{
			if(string[i][j] == word[0])
				dy[i][j][0] = 1;
		}
		for(j = 1; j < 19; j ++)
		{
			for(k = 0; k < leng[i]; k ++)
			{
				if(string[i][k] != word[j])
					continue;
				for(t = k - 1; t >= 0; t --)
				{
					if(string[i][t] == word[j-1])
					{
						dy[i][k][j] += dy[i][t][j-1];
						dy[i][k][j] %= 10000;
					}
				}
			}
		}
	}
	for(i = 0 ; i < n; i ++)
	{
		for(j = 0; j < leng[i]; j ++)
		{
			sum[i] += dy[i][j][18];
		}
	}
}

void Output()
{
	int i;
	FILE *out = fopen("output.txt","w");
	for(i = 0; i < n; i ++)
	{
		fprintf(out,"Case #%d: ", i + 1);
		if(sum[i]<1000)
			fprintf(out,"0");
		if(sum[i]<100)
			fprintf(out,"0");
		if(sum[i]<10)
			fprintf(out,"0");
		fprintf(out,"%d\n", sum[i]);
	}
	fclose(out);
}

int main()
{
	Input();
	Process();
	Output();
	return 0;
}
