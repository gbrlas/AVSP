#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 10;

struct node {
	int b, e, w;
};

node a[maxn * 3];
int t, x, s, r, n;

bool cmp(node i, node j) {
	return i.b < j.b;
}

double save_time(node x) {
	double walk = (x.e - x.b) / (double)(x.w + s);
	double run = (x.e - x.b) / (double)(x.w + r);
	if (run > t) {
		double left = (x.e - x.b) - t * (x.w + r);
		run = t + left / (double)(x.w + s);
	}
	return walk - run;
}

bool cmp2(node i, node j) {
	//return save_time(i) > save_time(j);
	return i.w + s < j.w + s;
}

int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	//freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d%d%d%d%d", &x, &s, &r, &t, &n);
		for (int i = 0; i < n; ++i) scanf("%d%d%d", &a[i].b, &a[i].e, &a[i].w);

		sort(a, a + n, cmp);

		int last = 0, m = n;
		for (int i = 0; i < n; ++i) {
			if (last < a[i].b) {
				a[m].b = last; a[m].e = a[i].b; a[m++].w = 0;
			}
			last = a[i].e;
		}
		if (last < x) {
			a[m].b = last; a[m].e = x; a[m++].w = 0;
		}

		sort(a, a + m, cmp2);
		//for (int i = 0; i < m; ++i) printf("%d %d %d\n", a[i].b, a[i].e, a[i].w); return 0;
		double ans = 0, used = 0;
		for (int i = 0; i < m; ++i) {
			if (used < t) {
				double run = (a[i].e - a[i].b) / (double)(a[i].w + r);
				if (used + run > t) {
					double left = (a[i].e - a[i].b) - (t - used) * (a[i].w + r);
					run = (t - used) + left / (double)(a[i].w + s);
					ans += run;
					used = t;
				}
				else {
					ans += run;
					used += run;
				}
			}
			else ans += (a[i].e - a[i].b) / (double)(a[i].w + s);
		}

		printf("Case #%d: %.8lf\n", nCase, ans);
	}

	return 0;
}
