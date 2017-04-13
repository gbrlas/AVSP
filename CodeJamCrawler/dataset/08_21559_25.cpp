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

int tc, n, m, a;

int find()
{
	REP(i, n + 1)	REP(j, m + 1)	REP(x, n + 1)	REP(y, m + 1)
		if ( i != x || j != y )
		{
			if ( a == ABS(i * y - j * x) )
			{
				printf("%d %d %d %d %d %d\n", 0, 0, i, j, x, y );
				return 1;
			}
		}
	return 0;
}

int main()
{
	freopen("B-small.in", "r", stdin);
	freopen("B-small-out.txt", "w", stdout);

	scanf("%d", &tc);
	REP(tci, tc)
	{
		scanf("%d %d %d", &n, &m, &a);
		printf("Case #%d: ", tci + 1);
		if ( ! find() )
		{
			printf("IMPOSSIBLE\n");
		}
	}
}
