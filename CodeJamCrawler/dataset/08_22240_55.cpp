#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int maxn = 100001;

char buf[1000000];
int ans;
int n;
int g[maxn], c[maxn];
int v[maxn];
int f[maxn][2];
int v0;

void init()
{
	scanf("%d%d", &n, &v0);
	for (int i = 0; i < (n-1)/2; ++i)
		scanf("%d%d", &g[i], &c[i]);
	for (int i = (n-1)/2; i < n; ++i)
		scanf("%d", &v[i]);
}

void process()
{
	for (int i = 0; i < n; ++i)
		f[i][0] = f[i][1] = 10000001;
	for (int i = (n-1)/2; i < n; ++i)
		f[i][v[i]] = 0;
	for (int i = (n-1)/2-1; i >= 0; --i)
	{
		int c1 = 2 * i + 1, c2 = 2 * i + 2;
		if (g[i]==0) // OR
		{
			f[i][0] = f[c1][0] + f[c2][0];
			f[i][1] = min(min(f[c1][1]+f[c2][0], f[c1][0]+f[c2][1]), f[c1][1]+f[c2][1]);
		}
		else // AND
		{
			f[i][1] = f[c1][1] + f[c2][1];
			f[i][0] = min(min(f[c1][1]+f[c2][0], f[c1][0]+f[c2][1]), f[c1][0]+f[c2][0]);
		}
		if (c[i])
		{
			f[i][0] = min(f[i][0], f[c1][0] + f[c2][0] + 1);
			f[i][1] = min(f[i][1], min(min(f[c1][1]+f[c2][0], f[c1][0]+f[c2][1]), f[c1][1]+f[c2][1])+1);
			f[i][1] = min(f[i][1], f[c1][1] + f[c2][1] + 1);
			f[i][0] = min(f[i][0], min(min(f[c1][1]+f[c2][0], f[c1][0]+f[c2][1]), f[c1][0]+f[c2][0])+1);
		}
//		cout << i << ' ' << f[i][0] << ' ' << f[i][1] << endl;
	}
	ans = f[0][v0];
}

void print()
{
	static int id = 0;
	++id;
	if (ans<0 || ans>1000000)
		printf("Case #%d: IMPOSSIBLE\n", id);
	else
		printf("Case #%d: %d\n", id, ans);
}

int main()
{
	freopen("a.txt", "rt", stdin);
	freopen("a_out.txt", "wt", stdout);
	int tt;
	scanf("%d", &tt);
	for (int i = 0; i < tt; ++i)
	{
		init();
		process();
		print();
	}
}
