#include <stdio.h>

int b0(int n) {
	if (n > 0)
		return n;
	else
		return 0;
}

int main() {
	int ecase;
	scanf("%d", &ecase);

	for (int ecount = 1; ecount <= ecase; ecount++) {
		int en, es, ep;
		int ans = 0;
		scanf("%d%d%d", &en, &es, &ep);

		int thra = ep + b0(ep - 1) * 2;
		int thrb = ep + b0(ep - 2) * 2;
		
		for (int i = 0; i < en; i++) {
			int et;
			scanf("%d", &et);
			if (et >= thra)
				ans++;
			else if (et >= thrb && es > 0) {
				ans++;
				es--;
			}
		}
		printf("Case #%d: %d\n", ecount, ans);
	}
	return 0;
}
