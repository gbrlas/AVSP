#include <cstdio>
#include <cstring>

using namespace std;

const int MAXL = 16;
const int MAXD = 5000;

char words[MAXD][MAXL];

int main() {
	int l, d, n;
	scanf("%d%d%d", &l, &d, &n);
	for (int i = 0; i < d; i++) {
		scanf("%s", words[i]);
	}
	bool tags[MAXL][128];
	for (int caseIndex = 1; caseIndex <= n; caseIndex++) {
		while (getchar() != '\n');
		for (int i = 0; i < l; i++) {
			memset(tags[i] + 'a', false, sizeof(bool) * 26);
			char ch = getchar();
			if (ch == '(') {
				while ((ch = getchar()) != ')') {
					tags[i][ch] = true;
				}
			} else {
				tags[i][ch] = true;
			}
		}
		int ans = 0;
		for (int i = 0; i < d; i++) {
			bool isOk = true;
			for (int j = 0; j < l; j++) {
				if (!tags[j][words[i][j]]) {
					isOk = false;
					break;
				}
			}
			if (isOk) {
				ans++;
			}
		}
		printf("Case #%d: %d\n", caseIndex, ans);
	}
	
	return 0;
}
