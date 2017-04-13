#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = 1000;
const double INF = 1e100;
const double EPS = 1e-8;

class Ship {
public:
	double x, y, z;
	double p;

	inline void read() {
		scanf("%lf%lf%lf%lf", &x, &y, &z, &p);
	}
};

const int COEF[8][3] = {
	{1, 1, 1},
	{1, -1, 1},
	{-1, 1, 1},
	{-1, -1, 1},
	{1, 1, -1},
	{1, -1, -1},
	{-1, 1, -1},
	{-1, -1, -1}
};

const int SIGN[8] = {1, 1, 1, 1, -1, -1, -1, -1};

int n;
Ship ships[MAXN];

inline bool check(double res) {
	double ds[8];
	for (int i = 0; i < 8; i++) {
		ds[i] = INF;
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 8; k++) {
			ds[k] = min(ds[k], COEF[k][0] * ships[i].x + COEF[k][1] * ships[i].y + COEF[k][2] * (ships[i].z + res * ships[i].p * SIGN[k]));
		}
		for (int k = 0; k < 4; k++) {
			double z1 = ds[k] / SIGN[k];
			double z2 = ds[7 - k] / SIGN[7 - k];
			if (z1 < z2 - EPS) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			ships[i].read();
		}
		double left = 0.0, right = 2e6;
		while (true) {
			double middle = (left + right) / 2.0;
			if (middle - left < EPS || right - middle < EPS) {
				break;
			}
			if (check(middle)) {
				right = middle;
			} else {
				left = middle;
			}
		}
		printf("Case #%d: %.7lf\n", caseIndex, right);
	}

	return 0;
}
