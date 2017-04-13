#include <stdio.h>
#include <string.h>
char s[5555][22];
char ss[2222];
char mark[22][33];

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int i, j, l, d, n, prob = 0, ans;
	char start;
	scanf("%d%d%d", &l, &d, &n);
	for (i = 0; i < d; i++) {
		scanf("%s", s[i]);
	}
	while (n--) {
		memset(mark, 0, sizeof(mark));
		scanf("%s", ss);
		start = true;
		for (i = j = 0; ss[i]; i++) {
			if (ss[i] == '(') {
				j++;
				start = false;
				continue;
			}
			if (ss[i] == ')') {
				start = true;
				continue;
			}
			if (start) {
				j++;
				mark[j][ss[i] - 'a'] = 1;
			} else {
				mark[j][ss[i] - 'a'] = 1;
			}
		}		
		if (j != l) {
			printf("Case #%d: 0\n", ++prob);
		} else {
			ans = 0;
			for (i = 0; i < d; i++) {
				for (j = 1; j <= l; j++) {
					if (!mark[j][s[i][j-1] - 'a']) break;
				}
				if (j > l) ans++;
			}
			printf("Case #%d: %d\n", ++prob, ans);
		}
	}
	return 0;
}
