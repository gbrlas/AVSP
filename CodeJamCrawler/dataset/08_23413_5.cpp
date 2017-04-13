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
//#include <complex>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define DOWNFOR(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define FOREACH(T, it, a) for (T::iterator it = (a).begin(); it != (a).end(); ++it)
//#define CD complex<double>
#define All(x) (x).begin(), (x).end()

LL N, H, W, R, r, c;

LL grid[150][150];

int main()
{
	cin >> N;
	FOR (icase, 0, N)
	{
		cin >> H >> W >> R;
		FOR (i, 0, H)
			FOR (j, 0, W)
				grid[i][j] = 0;
		
		grid[0][0] = 1;

		FOR (i, 0, R)
		{
			cin >> r >> c;
			grid[r-1][c-1] = -1;
		}

		FOR (rr, 0, H)
			FOR (cc, 0, W)
			{
				if (grid[rr][cc] < 0)
					continue;
				if (rr-2 >= 0 && cc-1 >= 0 && grid[rr-2][cc-1] >= 0)
					grid[rr][cc] += grid[rr-2][cc-1];
				if (rr-1 >= 0 && cc-2 >= 0 && grid[rr-1][cc-2] >= 0)
					grid[rr][cc] += grid[rr-1][cc-2];
				grid[rr][cc] = grid[rr][cc] % 10007;
			}

		cout << "Case #" << icase+1 << ": " << grid[H-1][W-1] << endl;
	}
	return 0;
}
