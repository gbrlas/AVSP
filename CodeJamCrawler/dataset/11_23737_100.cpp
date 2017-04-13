#include <cstdio>
using namespace std;

int main() {
	int casenum, min, in, n, sum, x;
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &casenum);
	for (int ca = 1; ca <= casenum; ca++) {
		scanf("%d", &n);
		min = 1000000000;
		sum = 0;
		x = 0;
		while (n--) {
			scanf("%d", &in);
			x ^= in;
			sum += in;
			min <?= in;
		}
		printf("Case #%d: ", ca);
		if (x) printf("NO\n");
		else printf("%d\n", sum - min);
	}
	return 0;
}
