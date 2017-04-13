#include <cstdio>
#include <cstring>

int k;
int len;
char data[1024];
char res[1024];
int used[16];
int pos[16];
int best;

void solve(int curr) {
	if (curr == k) {
		for (int i=0; i<len; i++)
			res[i%k+(i/k)*k]=data[pos[i%k]+(i/k)*k];
		int t=0;
		char s = 0;
		for (int i=0; i<len; i++)
			if (res[i] != s) {
				s=res[i];
				t++;
			}
		if (t < best) best=t;
		return;
	}

	for (int i=0; i<k; i++)
		if (!used[i]) {
			used[i]=1;
			pos[curr]=i;
			solve(curr+1);
			used[i]=0;
		}
}

int main() {
	FILE *fin = fopen("in.txt", "r");
	FILE *fout = fopen("out.txt", "w");

	int tests;

	fscanf(fin, "%d", &tests);
	for (int test=0; test<tests; test++) {
		fscanf(fin, "%d\n%s\n", &k, data);
		len = strlen(data);

		best = 1000000;
		solve(0);

		fprintf(fout, "Case #%d: %d\n", test+1, best);
	}

	return 0;
}
