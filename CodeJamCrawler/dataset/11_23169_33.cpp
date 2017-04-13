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
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
}

struct Point
{
    int x;
    int y;
    Point(int x_, int y_): x(x_), y(y_)
    { }
};

const int MAX = 10000 + 10;
int mas[MAX];
int has[MAX];

bool solve(const vector<int>& numbers, int l) {
	map<int, int> ends;
	memset(has, 0, sizeof(has));
	for (int i = 0; i < numbers.size(); ++i) {
		if (has[numbers[i]] == mas[numbers[i]]) continue;
		int b = numbers[i];
		while (has[b] != mas[b] && (b - numbers[i] + 1) < l) {
			b += 1;
		}
		if ((b - numbers[i] + 1) == l && has[b] != mas[b]) {
			for (int j = numbers[i]; j <= b; ++j) {
				has[j] += 1;
			}
			ends[b] += 1;
		}
		else {
			if (ends[numbers[i] - 1] == 0) {
				return false;
			}
			ends[numbers[i] - 1] -= 1;
			ends[numbers[i]] += 1;
			has[numbers[i]] += 1;
		}
	}
	return true;
}

int main()
{
    initialize();

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		memset(mas, 0, sizeof(mas));
		int n;
		cin >> n;
		vector<int> numbers(n);
		for (int i = 0; i < n; ++i) {
			cin >> numbers[i];
			mas[numbers[i]] += 1;
		}
		sort(all(numbers));

		int res = 0;

		if (numbers.size() > 0) {
			int down = 1, up = n + 1;
			while(up - down > 1) {
				int med = (down + up) / 2;
				if (solve(numbers, med)) {
					down = med;
				}
				else {
					up = med;
				}
			}
			res = down;
		}
		printf("Case #%d: %d\n", tt, res);
	}

    return 0;
}