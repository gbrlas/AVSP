#include <stdio.h>
#include <string.h>
struct To {
	int r, c;
}ans[111][111];
int g[111][111];
char mark[111][111];
char match[111][111];
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
int r, c;
char tot;

void findit(int x, int y) {	
	int i, b, bp;
	int px, py;
	b = 11111111;
	for (i = 0; i < 4; i++) {
		px = x + dx[i];
		py = y + dy[i];
		if (px < 0 || px >= r || py < 0 || py >= c) continue;
		if (g[px][py] < b) b = g[px][py], bp = i;		
	}
	if (b >= g[x][y]) {
		mark[x][y] = 1;
		ans[x][y].r = x, ans[x][y].c = y;
		match[x][y] = ++tot;
		return;
	}
	px = x + dx[bp];
	py = y + dy[bp];
	if (!mark[px][py]) {
		findit(px, py);
	}
	mark[x][y] = 1;
	ans[x][y].r = ans[px][py].r, ans[x][y].c = ans[px][py].c;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int i, j, tn, prob = 0;		
	for (scanf("%d", &tn); tn--; ) {
		tot = 0;
		scanf("%d%d", &r, &c);
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				scanf("%d", &g[i][j]);
			}
		}
		memset(mark, 0, sizeof(mark));
		memset(match, 0, sizeof(match));
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				if (!mark[i][j]) {
					findit(i, j);
				}
			}
		}
		printf("Case #%d:\n", ++prob);
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				if (j) printf(" ");
				printf("%c", match[ans[i][j].r][ans[i][j].c] + 'a' - 1);
			}
			printf("\n");
		}
	}
	return 0;
}
