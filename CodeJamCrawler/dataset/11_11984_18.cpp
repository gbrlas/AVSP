#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef double real;

#define _N 1024

int  cases, n;
real x, s, r, t;
struct Walkway {
	real b, e, w;
	bool operator < (const Walkway &b) const {
		return w < b.w;
	}
};
Walkway data[_N];

int main() {
//	freopen("A-small-attempt1.in", "r", stdin);
//	freopen("A-small-attempt1.out", "w", stdout);
	scanf("%d", &cases);
	for(int I = 1; I <= cases; ++I) {
		scanf("%lf%lf%lf%lf%d", &x, &s, &r, &t, &n);
		real totallen = 0.0;
		int i;
		for(i = 0; i < n; ++i) {
			scanf("%lf%lf%lf", &data[i].b, &data[i].e, &data[i].w);
			totallen += (data[i].e - data[i].b);
		}
		data[n].b = 0.0;
		data[n].e = x - totallen;
		data[n++].w = 0.0;
		sort(data, data + n);

		real cnt = 0.0;
		for(i = 0; i < n && t > 1e-8; ++i) {
			if(t * (data[i].w + r) >= data[i].e - data[i].b) {
				cnt += (data[i].e - data[i].b) / (data[i].w + r);
				t -= (data[i].e - data[i].b) / (data[i].w + r);
			}
			else {
				cnt += t + ((data[i].e - data[i].b - t * (data[i].w + r)) / (data[i].w + s));
				t = 0.0;
			}
		}
		for(; i < n; ++i)
			cnt += (data[i].e - data[i].b) / (data[i].w + s);
		printf("Case #%d: %.7lf\n", I, cnt);
	}
	return 0;
}
