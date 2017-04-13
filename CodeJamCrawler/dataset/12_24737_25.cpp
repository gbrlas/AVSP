#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, l, t, a, b, x, k, y, sum, p, prej, prey;
	int w[10];

	FILE * fin = fopen("C-small-attempt0.in", "r");
	FILE * fout = fopen("C-small-attempt0.out", "w");

	fscanf(fin, "%d", &t);

	for (i = 1; i <= t; i++)
	{
		fscanf(fin, "%d%d", &a, &b);
		sum = 0;
		prej = 0; prey = 0;
		for (j = a; j <= b; j++)
		{
			l = 0;
			x = j;
			while ( x > 0 )
			{
				w[l++] = x % 10;
				x /= 10;
			}			
			for (k = 0; k < l; k++)
			{
				y = 0;
				for (p = l-1; p >= 0; p--)
				{
					y = y * 10 + w[(k+p)%l];
				}
				if ( y > j  &&  y <= b  &&  y >= a  &&  (prej != j || prey != y))
				{
					sum++;
					prej = j; prey = y;
					//fprintf(fout, "%d %d\n", j, y);
				}
			}		
		}
		fprintf(fout, "Case #%d: %d\n", i, sum);
	}

	fclose(fin);
	fclose(fout);

	return 0;
}