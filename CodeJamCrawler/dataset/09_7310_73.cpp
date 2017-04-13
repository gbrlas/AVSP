#include <stdio.h>
#include <stdlib.h>
typedef int(*CMP)(const void *, const void *);
int n, m;
int s[100];
int cmp(int* a, int* b) {
	return *a - *b;
}
int f(int x) {
	int ans = 0;
	if(x == 0) ans += s[x] - 1;
	else ans += s[x] - s[x - 1] - 1;
	if(x == m - 1) ans += n - s[x];
	else ans += s[x + 1] - s[x];
	return ans;
} 

int main() {
	int t;
	scanf("%d", &t);
	for(int tt = 1; tt <= t; ++tt) {
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; ++i) scanf("%d", s + i);
		int ans = 0;
		while(m) {
			qsort(s, m, sizeof(s[0]), (CMP)cmp);
			//for(int i = 0; i < m; ++i) printf("%d ", s[i]);
			//puts("");
			int x = 0;
			for(int j = 1; j < m; ++j) {
				if(f(j) < f(x)) x = j;
			}
			ans += f(x);
			printf("%d %d\n", s[x], f(x));
			s[x] = s[m - 1];
			--m;
		}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
