#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENGINE	100
#define MAX_QUERIE	1000


int processing(int S, int Q);


char Search_engine[MAX_ENGINE][100];
char Querie[MAX_QUERIE][100];

int main(void)
{
	int n, i, j;
	FILE* in;
	FILE* out;
	int S, Q;
	char string[100];
	char ch;
	int t;

	in = fopen("A-large.in", "r");
	out = fopen("out", "wt");

	fscanf(in, "%d", &n);

	for(i=0; i < n; i++)
	{
		fscanf(in, "%d", &S);
		fgetc(in);
		for(j=0; j < S; j++)
		{
			memset(&string, '\0', sizeof(char)*100);
			t = 0;
			while((ch=fgetc(in))!='\n')
			{
				string[t++] = ch;
			}
			strncpy(Search_engine[j], string, 100);
		}
		fscanf(in, "%d", &Q);
		fgetc(in);
		for(j=0; j < Q; j++)
		{
			memset(&string, '\0', sizeof(char)*100);
			t = 0;
			while((ch=fgetc(in))!='\n' && ch !=EOF)
			{
				string[t++] = ch;
			}
			strncpy(Querie[j], string, 100);
		}
		//fprintf(stdout, "Case #%d: %d\n", i+1, processing(S, Q));
		fprintf(out, "Case #%d: %d\n", i+1, processing(S, Q));
	}

	return 0;
}

int processing(int S, int Q)
{
	int* check;
	int i, j;
	int ok;
	int out;
	int f;

	check = (int *)calloc(sizeof(int), S);

	out = 0;
	ok = 0;
 	for(i=0; i < Q; i++)
	{
		for(j=0; j < S; j++)
		{
			if(!strncmp(Querie[i], Search_engine[j],100))
			{
				check[j] = 1;
				f = j;
				break;
			}
		}
		for(j=0; j < S; j++)
		{
			if(check[j]==0)
			{
				ok = 1;
				break;
			}
		}
		if(ok==0)
		{
			for(j=0; j < S; j++)
				check[j] = 0;
			out ++;
			check[f] = 1;
		}
		else 
			ok = 0;
	}

	return out;
}