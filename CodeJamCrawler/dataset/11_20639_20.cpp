#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<stdlib.h>


int T, R, C;
int i, j, k, p, q, r, c, ans;
char rc[64][64];

int main (int argc, const char * argv[]) {
	
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); 
	strcpy(outfile, filename);
	strcat(infile, ".in"); 
	strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");
	
	
	fscanf(fp, "%d", &T);
	
	for (i=1; i<=T; i++)
	{
		fscanf(fp, "%d", &R);
		fscanf(fp, "%d", &C);
		memset(rc, 0, sizeof(rc));
		ans = 1;
		for (j=1; j<=R; j++)
		{
			fscanf(fp, "%s", &rc[j][1]);
		}
		
		for (r=1; r<=R; r++)
		{
			for (c=1; c<=C; c++)
			{
				if (((rc[r][c] - '.') == 0) ||
					((rc[r][c] - '/') == 0) ||
					((rc[r][c] - '\\') == 0)) {
					continue;
				}
				if ((rc[r][c] - '#') == 0) {
					if (((r+1)<=R) && ((c+1)<=C)) {
						if (((rc[r][c+1] - '#') == 0) &&
							((rc[r+1][c] - '#') == 0) &&
							((rc[r+1][c+1] - '#') == 0)) {
							rc[r][c] = '/';
							rc[r][c+1] = '\\';
							rc[r+1][c] = '\\';
							rc[r+1][c+1] = '/';
						} else {
							ans = 0;
						}
					} else {
						ans = 0;
					}
				}
			}
		}

		//printf("Case #%d:\n", i);
		fprintf(ofp, "Case #%d:\n", i);
		if (ans == 1) {
			for (r=1; r<=R; r++)
			{			
				//printf("%s\n", &rc[r][1]);
				fprintf(ofp, "%s\n", &rc[r][1]);
			}
		} else {
			//printf("Impossible\n");
			fprintf(ofp, "Impossible\n");
		}
	}
	
	
	
	
	
	return 0;
}

