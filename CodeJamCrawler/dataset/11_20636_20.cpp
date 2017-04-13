#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<stdlib.h>


int T, N;
int i, j, k, p, q, r;
int in[128][128];
char L[128];
float WP[128];
float OWP[128];
float OOWP[128];
int n_cnt = 0, w_cnt = 0, l_cnt = 0;
float RPI;

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
		fscanf(fp, "%d", &N);
		memset(in, 0, sizeof(in));
		for (j=1; j<=N; j++)
		{
			n_cnt = 0;
			w_cnt = 0;
			l_cnt = 0;
			fscanf(fp, "%s", &L[1]);
			for (k=1; k<=N; k++)
			{
				if ((L[k] - '.') == 0) {
					in[j][k] = -1;
					n_cnt ++;
				} else {
					in[j][k] = L[k] - '0';
					if (in[j][k] == 0) {
						l_cnt ++;
					} else {
						w_cnt ++;
					}
				}
			}
			in[j][N+1] = n_cnt;
			in[j][N+2] = w_cnt;
			in[j][N+3] = l_cnt;
			WP[j] = w_cnt * 1.0 / (w_cnt + l_cnt);
		}

		memset(OWP, 0, sizeof(OWP));
		for (j=1; j<=N; j++)
		{
			int owp_cnt = 0;
			for (k=1; k<=N; k++)
			{
				// find each exist win rate
				if (in[j][k] >= 0) {				
						n_cnt = in[k][N+1];
						w_cnt = in[k][N+2];
						l_cnt = in[k][N+3];
						if (in[k][j] < 0) {
							OWP[j] += (w_cnt * 1.0 / (w_cnt + l_cnt));
						} else if (in[k][j] == 0) {
							l_cnt --;
							OWP[j] += (w_cnt * 1.0 / (w_cnt + l_cnt));
							owp_cnt ++;
						} else {
							w_cnt --;
							OWP[j] += (w_cnt * 1.0 / (w_cnt + l_cnt));
							owp_cnt ++;
						}
				}
			}
			OWP[j] = OWP[j] * 1.0 / owp_cnt;
		}
		
		memset(OOWP, 0, sizeof(OOWP));
		for (j=1; j<=N; j++)
		{
			int oowp_cnt = 0;
			for (k=1; k<=N; k++)
			{
				// find each exist win rate
				if (in[j][k] >= 0) {				
					oowp_cnt ++;
					OOWP[j] += OWP[k];
				}
			}
			OOWP[j] = OOWP[j] * 1.0 / oowp_cnt;
		}
		
		//printf("Case #%d:\n", i);
		fprintf(ofp, "Case #%d:\n", i);
		for (j=1; j<=N; j++)
		{			
			RPI = 0.25 * WP[j] + 0.5 * OWP[j] + 0.25 * OOWP[j];
			//printf("%f\n", RPI);
			fprintf(ofp, "%f\n", RPI);
		}
	}
	

	
	
	
	return 0;
}

