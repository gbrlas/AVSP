#include <stdio.h>

long n, m, a, b, c, d, area;
bool ok;
int numT;

void solve ()
{
	for (a = 0; a <= n; a++)
		for (b = 0; b <= m; b++)
			for (c = 0; c <= n; c++)
			{
				if (a != 0)
					d = (area + b * c) / a;
				else
					d = 1;
				if ((d >= 0) && (d <= m) && (a * d - b * c == area))
				{
					ok = true;
					return;
				}
			}
	ok = false;
}

int main ()
{
	FILE *in;
	FILE *out;
	in = fopen ("B-small.in", "r");
	out = fopen ("B.out", "w");

	fscanf (in, "%ld", &numT);
	for (int t = 0; t < numT; t++)
	{
		fscanf (in, "%ld %ld %ld", &n, &m, &area);

		solve ();
		
		if (ok == true)
			fprintf (out, "Case #%d: 0 0 %ld %ld %ld %ld\n", (t + 1), a, b, c, d);
		else
			fprintf (out, "Case #%d: IMPOSSIBLE\n", (t + 1));
	}

	fclose (in);
	fclose (out);
	return 0;
}