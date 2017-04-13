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

string str[10];
int table[5][5];

int dx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

int main()
{
    initialize();

	typedef pair<char, bool> cb;
	map<cb, int> mm;
	mm[cb('|', false)] = 3;
	mm[cb('|', true)] = 7;
	mm[cb('-', false)] = 1;
	mm[cb('-', true)] = 5;
	mm[cb('/', false)] = 0;
	mm[cb('/', true)] = 4;
	mm[cb('\\', false)] = 2;
	mm[cb('\\', true)] = 6;

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> str[i];
		}

		int res = 0;
		for (int k = 0; k < (1 << (n * m)); ++k) {
			memset(table, 0, sizeof(table));
			bool ok = true;
			for (int i = 0; i < n && ok; ++i) {
				for (int j = 0; j < m && ok; ++j) {
					int v = (i * m) + j;
					bool s = ((1 << v) & k) > 0;
					int d = mm[cb(str[i][j], s)];
					int x = (i + dx[d] + n) % n;
					int y = (j + dy[d] + m) % m;
					table[x][y] += 1;
					if (table[x][y] > 1) {
						ok = false;
					}
				}
			}
			if (ok) res += 1;
		}
		printf("Case #%d: %d\n", tt, res);
	}

    return 0;
}