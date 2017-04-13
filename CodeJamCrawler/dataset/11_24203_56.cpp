#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

struct walkway {
	int b;
	int e;
	int w;

	bool operator < (const walkway & y) const {
	if (w == y.w)
		return (y.e - y.b) < (e - b);
	return w < y.w;
	}
};

walkway w[1000001];

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	rep(tc, t) {
		int x, s, r, T, n;
		scanf("%d %d %d %d %d", &x, &s, &r, &T, &n);
		double rt = T;
		int pe = 0;
		double time = 0;
		rep(i, n) {
			scanf("%d %d %d", &w[i].b, &w[i].e, &w[i].w);
		}
		rep(i, n) {
			int l = w[i].b - pe;
			if (rt > 0 && l <= r * rt) {
				double cur = l / (double)r;
				time += cur;
				rt -= cur;
			} else {
				double cur = rt + (l - r * rt) / (double)s;
				time += cur;
				rt = 0;
			}
			pe = w[i].e;
		}
		int l = x - pe;
		if (rt > 0 && l <= r * rt) {
			double cur = l / (double)r;
			time += cur;
			rt -= cur;
		} else {
			double cur = rt + (l - r * rt) / (double)s;
			time += cur;
			rt = 0;
		}
		sort(w, w + n);
		rep(i, n) {
			int l = w[i].e - w[i].b;
			if (rt > 0 && l <= (r + w[i].w) * rt) {
				double cur = l / (double)(r + w[i].w);
				time += cur;
				rt -= cur;
			} else {
				double cur = rt + (l - (r + w[i].w) * rt) / (double)(s + w[i].w);
				time += cur;
				rt = 0;
			}
		}
		printf("Case #%d: %.9lf\n", tc + 1, time);
	}
}