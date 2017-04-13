#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define zrp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
#define foredge(i, x) for (int i = start[x]; i; i = e[i].l)
struct edge{int a, l, c;}e[1000005];
const int maxN = 110005;
const int inf = 19950108;
int n, m, k, w, tt, in[505][505], ou[505][505], p[505][505];
int tot, start[maxN], S, T, lev[maxN], q[maxN];
const int dx[5] = {0, 1, -1, 0, 0};
const int dy[5] = {0, 0, 0, 1, -1};

void add(int x, int y, int z)
{
	e[++tot].l = start[x]; e[tot].a = y; e[tot].c = z; start[x] = tot;
	e[++tot].l = start[y]; e[tot].a = x; e[tot].c = 0; start[y] = tot;
}

bool bfs()
{
	rep(i, T) lev[i] = 0;
	lev[S] = 1;
	int h, t;
	h = 0; q[t = 1] = S;
	while (h != t)
	{
		int x = q[++h];
		//cerr << x << endl;
		for (int i = start[x]; i; i = e[i].l) if (e[i].c > 0 && !lev[e[i].a])
		{
			q[++t] = e[i].a;
			lev[e[i].a] = lev[x] + 1;
		}
	}
	return lev[T];
}

int dinic(int x, int f)
{
	if (x == T) return f;
	int l = f, tmp;
	for (int i = start[x]; i; i = e[i].l) if (e[i].c > 0 && lev[e[i].a] == lev[x] + 1)
	{
		tmp = dinic(e[i].a, min(l, e[i].c));
		e[i].c -= tmp; e[i ^ 1].c += tmp;
		l -= tmp;
		if (l == 0) break;
	}
	if (l == f) lev[x] = -1;
	return f - l;
}

int maxFlow()
{
	int s = 0;
	while (bfs())
		s += dinic(S, inf);
	return s;
}

int main()
{
	int ca, x1, x2, y1, y2;
	scanf("%d", &ca);
	rep(t, ca) 
	{
		++w;
		scanf("%d%d%d", &n, &m, &k);
		rep(i, k)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			++x1; ++y1; ++x2; ++y2;
			FOR(x, x1, x2) FOR(y, y1, y2) p[x][y] = w;
		}
		tt = 0;
		rep(i, n) rep(j, m) if (p[i][j] != w) 
		{
			in[i][j] = ++tt;
		}

		tot = 1; memset(start, 0, sizeof(start));

		rep(i, n) rep(j, m) if (p[i][j] != w) 
		{
			ou[i][j] = ++tt;
			add(in[i][j], ou[i][j], 1);
		}

		rep(i, n) rep(j, m) if (p[i][j] != w)
		{
			int x, y;
			rep(k, 4)
			{
				x = i + dx[k];
				y = j + dy[k];
				if (x >= 1 && x <= n && y >= 1 && y <= m && p[x][y] != w)
				{
					add(ou[i][j], in[x][y], 1);
				}
			}
		}

		S = ++tt; T = ++tt;
		rep(i, n) if (p[i][1] != w)
		{
			add(S, in[i][1], 1);
		}

		rep(i, n) if (p[i][m] != w)
		{
			add(ou[i][m], T, 1);
		}

		//cerr << tt << endl;

		int ans = maxFlow();

		printf("Case #%d: %d\n", w, ans);

	}
	return 0;
}
