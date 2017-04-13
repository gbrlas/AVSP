#include <stdio.h>

//inline int dif(int a, int b) { return a < b ? b-a : a-b;}

int main () {
	int T, N, S, p;
	int ans, thr;
	int i, j, x;
	scanf("%d", &T);
	for(i = 0; i != T; ++i) {
		scanf("%d %d %d", &N, &S, &p);
		ans = 0;
		thr = 3*p-2;

		for (j = 0; j != N; j++) {
			scanf("%d", &x);
			if (x >= thr) ans++;
			else if (S && x && thr-x <= 2) {
				ans++;
				S--;
			}

		}
		printf("Case #%d: %d\n", i+1, ans);
	}
	return 0;
}
