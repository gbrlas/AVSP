#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 1001

int n, m, d;
int w [MAXN][MAXN];
int sol;

int min (int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main ()
{
	FILE *in = fopen ("B-small.in", "r");
	FILE *out = fopen ("B-small.out", "w");
	int numt;
	fscanf (in, "%d", &numt);
	for (int t = 0; t < numt; t++)
	{
		fscanf (in, "%d %d %d", &n, &m, &d);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				char c = ' ';
				while ((c < '0') || (c > '9'))
					fscanf (in, "%c", &c);
				w [i][j] = c - '0';
			}
		}
			
		sol = 0;
		for (int k = min (n, m); k >= 3; k--)
		{
			for (int i = 0; i <= n - k; i++)
			{
				for (int j = 0; j <= m - k; j++)
				{
					double sumx = 0.0;
					double sumy = 0.0;
					double centerx = ((double)(i + i + k)) / 2.0;
					double centery = ((double)(j + j + k)) / 2.0;
					for (int ii = i; ii < i + k; ii++)
						for (int jj = j; jj < j + k; jj++)
							if (((ii != i) || (jj != j)) && ((ii != i) || (jj != j + k - 1)) && ((ii != i + k - 1) || (jj != j)) && ((ii != i + k - 1) || (jj != j + k - 1)))
							{
								sumx = sumx + ((double) w [ii][jj]) * (ii - centerx + 0.5);
								sumy = sumy + ((double) w [ii][jj]) * (jj - centery + 0.5);
							}
					if (sumx * sumx + sumy * sumy < 1e-8)
					{
						sol = k;
						break;
					}
				}
				if (sol > 0)
					break;
			}
			if (sol > 0)
				break;
		}

		if (sol == 0)
			fprintf (out, "Case #%d: IMPOSSIBLE\n", t + 1);
		else
			fprintf (out, "Case #%d: %d\n", t + 1, sol);
	}
	fclose (in);
	fclose (out);
	return 0;
}
