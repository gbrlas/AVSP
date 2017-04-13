#include <stdio.h>

void sort_fre(int* fre, int L);

FILE* out;
int main(void)
{
	FILE* in;
	int N, P, K, L;
	int i, j,  k;
	int* fre;
	int key_table;
	int result;
	int temp;

	in = fopen("A-small-attempt0.in", "r");
	out = fopen("out.txt", "wt");

	fscanf(in, "%d", &N);
	for(i=0; i < N; i++)
	{
		fscanf(in, "%d %d %d", &P, &K, &L);
		fre = (int *)calloc(sizeof(int), L);
		for(j=0; j < L; j++) fscanf(in, "%d", &fre[j]);

		sort_fre(fre, L);
		
		result = 0;
		temp=0;
		for(j=0; j < L; j++)
		{
			if(j%K==0) temp++;
			result += temp*fre[j];
		}
		fprintf(stdout, "Case #%d: %d\n", i+1, result);
		fprintf(out, "Case #%d: %d\n", i+1, result);
	}
	


	return 0;
}

void sort_fre(int* fre, int L)
{
	int i, j, t;

	for(i=0; i < L; i++)
	{
		for(j=i; j < L; j++)
		{
			if(fre[i] < fre[j])
			{
				t = fre[i];
				fre[i] = fre[j];
				fre[j] = t;
			}
		}
	}
}
