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
struct edge{int a, l;};
int n, m, bl[10], tot;
char s[10][13];
int ans, cnt, ch[105][100];

int newNode()
{
	++tot;
	memset(ch[tot], 0, sizeof(ch[tot]));
	return tot;
}

void init()
{
	tot = 0;
	newNode();
}

void add(char s[])
{
	int len = strlen(s + 1);

	int x = 1;
	rep(i, len)
	{
		if (ch[x][s[i]] != 0) {
			x = ch[x][s[i]];
		}
		else
		{
			ch[x][s[i]] = newNode();
			x = ch[x][s[i]];
		}
	}
}

void ck()
{
	bool bo[10];
	rep(i, m) bo[i] = 0;
	rep(i, n) bo[bl[i]] = 1;
	rep(i, m) if (!bo[i]) return;

	int tmp = 0;
	rep(i, m)
	{
		init();
		rep(j, n) if (bl[j] == i)
			add(s[j]);
		tmp += tot;
	}
	if (tmp > ans)
	{
		ans = tmp;
		cnt = 0;
	}
	if (tmp == ans) ++cnt;
}

void dfs(int x)
{
	if (x > n)
	{
		ck();
		return;
	}
	rep(i, m)
	{
		bl[x] = i;
		dfs(x + 1);
	}
}

int main()
{
	int ca;
	scanf("%d", &ca);
	rep(t, ca) {
		ans = 0;
		scanf("%d%d", &n, &m);
		rep(i, n) scanf("%s", &s[i][1]);
		dfs(1);
		printf("Case #%d: %d %d\n", t, ans, cnt);
	}
	return 0;
}
