#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>

using namespace std;

char buf[1000000];
char s[100000];
int m;
int n;
int ch[20][20];
int hs[20][20];
int f[1<<16][16];
int ans;

const int none = 1000000;

void init()
{
	gets(buf);
	sscanf(buf, "%d", &m);
	gets(s);
	n = strlen(s);
}

void process()
{
	memset(ch, 0, sizeof(ch));
	memset(hs, 0, sizeof(hs));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			if (i!=j)
			{
				for (int k = 0; k < n/m; ++k)
					if (s[m*k+i]!=s[m*k+j])
						++ch[i][j];
				for (int k = 1; k < n/m; ++k)
				{
					if (s[m*k+i]!=s[m*(k-1)+j])
						++hs[i][j];
				}
			}
	int MM = 1<<m;
	ans = none;
	for (int j = 0; j < m; ++j)
	{
		for (int k = 0; k < MM; ++k)
			for (int l = 0; l < m; ++l)
				f[k][l] = none;
		for (int i = 0; i < m; ++i)
			if (i!=j)
			{
				f[1<<i][i] = hs[i][j];
			}
		for (int k = 1; k < MM; ++k)
		{
			for (int l = 0; l < m; ++l)
			{
				int r = 1<<l;
				if ((k&r) && (k!=r))
				{
					for (int x = 0; x < m; ++x)
					{
						int xx = 1<<x;
						if (x!=l && (k&xx))
						{
							f[k][l] = min(f[k][l], f[k-r][x] + ch[x][l]);
						}
					}
				}
			}
		}
		if (f[MM-1][j]<ans)
			ans = f[MM-1][j] + 1;
	}
}

void print()
{
	static int id = 0;
	++id;
	printf("Case #%d: %d\n", id, ans);
}

int main()
{
	freopen("d.txt", "rt", stdin);
	freopen("d_out.txt", "wt", stdout);
	int tt;
	gets(buf);
	sscanf(buf, "%d", &tt);
	for (int i = 0; i < tt; ++i)
	{
		init();
		process();
		print();
	}
}
