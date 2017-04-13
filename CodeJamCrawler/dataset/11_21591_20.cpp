#include <stdio.h>

bool tab[101][101];

int main()
{
	for (int nn = 1; nn <= 100; nn++)
	{
		for (int w = 0; w <= nn; w++)
		{
			if ((100*w) % nn == 0)
				tab[nn][100*w/nn] = true;
		}
		for (int i = 0; i <= 100; i++)
		{
			if (tab[nn-1][i])
				tab[nn][i] = true;
		}
	}

	int t;

	scanf("%d", &t);

	for (int q = 1; q <= t; q++)
	{
		int n, pd, pg;
		scanf("%d %d %d", &n, &pd, &pg);

		bool ans;
		if (pg == 100 && pd < 100)
			ans = false;
		else if (pg == 0 && pd > 0)
			ans = false;
		else if (n >= 100)
			ans = true;
		else
			ans = tab[n][pd];

		if (ans)
			printf("Case #%d: Possible\n", q);
		else
			printf("Case #%d: Broken\n", q);
	}

	return 0;
}
