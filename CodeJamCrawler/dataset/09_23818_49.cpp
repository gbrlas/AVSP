#include <stdio.h>
#include <string.h>
const int MAXN = 111;
int p[111][111];
int n1, n2, map[MAXN][MAXN], cover[MAXN], link[MAXN];

int find(int i) {
	int k, q;
	for(k = 1; k <= n2; k++) {
		if(map[i][k] && !cover[k]) {
			q = link[k]; link[k] = i; cover[k] = 1;
			if (!q || find(q)) return 1;
			link[k] = q;
		}
	}
	return 0;
}

int match() {
	int i;
	for (i = 1; i <= n1; i++) {
		memset(cover,0,sizeof(cover));
		find(i);
	}
	int s = 0;
	for (i = 1; i <= n2; i++) if (link[i]) s++;
	return s;
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int tn, i, j, x, k, n, prob = 0;
	for (scanf("%d", &tn); tn--; ) {
		scanf("%d%d", &n, &k);
		n2 = n1 = n;
		for (i = 1; i <= n; i++) {
			for (j = 0; j < k; j++) {
				scanf("%d", &p[i][j]);
			}
		}
		memset(map, 0, sizeof(map));
		memset(link, 0, sizeof(link));
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				map[i][j] = 1;
				for (x = 0; x < k; x++) {
					if (p[i][x] <= p[j][x]) map[i][j] = 0;
				}
			}
		}
		printf("Case #%d: %d\n", ++prob, n - match());
	}
	return 0;
}
