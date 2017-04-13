#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, bool> PIB;

const int MAXM = 2000;

vector<PIB> req[MAXM];

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			int t;
			scanf("%d", &t);
			req[i].resize(t);
			for (int j = 0; j < t; j++) {
				int k, b;
				scanf("%d%d", &k, &b);
				req[i][j] = PIB(k - 1, b == 1);
			}
		}
		int ans = -1;
		int ansCnt = n + 1;
		const int size = 1 << n;
		for (int mask = 0; mask < size; mask++) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (mask & (1 << i)) {
					cnt++;
				}
			}
			if (cnt < ansCnt) {
				bool isOk = true;
				for (int j = 0; j < m; j++) {
					bool curOk = false;
					for (int k = 0; k < req[j].size(); k++) {
						if (req[j][k].second) {
							if (mask & (1 << req[j][k].first)) {
								curOk = true;
								break;
							}
						} else {
							if ((mask & (1 << req[j][k].first)) == 0) {
								curOk = true;
								break;
							}
						}
					}
					if (!curOk) {
						isOk = false;
						break;
					}
				}
				if (isOk) {
					ansCnt = cnt;
					ans = mask;
				}
			}
		}
		printf("Case #%d:", caseIndex);
		if (ans == -1) {
			puts(" IMPOSSIBLE");
		} else {
			for (int i = 0; i < n; i++) {
				if (ans & (1 << i)) {
					printf(" 1");
				} else {
					printf(" 0");
				}
			}
			putchar('\n');
		}
	}
	
	return 0;
}
