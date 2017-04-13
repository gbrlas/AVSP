#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct A {
	int ind;
	int d;
	int dir;
	A(int _i = 0, int _d = 0, int _di = 0) : ind(_i), d(_d), dir(_di) {
	}
	bool operator < (const A &rhs) const {
		return d < rhs.d;
	}
};

int f(int a, int b) {
	if (b > a)
		return a;
	else
		return b;
}

int main() {
	int ecase, ecount;
	int en;
	int ed[60000], el[60000];
	int edd;
	int l[60000], r[60000];

	
	scanf("%d", &ecase);
	for (ecount = 1; ecount <= ecase; ecount++) {
		scanf("%d", &en);
		for (int i = 0; i < en; i++) {
			scanf("%d%d", &ed[i], &el[i]);
			l[i] = 0;
			r[i] = 0;
		}
		scanf("%d", &edd);

		priority_queue<A> que;
		que.push( A(0, ed[0], 1) );
		l[0] = ed[0];

		bool ans = false;
		while (que.empty() == false && ans == false) {
			A focus = que.top();
			que.pop();

			//printf("%d %d %d\n", focus.ind, focus.d, focus.dir);

			if (focus.dir == 1) {
				if (focus.d + ed[ focus.ind ] >= edd) {
					ans = true;
					break;
				}

				for (int i = focus.ind - 1; i >= 0; i--) {
					if (focus.d < ed[focus.ind] - ed[i])
						break;
					int td = f(ed[focus.ind]-ed[i], el[i]);
					if (td > r[i]) {
						r[i] = td;
						que.push( A(i, td, 0) );
					}
				}
				for (int i = focus.ind + 1; i < en; i++) {
					if (focus.d < ed[i] - ed[focus.ind])
						break;
					int td = f(ed[i]-ed[focus.ind], el[i]);
					if (td > l[i]) {
						l[i] = td;
						que.push( A(i, td, 1) );
					}
				}
			}
			else {
				for (int i = focus.ind - 1; i >= 0; i--) {
					if (focus.d < ed[focus.ind] - ed[i])
						break;
					int td = f(ed[focus.ind]-ed[i], el[i]);
					if (td > l[i]) {
						l[i] = td;
						que.push( A(i, td, 0) );
					}
				}
				for (int i = focus.ind + 1; i < en; i++) {
					if (focus.d < ed[i] - ed[focus.ind])
						break;
					int td = f(ed[i]-ed[focus.ind], el[i]);
					if (td > r[i]) {
						r[i] = td;
						que.push( A(i, td, 1) );
					}
				}
			}
		}

		if (ans)
			printf("Case #%d: YES\n", ecount);
		else
			printf("Case #%d: NO\n", ecount);
	}

	return 0;
}
