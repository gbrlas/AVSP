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
    freopen("l.in", "r", stdin);
    freopen("l.out", "w", stdout);
}

struct Point
{
    int x;
    int y;
    Point(int x_, int y_): x(x_), y(y_)
    { }
};

const int MAX = 100 + 5;
//ool table[MAX][MAX];
int games[MAX];
int wins[MAX];

int table[MAX][MAX];
double wp[MAX];
double owp[MAX];
double oowp[MAX];

int main()
{
    initialize();

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		memset(games, 0, sizeof(games));
		memset(wins, 0, sizeof(wins));
		memset(table, 0 , sizeof(table));
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			string str;
			cin >> str;
			for (int j = 0; j < n; ++j) {
				if (str[j] != '.') {
					games[i] += 1;
					if (str[j] == '1') {
						table[i][j] = 1;
					} else {
						table[i][j] = 2;
					}
				}
				else {
					table[i][j] = 0;
				}
				if (str[j] == '1') wins[i] += 1;
			}
		}

		for (int i = 0; i < n; ++i) {
			wp[i] = double(wins[i]) / double(games[i]);
		}
		for (int i = 0; i < n; ++i) {
			double sum = 0.0;
			for (int j = 0; j < n; ++j) {
				if (table[i][j]) {
					int w = wins[j];
					int g = games[j] - 1;
					if (table[i][j] == 2) {
						w -= 1;
					}
					sum += double(w) / double(g);
				}
			}
			owp[i] = sum / games[i];
		}
		for (int i = 0; i < n; ++i) {
			double sum = 0.0;
			for (int j = 0; j < n; ++j) {
				if (table[i][j]) {
					sum += owp[j];
				}
			}
			oowp[i] = sum / games[i];
		}

		printf("Case #%d:\n", tt);
		for (int i = 0; i < n; ++i) {
			printf("%.10lf\n", 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]);
		}
	}

    return 0;
}