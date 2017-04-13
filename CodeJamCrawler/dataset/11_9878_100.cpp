#include <stdio.h>

long n, low, high, sol;
long a [10001];

int main ()
{
	FILE *in = fopen ("C-small.in", "r");
	FILE *out = fopen ("C-small.out", "w");
	int numt;
	fscanf (in, "%d", &numt);
	for (int t = 0; t < numt; t++)
	{
		fscanf (in, "%ld %ld %ld", &n, &low, &high);
		for (int i = 0; i < n; i++)
			fscanf (in, "%ld", &a [i]);

		sol = -1;
		for (int j = low; j <= high; j++)
		{
			bool ok = true;
			for (int i = 0; i < n; i++)
				if ((j % a [i] != 0) && (a [i] % j != 0))
				{
					ok = false;
					break;
				}
			if (ok == true)
			{
				sol = j;
				break;
			}
		}
		if (sol == -1)
			fprintf (out, "Case #%d: NO\n", t + 1);
		else
			fprintf (out, "Case #%d: %ld\n", t + 1, sol);
	}
	fclose (in);
	fclose (out);
	return 0;
}
