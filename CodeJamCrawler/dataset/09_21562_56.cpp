#include <stdio.h>
#include <string.h>
#include <memory.h>

#define NMAX 101

int T;
int Line;

int N;

int		tree[NMAX];
int		count[NMAX];
char	name[NMAX][30];
double	data[NMAX];

int		stack[NMAX];
int		top;

int		an;

char	ani[NMAX];
int		NN;
char	atri[NMAX][NMAX];

double	ans;

void init()
{
	N = 0;

	memset(tree, 0, sizeof(tree));
	memset(count, 0, sizeof(count));
	memset(name, 0, sizeof(name));
	memset(data, 0, sizeof(data));

	memset(stack, 0, sizeof(stack));
	top = 0;

	an = 0;

	memset(ani, 0, sizeof(ani));

	NN = 0;

	memset(atri, 0, sizeof(atri));

	ans = 0;
}

FILE *in = fopen("input.txt","r");
FILE *out = fopen("output.txt","w");

void input(int K)
{
	char temp;
	int i;

	do
	{
		fscanf(in, "%c", &temp);
	}while(temp != '(');

	fscanf(in, "%lf", &data[N]);

	tree[N] = K;

	fscanf(in, "%c", &temp);

	if(temp == ')')
	{
		N++;
		return;
	}

	fscanf(in, "%s", &name[N]);

	fscanf(in, "\n");

	i = N;

	N++;

	input(i);
	input(i);

	do
	{
		fscanf(in, "%c", &temp);
	}while(temp != ')');
}

void proc()
{
	int i, j, k;
	int flag, flag2;
	int p;

	ans = data[0];

	p = 0;

	while(p != -1)
	{
		flag = 0;

		if(strlen(name[p]) == 0)
		{
			break;
		}

		for(i = 0; i < NN; i ++)
		{
			if(!strcmp(atri[i], name[p]))
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			for(i = 0; i < N; i ++)
			{
				if(tree[i] == p)
				{
					flag2 = i;
					break;
				}
			}
		}
		else
		{
			flag2 = -1;
			for(i = 0; i < N; i ++)
			{
				if(tree[i] == p && flag2 == -1)
				{
					flag2 = i;
				}
				else if(tree[i] == p && flag2 != -1)
				{
					flag2 = i;
					break;
				}
			}
		}
		
		ans = ans * data[flag2];

		p = flag2;
	}

	fprintf(out, "%.7lf\n", ans);
}

int main()
{
	int i, j, k;

	fscanf(in, "%d\n", &T);

	for(i = 0; i < T; i ++)
	{
		init();

		fscanf(in, "%d\n", &Line);

		input(-1);

		fscanf(in, "%d", &an);

		fprintf(out, "Case #%d:\n", i+1);

		for(j = 0; j < an; j ++)
		{
			do
			{
				fscanf(in, "%s", &ani);
			}while(ani[0] == ' ' || ani[0] == '\n');

			fscanf(in, " ");

			fscanf(in, "%d ", &NN);

			for(k = 0; k < NN; k ++)
			{
				fscanf(in, "%s", &atri[k]);
				if(k != NN-1)
					fscanf(in, " ");
				else
					fscanf(in, "\n");
			}

			if(NN == 0)
				fscanf(in,"\n");

			proc();
		}
	}

	fclose(in);
	fclose(out);
	return 0;
}
