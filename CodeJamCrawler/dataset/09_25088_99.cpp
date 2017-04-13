#include <stdio.h>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <memory.h>
#include <sstream>

using namespace std;



int a[110][110];
vector<pair<int, int>> g[110][110];
int c[110][110];


int n, m;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void dfs(int i, int j, int li, int lj, int color)
{
	c[i][j] = color;
	for (int k = 0; k < g[i][j].size(); ++k)
	{
		if (g[i][j][k].first != li || g[i][j][k].second != lj)
		{
			dfs(g[i][j][k].first, g[i][j][k].second, i, j, color);
		}
	}
}



int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &a[i][j]);
				g[i][j].resize(0);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int min_a = a[i][j];
				int i0 = i;
				int j0 = j;
				for (int k = 0; k < 4; ++k)
				{
					if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < m)
					{
						if (a[i + dx[k]][j + dy[k]] < min_a)
						{
							i0 = i + dx[k];
							j0 = j + dy[k];
							min_a = a[i0][j0];
						}
					}
				}
				pair<int ,int> p = make_pair(i0, j0);
				g[i][j].push_back(p);
				p = make_pair(i, j);
				g[i0][j0].push_back(p);
			}
		}

		int color = 0;
		memset(c, -1, sizeof(c));
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (c[i][j] == -1)
				{
					dfs(i, j, -1, -1, color);
					++color;
				}
			}
		}

		printf("Case #%d:\n", t + 1);
		vector<int> res(color, -1);
		int cur = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (res[c[i][j]] == -1)
				{
					res[c[i][j]] = cur;
					++cur;
				}
				printf("%c ", 'a' + res[c[i][j]]);
			}
			printf("\n");
		}


	}


	return 0;
}