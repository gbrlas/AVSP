#include <iostream>

using namespace std;

int a[100][100];
char b[100][100];
int n, m;

int dy[4] = {0, -1, 1, 0};
int dx[4] = {-1, 0, 0, 1};

char sym;

int corr(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

char dfs(int x, int y)
{
	if (b[x][y] != ' ') return b[x][y];
	int mind = -1;
	for (int d = 0; d < 4; ++d)
		if (corr(x + dx[d], y + dy[d]))
			if (a[x + dx[d]][y + dy[d]] < a[x][y] && (mind == -1 || a[x + dx[d]][y + dy[d]] < a[x + dx[mind]][y + dy[mind]]))
				mind = d;
	if (mind == -1)
		return b[x][y] = sym++; else
	return b[x][y] = dfs(x + dx[mind], y + dy[mind]);
}

int main()
{
	freopen("b.in", "rt", stdin);
	freopen("b.out", "wt", stdout);
	int q;
	cin >> q;
	for (int qq = 0; qq < q; ++qq)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				cin >> a[i][j];
				b[i][j] = ' ';
			}
		sym = 'a';
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				dfs(i, j);
		cout << "Case #" << qq + 1 << ":\n";
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cout << b[i][j] << ' ';
			cout << '\n';
		}
	}
	return 0;
}
