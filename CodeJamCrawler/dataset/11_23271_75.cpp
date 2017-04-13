#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define FILE_IN  "A-large.in"
#define FILE_OUT "A-large.out"

#define MAXN 103

int n;
char res[MAXN][MAXN];
double wp[MAXN];
double owp[MAXN];
double oowp[MAXN];
double rpi[MAXN];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf(" %s", res[i]);
	for (int i = 0; i < n; ++i) {
		int w = 0, t = 0;
		double owps = 0;
		for (int j = 0; j < n; ++j) if (res[i][j] != '.') {
			++t;
			if (res[i][j] == '1')
				++w;
			int ww = 0, tt = 0;
			for (int k = 0; k < n; ++k) if (res[j][k] != '.' && k != i) {
				++tt;
				if (res[j][k] == '1')
					++ww;
			}
			owps += (double) ww / tt;
		}
		wp[i] = (double) w / t;
		owp[i] = owps / t;
	}
	for (int i = 0; i < n; ++i) {
		int t = 0;
		double oowps = 0;
		for (int j = 0; j < n; ++j) if (res[i][j] != '.') {
			++t;
			oowps += owp[j];
		}
		oowp[i] = (double) oowps / t;
		rpi[i] = wp[i] / 4 + owp[i] / 2 + oowp[i] / 4;
	}
	for (int i = 0; i < n; ++i)
		printf("%.9lf\n", rpi[i]);
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d:\n", i);
		solve();
	}
	return 0;
}
