#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXK = 5;
const int MAX_LEN = 1024;

char str[MAX_LEN];

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int k;
		scanf("%d%s", &k, str);
		const int len = strlen(str);
		int perm[MAXK];
		for (int i = 0; i < k; i++) {
			perm[i] = i;
		}
		int ans = len;
		do {
			char last = '\0';
			int cnt = 0;
			for (int j = 0; j * k < len; j++) {
				for (int i = 0; i < k; i++) {
					if (str[j * k + perm[i]] != last) {
						last = str[j * k + perm[i]];
						cnt++;
					}
				}
			}
			ans = min(ans, cnt);
		} while (next_permutation(perm, perm + k));
		printf("Case #%d: %d\n", caseIndex, ans);
	}

	return 0;
}
