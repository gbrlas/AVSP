#include <iostream>

void initialize()
{
	freopen("bl.in", "r", stdin);
	freopen("b.out", "w", stdout);
}

int dx[4] = {-1, 0, 0, 1},
	dy[4] = {0, -1, 1, 0};

const int MAX = 100 + 10;
bool visited[MAX][MAX];
int h[MAX][MAX];
int minx[MAX][MAX], miny[MAX][MAX];
char res[MAX][MAX];
int n, m;

bool good(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) 
		return true;
	return false;
}

void dfs(int x, int y, char sym)
{
	visited[x][y] = true;
	res[x][y] = sym;
	if (good(minx[x][y], miny[x][y]))
		dfs(minx[x][y], miny[x][y], sym);
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (!good(nx, ny)) continue;
		if (minx[nx][ny] == x && miny[nx][ny] == y)
			dfs(nx, ny, sym);
	}
}

int main()
{
	initialize();

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		scanf("%d%d", &n, &m);
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < m; ++y)
			{
				scanf("%d", &h[x][y]);
				visited[x][y] = false;
			}

		for (int x = 0; x < n; ++x)
			for (int y = 0; y < m; ++y)
			{
				int kx = -1, ky = -1;
				for (int i = 0; i < 4; ++i)
				{
					int nx = x + dx[i], ny = y + dy[i];
					if (!good(nx, ny)) continue;
					if (h[nx][ny] >= h[x][y]) continue;
					if (kx == -1 || h[nx][ny] < h[kx][ky])
						kx = nx, ky = ny;
				}
				minx[x][y] = kx, miny[x][y] = ky;
			}


		char sym = 'a';
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < m; ++y)
				if (!visited[x][y])
					dfs(x, y, sym++);

		printf("Case #%d:\n", t);
		for (int x = 0; x < n; ++x)
		{
			for (int y = 0; y < m; ++y)
				printf("%c ", res[x][y]);
			printf("\n");
		}

	}


	return 0;
}