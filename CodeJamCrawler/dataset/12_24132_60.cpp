#include <cstdio>
#include <cstring>
inline int max(int a, int b) {
	return a > b ? a : b;
}
const int MAXN = 111;
int cnt[MAXN][MAXN];
int main() {
	int testnum, n, s, p, cur, add0, add1;
	scanf("%d", &testnum);
	for (int test = 1; test <= testnum; test++) {
		scanf("%d%d%d", &n, &s, &p);
		memset(cnt, -1, sizeof(cnt));
		cnt[0][0] = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &cur);
			add0 = ((cur + 2) / 3) >= p;
			if (cur < 2) add1 = -1;
			else if (cur % 3 == 0) add1 = ((cur + 3) / 3) >= p;
			else if (cur % 3 == 1) add1 = ((cur + 2) / 3) >= p;
			else add1 = ((cur + 4) / 3) >= p;
			for (int j = 0; j <= i; j++) if (cnt[i][j] >= 0) {
				cnt[i + 1][j] = max(cnt[i + 1][j], cnt[i][j] + add0);
				if (add1 >= 0) cnt[i + 1][j + 1] = max(cnt[i + 1][j + 1], cnt[i][j] + add1);
			}
		}
		printf("Case #%d: %d\n", test, max(0, cnt[n][s]));
	}
	return 0;
}