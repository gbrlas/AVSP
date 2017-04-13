#include <cstdio>
#include <string>
using namespace std;

int casenum;
int n, pd, pg;

int main() {
	int D, G, win, lose;
	bool ok;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &casenum);
	for (int ca = 1; ca <= casenum; ca++) {
		scanf("%d %d %d", &n, &pd, &pg);
		ok = false;
		for (D = 1; D <= n; D++) {
			if (pd * D % 100 == 0) {
				win = pd * D / 100;
				lose = D - win;
				if (pg * 10 >= win && (100-pg) * 10 >= lose) ok = true;
			}
		}
		printf("Case #%d: ", ca);
		if (ok) puts("Possible");
		else puts("Broken");
	}
	return 0;
}
