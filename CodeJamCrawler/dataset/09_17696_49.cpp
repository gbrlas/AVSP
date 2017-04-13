#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

const int maxw = 10 + 5;
const int maxr = 200 + 10;
const int delta = 200;

char a[maxw][maxw];
string f[maxw][maxw][maxw * maxw][maxr * 2];
bool g[maxw][maxw][maxw * maxw][maxr * 2];
int w, q;

bool small(string a, string b)
{
	if (a.size() < b.size()) return 1;
	if (a.size() > b.size()) return 0;
	return a < b;
}

void DP(int i, int j, int k, int l)
{
	if (g[i][j][l][k]) return;
	for (int z = 0; z < 4; ++z)
	{
		int x = i + dx[z], y = j + dy[z];
		if (x < 0 || x >= w || y < 0 || y >= w) continue;
		int xx = x + dx[z], yy = y + dy[z];
		if (xx < 0 || xx >= w || yy < 0 || yy >= w) continue;
		if (a[x][y] == '+')
		{
			if (l == 0 || k - (a[xx][yy] - '0') < 0) continue;
			DP(xx, yy, k - (a[xx][yy] - '0'), l - 1);
			if (f[xx][yy][l - 1][k - (a[xx][yy] - '0')] != "")
			{
				string s = f[xx][yy][l - 1][k - (a[xx][yy] - '0')] + '+';
				if (f[i][j][l][k] == "" || small(s, f[i][j][l][k])) f[i][j][l][k] = s;
			}
		}
		else
		{
			if (l == 0 || k + (a[xx][yy] - '0') >= maxr) continue;
			DP(xx, yy, k + (a[xx][yy] - '0'), l - 1);
			if (f[xx][yy][l - 1][k + (a[xx][yy] - '0')] != "")
			{
				string s = f[xx][yy][l - 1][k + (a[xx][yy] - '0')] + '-';
				if (f[i][j][l][k] == "" || small(s, f[i][j][l][k])) f[i][j][l][k] = s;
			}
		}
	}

	if (f[i][j][l][k] != "") f[i][j][l][k] += a[i][j];
	g[i][j][l][k] = 1;
}

void solve(int x)
{
	string ans = "";
	for (int i = 0; i < w; ++i)
		for (int j = 0; j < w; ++j)
			if (a[i][j] >= '0' && a[i][j] <= '9')
			{
				for (int k = 0; k <= 100; ++k)
				{
					DP(i, j, x, k);
					if (f[i][j][k][x] != "")
						if (ans == "" || small(f[i][j][k][x], ans)) ans = f[i][j][k][x];
				}
			}
	printf("%s\n", ans.c_str());
}

int main()
{
	freopen("a.in", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		scanf("%d%d", &w, &q);
		for (int i = 0; i < w; ++i) scanf("%s", a[i]);

		for (int i = 0; i < w; ++i)
			for (int j = 0; j < w; ++j)
			{
				for (int k = 0; k < maxr; ++k)
					for (int l = 0; l < maxw * maxw; ++l)
						f[i][j][l][k] = "", g[i][j][l][k] = 0;
				if (a[i][j] >= '0' && a[i][j] <= '9')
				{
					memset(g[i][j][0], 1, sizeof(g[i][j][0]));
					f[i][j][0][a[i][j] - '0' + delta] = a[i][j];
				}
			}

		printf("Case #%d:\n", tst);
		for (int i = 0; i < q; ++i)
		{
			int x;
			scanf("%d", &x);
			solve(x + delta);
		}
	}

	return 0;
}
