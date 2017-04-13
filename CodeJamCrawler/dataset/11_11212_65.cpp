#include <stdio.h>

int n, m;
char in[100][100];

int isOK(int i, int j) {
	if(i + 1 >= n) return 0;
	if(j + 1 >= m) return 0;
	if(in[i][j] != '#') return 0;
	if(in[i + 1][j] != '#') return 0;
	if(in[i][j + 1] != '#') return 0;
	if(in[i + 1][j + 1] != '#') return 0;
	in[i][j] = '/';
	in[i][j + 1] = '\\';
	in[i + 1][j] = '\\';
	in[i + 1][j + 1] = '/';
	return 1;
}

int solve() {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(in[i][j] == '#') {
				if(!isOK(i, j)) return 0;
			}
		}
	}
	return 1;
}

int main() {
	int t;
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; ++i) scanf("%s", in[i]);
		printf("Case #%d:\n", tt + 1);
		if(solve()) {
			for(int i = 0; i < n; ++i) puts(in[i]);
		} else {
			puts("Impossible");
		}
	}
	return 0;
}
