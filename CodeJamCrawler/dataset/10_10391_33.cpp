#include <stdio.h>
int main(void) {
	int t, n, k, i;

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%d %d", &n, &k);
		printf("Case #%d: %s\n", i + 1, k % (1 << n) == (1 << n) - 1 ? "ON" : "OFF");
	}
	return 0;
}
