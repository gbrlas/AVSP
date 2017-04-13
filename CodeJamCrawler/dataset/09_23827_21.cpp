#pragma warning(disable:4786)
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <queue>
using namespace std;
struct Node {
	int x[6], y[6], s;
};
set <__int64> se;
queue <Node> q;
char g[22][22];
int num, r, c;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int myabs(int x) { return x < 0 ? -x : x; }

bool check(Node t) {
	int i;
	for (i = 0; i < num; i++) {
		if (g[t.x[i]][t.y[i]] != 'x') return false;
	}
	return true;
}

__int64 getHash(Node t) {
	int i, j, tint;
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (t.x[i] > t.x[j] || t.x[i] == t.x[j] && t.y[i] > t.y[j]) {
				tint = t.x[i], t.x[i] = t.x[j], t.x[j] = tint;
				tint = t.y[i], t.y[i] = t.y[j], t.y[j] = tint;
			}
		}
	}
	__int64 p = 1, ret = 0;
	for (i = 0; i < num; i++) {
		ret += p * t.x[i] + p * 12 * t.y[i];
		p *= 144;
	}
	return ret;
}

bool checkDan(Node st) {
	int i, qq[7], ff, rr;
	char mm[7];
	memset(mm, 0, sizeof(mm));
	ff = rr = 0;
	qq[++rr] = 0;
	mm[0] = 1;
	while (++ff <= rr) {
		for (i = 0; i < num; i++) {
			if (!mm[i] &&
				myabs(st.x[i]-st.x[qq[ff]])+myabs(st.y[i]-st.y[qq[ff]]) == 1) {
				mm[i] = 1;
				qq[++rr] = i;
			}
		}
	}
	return rr == num ? false : true;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int tn, i, j, k, prob = 0;
	Node st, nt;
	for (scanf("%d", &tn); tn--; ) {
		printf("Case #%d: ", ++prob);
		while (!q.empty()) q.pop();
		se.clear();
		scanf("%d%d", &r, &c);
		for (i = 0; i < r; i++) scanf("%s", g[i]);
		k = 0;
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				if (g[i][j] == 'o') {
					st.x[k] = i, st.y[k] = j;
					k++;
				} else if (g[i][j] == 'w') {
					st.x[k] = i, st.y[k] = j;
					k++;
					g[i][j] = 'x';
				}
			}
		}
		num = k;
		if (check(st)) {
			printf("0\n");
			continue;
		}
		se.insert(getHash(st));
		st.s = 0;
		q.push(st);
		__int64 hx;
		int k, tx, ty, ans = -1;
		int ttx, tty;
		bool dan;
		while (!q.empty()) {
			st = q.front(), q.pop();
			dan = checkDan(st);
			for (i = 0; i < num; i++) {
				for (k = 0; k < 4; k++) {
					tx = st.x[i] + dx[k], ty = st.y[i] + dy[k];
					ttx = st.x[i] + dx[(k+2)%4], tty = st.y[i] + dy[(k+2)%4];
					if (tx < 0 || ty < 0 || tx >= r || ty >= c) continue;
					if (ttx < 0 || tty < 0 || ttx >= r || tty >= c) continue;
					if (g[tx][ty] == '#' || g[ttx][tty] == '#') continue;
					for (j = 0; j < num; j++) {
						if (myabs(st.x[j] - tx) + myabs(st.y[j] - ty) == 0) break; 
					}
					if (j < num) continue;
					for (j = 0; j < num; j++) {
						if (myabs(st.x[j] - ttx) + myabs(st.y[j] - tty) == 0) break; 
					}
					if (j < num) continue;
					nt = st;
					nt.x[i] = tx, nt.y[i] = ty;
					nt.s++;
					if (dan && checkDan(nt)) continue;
					if (check(nt)) {
						ans = nt.s;
						break;
					}
					hx = getHash(nt);
					if (se.find(hx) == se.end()) {
						se.insert(hx);
						q.push(nt);
					}
				}
				if (ans != -1) break;
			}
			if (ans != -1) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
