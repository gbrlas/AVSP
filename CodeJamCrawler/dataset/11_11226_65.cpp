#include <stdio.h>

int n, l, h;
int in[200];

int isOK(int x) {
	for(int i = 0; i < n; ++i) {
		if(x > in[i]) {
			if(x % in[i]) return 0;
		} else {
			if(in[i] % x) return 0;
		}
	}
	return 1;
}

int solve() {
	for(int i = l; i <= h; ++i) {
		if(isOK(i)) {
			printf("%d\n", i);
			return 1;
		}
	}
	return 0;
}
int main() {
	int t;
	freopen("C-small-attempt0.in", "r", stdin); freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		scanf("%d %d %d", &n, &l, &h);
		for(int i = 0; i < n; ++i) scanf("%d", in + i);
		printf("Case #%d: ", tt + 1);
		if(!solve()) {
			puts("NO");
		}
	}	
	return 0;
}
