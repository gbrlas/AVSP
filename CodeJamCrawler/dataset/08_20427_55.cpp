#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int sx, sy, a;
		scanf("%d%d%d", &sx, &sy, &a);
		printf("Case #%d:", caseIndex);
		try {
			for (int x1 = 0; x1 <= sx; x1++) {
				for (int y1 = 0; y1 <= sy; y1++) {
					for (int x2 = 0; x2 <= sx; x2++) {
						for (int y2 = y1; y2 <= sy; y2++) {
							if (x1 * y2 != x2 * y1) {
								int up, down;
								if (x2 == 0) {
									up = 0;
									down = 1;
								} else {
									up = x2 * y1;
									down = y2;
								}
								up = abs(down * x1 - up);
								if ((long long) a * down == (long long) up * y2) {
									vector<int> ans(4);
									ans[0] = x1;
									ans[1] = y1;
									ans[2] = x2;
									ans[3] = y2;
									throw ans;
								}
							}
						}
					}
				}
			}
			puts(" IMPOSSIBLE");
		} catch (const vector<int> & ans) {
			printf(" 0 0");
			for (int i = 0; i < 4; i++) {
				printf(" %d", ans[i]);
			}
			putchar('\n');
		}
	}
	
	return 0;
}
