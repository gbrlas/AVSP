#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>

#define INFILE1 "A-small-attempt4.in"
#define OUTFILE1 "A-small.out"

#define INFILE2 "A-large.in"
#define OUTFILE2 "A-large.out"

FILE *fi = fopen(INFILE1, "r+");
FILE *fo = fopen(OUTFILE1, "w+");

int S, Q, ans, tcase;
int query[1001], count[1001][101], check[101];
char name[101][110];

void init()
{
	S = Q = ans = 0;
	memset(query, 0, sizeof(query));
	memset(name, 0, sizeof(name));
	memset(count, 0, sizeof(count));
	memset(check, 0, sizeof(check));
}

void input()
{
	int i, j, pos;
	char temp[101];

	fscanf(fi, "%d", &S);
	for(i=0; i<S; i++)
	{
		do
			fgets(name[i], 102, fi);
		while(name[i][0] != ' ' && '0' > name[i][0] && name[i][0] < 'z' );
	}
	fscanf(fi, "%d", &Q);
	for(i=0; i<Q; i++)
	{
		do
			fgets(temp, 102, fi);
		while(temp[0] != ' ' && '0' > temp[0] && temp[0] < 'z' );

		for(j=0; j<S; j++)
		{
			if(strcmp(temp, name[j]) == 0)
			{
				pos = j;
				break;
			}
		}
		query[i] = pos;
	}
}

void proc()
{
	int i, j, cnt, before;

	for(i=0; i<Q; i++)
	{
		for(j=0; j<S; j++)
		{
			if(j == query[i]) continue;
			if(i == 0) count[i][j] = 1;
			else count[i][j] = count[i - 1][j] + 1;
		}
		count[i][query[i]] = 0;
	}

	FILE *fo2 = fopen("t.txt", "w+");
	for(i=0; i<Q; i++)
	{
		for(j=0; j<S; j++)
		{
			fprintf(fo2, "%2d ", count[i][j]);
		}
		fprintf(fo2, "\n");
	}
	fclose(fo2);

	i = 0;
	cnt = S;
	for(;;)
	{
		for(j=0; j<S; j++)
		{
			if(count[i][j] == 0 && check[j] != 1)
			{
				check[j] = 1;
				cnt--;
				break;
			}
		}
		if(cnt == 0)
		{
			cnt = S;
			memset(check, 0, sizeof(check));
			ans++;
		}
		else
		{
			i++;
			if(i >= Q) break;
		}
	}
}

void output()
{
	fprintf(fo, "Case #%d: %d\n", tcase + 1, ans);
	tcase++;
	printf("%d\n", tcase);
}

int main()
{
	int t, i;

	fscanf(fi, "%d", &t);
	for(i=0; i<t; i++)
	{
		input();
		proc();
		output();
		init();
	}
	fclose(fi);
	fclose(fo);
	return 0;
}
