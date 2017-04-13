#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <complex>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define DOWNFOR(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define FOREACH(T, it, a) for (T::iterator it = (a).begin(); it != (a).end(); ++it)
#define CD complex<double>
#define All(x) (x).begin(), (x).end()

LL C, X, Y, A;

int main()
{
	cin >> C;

	FOR (icase, 0, C)
	{
		cin >> X >> Y >> A;
		FOR (y, 0, Y+1)
			FOR (x, 0, X+1)
				FOR (y1, 0, Y+1)
					FOR (x1, 0, X+1)
						if (abs(x*y1-y*x1) == A)
						{
							cout << "Case #" << icase+1 << ": 0 0 " << x << " " << y << " " << x1 << " " << y1 << endl;
							goto haluz;
						}
		cout << "Case #" << icase+1 << ": IMPOSSIBLE" << endl;
		haluz:
			;

	}
	return 0;
}
