#include <stdio.h>
#include <string.h>

int n, m, map[120][120], mark[120][120], now;
int fx[4][2] = {-1, 0, 
				 0, -1, 
				 0, 1, 
				 1, 0};


int f(int x, int y) {
	int nx, ny, min = -1;
	for(int i = 0; i < 4; ++i) {
		nx = x + fx[i][0];
		ny = y + fx[i][1];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if(min == -1 || min > map[nx][ny]) min = map[nx][ny];
	}
	if(min >= map[x][y]) return -1;
	for(int i = 0; i < 4; ++i) {
		nx = x + fx[i][0];
		ny = y + fx[i][1];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if(map[nx][ny] == min) return i;
	}
	return -1;
}

int dl[120 * 120], beg, end;

void bfs(int x, int y) {
	beg = end = 0;
	int t;
	while((t = f(x, y)) != -1) {
		dl[end++] = ((x << 16) | y);
		x += fx[t][0];
		y += fx[t][1];
		if(mark[x][y] != 0) break;
	}
	if(mark[x][y] == 0) mark[x][y] = now++;
	for(int i = 0; i < end; ++i) {
		mark[dl[i] >> 16][dl[i] & 0xffff] = mark[x][y];
	}
}


void solve() {
	memset(mark, 0, sizeof(mark));
	now = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(!mark[i][j]) {
				bfs(i, j);
			}
		}
	}
}


int main() {
	int t;
	freopen("bout.txt", "w", stdout);
	scanf("%d", &t);
	for(int tt = 1; tt <= t; ++tt) {
		printf("Case #%d:\n", tt);
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				scanf("%d", &map[i][j]);
			}
		}
		solve();
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				printf("%c ", mark[i][j] + 'a' - 1);
			}
			puts("");
		}
	}
	return 0;
}
