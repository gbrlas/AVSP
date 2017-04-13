#include <stdio.h>

int n, now, in[100], ans;

int solve() {
	int ret = 0;
	for(int i = 0; i < n - 1; ++i) {
		if(in[i] > i) {
			int j;
			for(j = i + 1; j < n; ++j) {
				if(in[j] <= i) break;			
			}
			int tmp = in[j];
			for(int l = j; j > i; --j) {
				in[j] = in[j - 1];
				++ret;
			}
			in[i] = tmp;
		}
	}
	return ret;
}

int main() {
	int t, x;
	char s[100];
	freopen("AS.txt", "w", stdout);
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%s", s);
			in[i] = 0;
			for(int j = 0; j < n; ++j) {
				if(s[j] == '1') in[i] = j;
			}
			//printf("%d\n", in[i]);
		}
		
		//ans = n * n * 2;
		//now = 0;
		ans = solve();
		printf("Case #%d: %d\n", tt + 1, ans);
	
	}
	return 0;
}
