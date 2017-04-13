#include <stdio.h>
#include <string.h>

#define MAX 512
#define MOD 10000

char buff[MAX];
char pat[MAX] = "welcome to code jam";
int sol[MAX];

int n, m;

int main()
{
	int cas, casos;
	gets(buff);
	sscanf(buff, "%d", &casos);
	int i, j;


	for (cas=1; cas<=casos; cas++)
	{
		printf("Case #%d: ", cas);

		gets(buff);
		n = strlen(buff);
		memset(sol, 0, sizeof(sol));

		for (i=0; i<n; i++)
		{
			for (j=0; pat[j]; j++)
			{
				if (buff[i] == pat[j])
				{
					if (j == 0)
					{
						sol[j]++;
						sol[j] %= MOD;
					}
					else
					{
						sol[j] += sol[j-1];
						sol[j] %= MOD;
					}
				}
			}
		}
		for (j=0; pat[j]; j++);
		printf("%04d\n", sol[j-1]);

	}

	return 0;
}
