#include <cstdio>
#include <cstring>

char engines[128][128];
int s, q;
int queries[1024];
int best[128][1024];

int solve(int eng, int query) {
	if (query == q) 
		return 0;
	if (best[eng][query])
		return best[eng][query] - 1;
	if (eng != queries[query])
		best[eng][query]=solve(eng, query+1)+1;
	else {
		int a = q+q+1;
		for (int k=0; k<s; k++)
			if (k != eng){
				int tmp = solve(k, query+1)+1;
				if (tmp < a)
					a = tmp;
			}
		best[eng][query]=a+1;
	}
	return best[eng][query]-1;
}

int main() {
	FILE *fin = fopen("in.txt", "r");
	FILE *fout = fopen("out.txt", "w");

	int tests;
	fscanf(fin, "%d\n", &tests);
	for (int test=0; test<tests; test++) {
		fscanf(fin, "%d\n", &s);
		for (int j=0; j<s; j++) {
			fgets(engines[j], 128, fin);
			engines[j][strlen(engines[j])-1]=0;
		}
		fscanf(fin, "%d\n", &q);
		for (int j=0; j<q; j++) {
			char tmp[128];
			fgets(tmp, 128, fin);
			tmp[strlen(tmp)-1]=0;
			int k;
			for (k=0; k<s; k++)
				if (strcmp(tmp, engines[k])==0) 
					break;
			queries[j]=k;
		}

		int ans = q + q + 1;
		memset(best, 0, sizeof(best));
		for (int j=0; j<s; j++) {
			int tmp = solve(j, 0);
			if (tmp < ans)
				ans = tmp;
		}
		fprintf(fout, "Case #%d: %d\n", test+1, ans);
	}

	return 0;
}
