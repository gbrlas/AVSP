#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define zrp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
#define foredge(i, x) for (int i = start[x]; i; i = e[i].l)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : (-(a)))
typedef long long int64;
char s[105][105], a[105][105];

bool check(char c)
{
	rep(i, 4) rep(j, 4) a[i][j] = s[i][j];
	rep(i, 4) rep(j, 4)
		if (a[i][j] == 'T') a[i][j] = c;
		
	rep(i, 4)
	{
		bool flag = 0;
		rep(j, 4) if (a[i][j] != c) flag = 1;
		if (!flag) return 1;
	}
	
	rep(j, 4)
	{
		bool flag = 0;
		rep(i, 4) if (a[i][j] != c) flag = 1;
		if (!flag) return 1;
	}
	
	bool flag = 0;
	rep(i, 4) if (a[i][i] != c) flag = 1;
	if (!flag) return 1;
	
	rep(i, 4) if (a[i][5 - i] != c) return 0;
	return 1;
}

void work()
{
	if (check('X'))
	{
		puts("X won");
		return;
	}
	if (check('O'))
	{
		puts("O won");
		return;
	}
	rep(i, 4) rep(j, 4)
		if (s[i][j] == '.')
		{
			puts("Game has not completed");
			return;
		}
	puts("Draw");
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int ca;
	scanf("%d", &ca);
	rep(t, ca)
	{
		rep(i, 4) scanf("%s", &s[i][1]);
		printf("Case #%d: ", t);
		work();
	}
	return 0;
}
