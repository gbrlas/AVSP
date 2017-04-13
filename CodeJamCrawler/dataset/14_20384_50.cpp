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
const int maxN = 10005;
int a[maxN];

int main()
{
	int ca, n, ans, m;
	scanf("%d", &ca);
	rep(t, ca) {
		scanf("%d", &n);
		rep(i, n) scanf("%d", a + i);
		int l = 1, r = n;
		ans = 0;
		rep(i, n) {
			//cerr << i << endl;
			m = 0;
			FOR(j, l, r) if (m == 0 || a[m] > a[j]) m = j;
			//cerr << m << endl;
			//cerr << l << " " << r << endl;
			if (m - l < r - m)
			{
				for (int j = m; j > l; --j)
				{
					swap(a[j], a[j - 1]);
					++ans;
				}
				l++;
			}
			else
			{
				for (int j = m; j < r; ++j)
				{
					swap(a[j], a[j + 1]);
					++ans;
				}
				--r;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
