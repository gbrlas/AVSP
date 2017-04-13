#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

const int MAXN = 40;
const double EPSB = 1e-7;
const double EPS = 1e-8;

struct Point {
	double x, y;
};

inline double dis(const Point & a, const Point & b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

Point intersection(const Point & u1, const Point & u2, const Point & v1, const Point & v2) {
	Point ret = u1;
	double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) / ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
	ret.x += (u2.x - u1.x) * t;
	ret.y += (u2.y - u1.y) * t;
	return ret;
}

void intersectionLineCircle(const Point & c, double r, const Point & l1, const Point & l2, Point & p1, Point & p2) {
	Point p = c;
	p.x += l1.y - l2.y;
	p.y += l2.x - l1.x;
	p = intersection(p, c, l1, l2);
	double t = sqrt(r * r - dis(p, c) * dis(p, c)) / dis(l1, l2);
	p1.x = p.x + (l2.x - l1.x) * t;
	p1.y = p.y + (l2.y - l1.y) * t;
	p2.x = p.x - (l2.x - l1.x) * t;
	p2.y = p.y - (l2.y - l1.y) * t;
}

void intersectionCircleCircle(const Point & c1, double r1, const Point & c2, double r2, Point & p1, Point & p2) {
	Point u, v;
	double t = (1 + (r1 * r1 - r2 * r2) / dis(c1, c2) / dis(c1, c2)) / 2;
	u.x = c1.x + (c2.x - c1.x) * t;
	u.y = c1.y + (c2.y - c1.y) * t;
	v.x = u.x + c1.y - c2.y;
	v.y = u.y - c1.x + c2.x;
	intersectionLineCircle(c1, r1, u, v, p1, p2);
}

int n;
Point center[MAXN];
double radius[MAXN];

inline bool check(double value) {
	Point c1[2], c2[2];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (value - radius[i] > EPS && value - radius[j] > EPS && dis(center[i], center[j]) <= 2 * value - radius[i] - radius[j]) {
				intersectionCircleCircle(center[i], value - radius[i], center[j], value - radius[j], c1[0], c1[1]);
				for (int p = 0; p < n; p++) {
					if (p != i && p != j) {
						for (int d1 = 0; d1 < 2; d1++) {
							bool isOk = true;
							for (int k = 0; k < n; k++) {
								if (!(dis(center[k], c1[d1]) <= value - radius[k] + EPS || dis(center[k], center[p]) <= value - radius[k] + EPS)) {
									isOk = false;
									break;
								}
							}
							if (isOk) {
								return true;
							}
						}
						for (int q = p + 1; q < n; q++) {
							if (value - radius[p] > EPS && value - radius[q] > EPS && dis(center[p], center[q]) <= 2 * value - radius[i] - radius[j]) {
								intersectionCircleCircle(center[p], value - radius[p], center[q], value - radius[q], c2[0], c2[1]);
								for (int d1 = 0; d1 < 2; d1++) {
									for (int d2 = 0; d2 < 2; d2++) {
										bool isOk = true;
										for (int k = 0; k < n; k++) {
											if (!(dis(center[k], c1[d1]) <= value - radius[k] + EPS || dis(center[k], c2[d2]) <= value - radius[k] + EPS)) {
												isOk = false;
												break;
											}
										}
										if (isOk) {
											return true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}

int main() {
	freopen("D:\\Studio\\Algorithm\\Contest\\D-large.in", "r", stdin);
	freopen("D:\\Studio\\Algorithm\\Contest\\D-large.out2", "w+", stdout);
	int caseNum;
	cin >> caseNum;
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> center[i].x >> center[i].y >> radius[i];
		}
		double ans;
		if (n == 1) {
			ans = radius[0];
		} else if (n == 2) {
			ans = max(radius[0], radius[1]);
		} else {
			double left = radius[0];
			for (int i = 1; i < n; i++) {
				left = max(left, radius[i]);
			}
			double right = 10000;
			int step = 0;
			while (step++ < 100) {
				double middle = (left + right) * 0.5;
				if (middle - left < EPSB || right - middle < EPSB) {
					break;
				}
				if (check(middle)) {
					right = middle;
				} else {
					left = middle;
				}
			}
			ans = right;
		}
		printf("Case #%d: %.6lf\n", caseIndex, ans);
	}

	return 0;
}
