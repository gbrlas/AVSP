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

const int N = 4;
char a[N][N];

inline bool read ()
{
	forn (i, 4)
		assert(scanf ("%s", a[i]) == 1);

	return true;
}

inline bool find (char c, char t)
{
	forn (i, 4)
	{
		bool ok = 1;
		
		forn (j, 4)
			ok &= ((a[i][j] == c) || (a[i][j] == t)); 
			
		if (ok)
			return true;
	}
	
	forn (i, 4)
	{
		bool ok = 1;
		
		forn (j, 4)
			ok &= ((a[j][i] == c) || (a[j][i] == t)); 
			
		if (ok)
			return true;
	}
	
	bool ok = 1;
	
	forn (i, 4)
		ok &= ((a[i][i] == c) || (a[i][i] == t));
		
	if (ok)
		return true;
		
	ok = 1;
	
	forn (i, 4)
		ok &= ((a[i][4 - i - 1] == c) || (a[i][4 - i - 1] == t));
		
	if (ok)
		return true;
		
	return false;
}

inline void solve (int test)
{
	printf ("Case #%d: ", test + 1);
	
	int isEnd = 1;
	forn (i, 4)
		forn (j, 4)
			isEnd &= (a[i][j] != '.');
			
	if (find('X', 'T'))
	{
		puts("X won");
		return;
	}
	
	if (find('O', 'T'))
	{
		puts("O won");
		return;
	}
	
	if (isEnd)
	{
		puts("Draw");
		return;
	}
	
	puts("Game has not completed");
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
