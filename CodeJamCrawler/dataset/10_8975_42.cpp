// GCJ Round 2 2010 -- Sat Jun 5 2010
// Problem C
//
// pre-written code follows
// #includes {{{
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// }}}
// constants, typedefs, macros {{{
typedef long long LL;
typedef unsigned long long ULL;
const int oo = 1000000000;
const LL OO = 1000000000000000000LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<string> VS;
typedef queue<int> QI;
typedef queue<PII> QPII;
typedef complex<double> tComp;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
#define FORIT(i,c) for (typeof((c).end()) i=(c).begin(); i!=(c).end(); ++i)
#define CERR(x) cerr << (#x) << " = " << (x) << endl
#define COUT(x) cout << (#x) << " = " << (x) << endl
// }}}

// code written during the competition follows
const int N = 300;
int a[N][N];
bool alive()
{
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (a[i][j])
				return true;
	return false;
}
int main()
{
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		int r;
		cin >> r;
		memset(a, 0, sizeof a);
		for (int i=0; i<r; i++)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for (int x=x1; x<=x2; x++)
				for (int y=y1; y<=y2; y++)
					a[x][y] = 1;
		}
		int t = 0;
		while (alive())
		{
			VPII die, alive;
			for (int i=1; i<N; i++)
				for (int j=1; j<N; j++)
					if (a[i][j])
					{
						assert(i != N-1 && j != N-1);
						if (!a[i-1][j] && !a[i][j-1])
							die.push_back(PII(i, j));
					}
					else
					{
						if (a[i-1][j] && a[i][j-1])
							alive.push_back(PII(i, j));
					}
			FORIT(it, die)
				a[it->first][it->second] = 0;
			FORIT(it, alive)
				a[it->first][it->second] = 1;
			t++;
		}
		printf("Case #%d: ", tkase+1);
		cout << t << endl;
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
