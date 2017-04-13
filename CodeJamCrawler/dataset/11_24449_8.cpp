/*
 * b.cpp
 *
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef unsigned long long ull;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

vector<vector<int> > mass;
vector<vector<ull> > sum;
vector<vector<ull> > sumx;
vector<vector<ull> > sumy;

int square(vector<vector<ull> > t, int x, int y, int sx, int sy) {
	return t[x + sx][y + sy] + t[x][y] - t[x + sx][y] - t[x][y + sy];
}

bool isvalid(int i, int j, int k) {
	int u = i + k - 1;
	int v = j + k - 1;
	if (u >= (int) mass.size() || v >= (int) mass[0].size())
		return false;
	int xcenter = square(sumx, i, j, k, k);
	int ycenter = square(sumy, i, j, k, k);
	int mcenter = square(sum, i, j, k, k);
	xcenter -= mass[i][j] * i;
	xcenter -= mass[i][v] * i;
	xcenter -= mass[u][j] * u;
	xcenter -= mass[u][v] * u;
	ycenter -= mass[i][j] * j;
	ycenter -= mass[i][v] * v;
	ycenter -= mass[u][j] * j;
	ycenter -= mass[u][v] * v;
	mcenter -= mass[i][j];
	mcenter -= mass[i][v];
	mcenter -= mass[u][j];
	mcenter -= mass[u][v];

	return (2 * xcenter == (i + u) * mcenter && 2 * ycenter == (j + v)
			* mcenter);
}

void makesum() {
	for (int i = 0; i < (int) mass.size(); ++i) {
		ull acc = 0ull, accx = 0ull, accy = 0ull;
		for (int j = 0; j < (int) mass[0].size(); ++j) {
			acc += mass[i][j];
			accx += mass[i][j] * i;
			accy += mass[i][j] * j;
			sum[i + 1][j + 1] = acc + sum[i][j + 1];
			sumx[i + 1][j + 1] = accx + sumx[i][j + 1];
			sumy[i + 1][j + 1] = accy + sumy[i][j + 1];
		}
	}
}

int main(void) {
	int i, t, r, c, d;
	for (i = 1, cin >> t; i <= t; ++i) {
		// Read input
		cin >> r >> c >> d;
		mass = vector<vector<int> > (r, vector<int> (c, 0));
		sum = vector<vector<ull> > (r + 1, vector<ull> (c + 1, 0));
		sumx = vector<vector<ull> > (r + 1, vector<ull> (c + 1, 0));
		sumy = vector<vector<ull> > (r + 1, vector<ull> (c + 1, 0));
		for (int u = 0; u < r; ++u) {
			for (int v = 0; v < c; ++v) {
				char wij;
				cin >> wij;
				mass[u][v] = d + wij - '0';
			}
		}
		// Compute
		makesum();
		int best = 0;
		for (int u = 0; u < r; ++u) {
			for (int v = 0; v < c; ++v) {
				for (int k = 3; k <= min(r, c); ++k) {
					if (isvalid(u, v, k))
						best = max(best, k);
				}
			}
		}
		// Print the result
		if (best == 0)
			printf("Case #%d: IMPOSSIBLE\n", i);
		else
			printf("Case #%d: %d\n", i, best);
		mass.clear();
		sum.clear();
		sumx.clear();
		sumy.clear();
	}
}
