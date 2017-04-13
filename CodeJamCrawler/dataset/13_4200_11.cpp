#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i, TotalCount;
	unsigned long long j, r, t, size, count, r2 = 1;
	FILE *input, *output;
	input = fopen("A-small-attempt3.in", "r");
	output = fopen("A-small-attempt3.out", "w");
	fscanf(input, "%d", &TotalCount);
	for(i = 0; i < TotalCount; i++)
	{
		count = 0;
		r2 = 1;
		fscanf(input, "%I64u %I64u", &r, &t);
		size = 0;
		if(r != 1)
		{
			if(r%2 == 1)
				r2 = r/2 + 1;
			else
				r2 = r/2;
		}
		for(j = r2; size <= t; j++)
		{
			if(r%2 == 1)
				size = (j * ((2 * j) + 1)) - ((r2-1) * ((2 * (r2-1)) + 1));
			else
				size = (j * ((2 * j) + 3)) - ((r2-1) * ((2 * (r2-1)) + 3));
			if(size <= t)
				count++;
		}
		fprintf(output, "Case #%d: %I64u\n", i+1, count);
	}
	return 0;
}