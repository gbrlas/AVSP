#pragma warning(disable:4786)
#include <stdio.h>
int n;
char g[111][111];

bool check(int i, int k) {
	int j;
	for (j = k + 1; j < n; j++) {
		if (g[i][j] == '1') return false;		
	}
	return true;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int tn, i, j, k, l, ans, prob = 0;
	for (scanf("%d", &tn); tn--; ) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%s", g[i]);
		ans = 0;
		for (i = 0; i < n; i++) {
			if (check(i, i)) continue;
			for (j = i + 1; j < n; j++) {
				if (check(j, i)) break;
			}			
			for (k = 0; k < n; k++) g[n][k] = g[j][k];
			for (l = j; l > i; l--) {
				ans++;
				for (k = 0; k < n; k++) g[l][k] = g[l - 1][k];
			}
			for (k = 0; k < n; k++) g[i][k] = g[n][k];
		}
		printf("Case #%d: %d\n", ++prob, ans);
	}		
	return 0;
}

