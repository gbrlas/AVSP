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
const int maxN = 1005;
double a[maxN], b[maxN];
int ca, n;

int main()
{
	scanf("%d", &ca);
	for (int T = 1; T <= ca; ++T)
	{
		scanf("%d", &n);
		rep(i, n) scanf("%lf", a + i);
		rep(i, n) scanf("%lf", b + i);

		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);

		int l = 1, r = n, c1 = 0;
		rep(i, n)
		{
			if (a[i] > b[l])
			{
				++c1; ++l;
			}
			else
			{
				--r;
			}
		}
		
		printf("Case #%d: %d ", T, c1);

		bool del[1005];
		int c = 0;
		memset(del, 0, sizeof(del));
		for (int i = 1; i <= n; ++i)
		{
			int x = 0;
			for (int j = 1; j <= n; ++j) if (!del[j] && (x == 0 || b[j] > a[i]))
			{
				x = j;
				if (b[x] > a[i])
					break;
			}
			del[x] = 1;
			if (a[i] > b[x]) ++c;
		}

		printf("%d\n", c);
	}
	return 0;
}
