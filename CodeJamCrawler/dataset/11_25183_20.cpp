#include <cstdio>

int gcd(int a, int b)
{
	if ( b == 0 )
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	int i, j, k, n, t, d;
	FILE *fin = fopen("A-small-attempt0.in", "r");
	FILE *fout = fopen("A-small-attempt0.out", "w");

	fscanf(fin, "%d", &t);
	for (i = 1; i <= t; i++)
	{
		fscanf(fin, "%d%d%d", &n, &k, &j);
		d = 100 / gcd(k, 100);
		fprintf(fout, "Case #%d: ", i);
		if ( j == 0  ||  j == 100 )
		{
			if ( j == k )
				fprintf(fout, "Possible\n");
			else
				fprintf(fout, "Broken\n");
			continue;
		}
		if ( d <= n )
			fprintf(fout, "Possible\n");
		else
			fprintf(fout, "Broken\n");
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
			
