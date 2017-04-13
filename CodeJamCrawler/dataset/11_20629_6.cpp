#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<stdlib.h>


int T, N, Pd, Pg;
int i, j, k, ans;

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
	float Gl, Gw, Dl, Dw;
	
	for (i=1; i<=T; i++)
	{
		fscanf(fp, "%d", &N);
		fscanf(fp, "%d", &Pd);
		fscanf(fp, "%d", &Pg);
		ans = 1;
		
		for (j=N; j>=1; j--)
		{
			if (((j*Pd) % 100) &&
				((j*(100-Pd)) % 100)) {
				continue;
			} else {
				break;
			}
		}
		if (j >= 1) {
			Dw = j * (Pd * 1.0 /100);
			Dl = j - Dw;
			if ((Pg == 0) && (Dw > 0)) {
				ans = 0;
			}
			if ((Pg == 100) && (Dl > 0)) {
				ans = 0;
			}
		} else {
			ans = 0;	
		}
		
		if (ans) {
			//printf("Case #%d: Possible\n", i);
			fprintf(ofp, "Case #%d: Possible\n", i);
		} else {
			//printf("Case #%d: Broken\n", i);
			fprintf(ofp, "Case #%d: Broken\n", i);
		}
	}
	
	return 0;
}
