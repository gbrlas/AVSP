#include <stdio.h>
#include <string.h>
int cnk[33][33], n;
int sum[33], ans[33], k;
char s[1111];

void cal(int x) {
	int i, p = 1, tot = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] == '+') {
			tot = (tot + p) % 10009;
			p = 1;
		} else {
			p = (p * sum[s[i] - 'a']) % 10009;
		}
	}
	tot = (tot + p) % 10009;
	ans[x] = (ans[x] + tot) % 10009;
}

void dfs(int x) {
	int i, d;
	cal(x);
	if (x == k) return;
	for (d = 0; d < n; d++) {
		for (i = 0; i < 26; i++) sum[i] += cnk[d][i];
		dfs(x + 1);
		for (i = 0; i < 26; i++) sum[i] -= cnk[d][i];
	}
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int tn, i, j, prob = 0;
	char t[1111];
	for (scanf("%d", &tn); tn--; ) {
		memset(cnk, 0, sizeof(cnk));
		memset(ans, 0, sizeof(ans));
		scanf("%s%d", s, &k);
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%s", t);
			for (j = 0; t[j]; j++) {
				cnk[i][t[j] - 'a']++;
			}
		}
		memset(sum, 0, sizeof(sum));
		dfs(0);
		printf("Case #%d:", ++prob);
		for (i = 1; i <= k; i++) {
			printf(" %d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
