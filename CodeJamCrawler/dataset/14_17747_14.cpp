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
#define x first
#define ft first
#define y second
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt; 

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

ld c, f, x;

inline bool read ()
{
	if (!(cin >> c >> f >> x))
		return false;

	return true;
}

const int M = 1000 * 1000 + 13;

inline void solve (int test)
{
	printf ("Case #%d: ", test + 1);

	ld ans = 1e18;
	ld add = 2;
	ld res = 0;

	for (int i = 0; i < M; i++)
	{
		ans = min(ans, res + x / add);

	 	res += c / add;
	 	add += f;	
	}

	printf ("%.15lf\n", double(ans));
}

int main () 
{	
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    
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
