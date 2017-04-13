#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define MAX (1<<20)

typedef struct
{
	double p;
	char nome[16];
	int f1, f2;
}tipo;

tipo v[MAX];
char buff[16];

char ani[128][16];

int qt;
char c;

int le()
{
	double p;
	int t = qt;
	qt++;

	scanf("%lf", &p);
	v[t].p = p;

	scanf(" %c", &c);

	if (c == ')')
	{
		v[t].f1 = v[t].f2 = -1;
		return t;
	}
	
//	buff[0] = c;
	ungetc(c, stdin);
	scanf("%[a-z]", buff);
	strcpy(v[t].nome, buff);

	scanf(" %c", &c);
	v[t].f1 = le();

	scanf(" %c", &c);
	v[t].f2 = le();

	scanf(" %c", &c);

	return t;
}

int n;
int kk;

double vai(int k, double p)
{
	p*= v[k].p;
	
	if (v[k].f1!=-1)
	{
		int i;

		for (i=0; i<kk; i++)
		{
			if (!strcmp(v[k].nome, ani[i]))
			{
				break;
			}
		}
		if (i!=kk) // achou alguem
		{
			p = vai(v[k].f1, p);
		}
		else
		{
			p = vai(v[k].f2, p);
		}
	}


	return p;
}

int main()
{
	int cas, casos;


	scanf("%d", &casos);

	for (cas=1; cas<=casos; cas++)
	{
		printf("Case #%d:\n", cas);
		scanf("%*d");
		scanf(" %c", &c);
		qt = 0;
		le();

		int i;

		scanf(" %d", &n);

		for (;n--; )
		{
			scanf("%*s %d", &kk);
			for (i=0; i<kk; i++)
			{
				scanf("%s", ani[i]);
			}

			printf("%.7f\n", vai(0, 1.0));
		}
	}
	return 0;
}
