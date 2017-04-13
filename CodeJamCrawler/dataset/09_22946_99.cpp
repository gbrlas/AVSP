#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int maxn = 1001;
const int none = 100000000;

int t, m, n;
int v[maxn][maxn];
int par[maxn*maxn];
int lab[maxn*maxn];

void init()
{
	cin >> m >> n;
	for (int i = 0; i <= m + 1; ++i)
		for (int j = 0; j <= n + 1; ++j)
			v[i][j] = none;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	for (int i = 1; i <= n * m; ++i)
		par[i] = i;
	for (int i = 1; i <= n * m; ++i)
		lab[i] = 0;
}

int pos(int x, int y)
{
	return (x-1)*n+y;
}

int getparent(int x)
{
	if (par[x]!=x) par[x] = getparent(par[x]);
	return par[x];
}

void merge(int a, int b, int c, int d)
{
	int aa = pos(a, b),
		bb = pos(c, d);
	par[getparent(aa)] = getparent(bb);
}

void process()
{
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			int dx = 0, dy = 0;
			if (v[i-1][j]<v[i+dx][j+dy])
				{dx = -1; dy = 0; }
			if (v[i][j-1]<v[i+dx][j+dy])
				{dx = 0; dy = -1; }
			if (v[i][j+1]<v[i+dx][j+dy])
				{dx = 0; dy = 1; }
			if (v[i+1][j]<v[i+dx][j+dy])
				{dx = 1; dy = 0; }
			merge(i, j, i+dx, j+dy);
		}
	int id = 0;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (lab[getparent(pos(i,j))]==0)
				lab[getparent(pos(i,j))]=++id;
		}
	}
}

void print()
{
	static int pid = 0;
	printf("Case #%d:\n", ++pid);
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			printf("%c ", (char)('a'+lab[getparent(pos(i,j))]-1));
		}
		printf("\n");
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		init();
		process();
		print();
	}
	return 0;
}
