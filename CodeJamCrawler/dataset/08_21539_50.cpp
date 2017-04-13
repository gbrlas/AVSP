#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#define REP(i, n)	for(int i = 0; i < (n); ++i)
#define FOR(i, a, b)	for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b)	for(int i = (a); i >= (b); --i)
#define ALL(x)		(x).begin(), (x).end()
#define ABS(x)		((x) < 0 ? ((x) * (-1)) : (x))
#define PB(x)		push_back(x)

typedef vector <int>	vi;
typedef vector <double>	vd;
typedef vector <string> vs;
typedef pair <int, int>	pii;

int tc, n, a[10], b[10];

int calc()
{
	int cand = 0;
	REP(i, n)
		cand += a[i] * b[i];
	return cand;
}

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small-out.txt", "w", stdout);

	scanf("%d", &tc);
	REP(tci, tc)
	{
		scanf("%d", &n);
		REP(i, n)
			scanf("%d", &a[i]);
		REP(i, n)
			scanf("%d", &b[i]);
		sort(b, b + n);
		int mn = calc();
		while ( next_permutation(b, b + n) )
		{
			int cand = calc();
			mn = min( mn, cand );
		}
		printf("Case #%d: %d\n", tci + 1, mn);
	}
}
