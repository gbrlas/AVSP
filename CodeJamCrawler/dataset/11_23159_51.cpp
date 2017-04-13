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


const int MAX = (int)1e6;
bool v[MAX];
vector<int> primes;

void createPrimes() {
	for (int i = 2; i <= MAX; ++i) {
		if (!v[i]) {
			primes.pb(i);
			for (int j = i; j < MAX; j += i) {
				v[j] = true;
			}
		}
	}
}

int main()
{
    initialize();

	createPrimes();

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		int64 n;
		cin >> n;
		int res;
		if (n == 1) {
			res = 0;
		}
		else {
			res = 1;
			for (int i = 0; i < primes.size() && primes[i] <= n; ++i) {
				int64 p = primes[i];
				int c = 0;
				while (p <= n) {
					c += 1;
					p *= primes[i];
				}
				if (c > 0) {
					res += c - 1;
				}
			}
		}
		printf("Case #%d: %d\n", tt, res);
	}

    return 0;
}