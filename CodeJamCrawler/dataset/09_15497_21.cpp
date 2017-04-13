#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

#define sz 50

struct plant{
	int x, y, r;
};
plant d[sz];

double dis(const plant &a, const plant &b) {
	double tmp = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return sqrt(tmp);
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int ncs = 1; ncs <= t; ncs ++) {
		printf("Case #%d: ", ncs);
		int n, i, j, k;
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d %d %d", &d[i].x, &d[i].y, &d[i].r);
		}
		double ret;
		if(n == 1) ret = d[0].r;
		else if(n == 2) ret = max(d[0].r, d[1].r);
		else {
			double d1, d2, ftmp;
			ret = 3000000000000.0;
			for(i = 0; i < n; i++) {
				for(j = i + 1; j < n; j++) {
					d1 = dis(d[i], d[j]) + (double)(d[i].r + d[j].r);
					d1 /= 2.0;
					for(k = 0; k < n; k++) {
						if(k == i || k == j) continue;
						d2 = (double) d[k].r;
					}
					ftmp = max(d1, d2);
					ret = min(ret, ftmp);
				}
			}
		}
		printf("%lf\n", ret);
	}
	return 0;
}
