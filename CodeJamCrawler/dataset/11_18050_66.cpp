#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 400 + 10;
const int maxm = 2000 + 10;

struct Tedge {
	int v, next;
};

Tedge edge[maxm * 2];
bool a[maxn][maxn];
int first[maxn], dist0[maxn], dist1[maxn], q[maxn];
int f[maxn][maxn][maxn];
char s[10000];
int n, m;

void BFS(int *dist, int S){
	for (int i = 0; i < n; ++i) dist[i] = -1;
	dist[S] = 0; q[0] = S;
	for (int h = 0, t = 1; h < t; ++h) {
		int u = q[h];
		for (int v = 0; v < n; ++v)
			if (a[u][v] && dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q[t++] = v;
			}
	}
}

int cal(int u, int x, int y) {
	if (f[u][x][y] != -1) return f[u][x][y];

	if (u == 1) return f[u][x][y] = 1;

	int cnt = 0;
	for (int i = first[u]; i != -1; i = edge[i].next) {
		int v = edge[i].v;
		if (v != x && !a[x][v] && !a[y][v]) ++cnt;
	}

	for (int i = first[u]; i != -1; i = edge[i].next) {
		int v = edge[i].v;
		if (dist0[v] == dist0[u] + 1 && dist1[v] + dist0[v] == dist0[1]) f[u][x][y] = max(f[u][x][y] , cal(v, u, x) + cnt - 1);
	}
	return f[u][x][y];
}
int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("d.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d%d", &n, &m);
		memset(a, 0, sizeof(a));
		memset(first, -1, sizeof(first));
		for (int i = 0; i < m; ++i) {
			scanf("%s", s);
			int u, v;
			sscanf(s, "%d,%d", &u, &v);
			
			a[u][v] = a[v][u] = 1;

			edge[i * 2].v = v; edge[i * 2].next = first[u]; first[u] = i * 2;
			edge[i * 2 + 1].v = u; edge[i * 2 + 1].next = first[v]; first[v] = i * 2 + 1;
		}

		BFS(dist0, 0); BFS(dist1, 1);

		//for (int i = 0; i < n; ++i) printf("%d %d\n", dist0[i], dist1[i]);

		memset(f, -1, sizeof(f));
		printf("Case #%d: %d %d\n", nCase, dist0[1] - 1, cal(0, n, n));
	}

	return 0;
}
