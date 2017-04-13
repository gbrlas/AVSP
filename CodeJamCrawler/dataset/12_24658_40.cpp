#include <stdio.h>
#include <math.h>
#include <string.h>

char fi[256];
char fo[256];

int A, B;

void solve() {
	FILE *f = fopen(fi, "r");
	FILE *g = fopen(fo, "w");
	
	int num_cases;
	fscanf(f, "%d", &num_cases);
	int idx;
	
	int history[7];
	for (idx = 0; idx < num_cases; ++idx) {
		fscanf(f, "%d %d", &A, &B);
	
		int m, n, d, k, h, L, H, tenk, total = 0;
		for (n = A; n <= B; ++n) {
			if (n < 10) d = 1;
			else if (n < 100) d = 2;
			else if (n < 1000) d = 3;
			else if (n < 10000) d = 4;
			else if (n < 100000) d = 5;
			else if (n < 1000000) d = 6;
			else d = 7;
			
			for (k = 1; k < d; ++k) {
				tenk = (int)pow(10, k);
				L = n / tenk;
				H = n % tenk;
				m = L + H * pow(10, d-k);
				if (m <= B && n < m) {
					int duplicate = 0;
					for (h = 1; h < k; ++h) {
						if (history[h] == m) {
							duplicate = 1;
							break;
						}
					}
					if (!duplicate) {
						//fprintf(g, "%d %d\n", n, m);
						total++;
					}					
				}
				history[k] = m;
			}
		}
		fprintf(g, "Case #%d: %d\n", idx+1, total);
	}
	fclose(f);
	fclose(g);
}

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("Input/output needed.\n");
		return 1;
	}
	strcpy(fi, argv[1]);
	strcpy(fo, argv[2]);
	solve();
	return 0;
}