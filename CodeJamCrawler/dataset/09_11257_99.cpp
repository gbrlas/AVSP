#include <stdio.h>
#include <string.h>
#define MaxN 102

struct Point {
	int x, y;
}s[MaxN*MaxN];
int d[MaxN][MaxN], a[MaxN][MaxN];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int main()
{
	int T, n, m, top, cnt;
	Point next;
	bool found;

	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		top = 0;
		cnt = 1;
		memset(d, 0, sizeof(d));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				Point u = {i, j};
				top = 0;
				s[top++] = u;
				while (d[u.x][u.y] == 0) {
					found = 0;
					next = u;
					for (int i = 0; i < 4; i++) {
						Point v = {u.x+dx[i], u.y+dy[i]};
						if (v.x <= 0 || v.x > n || v.y <= 0 || v.y > m) continue;
						if (a[v.x][v.y] < a[next.x][next.y]) {
							found = 1;
							next = v;
						}
					}
					if (found) {
						u = next;
						s[top++] = u;
					}
					if (!found || d[u.x][u.y]) {
						if (!found) d[u.x][u.y] = cnt++;
						while (top--)
							d[s[top].x][s[top].y] = d[u.x][u.y];
					}
				}
			}
		printf("Case #%d:\n", cas);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < m; j++)
				printf("%c ", d[i][j]+'a'-1);
			printf("%c\n", d[i][m]+'a'-1);
		}
	}
	return 0;
}