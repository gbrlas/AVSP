#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

int map[1000][1000];




int findArea(int x1, int y1, int x2, int y2, int x3, int y3) {
	return abs((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1));
}

int main() {

	int tt, tn;
	cin >> tn;
	F1(tt,tn) {
		int n, m, A, isDone = 0;
		cin >> n >> m >> A;
		for (int i = 0; i <= n && !isDone; i++) {
					for (int p = 0; p <= m && !isDone; p++) {
						for (int r = 0; r <= n && !isDone; r++) {
							for (int s = 0; s <= m && !isDone; s++) {
								pii p1 = pii(i, 0);
								pii p2 = pii(0, p);
								pii p3 = pii(r, s);
								if (p1 == p2 || p1 == p3 || p2 == p3) continue;
								double area = findArea(i, 0, 0, p, r, s);
								if (area == A) {
									printf("Case #%d: %d %d %d %d %d %d\n", tt, i, 0, 0, p, r, s);
									isDone = 1;
								}
							}
						}
					}
		}
		if (!isDone)
			printf("Case #%d: IMPOSSIBLE\n", tt);
	}

	return 0;
}

