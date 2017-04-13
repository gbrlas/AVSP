#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
	freopen("B-small.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	rep(tc, t) {
		int l, t, n, c;
		scanf("%d %d %d %d", &l, &t, &n, &c);
		int a[1000];
		rep(i, c)
			scanf("%d", &a[i]);
		list<int> d;
		rep(i, n)
			d.push_back(a[i % c]);
		int total = 0;
		while (t > 0 && !d.empty()) {
			if (t >= *d.begin() * 2) {
				t -= *d.begin() * 2;
				total += *d.begin() * 2;
				d.pop_front();
			} else {
				*d.begin() -= t / 2;
				total += t;
				t = 0;
			}
		}
		d.sort();
		d.reverse();
		while (l > 0 && !d.empty()) {
			total += *d.begin();
			d.pop_front();
			--l;
		}
		for (list<int>::iterator it = d.begin(); it != d.end(); ++it) {
			total += *it * 2;
		}
		printf("Case #%d: %d\n", tc + 1, total);
	}
}