#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> p;

struct Triangle
{
	int a, b, c;
};

vector<Triangle> tr;
vector<pair<int, int>> e;

int maxY[33];
int a[1010][1010];
int color[1010];



int main()
{
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		tr.resize(0);
		e.resize(0);
		p.resize(0);
		bool was_edge = false;
		bool was_triangle = false;
		memset(a, 0, sizeof(a));
		memset(color, -1, sizeof(color));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			p.push_back(make_pair(x, y));
		}
		sort(p.begin(), p.end());
		reverse(p.begin(), p.end());
		memset(maxY, -1, sizeof(maxY));
		for (int i = 0; i < n; ++i)
		{
			int x = p[i].first;
			int y = p[i].second;

			int u = -1;
			int d = -1;
			int s = -1;

			if (i > 0)
			{
				u = maxY[y - 1];
				s = maxY[y];
				d = maxY[y + 1];
			}
			if (u != -1)
			{
				a[i][u] = a[u][i] = 1;
				e.push_back(make_pair(i, u));
			}
			if (s != -1)
			{
				a[i][s] = a[s][i] = 1;
				e.push_back(make_pair(i, s));
			}
			if (d != -1)
			{
				a[i][d] = a[d][i] = 1;
				e.push_back(make_pair(i, d));
			}
			if (u != -1 || s != -1 || d != -1)
				was_edge = true;

			if (u != -1 && s != -1)
			{
				if (a[u][s] == 0)
				{
					a[u][s] = a[s][u] = 1;
					e.push_back(make_pair(u, s));
				}
				was_triangle = true;
				Triangle tri;
				tri.a = i;
				tri.b = s;
				tri.c = u;
				tr.push_back(tri);
			}
			if (d != -1 && s != -1)
			{
				if (a[d][s] == 0)
				{
					a[d][s] = a[s][d] = 1;
					e.push_back(make_pair(d, s));
				}
				was_triangle = true;
				Triangle tri;
				tri.a = i;
				tri.b = s;
				tri.c = d;
				tr.push_back(tri);
			}

			maxY[y] = i;
		}
		int res = 3;
		if (!was_edge)
			res = 1;
		else if (!was_triangle)
			res = 2;
		else
		{

			while (1)
			{
				bool invalid = false;
				bool no_pairs = true;
				for (int i = 0; i < tr.size(); ++i)
				{
					//c
					if (color[tr[i].a] != -1 && color[tr[i].b] != -1)
					{
						if (color[tr[i].a] == color[tr[i].b])
						{
							invalid = true;
							break;
						}
						if (color[tr[i].c] == -1)
						{
							color[tr[i].c] = 6 - color[tr[i].a] - color[tr[i].b];
							no_pairs = false;
						}
						else if (color[tr[i].c] == color[tr[i].a] || color[tr[i].c] == color[tr[i].b])
						{
							invalid = true;
							break;
						}
					}
					//b
					if (color[tr[i].a] != -1 && color[tr[i].c] != -1)
					{
						if (color[tr[i].a] == color[tr[i].c])
						{
							invalid = true;
							break;
						}
						if (color[tr[i].b] == -1)
						{
							color[tr[i].b] = 6 - color[tr[i].a] - color[tr[i].c];
							no_pairs = false;
						}
						else if (color[tr[i].b] == color[tr[i].a] || color[tr[i].b] == color[tr[i].c])
						{
							invalid = true;
							break;
						}
					}
					//a
					if (color[tr[i].b] != -1 && color[tr[i].c] != -1)
					{
						if (color[tr[i].b] == color[tr[i].c])
						{
							invalid = true;
							break;
						}
						if (color[tr[i].a] == -1)
						{
							color[tr[i].a] = 6 - color[tr[i].b] - color[tr[i].c];
							no_pairs = false;
						}
						else if (color[tr[i].a] == color[tr[i].b] || color[tr[i].a] == color[tr[i].c])
						{
							invalid = true;
							break;
						}
					}
				}
				if (invalid)
				{
					res = 4;
					break;
				}

				if (no_pairs)
				{
					bool no_verts = true;
					for (int i = 0; i < e.size(); ++i)
					{
						int u = e[i].first;
						int v = e[i].second;
						if (color[u] == color[v] && color[u] != -1)
							res = 4;
						if (color[u] != -1 && color[v] == -1)
						{
							color[v] = color[u] + 1;
							if (color[v] == 4)
								color[v] = 1;
							no_verts = false;
							break;
						}
						if (color[v] != -1 && color[u] == -1)
						{
							color[u] = color[v] + 1;
							if (color[u] == 4)
								color[u] = 1;
							no_verts = false;
							break;
						}
					}
					if (no_verts)
					{
						int i;
						for (i = 0; i < n; ++i)
						{
							if (color[i] == -1)
							{
								color[i] = 3;
								break;
							}
						}
						if (i == n)
							break;
					}
				}
			}
		}

		printf("Case #%d: %d\n", t + 1, res);

	}

	return 0;
}