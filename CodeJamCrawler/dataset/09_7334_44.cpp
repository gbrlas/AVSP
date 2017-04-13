#include <stdio.h>
#include <string.h>
int n, k, in[200][35], m[200][200];

int isOK(int a[], int b[]) {
	for(int i = 0; i < k; ++i) {
		if(a[i] >= b[i]) return 0;
	}
	return 1;
}

int a, b, v[200], p[200];

int dfs(int x) {
	for(int i = 0; i < b; ++i) {
		if(m[x][i] && !v[i]) {
			v[i] = 1;
			if(p[i] < 0 || dfs(p[i])) {
				p[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int t, max;
	freopen("CS.txt", "w", stdout);

	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < k; ++j) {
				scanf("%d", in[i] + j);
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(isOK(in[i], in[j])) m[i][j] = 1;
				else m[i][j] = 0;
				//printf("%d ", m[i][j]);
			}
			//puts("");
		}
		int ans = 0;
		a = b = n;
		memset(p, -1, sizeof(p));
		for(int i = 0 ; i < n; ++i) {
			memset(v, 0, sizeof(v));
			ans += dfs(i);
		}
		printf("Case #%d: %d\n", tt + 1, n - ans);
	}
}
