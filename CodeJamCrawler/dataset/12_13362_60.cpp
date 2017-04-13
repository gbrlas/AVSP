#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a, b;
#define MAXN 2000005
bool vis[MAXN];
int w;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		scanf("%d%d", &a, &b);
		memset(vis, false, sizeof(vis));
		int ans = 0;
		for (int j = a; j <= b; ++j)
		{
			int tmp = j;
			int t = 1;
			if (!vis[tmp])
			{
				vis[tmp] = true;
				w = 0;
				while (tmp)
				{
					tmp /= 10;
					++w;
					t *= 10;
				}
				t /= 10;
			
				tmp = j;
				int tot = 1;
				if (w > 1)
					for (int k = 1; k < w; ++k)
					{
						tmp = tmp % t * 10 + tmp / t;
//						cout << tmp << ' ';
						if (tmp >= a && tmp <= b && !vis[tmp])
						{
							vis[tmp] = true;
							++tot;
						}
					}
				ans += tot * (tot - 1) / 2;
			}
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}