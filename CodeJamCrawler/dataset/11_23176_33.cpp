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

bool isSqr(int64 a) {
	int64 num = max((int64)0, int64(sqrt(double(a))) - 10);
	for (int i = 0; i < 20; ++i) {
		if (sqr(num + i) == a) return true;
	}
	return false;
}

int main()
{
    initialize();

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		string s;
		cin >> s;
		vector<int> pos;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '?') pos.pb(i);
		}

		string rr;
		for (int m = 0; m < (1 << (pos.size())); ++m) {
			string k = s;
			for (int i = 0; i < pos.size(); ++i) {
				k[pos[i]]= ((m & (1 << i)) > 0) ? '1' : '0';
			}
			int64 res = 0;
			for (int i = 0; i < k.size(); ++i) {
				res = res * 2;
				if (k[i] == '1') res += 1;
			}
			if (isSqr(res)) {
				rr = k;
				break;
			}
		}
		printf("Case #%d: %s\n", tt, rr.c_str());
	}

    return 0;
}