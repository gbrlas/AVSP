/*
  Hi! This is my solution to C-small with a brute force. I generate all possible
  fields and then check if they can be solved in one click.
 */


#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define VAR(a,b)        __typeof(b) a=(b)
#define REP(i,n)        for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b)      for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b)     for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c)   for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c)          (c).begin(),(c).end()
#define TRACE(x)        cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x)        cerr << #x << " = " << x << endl;
#define eprintf(...)    fprintf(stderr, __VA_ARGS__)

typedef long long               ll;
typedef long double             ld;
typedef unsigned long           ulong;
typedef unsigned long long      ull;
typedef vector<int>             VI;
typedef vector<vector<int> >    VVI;
typedef vector<char>            VC;

// get the next int with the same number of bits
int next(int v) {
	//	int last = x & -x; // the last 1 of x
	unsigned int t = v | (v - 1);
	return ((t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1)));
}

char f[5][5];
char was[5][5];

int r, c, m;

int fill(int x, int y) {
	if (f[x][y])
		return -1;
	int result = 1;
	was[x][y] = true;
	int cnt = 0;
	FOR(dx, -1, +1) {
		FOR(dy, -1, +1) {
			if (abs(dx)+abs(dy) > 0 && x+dx >= 0 && x+dx < r && y+dy >= 0 && y+dy < c &&!was[x+dx][y+dy])
				cnt += f[x+dx][y+dy];
		}
	}
	if (cnt)
		return result;
	FOR(dx, -1, +1) {
		FOR(dy, -1, +1) {
			if (abs(dx)+abs(dy) > 0 && x+dx >= 0 && x+dx < r && y+dy >= 0 && y+dy < c &&!was[x+dx][y+dy])
				result += fill(x+dx, y+dy);
		}
	}
	return result;
}

int main() {
	int tnum;
	cin >> tnum;
	FOR(ti,1,tnum) {
		cin >> r >> c >> m;
		int bitfield = (1 << m) - 1;
		int maxbitfield = (1 << (r*c));
		int n = 0;
		for (; bitfield < maxbitfield; bitfield = next(bitfield)) {
			//fprintf(stderr, "Attempt #%d of %d...\n", ++n, maxbitfield);
			memset(f, 0, sizeof(f));
			int tmp = bitfield;
			REP(i,r) REP(j,c) {
				f[i][j] = tmp & 1;
				tmp >>= 1;
			}
			char ok = false;
			int cx, cy;
			REP(i,r) REP(j,c) {
				memset(was, 0, sizeof(was));
				int fillnum = fill(i,j);
				//cerr << "filled " << fillnum << endl;
				if (fillnum == r*c-m) {
					ok = true;
					cx = i;
					cy = j;
					printf("Case #%d:\n", ti);
					REP(cx,r) {
						REP(cy,c)
							if (i == cx && j == cy)
								putchar('c');
							else
								putchar((f[cx][cy])? '*' : '.');
						putchar('\n');
					}
					goto NEXT;
				}
			}
		}
		printf("Case #%d:\nImpossible\n", ti);
		NEXT: n = 0;
	}
    return 0;
}
