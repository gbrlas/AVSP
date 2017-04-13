#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

const char *inf = "C-small-attempt0.in";
const char *ouf = "output.txt";

using namespace std;

const int maxn = 200;
int n, k;
int p[maxn][30];
int c[maxn][maxn];

void init()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j)
			cin >> p[i][j];
}

int g[maxn][maxn];
int ans;
int m[maxn];

void search(int t, int r, int id)
{
	if (t >= ans)
		return ;
	int f = -1;
	bool fd = false;
	for (int i = id; i < n; ++i)
	{
		if (!m[i])
			continue;
		bool ok = true;
		for (int j = 0; j < r; ++j)
			if (!c[i][g[t][j]])
			{
				ok = false;
				break;
			}
		if (!ok)
			continue;
		fd = true;
		g[t][r] = i;
		m[i] = false;
		search(t, r + 1, i+1);
		m[i] = true;
	}
	if (!fd)
	{
		for (int i = 0; i < n; ++i)
		{
			if (m[i])
			{
				g[t+1][0] = i;
				m[i] = false;
				search(t+1, 1, i+1);
				m[i] = true;
				return ;
			}
		}
		ans = t;
	}
}

void process()
{
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;
			c[i][j] = true;
			for (int r = 0; r < k; ++r)
			{
				if (p[i][r] >= p[j][r])
				{
					c[i][j] = false;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			c[i][j] |= c[j][i];
	ans = n;
	memset(m, true, sizeof(m));
	search(0, 0, 0);
}

void print()
{
	printf("%d", ans + 1);
}

int main()
{
	freopen(inf, "rt", stdin);
	freopen(ouf, "wt", stdout);
	
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i)
	{
		printf("Case #%d: ", i+1);
		init();
		process();
		print();
		printf("\n");
	}
	return 0;
}
