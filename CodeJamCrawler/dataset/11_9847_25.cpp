#include <stdio.h>

int main ()
{
	FILE *in = fopen ("C-large.in", "r");
	FILE *out = fopen ("C-large.out", "w");
	int numt;
	fscanf (in, "%d", &numt);
	for (int t = 0; t < numt; t++)
	{
		int n;
		fscanf (in, "%d", &n);
		int sum = 0;
		int xor = 0;
		int min = 10000001;
		int a;
		for (int i = 0; i < n; i++)
		{
			fscanf (in, "%d", &a);
			sum = sum + a;
			xor = xor ^ a;
			if (min > a)
				min = a;
		}
		if (xor != 0)
			fprintf (out, "Case #%d: NO\n", t + 1);
		else
			fprintf (out, "Case #%d: %d\n", t + 1, sum - min);
	}
	fclose (in);
	fclose (out);
	return 0;
}
