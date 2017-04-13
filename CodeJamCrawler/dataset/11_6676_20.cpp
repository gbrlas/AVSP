#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n)-1); i >= 0; --i)

typedef long long int64;

template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T> void remin(T& a, const T& b) { if (b < a) a = b; }
template<typename T> void remax(T& a, const T& b) { if (b > a) a = b; }

const long double PI = 2*asin(1);

void solve()
{
	int ret;
	int n, pd, pg;
	scanf("%d%d%d", &n, &pd, &pg);

	FOR(i, 1, 100)
		FOR(j, 1, 100)
			if (i <= n && (i*pd)%100 == 0 && (j*pg)%100 == 0)
			{
				int d = i*pd/100, g = j*pg/100;
				if (g*100 >= d && (j - g)*100 >= (i - d))
				{
					printf("Possible");
					return;
				}

			}

	printf("Broken");
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int T;
	scanf("%d\n", &T);
	FOR(i, 1, T)
	{
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}

	return 0;
}
