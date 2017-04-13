#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, m, a[105][105];
char label[105][105], cur;

bool check(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < m);
}

char dfs(int x, int y) {
	if(label[x][y]) {
		return label[x][y];
	}

	int X = -1, Y = -1;

	for(int i = 0; i < 4; i++) {
		if(check(x+dx[i], y+dy[i]) && a[x][y] > a[x+dx[i]][y+dy[i]] && (X == -1 || a[X][Y] > a[x+dx[i]][y+dy[i]])) {
			X = x+dx[i];
			Y = y+dy[i];
		}
	}

	if(X != -1) return (label[x][y] = dfs(X, Y));
	else return (label[x][y] = cur++);
}

int main(void) {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int i, j, k, x, y, t;

	scanf("%d", &t);
	for(x = 0; x < t; x++) {
		printf("Case #%d:\n", x+1);

		scanf("%d%d", &n, &m);
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
				label[i][j] = 0;
			}
		}

		cur = 'a';
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				if(j) printf(" ");
				if(label[i][j] == 0) {
					dfs(i, j);
				}
				printf("%c", label[i][j]);
			}
			printf("\n");
		}
	}

	exit(0);
}