#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <utility>
#include <complex>
#include <vector>
#include <bitset>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define x1 ___x1
#define y1 ___y1
#define X first
#define ft first
#define Y second
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt; 

const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int N = 10 + 3;
int n, m;
int a[N][N];

inline bool read ()
{
	if (scanf ("%d%d", &n, &m) != 2)
		return false;
		
	forn (i, n)
		forn (j, m)
			assert(scanf ("%d", &a[i][j]) == 1);

	return true;
}

int maxR[N], maxC[N];

inline void solve (int test)
{
	printf ("Case #%d: ", test + 1);
	
	forn (i, n)
	{
		maxR[i] = 0;
		
		forn (j, m)
			maxR[i] = max(maxR[i], a[i][j]);
	}
	
	forn (i, m)
	{
		maxC[i] = 0;
		
		forn (j, n)
			maxC[i] = max(maxC[i], a[j][i]);
	}
	
	forn (i, n)
		forn (j, m)
			if (maxR[i] != a[i][j] && maxC[j] != a[i][j])
			{
				puts("NO");
				return;
			}
			
	puts("YES");
}

int main () 
{	
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
	
    int testCnt;
    assert(scanf ("%d", &testCnt) == 1);
    
    forn (test, testCnt)
    {
		assert(read());
		solve(test);
	}
	
	return 0;
}
