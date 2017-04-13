#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<stdlib.h>


int T, N, cnt;
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
        cnt = 0;
        fscanf(fp, "%d", &N);
        for (j=1; j<=N; j++) {
            fscanf(fp, "%d", &dat[j]);
            if (dat[j] == j) cnt ++;
        }
 #if 1
        if (cnt == 0) {
           fprintf(ofp, "Case #%d: %d\n", i, N);
        } else if (cnt == N) {
           fprintf(ofp, "Case #%d: %d\n", i, 0);
        } else {
           fprintf(ofp, "Case #%d: %d\n", i, N-cnt);
        }
 #else
        if (cnt == 0) {
           printf("Case #%d: %d\n", i, N);
        } else if (cnt == N) {
           printf("Case #%d: %d\n", i, 0);
        } else {
           printf("Case #%d: %d\n", i, N-cnt);
        }
 #endif
	}
    //scanf("%s", filename);
	return 0;
}

