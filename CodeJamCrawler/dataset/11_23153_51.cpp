#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;
#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("0.in", "r", stdin);
    freopen("0.out", "w", stdout);
}

struct Point
{
    int x;
    int y;
    Point(int x_, int y_): x(x_), y(y_)
    { }
};

const int MAX = 500 + 5;
double table[MAX][MAX];
double mass[MAX][MAX];
double xmass[MAX][MAX];
double ymass[MAX][MAX];
int n, m;

bool check(int med) {
	bool ok = false;
	for (int i = med; i <= n && !ok; ++i) {
		for (int j = med; j <= m && !ok; ++j) {
			double m = mass[i][j] - mass[i - med][j] - mass[i][j - med] + mass[i - med][j - med];
			double x = xmass[i][j] - xmass[i - med][j] - xmass[i][j - med] + xmass[i - med][j - med];
			double y = ymass[i][j] - ymass[i - med][j] - ymass[i][j - med] + ymass[i - med][j - med];
			m -= table[i][j] + table[i - med + 1][j] + table[i][j - med + 1] + table[i - med + 1][j - med + 1];
			x -= table[i][j] * i + table[i - med + 1][j] * (i - med + 1) + table[i][j - med + 1] * i + table[i - med + 1][j - med + 1] * (i - med + 1);
			y -= table[i][j] * j + table[i - med + 1][j] * j + table[i][j - med + 1] * (j - med + 1) + table[i - med + 1][j - med + 1] * (j - med + 1);
			if (x / m == (i - (double(med) - 1.0) / 2) &&  y / m == (j - (double(med) - 1.0) / 2)) ok = true;
		}
	}
	return ok;
}

int main()
{
    initialize();

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		double d;
		cin >> n >> m >> d;
		for (int i = 0; i < n; ++i) {
			string str;
			cin >> str;
			for (int j = 0; j < m; ++j) {
				table[i + 1][j + 1] = d + (str[j] - '0');
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				//if (i == 0 && j == 0) {
				//	mass[i][j] = xmass[i][j] = ymass[i][j] = table[i][j];
				//}
				//else if (i == 0) {
				//	mass[i][j] = mass[i][j - 1] + table[i][j];
				//	xmass[i][j] = xmass[i][j - 1] + i * table[i][j];
				//	ymass[i][j] = ymass[i][j - 1] + j * table[i][j];
				//}
				//else if (j == 0) {
				//	mass[i][j] = mass[i - 1][j] + table[i][j];
				//	xmass[i][j] = xmass[i - 1][j] + i * table[i][j];
				//	ymass[i][j] = ymass[i - 1][j] + j * table[i][j];
				//}
				//else {
					mass[i][j] = mass[i - 1][j] + mass[i][j - 1] - mass[i - 1][j - 1] + table[i][j];
					xmass[i][j] = xmass[i - 1][j] + xmass[i][j - 1] - xmass[i - 1][j - 1] + i * table[i][j];
					ymass[i][j] = ymass[i - 1][j] + ymass[i][j - 1] - ymass[i - 1][j - 1] + j * table[i][j];
				//}
			}
		}

		int res = -1;
		for (int i = min(n, m); i >= 3; --i) {
			if (check(i)) {
				res = i;
				break;
			}
		}
		printf("Case #%d: ", tt);
		if (res != -1) {
			printf("%d\n", res);
		}
		else {
			printf("IMPOSSIBLE\n");
		}
	}

    return 0;
}