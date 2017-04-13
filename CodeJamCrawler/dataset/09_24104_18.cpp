#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int x[5], y[5], r[5];

double find(int x1, int y1, int r1, int x2, int y2, int r2) {
	if(r2 > r1) {
		swap(x1, x2);
		swap(y1, y2);
		swap(r1, r2);
	}

	double dist = sqrt(0.0+(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

	double f = r1+r2-dist;
	if(f > 2*r2) {
		return 2*r1;
	}

	return dist+r1+r2;
}

int main(void) {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, j, k, t;


	scanf("%d", &t);
	for(int T = 1; T <= t; T++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d%d%d", &x[i], &y[i], &r[i]);
		}

		printf("Case #%d: ", T);
		if(n == 1) {
			printf("%.6f\n", 0.0+r[0]);
			continue;
		}
		if(n == 2) {
			printf("%.6f\n", 0.0+max(r[0], r[1]));
			continue;
		}

		double sol = -1.0;
		for(i = 0; i < 3; i++) {
			for(j = i+1; j < 3; j++) {
				double R = max(0.0+r[3-i-j], 0.5*find(x[i], y[i], r[i], x[j], y[j], r[j]));
				if(sol == -1.0 || sol > R) {
					sol = R;
				}
			}
		}
		printf("%.6f\n", sol);
	}

	exit(0);
}