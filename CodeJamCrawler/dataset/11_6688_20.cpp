#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <utility>
#include <set>

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
	int n;
	char a[128][128];
	int w[128];
	int c[128];
	long double wp[128], owp[128], oowp[128];

	scanf("%d", &n);
	REP(i, n)
	{
		char tmp;
		scanf("%c", &tmp);
		REP(j, n)
			scanf("%c", &a[i][j]);


	}
	REP(i, n)
	{
		int sum = 0, count = 0;

		REP(j, n)
			if (a[i][j] != '.')
			{
				count++;
				sum += (a[i][j] == '1' ? 1 : 0);
			}
		w[i] = sum;
		c[i] = count;
		wp[i] = (double)sum/count;
	}

	REP(i, n)
	{
		long double sum = 0;
		int count = 0;
		REP(j, n)
			if (a[i][j] != '.')
			{
				count++;
				sum += (double)(w[j] - (a[i][j] == '1' ? 0 : 1))/(c[j] - 1);
			}
		owp[i] = sum/count;
	}

	REP(i, n)
	{
		long double sum = 0;
		int count = 0;
		REP(j, n)
			if (a[i][j] != '.')
			{
				count++;
				sum += owp[j];
			}
		oowp[i] = sum/count;
	}

	REP(i, n)
	{
		printf("\n%.9Lf", 0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i]);
	}
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
		fprintf(stderr, "Case #%d\n", i);
		solve();
		printf("\n");
	}

	return 0;
}
