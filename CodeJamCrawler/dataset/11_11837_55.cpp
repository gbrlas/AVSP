#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t); 
	for (int c = 1; c <= t; c++) {
		int n;
		scanf("%d", &n);
		unsigned int x, p = 0, s = 0, m = 1000000000;
		for (int i = 0; i < n; i++) {
			scanf("%u", &x);
			p ^= x;
			s += x;
			if (m > x) m = x;
		}
		if (p == 0) {
			printf("Case #%d: %u\n", c, s-m);
		} else {
			printf("Case #%d: NO\n", c);
		}
	}
	return 0;
}

