#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_R 4
#define MAX_T 500

int temp;

int main(){
	
	FILE *fp = fopen("A-small-attempt2.in", "r");
	FILE *wfp = fopen("A-small-attempt2.out", "w");

	int testcase=0, t;
	int a[MAX_R+2][MAX_R+2], b[MAX_R+2][MAX_R+2];
	int m, n, count=0, vol1, vol2;

	fscanf(fp,"%d", &testcase);
	for(t=1; t<=testcase; t++){
		int i;
		int volnum1[MAX_T], volnum2[MAX_T];
		
		fscanf(fp,"%d", &volnum1[t]);
		for(i=1; i<=MAX_R; i++){
			fscanf(fp,"%d %d %d %d", &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
		}
		
		fscanf(fp,"%d", &volnum2[t]);
		for(i=1; i<=MAX_R; i++){
			fscanf(fp,"%d %d %d %d", &b[i][1], &b[i][2], &b[i][3], &b[i][4]);
		}
		
		/*Ãâ·Â*/
	
		count = 0;
		fprintf(wfp,"Case #%d: ", t);
		vol1 = volnum1[t];
		vol2 = volnum2[t];
		for(m=1; m<=MAX_R;m++){
			for(n=1; n<=MAX_R;n++){
				if(a[vol1][m]==b[vol2][n]){
					count++;
					temp = a[vol1][m];
				}
			}
		
		}
		if(count==1)
			fprintf(wfp,"%d\n", temp);
		else if(count>1)
			fprintf(wfp,"Bad magician!\n");
		else if(count==0)
			fprintf(wfp,"Volunteer cheated!\n");

		
	}
	fclose(fp);
	fclose(wfp);
	return 0;
}
