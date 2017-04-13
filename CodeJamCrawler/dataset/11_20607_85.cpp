#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<stdlib.h>


int t, n, r;
char dat[500];
char a[1024];
//int pos[32][32] = {0};
int pO = 0;
int pB = 0;
int mO = 0;
int mB = 0;
int chg = 0;
int la = 0;
int ans, tim;
int i, j, k, tc, sec;
int isO, wasO, btn, clr;

int main (int argc, const char * argv[]) {
	
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); 
	strcpy(outfile, filename);
	strcat(infile, ".in"); 
	strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");
	
	
	fscanf(fp, "%d", &n);

	for (i=1; i<=n; i++) 
	{
		pO = 1; pB = 1; ans = 0; la = 0;
		memset(dat, 0, sizeof(dat));
		
		fscanf(fp, "%d", &dat[0]);
		for(j=1; j<=dat[0]; j++) {
			fscanf(fp, "%s", &dat[j*2-1]);
			fscanf(fp, "%d", &dat[j*2]);
		}
		for(j=1; j<=dat[0]; j++) 
		{
			isO = ((dat[j*2-1]-'O') == 0);
			btn = dat[j*2];
			chg = (!isO & wasO) || (isO & !wasO) || (j==1);
			
			if (isO) {
				// Orange
				mO = abs(btn - pO);
				pO = btn;
				if (chg) {
					if (mO <= la) {
						tim = 1;
					} else {
						tim = (mO - la) + 1;
					}
				} else {
					tim = mO + 1;
				}
			} else {
				// Blue
				mB = abs(btn - pB);
				pB = btn;
				if (chg) {
					if (mB <= la) {
						tim = 1;
					} else {
						tim = (mB - la) + 1;
					}
				} else {
					tim = mB + 1;
				}
			}
			wasO = isO;
			ans += tim;
			
			if (!chg) {
				la += tim;
			} else {
				la = tim;
			}

		}
		//printf("Case #%d: %d\n", i, ans);
		fprintf(ofp, "Case #%d: %d\n", i, ans);
		
	}

	
	return 0;
}
