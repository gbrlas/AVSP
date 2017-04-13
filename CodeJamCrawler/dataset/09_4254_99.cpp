#include <stdio.h>
#include <string.h>

#define NMAX 501
#define LMAX 16
#define DMAX 5010

int l, d, n;

char data[DMAX][LMAX];
char word[NMAX][LMAX][26];

char buffer[1000];

int count[NMAX];

void input();
void process();
void output();

int main()
{
	input();
	process();
	output();
	return 0;
}

void buffer_proc(int t)
{
	int i, j;
	int leng;
	int flag;

	leng = strlen(buffer);

	flag = 0;
	for(i = 0; i < leng; i ++)
	{
		if(buffer[i] != '(')
		{
			word[t][flag][buffer[i]-'a'] = 1;
			flag++;
			continue;
		}

		i ++;

		while(buffer[i] != ')')
		{
			word[t][flag][buffer[i]-'a'] = 1;
			i ++;
		}

		flag ++;
	}
}

void input()
{
	int i;

	FILE *in = fopen("input.txt","r");
	fscanf(in, "%d%d%d", &l, &d, &n);
	
	for(i = 0; i < d; i ++)
	{
		fscanf(in, "%s", data[i]);
	}

	for(i = 0; i < n; i ++)
	{
		fscanf(in, "%s", buffer);
		buffer_proc(i);
	}

	fclose(in);
}

void process()
{
	int i, j, k;
	for(i = 0; i < n; i ++)
	{
		for(j = 0; j < d; j ++)
		{
			for(k = 0; k < l; k ++)
			{
				if(!word[i][k][data[j][k]-'a'])
					break;
			}
			if(k == l)
				count[i] ++;
		}
	}
}

void output()
{
	int i;
	FILE *out = fopen("output.txt","w");
	for(i = 0; i < n; i ++)
		fprintf(out, "Case #%d: %d\n", i+1, count[i]);
	fclose(out);
}