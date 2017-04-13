#include <stdio.h>
#include <string.h>

#define MAX (1<<10)

int v[MAX];

char nome[MAX][MAX];

int s, q;
int cas;

char buff[MAX];

int acha()
{
	int i;

	for (i=0; i<s; i++)
	{
		if (!strcmp(nome[i], buff))
			return i;
	}
	return -1;
}

char foi[MAX];


int main()
{
	int casos, resp;
	int i, j;
	int cont;

	gets(buff);

	sscanf(buff, "%d",&casos);

	for (cas=0; cas<casos; cas++)
	{
		gets(buff);
		sscanf(buff, "%d", &s);
		for (i=0; i<s; i++)
			gets(nome[i]);
		gets(buff);
		sscanf(buff, "%d", &q);

		for (i=0; i<q; i++)
		{
			gets(buff);
			v[i] = acha();
		}

		for (i=0; i<s; i++)
			foi[i] = 0;

		cont = 0;
		resp = 0;

		for (i=0; i<q; i++)
		{
			if (!foi[v[i]])
			{
				cont++;
				if (cont == s)
				{
					resp++;
					for (j=0; j<q; j++)
						foi[j] = 0;
					cont = 1;
				}
				foi[v[i]] = 1;
			}
		}


		printf("Case #%d: %d\n", cas+1, resp);
	}

	return 0;
}
