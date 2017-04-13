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
	int r, c, bcount = 0;
	char a[100][100];
	scanf("%d%d", &r, &c);
	REP(i, r)
	{
		char tmp;
		scanf("%c", &tmp);
		REP(j, c)
		{
			scanf("%c", &a[i][j]);
			if (a[i][j] == '#')
				bcount++;
		}
	}
	if (bcount%4 != 0)
	{
		printf("\nImpossible");
		return;
	}
	REP(i, r-1)
		REP(j, c-1)
			if (a[i][j] == '#'
				&& a[i+1][j] == '#'
				&& a[i][j+1] == '#'
				&& a[i+1][j+1] == '#'
						)
			{
				a[i][j] = '/';
				a[i][j+1] = '\\';
				a[i+1][j] = '\\';
				a[i+1][j+1] = '/';
				bcount -= 4;
			}
	if (bcount != 0)
	{
		printf("\nImpossible");
		return;
	}
	REP(i, r)
	{
		cout << "\n";
		REP(j, c)
			cout << a[i][j];
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
