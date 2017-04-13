#include <stdio.h>
#include <string.h>

int n, k;
int dic[4][2] = {0, 1, 1, 0, 1, 1, 1, -1};
char map[100][100];
char nw[100][100];

int chk(char a) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int l = 0; l < 4; ++l) {
				int t, x = i, y = j;
				for(t = 0; t < k; ++t) {
					if(x < 0 || x >= n || y < 0 || y >= n) break;
					if(nw[x][y] != a) break;
					x += dic[l][0];
					y += dic[l][1];
				}
				if(t == k) return 1;
			}
		}
	}
	return 0;
}
int solve() {
	memset(nw, 0, sizeof(nw));
	for(int i = 0; i < n; ++i) {
		for(int j = n - 1, l = 0; j >= 0; --j) {
			if(map[i][j] == '.') continue;
			nw[l++][i] = map[i][j];
		}
	}
	int ret = 0;
	if(chk('R')) ret |= 1;
	if(chk('B')) ret |= 2;
	return ret;
}

int main() {
	int t;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n; ++i) scanf("%s", map[i]);
		int ret = solve();
		printf("Case #%d: ", tt + 1);
		if(ret == 0) puts("Neither");
		else if(ret == 1) puts("Red");
		else if(ret == 2) puts("Blue");
		else puts("Both");
	}
	return 0;
}
