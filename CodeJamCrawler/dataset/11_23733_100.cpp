#include <cstdio>
#include <string>
using namespace std;

const int MAXN = 128;
char com[MAXN][MAXN];
int opp[MAXN][MAXN];
int casenum;
char ans[128];
int tp, n;

int main() {
	char str[128];
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &casenum);
	for (int ca = 1; ca <= casenum; ca++) {
		memset(com, 0, sizeof(com));
		memset(opp, 0, sizeof(opp));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			com[str[0]][str[1]] = str[2];
			com[str[1]][str[0]] = str[2];
		}
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			opp[str[0]][str[1]] = 1;
			opp[str[1]][str[0]] = 1;
		}
		scanf("%d", &n);
		scanf("%s", str);
		tp = 0;
		for (int i = 0; i < n; i++) {
			ans[tp++] = str[i];
			while (tp > 1 && com[ans[tp-1]][ans[tp-2]] != 0) {
				ans[tp-2] = com[ans[tp-1]][ans[tp-2]];
				tp--;
			}
			for (int j = 0; j < tp; j++) {
				if (opp[ans[j]][ans[tp-1]]) {
					tp = 0;
					break;
				}
			}
/*
			if (tp > 0 && com[ans[tp-1]][str[i]] != 0) {
				ans[tp-1] = com[ans[tp-1]][str[i]];
			} else {
				int indx = -1;
				for (int j = 0; j < tp; j++) {
					if (opp[ans[j]][str[i]]) {
						indx = j;
						break;
					}
				}
				if (-1 != indx) {
					tp = indx;
				} else {
					ans[tp++] = str[i];
				}
			}
*/
		}

		printf("Case #%d: [", ca);
		for (int i = 0; i < tp; i++) {
			if (i > 0) printf(", ");
			printf("%c", ans[i]);
		}
		puts("]");
	}
	return 0;
}
