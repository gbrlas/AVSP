#include <stdio.h>

char s[25][25];
char u[25][25];

char r[128];
int ri;

void wyczysc()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			s[i][j] = 0;
			u[i][j] = 0;
		}
	}
	ri = 0;
}

void sprawdz()
{
	if (ri > 1)
	{
		for (int i = 0; i < ri-1; i++)
		{
			if (u[r[i]-'A'][r[ri-1]-'A'])
			{
				ri = 0;
				return;
			}
		}
	}
}

void wstaw(char x)
{
	r[ri++] = x;
	if (ri > 1)
	{
		if (s[r[ri-1]-'A'][r[ri-2]-'A'])
		{
			ri -= 2;
			wstaw(s[r[ri+1]-'A'][r[ri]-'A']);
		}
		else
			sprawdz();
	}
}

void wypisz()
{
	if (ri == 0)
		printf("[]\n");
	else
	{
		printf("[%c", r[0]);
		for (int i = 1; i < ri; i++)
			printf(", %c", r[i]);
		printf("]\n");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i != n; i++)
	{
		wyczysc();
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			char ss[8];
			scanf("%s", ss);
			s[ss[0]-'A'][ss[1]-'A'] = ss[2];
			s[ss[1]-'A'][ss[0]-'A'] = ss[2];
		}
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			char uu[8];
			scanf("%s", uu);
			u[uu[0]-'A'][uu[1]-'A'] = 1;
			u[uu[1]-'A'][uu[0]-'A'] = 1;
		}
		scanf("%d", &k);
		char wej[128];
		scanf("%s", wej);
		for (int j = 0; j < k; j++)
			wstaw(wej[j]);

		printf("Case #%d: ", i+1);
		wypisz();
	}
	return 0;
}
