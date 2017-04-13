#include <stdio.h>
#include <string.h>

// 168
int primes[168] =
{
	2, 3, 5, 7, 11, 13, 17, 19, 23,
	29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
	71, 73, 79, 83, 89, 97, 101, 103, 107, 109,
	113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
	173, 179, 181, 191, 193, 197, 199, 211, 223, 227,
	229, 233, 239, 241, 251, 257, 263, 269, 271, 277,
	281, 283, 293, 307, 311, 313, 317, 331, 337, 347,
	349, 353, 359, 367, 373, 379, 383, 389, 397, 401,
	409, 419, 421, 431, 433, 439, 443, 449, 457, 461,
	463, 467, 479, 487, 491, 499, 503, 509, 521, 523,
	541, 547, 557, 563, 569, 571, 577, 587, 593, 599,
	601, 607, 613, 617, 619, 631, 641, 643, 647, 653,
	659, 661, 673, 677, 683, 691, 701, 709, 719, 727,
	733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
	809, 811, 821, 823, 827, 829, 839, 853, 857, 859,
	863, 877, 881, 883, 887, 907, 911, 919, 929, 937,
	941, 947, 953, 967, 971, 977, 983, 991, 997
};

int pod[168];

int main()
{
	int T;
	scanf("%d", &T);

	for (int tst = 1; tst <= T; tst++)
	{
		int n;
		scanf("%d", &n);

		if (n == 1)
		{
			printf("Case #%d: %d\n", tst, 0);
			continue;
		}

		memset(pod, 0, 168 * sizeof(int));
		int max = 1;

		for (int i = 1; i <= n; i++)
		{
			int v = i;
			int inc = 0;
			for (int p = 0; p < 168 && v > 1; p++)
			{
				int x = 0;
				while ((v % primes[p]) == 0)
				{
					x++;
					v /= primes[p];
				}
				if (x > pod[p])
				{
					pod[p] = x;
					inc = 1;
				}
			}
			max += inc;
		}

		int min = 0;
		for (int p = 0; p < 168; p++)
		{
			if (pod[p])
			{
				int pot = 1;
				for (int i = 0; i < pod[p]; i++)
					pot *= primes[p];
				pod[p] = pot;
			}
		}

		for (int p = 167; p >= 0; p--)
		{
			if (pod[p])
			{
				min++;

				int l = 1;
				for (int pp = p; pp >= 0; pp--)
				{
					if (pod[p] && pod[p] * l <= n)
					{
						l *= pod[p];
						pod[p] = 0;
					}
				}
			}
		}

		printf("Case #%d: %d\n", tst, max-min);
	}

	return 0;
}
