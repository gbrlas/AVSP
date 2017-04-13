#include <stdio.h>

typedef unsigned long long llu;

int main()
{
	int T;
	scanf("%d", &T);

	for (int tst = 1; tst <= T; tst++)
	{
		char v[64];

		scanf("%s", v);

		llu max = 0;
		llu min = 0;
		for (char *c = v; *c; c++)
		{
			max <<= 1;
			min <<= 1;
			if (*c == '1')
			{
				max++;
				min++;
			}
			if (*c == '?')
				max++;
		}
		llu mask = 0x80000000;
		llu x = 0;
		while (mask)
		{
			if ((x | mask) * (x | mask) < min)
				x |= mask;
			mask >>= 1;
		}

		for (;;)
		{
			llu sq = x*x;
			if ((sq & min) == min && (sq | max) == max)
			{
				printf("Case #%d: ", tst);
				x*=x;
				mask = 0x4000000000000000ULL;

				while (mask && (mask & x) == 0)
					mask >>= 1;

				do
				{
					printf((mask & x) ? "1" : "0");
					mask >>= 1;
				} while (mask);

				printf("\n");

				break;
			}

			x++;
		}
	}

	return 0;
}
