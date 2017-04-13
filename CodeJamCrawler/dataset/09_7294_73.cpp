#include <stdio.h>
#include <string.h>
int n, m, len;
char s[100];
int b[128];
int main() {
	freopen("CA.out", "w", stdout);
	scanf("%d", &n);
	for(int t = 0; t < n; ++t) {
		printf("Case #%d: ", t + 1);
		scanf("%s", s);
		memset(b, 0, sizeof(b));
		len = strlen(s);
		m = 0;
		for(int i =0; i < len; ++i) {
			if(!b[s[i]]) {
				b[s[i]] = 1;
				++m;
			}
		}
		memset(b, -1, sizeof(b));
		if(m < 2) m = 2;
		__int64 ans = 0, w = 1;
		for(int i = 0; i < len; ++i) w *= m;
		w /= m;
		b[s[0]] = 1;
		ans += w;
		w /= m;
		for(int i = 1, j = 0; i < len; ++i) {
			if(b[s[i]] == -1) {
				b[s[i]] = j;
				if(j == 0) j = 2;
				else ++j;
			}
			ans += b[s[i]] * w;
			w /= m;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
