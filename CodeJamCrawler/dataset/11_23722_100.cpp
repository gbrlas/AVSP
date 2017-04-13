#include <cstdio>
#include <string>
using namespace std;

struct SS {
	int la;
	int p;
} rob[128];

int tim[2], pp[2], casenum, op, cur;

int main() {
	char str[2];
	int pos, t;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &casenum);
	for (int ca = 1; ca <= casenum; ca++) {
		scanf("%d", &op);
		for (int i = 0; i < op; i++) {
			scanf("%s%d", str, &pos);
			rob[i].la = (str[0] == 'O') ? 0 : 1;
			rob[i].p = pos;
		}
		memset(tim, 0, sizeof(tim));
		pp[0] = pp[1] = 1;
		cur = rob[0].la;
		t = 0;
		while (t < op) {
			if (rob[t].la == cur) {
				tim[cur] += abs(rob[t].p - pp[cur]) + 1;
				pp[cur] = rob[t].p;
			} else {
				int ti = abs(rob[t].p - pp[cur^1]);
				tim[cur^1] = max(tim[cur^1]+ti, tim[cur]) + 1;
				pp[cur^1] = rob[t].p;
				cur ^= 1;
			}
			t++;
		}
		printf("Case #%d: %d\n", ca, max(tim[0], tim[1]));

	}
	return 0;
}
