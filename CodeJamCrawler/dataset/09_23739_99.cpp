#include <stdio.h>

#define MAX (1<<20)
#define MAXL (16)
#define MAXDIC (5004)

char buff[MAX];
char dic[MAXDIC][MAXL];


int main()
{
	int casos, cas, i, l, n;

	gets(buff);
	sscanf(buff, "%d %d %d", &l, &n, &casos);

	for (i=0; i<n; i++)
	{
		gets(dic[i]);
	}

	int k, resp, j;

	for (cas = 1; cas <= casos; cas++)
	{
		gets(buff);	
		resp = 0;

		for (i=0; i<n; i++)
		{
			for (k=0, j=0; k<l; k++, j++)
			{
				if (buff[j] == '(')
				{
					while (buff[j]!= dic[i][k] && buff[j]!= ')')
					{
						j++;
					}
					if (buff[j] == ')')
					{
						k = 1000;
						break;
					}
					while (buff[j]!= ')')
					{
						j++;
					}
				}
				else
				{
					if (buff[j]!= dic[i][k])
					{
						k = 1000;
						break;
					}
				}
			}
			if (k==l)
			{
				resp++;
			}
		}
		printf("Case #%d: %d\n", cas, resp);
	}
	return 0;
}

