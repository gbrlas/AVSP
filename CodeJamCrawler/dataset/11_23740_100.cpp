#include <cstdio>
#include <string>
using namespace std;

const int MAXN = 1024;
int casenum, n, s[MAXN];

int main() {
	double cnt;
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-small-attempt1.out", "w", stdout);
	scanf("%d", &casenum);
	for (int ca = 1; ca <= casenum; ca++) {
		cnt = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", s+i);
			if (s[i] != i) cnt++;
		}
		printf("Case #%d: %.6lf\n", ca, cnt);
	}
	return 0;
}
