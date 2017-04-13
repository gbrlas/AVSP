#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, a[44], b[55], c[44];
char s[44][44];
int can[44];
int sol;

int main(void) {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, j, k, t;

	scanf("%d", &t);
	for(int T = 1; T <= t; T++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%s", s[i]);
			for(j = n-1; j >= 0; j--) {
				if(s[i][j] == '1') {
					break;
				}
			}
			if(j < 0) j = 0;
			can[i] = j;
			a[i] = i;
		}

		sol = 1000000;
		do {
			bool q = 1;
			for(i = 0; i < n; i++) {
				if(i < can[a[i]]) {
					q = 0;
					break;
				}
			}
			if(! q) continue;

			for(i = 0; i < n; i++) {
				b[i] = i;
				c[i] = a[i];
			}

			int l = 0;
			for(i = 0; i < n; i++) {
				for(j = i; j < n; j++) {
					if(b[j] == c[i]) {
						for(k = j; k > i; k--) {
							l++;
							swap(b[k], b[k-1]);
						}
						break;
					}
				}
			}
			sol = min(sol, l);
		} while(next_permutation(a, a+n));

		printf("Case #%d: %d\n", T, sol);
	}

	exit(0);
}