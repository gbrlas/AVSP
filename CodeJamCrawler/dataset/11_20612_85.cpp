#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<stdlib.h>


int T, C, D, N, N_ans, w_idx;
char dat[500];
char a[1024];
char c_tbl[50][3];
char d_tbl[30][2];
char w_tbl[150];
char out[150];
char rr;

int ctbl_check2(char ch1, char ch2, char *r) {
	int i;
	
	for (i=1; i<=C; i++) {
		if (((ch1 == c_tbl[i][0]) && (ch2 == c_tbl[i][1])) ||
			((ch1 == c_tbl[i][1]) && (ch2 == c_tbl[i][0]))) {
			*r = c_tbl[i][2];
			return 1;
		}
	}
	*r = 0;
	
	return 0;
}

int dtbl_check1(char ch1, char *r) {
	int i;
	
	for (i=1; i<=D; i++) {
		if (ch1 == d_tbl[i][0]) {
			*r = d_tbl[i][1];
			return 1;
		}
		if (ch1 == d_tbl[i][1]) {
			*r = d_tbl[i][0];
			return 1;
		}
	}
	*r = 0;
	
	return 0;
}

int wtbl_check1(char ch1, int *s) {
	int i;
	
	for (i=1; i<=w_idx-1; i++) {
		if (ch1 == w_tbl[i]) {
			return 1;
		}
	}
	return 0;
}

void out_combine(int idx, char r) {
	int i;
	
	out[idx] = r;
	for (i=idx+1; (i+1)<=N_ans; i++) {
		out[i]=out[i+1];
	}
	N_ans--;
}

void out_delete(int idx_fr, int idx_to) {
	int i, len = idx_to - idx_fr + 1;
	
	for (i=idx_fr; (i+len)<=N_ans; i++) {
		out[i]=out[i+len];
	}
	for (i=N_ans-len+1; i<=N_ans; i++) {
		out[i] = 0;
	}
	N_ans-=len;
}

void come_back_len(int *idx, int len) {
	*idx -= len;
	if (*idx < 1) *idx = 1;
}


int main (int argc, const char * argv[]) {
	
	char filename[32];
	char infile[32], outfile[32];
	scanf("%s", filename);
	strcpy(infile, filename); 
	strcpy(outfile, filename);
	strcat(infile, ".in"); 
	strcat(outfile, ".out");
	FILE *fp=fopen(infile, "r"), *ofp=fopen(outfile, "w");
	int i, j, k, s, rval = 0;
	
	fscanf(fp, "%d", &T);
	
	for (i=1; i<=T; i++) 
	{
		// build c_tbl
		fscanf(fp, "%d", &C);
		for (j=1; j<=C; j++) {
			fscanf(fp, "%s", &c_tbl[j][0]);
		}
		// build d_tbl
		fscanf(fp, "%d", &D);
		for (j=1; j<=D; j++) {
			fscanf(fp, "%s", &d_tbl[j][0]);
		}
		// get input
		fscanf(fp, "%d", &N);
		fscanf(fp, "%s", &out[1]);
		N_ans = N;
		w_idx = 1;
		memset(w_tbl, 0, sizeof(w_tbl));
		
		// go!
		for (j=1; j<N_ans; ) {
			// check combine table (cur, next)
			if (ctbl_check2(out[j], out[j+1], &rr)) {
				out_combine(j, rr);
				come_back_len(&j, 1);
				continue;
			}

			// check delete table (cur)
			if (dtbl_check1(out[j], &rr)) {
				w_tbl[w_idx] = rr;
				w_idx ++;
			}			
			
			// check wait table (next)
			if (wtbl_check1(out[j+1], &s)) {
				out_delete(1, j+1);
				w_idx = 1;
				come_back_len(&j, j+1);
				continue;
			}
			j++;
		}
		
#if 1
		fprintf(ofp, "Case #%d: [", i);
		for (j=1; j<=N_ans; j++) {
			fprintf(ofp, "%c", out[j]);
			if (j<N_ans)
				fprintf(ofp, ", ");
		}
		if (i<T) {
			fprintf(ofp, "]\n");
		} else {
			fprintf(ofp, "]");
		}
#else
		printf("Case #%d: [", i);
		for (j=1; j<=N_ans; j++) {
			printf("%c", out[j]);
			if (j<N_ans)
				printf(", ");
		}
		if (i<T) {
			printf("]\n");
		} else {
			printf("]");
		}	
#endif
	}
	
	return 0;
}
