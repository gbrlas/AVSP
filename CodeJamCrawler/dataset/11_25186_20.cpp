#include <cstdio>

long long gcd(long long a, long long b)
{
	if ( b == 0 )
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	long long i, j, k, n, t, d;
	FILE *fin = fopen("A-large.in", "r");
	FILE *fout = fopen("A-large.out", "w");

	fscanf(fin, "%lld", &t);
	for (i = 1; i <= t; i++)
	{
		fscanf(fin, "%lld%lld%lld", &n, &k, &j);
		d = 100 / gcd(k, 100);
		fprintf(fout, "Case #%lld: ", i);
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
			
