#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

const int none = 10000;
char buf[100000];
map<string, int> names;
int ids[1001];
int f[1001][101];
int n, m;
int ans;

void init()
{
	gets(buf);
	sscanf(buf, "%d", &n);
	names.clear();
	for (int i = 1; i <= n; ++i)
	{
		gets(buf);
		names[buf] = i;
	}
	gets(buf);
	sscanf(buf, "%d", &m);
	for (int i = 0; i < m; ++i)
	{
		gets(buf);
		ids[i] = names[buf];
	}
}

void process()
{
	memset(f, 0, sizeof(f));
	if (ids[0])
		f[0][ids[0]-1] = none;
	int minx = 0;
	for (int i = 1;i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			f[i][j] = min(f[i-1][j], minx + 1);
		if (ids[i])
			f[i][ids[i]-1] = none;
		minx = f[i][0];
		for (int j = 0; j < n; ++j)
			minx = min(minx, f[i][j]);
	}
	ans = minx;
}

void print()
{
	static int id = 0;
	++id;
	printf("Case #%d: %d\n", id, ans);
}

int main()
{
	freopen("a.txt", "rt", stdin);
	freopen("a_out.txt", "wt", stdout);
	int tt;
	gets(buf);
	sscanf(buf, "%d", &tt);
	for (int i = 0; i < tt; ++i)
	{
		init();
		process();
		print();
	}
	return 0;
}
