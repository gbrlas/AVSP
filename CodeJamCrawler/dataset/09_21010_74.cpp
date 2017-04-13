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

const int MAXN = 3;

struct Point {
	double x, y;
};

inline double dis(const Point & a, const Point & b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

int main() {
	int caseNum;
	cin >> caseNum;
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int n;
		cin >> n;
		Point center[MAXN];
		double radius[MAXN];
		for (int i = 0; i < n; i++) {
			cin >> center[i].x >> center[i].y >> radius[i];
		}
		double ans;
		if (n == 1) {
			ans = radius[0];
		} else if (n == 2) {
			ans = max(radius[0], radius[1]);
		} else {
			ans = 1e100;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					double cur = (dis(center[i], center[j]) + radius[i] + radius[j]) * 0.5;
					cur = max(cur, radius[0 + 1 + 2 - i - j]);
					ans = min(ans, cur);
				}
			}
		}
		printf("Case #%d: %.6lf\n", caseIndex, ans);
	}

	return 0;
}
