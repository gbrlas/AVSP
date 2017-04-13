#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

const int maxn = 100 + 10;

int a[maxn][maxn], b[maxn][maxn];
bool used[maxn][maxn];
int q[maxn * maxn][2];
int n, m, cnt;

void BFS(int sx, int sy)
{
	int color = -1, t = 1;
	q[0][0] = sx; q[0][1] = sy; used[sx][sy] = 1;
	for (int h = 0; h < t; ++h)
	{
		int x = q[h][0], y = q[h][1], best = a[x][y], d;
		for (int i = 0; i < 4; ++i)
		{
			int xx = x + dx[i], yy = y + dy[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m || a[xx][yy] >= a[x][y]) continue;
			if (a[xx][yy] < best) best = a[xx][yy], d = i;
		}
		if (best >= a[x][y]) continue;
		x  += dx[d]; y += dy[d];
		if (b[x][y] != -1)
		{
			color = b[x][y];
			break;
		}
		q[t][0] = x; q[t++][1] = y; used[x][y] = 1;
	}

	if (color == -1) color = cnt++;
	for (int i = 0; i < t; ++i) b[q[i][0]][q[i][1]] = color;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &a[i][j]);

		cnt = 0;
		memset(b, -1, sizeof(b));
		memset(used, 0, sizeof(used));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (!used[i][j]) BFS(i, j);

		printf("Case #%d:\n", tst);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (j) printf(" ");
				printf("%c", b[i][j] + 'a');
			}
			printf("\n");
		}
	}

	return 0;
}
