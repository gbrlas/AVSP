#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int T, N;
	unsigned long int L, H;
	int i, k;
	unsigned long int freq[15000];
	int div, j;
	unsigned long int thefreq;
	
	fscanf(stdin, "%i", &T);
	for(i=0; i < T; i++)
	{
		fscanf(stdin, "%i %lu %lu", &N, &L, &H);
		for(j=0; j < N; j++)
		{
			fscanf(stdin, "%lu", &freq[j]);
		}
		div = 1;
		thefreq = -1;
		for(j=L; j <= H; j++)
		{
			div = 1;
			for(k=0; k < N; k++)
			{
				if(j%freq[k] != 0 && freq[k] % j != 0)
				{
					div = 0;
					break;
				}
				/*else
				{
					thefreq = j;
					break;
				}*/
			}
			if(div == 1) 
			{
				thefreq = j;
				break;
			}
		}
		printf("Case #%i: ", i+1);
		if(thefreq > 0 && div != 0)
			printf("%lu\n", thefreq);
		else
			printf("NO\n");
	}
	return 0;
}
