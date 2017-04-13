#include <stdio.h>
#include <stdlib.h>

long n, L, c;
long long time, sol, final_sol;
long a [1001];
long long count [1001];
long p [1001];

int compare (const void *ii, const void *jj)
{
	long i = *(long*)ii; 
	long j = *(long*)jj; 
	if (a [i] < a [j])
		return 1;
	else if (a [i] > a [j])
		return -1;
	else
		return 0;
}

int main ()
{
	FILE *in = fopen ("B-large.in", "r");
	FILE *out = fopen ("B-large.out", "w");
	int numt;
	fscanf (in, "%d", &numt);
	for (int t = 0; t < numt; t++)
	{
		printf ("%d %d\n", t, numt);
		fscanf (in, "%ld %lld %ld %ld", &L, &time, &n, &c);
		for (int i = 0; i < c; i++)
			fscanf (in, "%ld", &a [i]);
		
		for (int i = 0; i < c; i++)
			p [i] = i;
		qsort (p, c, sizeof(long), compare);
//		for (int i = 0; i < c; i++)
//			printf ("%d\n", a [p [i]]);

		sol = 0;
		for (int i = 0; i < c; i++)
		{
			count [i] = n / c;
			if (n % c > i)
				count [i]++;
			sol += count [i] * (2 * a [i]);
		}
		final_sol = sol;

		long i = 0;
		long k = 0;
		long long current_time = 0;
		while (current_time < time)
		{
			current_time += 2 * a [i];
			count [i]--;
			i++;
			if (i == c)
				i = 0;
			k++;
		}

		// Ne uzimam parcijalno
		long long new_sol = sol;
		long count_sum = 0;
		int j = 0;
		while ((j < c) && (count_sum < L))
		{
			if (count [p [j]] + count_sum < L)
			{
				new_sol -= count [p [j]] * a [p [j]];
				count_sum += count [p [j]];
			}
			else
			{
				new_sol -= (L - count_sum) * a [p [j]];
				count_sum += (L - count_sum);
			}
			j++;
		}
		if (final_sol > new_sol)
			final_sol = new_sol;

		if (L > 0)
		{
			// Uzecu parcijalno
			k--;
			i = (i + c - 1) % c;
			current_time -= 2 * a [i];
			new_sol = sol - 2 * a [i] + (time - current_time) + (a [i] - (time - current_time) / 2);
			L--;

			count_sum = 0;
			j = 0;
			while ((j < c) && (count_sum < L))
			{
				if (count [p [j]] + count_sum < L)
				{
					new_sol -= count [p [j]] * a [p [j]];
					count_sum += count [p [j]];
				}
				else
				{
					new_sol -= (L - count_sum) * a [p [j]];
					count_sum += (L - count_sum);
				}
				j++;
			}
			if (final_sol > new_sol)
				final_sol = new_sol;
		}

		fprintf (out, "Case #%d: %lld\n", t + 1, final_sol);
	}
	fclose (in);
	fclose (out);
	return 0;
}
