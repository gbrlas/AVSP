#include <stdio.h>
#include <stdlib.h>

#define MAXN 1001

int x, s, r, n;
double t;
int b [MAXN], e [MAXN], w [MAXN], p [MAXN];
double time [MAXN];
double sol;

int compare (const void * a, const void * b)
{
	return ( w [*(int*)a] - w [*(int*)b] );
}

int main ()
{
	FILE *in = fopen ("A-small.in", "r");
	FILE *out = fopen ("A-small.out", "w");
	int numt;
	fscanf (in, "%d", &numt);
	for (int tt = 0; tt < numt; tt++)
	{
		fscanf (in, "%d %d %d %lf %d", &x, &s, &r, &t, &n);
		double rest = x;
		for (int i = 0; i < n; i++)
		{
			fscanf (in, "%d %d %d", &b [i], &e [i], &w [i]);
			time [i] = ((double)(e [i] - b [i])) / (w [i] + s);
			rest = rest - (double)(e [i] - b [i]);
			p [i] = i;
		}
		qsort (p, n, sizeof (int), compare);
		double sol = 0.0;

		if (t <= rest / r)
		{
			sol = t + (rest - t * r) / s;
			for (int i = 0; i < n; i++)
				sol += time [i];
		}
		else
		{
			sol = rest / r;
			t = t - rest / r;
			for (int j = 0; j < n; j++)
			{
				int i = p [j];
				if (t > 0)
				{
					if (t > ((double)(e [i] - b [i])) / (w [i] + r))
					{
						sol = sol + ((double)(e [i] - b [i])) / (w [i] + r);
						t = t - ((double)(e [i] - b [i])) / (w [i] + r);
					}
					else
					{
						sol = sol + t + ((double)(e [i] - b [i] - (r + w [i]) * t)) / (w [i] + s);
						t = 0.0;
					}
				}
				else
					sol = sol + time [i];
			}
		}
		
		fprintf (out, "Case #%d: %0.10lf\n", tt + 1, sol);
	}
	fclose (in);
	fclose (out);
	return 0;
}
