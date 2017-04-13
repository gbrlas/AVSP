#include <cstdio>
#include <string>
using namespace std;

const int MAXN = 128;
int casenum, L, H, n, note[MAXN];

int main() {
	int ans;
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &casenum);
	for (int ca = 1; ca <= casenum; ca++) {
		scanf("%d %d %d", &n, &L, &H);
		for (int i = 0; i < n; i++) scanf("%d", &note[i]);
		ans = -1;
		for (int i = L; i <= H; i++) {
			bool found = true;
			for (int j = 0; j < n; j++) {
				if (note[j] > i && note[j] % i != 0) {
					found = false;
					break;
				}
				else if (note[j] <= i && i % note[j] != 0) {
					found = false;
					break;
				}
			}
			if (found) {
				ans = i; 
				break;
			}
		}
		printf("Case #%d: ", ca);
		if (-1 == ans) printf("NO\n");
		else printf("%d\n", ans);
	}
	return 0;
}
