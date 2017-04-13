#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<stdlib.h>


int T, N, sum, ex_or, min;
int dat[1100];


int main (int argc, const char * argv[]) {
	
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); 
	strcpy(outfile, filename);
	strcat(infile, ".in"); 
	strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");
	int i, j;
	
	fscanf(fp, "%d", &T);
	
	for (i=1; i<=T; i++) 
	{
		ex_or = 0;
		sum = 0;
		min = 10000000;

		memset(dat, 0, sizeof(dat));
		
		fscanf(fp, "%d", &N);
		for (j=1; j<=N; j++) {
			fscanf(fp, "%d", &dat[j]);
			ex_or ^= dat[j];
			sum += dat[j];
			if (dat[j] < min) {
				min = dat[j];
			}
		}

		if (ex_or != 0) {
			fprintf(ofp, "Case #%d: NO\n", i);
		} else {
			sum -= min;
			fprintf(ofp, "Case #%d: %d\n", i, sum);
		}
	}
	
	return 0;
}
