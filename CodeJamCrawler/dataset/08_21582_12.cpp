#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cctype>

using namespace std;

#define ABS(x)		((x) < 0 ? ((x) * -1) : (x))
#define REP(i, n)		for( int i = 0; i < (n); ++i )
#define INIT(x)		memset(x, 0, sizeof(x))
#define INIT1(x)		memset(x, 255, sizeof(x))
#define ALL(x)		x.begin(), x.end()

typedef pair < int , int >	pii;
typedef vector < int >	vi;
typedef vector < string > vs;

int n, m, check[10], use[10];
int e[10][10];
vector < pii > ve;
bool found;

void go(int p)
{
	if ( p == m )
	{
		int yes = true;
		REP(i, ve.size())
		{
			if ( e[use[ve[i].first]][use[ve[i].second]] == 0 )
			{
				yes = false;
				break;
			}
		}
		if ( yes )
		{
			found = true;
		}
	}
	else
	{
		REP(i, n)
			if ( check[i] == 0 )
			{
				check[i] = 1;
				use[p] = i;
				go(p + 1);
				check[i] = 0;
				if ( found )
					return;
			}
	}
}

int main()
{
	int tcn;

	freopen("D-small.in", "r", stdin);
	freopen("D-small-out.txt", "w", stdout);
	scanf("%d", &tcn);
	REP(tc, tcn)
	{
		scanf("%d", &n);
		ve.clear();
		INIT(e);
		REP(i, n - 1)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			e[u - 1][v - 1] = e[v - 1][u -1 ] = 1;
		}
		scanf("%d", &m);
		REP(i, m - 1)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			ve.push_back(pii(u - 1, v - 1));
		}
		INIT(check);
		found = false;
		go(0);
		printf("Case #%d: ", tc + 1);
		if ( found )
			printf("YES\n");
		else
			printf("NO\n");
	}
}
