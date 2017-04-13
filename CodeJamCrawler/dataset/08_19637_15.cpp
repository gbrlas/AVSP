#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"

int primes[169] = {2,	3,	5,	7,	11,	13,	17,	19,	23,
29,	31,	37,	41,	43,	47,	53,	59,	61,	67,
71,	73,	79,	83,	89,	97,	101,	103,	107,	109,
113,	127,	131,	137,	139,	149,	151,	157,	163,	167,
173,	179,	181,	191,	193,	197,	199,	211,	223,	227,
229,	233,	239,	241,	251,	257,	263,	269,	271,	277,
281,	283,	293,	307,	311,	313,	317,	331,	337,	347,
349,	353,	359,	367,	373,	379,	383,	389,	397,	401,
409,	419,	421,	431,	433,	439,	443,	449,	457,	461,
463,	467,	479,	487,	491,	499,	503,	509,	521,	523,
541,	547,	557,	563,	569,	571,	577,	587,	593,	599,
601,	607,	613,	617,	619,	631,	641,	643,	647,	653,
659,	661,	673,	677,	683,	691,	701,	709,	719,	727,
733,	739,	743,	751,	757,	761,	769,	773,	787,	797,
809,	811,	821,	823,	827,	829,	839,	853,	857,	859,
863,	877,	881,	883,	887,	907,	911,	919,	929,	937,
941,	947,	953,	967,	971,	977,	983,	991,	997, 2000};

int main()
{
	char N;
	FILE *fileIn;

	fileIn = fopen("b.in", "r");

	fscanf(fileIn, "%d", &N);

	int i, j, k, n, tmp, count;
	int a, b, p;

	n = 0;
	for (n = 0; n < N; n++)
	{
		int pole[1002] = {0};
		int primes2[3000] = {0};

		fscanf(fileIn, "%d %d %d\n", &a, &b, &p);

		i = 0;
		while (p > primes[i]) i++;

		while ((primes[i] < b))
		{
			
			if (a % primes[i] != 0)	j = a - a % primes[i] + primes[i];
			else j = a;

			while (j <= b)
			{
				if (pole[j] == 0) pole[j] = primes[i];
				else
				{
					tmp = pole[j];
					for (k = a; k <= b; k++)
						if (pole[k] == tmp) pole[k] = primes[i];
				}

				j += primes[i];
			}
			
			i++;
		}

		count = 0;
		for (k = a; k <= b; k++)
		{
			if (pole[k] == 0) count++;
			if (pole[k] > 0)
			{
				if (primes2[pole[k]] != 1)
				{
					primes2[pole[k]] = 1;
					count++;
				}
			}
		}

		printf("Case #%d: %d\n", n + 1, count);
	}

	fclose(fileIn);

	return 0;
}

