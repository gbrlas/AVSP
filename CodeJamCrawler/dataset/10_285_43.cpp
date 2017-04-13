#include<stdio.h>

int main()
{
	FILE* fpi;
	FILE* fpo;
	fpi = fopen("A-large.in", "r");
	fpo = fopen("output.out", "w");
	int i,t,n;
	long k;
	fscanf(fpi, "%d",&t);
	for (i = 0; i < t; i++)
	{
		fscanf(fpi,"%d%ld",&n,&k);
		if ((k + 1) % (1 << n) == 0)
				fprintf(fpo,"Case #%d: ON\n",i + 1);
		else
			fprintf(fpo,"Case #%d: OFF\n",i + 1);
	}
	fclose(fpo);
	fclose(fpi);
	return 0;
}