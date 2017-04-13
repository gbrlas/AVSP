#include <stdio.h>

int n, in[2000];


int solve() {
	int t = 0, min = in[0], sum = 0;
	for(int i = 0; i < n; ++i) {
		t ^= in[i];
		sum += in[i];
		if(min > in[i]) min = in[i];
	}
	if(t != 0) return 0;
	return sum - min;
	
}

int main() {
	int t;
	//freopen("C-large.in", "r", stdin);
	//freopen("C-large.out", "w", stdout);
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%d", in + i);
		int ret = solve();
		printf("Case #%d: ", tt + 1);
		if(ret > 0) printf("%d\n", ret);
		else puts("NO");
	}
	return 0;
}
