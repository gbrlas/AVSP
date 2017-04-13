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

int tc, n;
char s[50010], temp[50010];

int main()
{
	freopen("D-small.in", "r", stdin);
	freopen("D-small-out.txt", "w", stdout);

	scanf("%d", &tc);
	REP(tci, tc)
	{
		int p[20], l, mn;

		scanf("%d", &n);
		scanf("%s", s);
		REP(i, n)
			p[i] = i;
		mn = l = strlen(s);
		do 
		{
			REP(i, l / n)	REP(j, n)
				temp[i * n + j] = s[i * n + p[j]];
			int cnt = 0;
			REP(i, l)
			{
				++cnt;
				while( i + 1 < l && temp[i] == temp[i + 1] )
					++i;
			}
			mn = min(mn, cnt);
		} while ( next_permutation(p, p + n) );
		printf("Case #%d: %d\n", tci + 1, mn );
	}
}
