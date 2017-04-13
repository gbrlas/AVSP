#include <cstdio>
#include <cstdlib>
#include <cstring>

inline int countDigits(int n);
inline int countRecycled(int min, int max, int numberOfDigits, int n);
inline int cycle(int n, int numberOfDigits);
const int p[] = {1,10,100,1000,10000,100000,1000000};

int main(int argc, char **argv)
{
	if(argc<2)
		return 1;
	FILE *input = fopen(argv[1], "r");
	FILE *output = fopen(argv[2], "w");
	int numberOfCases;
	int numberOfRecycled;
	fscanf(input, "%d ", &numberOfCases);

	for(int i = 0; i<numberOfCases; i++)
	{
		int min, max, numberOfDigits;
		fscanf(input, "%d %d ", &min, &max);
		numberOfDigits = countDigits(min);
		numberOfRecycled = 0;
		for(int j = min; j<=max; j++)
		{
			numberOfRecycled += countRecycled(min, max, numberOfDigits, j);
		}
		fprintf(output, "Case #%d: %d\n", i+1, numberOfRecycled);
	}
	
}

inline int countDigits(int n)
{
	if(n/1000000>0)
		return 7;
	else if(n/100000>0)
		return 6;
	else if(n/10000>0)
		return 5;
	else if(n/1000>0)
		return 4;
	else if(n/100>0)
		return 3;
	else if(n/10>0)
		return 2;
	else
		return 1;
}

inline int cycle(int n, int numberOfDigits)
{
	int out = 0;
	for(int i = numberOfDigits-1; i>0; i--)
	{
		out += n/p[i]*p[i-1];
		n = n%p[i];
	}
	out += n*p[numberOfDigits-1];
	return out;
}

inline int countRecycled(int min, int max, int numberOfDigits, int n)
{
	int perm[7];
	perm[0] = n;
	bool alreadyExist;
	int count = 0;
	for(int i = 1; i<numberOfDigits; i++)
	{
		perm[i] = cycle(perm[i-1], numberOfDigits);
		if(perm[i]>n && perm[i]<=max)
		{
			alreadyExist = false;
			for(int j = 1; j<i; j++)
				if(perm[j] == perm[i])
					alreadyExist = true;
			if(!alreadyExist)
				count ++;
		}
	}
	return count;
}