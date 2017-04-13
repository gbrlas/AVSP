#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

#define MAX 10002


#define MAXI(a,b) ((a)>(b)?(a):(b))
#define MINI(a,b) ((a)<(b)?(a):(b))

#define AND 1
#define OR 0



int n;
int v[MAX];
char pode[MAX];

int calc(int a, int alvo)
{
	int t, q, xx, yy;

	if (a >= (n-1)/2)
	{
		if (alvo!=v[a])
			return -1;
		return 0;
	}

	if (alvo == 0)
	{
		q = calc(2*a + 1, 0);
		t = calc(2*a + 2, 0);

		if (v[a] == AND)
		{
			if (MAXI(q,t) == -1)
				return -1;
			else
			{
				if (q == -1)
				{
					return t;
				}
				else if (t== -1)
					return q;
				else
					return MINI(q, t);
			}
		}
		else
		{
			if (q < 0 || t < 0)
				xx = -1;
			else
				xx = q + t;
			yy = xx;
			if (pode[a])
			{
				if (MAXI(q,t) == -1)
				{
					return yy;
					xx = -1;
				}
				else
				{
					if (q == -1)
					{
						xx = t;
					}
					else if (t== -1)
						xx = q;
					else
						xx = MINI(q, t);
				}
			}
			if (yy == -1)
			{
				if (xx == -1)
					return -1;
				return xx + 1;
			}
			if (xx == -1)
				return yy;
			xx = MINI(xx + 1, yy);
		}
	}
	else // alvo = 1;
	{
		q = calc(2*a + 1, 1);
		t = calc(2*a + 2, 1);
		if (v[a] == OR)
		{
			if (MAXI(q,t) == -1)
				xx = -1;
			else
			{
				if (q == -1)
				{
					xx = t;
				}
				else if (t== -1)
					xx = q;
				else
					xx = MINI(q, t);
			}
		}
		else
		{
			if (q < 0 || t < 0)
				xx = -1;
			else
				xx = q + t;
			yy = xx;
			if (pode[a])
			{
				if (MAXI(q,t) == -1)
				{
					return yy;
				}
				else
				{
					if (q == -1)
					{
						xx = t;
					}
					else if (t== -1)
						xx = q;
					else
						xx = MINI(q, t);
				}
			}
			if (yy == -1)
			{
				if (xx == -1)
					return -1;
				return xx + 1;
			}
			if (xx == -1)
				return yy;

			return MINI(xx + 1, yy);
		}
	}

	return xx;

}

int main()
{
	int casos, cas;
	int a, b, bom;
	int c, i, j;

	scanf("%d",&casos);

	for (cas = 1; cas <= casos; cas++)
	{
		scanf("%d %d", &n, &bom);

		for (i=0; i<(n-1)/2; i++)
		{
			scanf("%d %d", &a, &b);
			v[i] = a;
			pode[i] = b;
		}
		j = i;
		for (i=0; i<(n+1)/2; i++, j++)
		{
			scanf("%d",&v[j]);
		}

		printf("Case #%d: ", cas);

		if ((c=calc(0, bom)) == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", c);
	}

	return 0;
}
