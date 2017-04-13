#include <stdio.h>

#define SLEN 101
#define MAX_S 100
#define MAX_Q 1000

struct srch {
	char name[101];
	int index;
};
struct srch search[MAX_S];
char query[MAX_Q][SLEN];

int main(int argc, char**argv)
{
	int N, S, Q;
	int i, j, k;
	char *input = argv[1];
	FILE *fp;
	int switches = 0;

	fp = fopen(input, "r");
	fscanf(fp, "%d", &N);
	for ( i=0; i < N; i++)
	{
		memset(search, 0, sizeof(struct srch)*MAX_S);
		memset(query, 0, MAX_Q * SLEN);
		fscanf(fp, "%d\n", &S);
		for (j=0; j < S; j++)
			fgets(search[j].name, SLEN, fp);

		fscanf(fp, "%d\n", &Q);
		for (j=0; j < Q; j++)
			fgets(query[j], SLEN, fp);

		switches = switchrequired(0, S, Q);
		printf("Case #%d: %d\n", i+1, switches);
	}
	fclose(fp);
	return 0;
}

int switchrequired(int start, int S, int Q)
{
	int j, k, max_index;

	for (j=0; j < S; j++)
	{
		search[j].index = MAX_Q + 1;;
		for (k=start; k < Q; k++)
			if (!strcmp(search[j].name, query[k]))
			{
				search[j].index = k;
				break;
			}
	}
	max_index = 0;
	for (j=0; j < S; j++)
	{
		if ( search[j].index == MAX_Q + 1)
			return 0;
		if ( search[j].index > max_index)
			max_index = search[j].index;
	}
/*
	if (max_index == (Q-1))
		return 1;
	else 
*/
		return (1 + switchrequired(max_index, S, Q));
	
}
