#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

const int maxn = 50 + 10;

char a[maxn][maxn];
int n, k;

bool check(int x, int y)
{
	for (int i = 0; i < 8; ++i)
	{
		bool flag = 1;
		int xx = x + dx[i], yy = y + dy[i];
		for (int j = 1; j <= k - 1; ++j)
		{
			if (xx < 0 || xx >= n || yy < 0 || yy >= n || a[xx][yy] != a[x][y])
			{
				flag = 0;
				break;
			}
			xx += dx[i]; yy += dy[i];
		}
		if (flag) return 1;
	}
	return 0;
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", a[i]);
			int tmp = n - 1;
			for (int j = n - 1; j >= 0; --j)
				if (a[i][j] != '.') a[i][tmp--] = a[i][j];
			for (int j = tmp; j >= 0; --j) a[i][j] = '.';
		}

		bool redWin = 0, blueWin = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (a[i][j] != '.' && check(i, j))
					if (a[i][j] == 'R') redWin = 1;
					else blueWin = 1;

		printf("Case #%d: ", nCase);
		if (redWin)
			if (blueWin) printf("Both\n");
			else printf("Red\n");
		else
			if (blueWin) printf("Blue\n");
			else printf("Neither\n");
	}
	return 0;
}
