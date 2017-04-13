#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

vector<int> y[110];
int g[110][110];
int n;
bool used[110];
int m[110];

bool Khun(int v)
{
	if (used[v])
		return false;
	used[v] = true;
	for (int u = 0; u < n; ++u)
	if (g[v][u])
	{
		if (m[u] == -1 || Khun(m[u]))
		{
			m[u] = v;
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("C-large (1).in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
		{
			y[i].resize(k);
			for (int j = 0; j < k; ++j)
				scanf("%d", &y[i][j]);
		}
		memset(g, 0, sizeof(g));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				bool ok = true;
				for (int l = 0; l < k; ++l)
				{
					if (y[i][l] >= y[j][l])
					{
						ok = false;
						break;
					}
				}
				if (ok)
					g[i][j] = 1;
			}
		}
		memset(m, -1, sizeof(m));
		for (int i = 0; i < n; ++i)
		{
			memset(used, false, sizeof(used));
			Khun(i);
		}
		int res = n;
		for (int i = 0; i < n; ++i)
		{
			if (m[i] != -1)
				--res;
		}
		printf("Case #%d: %d\n", t, res);

	}

	return 0;
}