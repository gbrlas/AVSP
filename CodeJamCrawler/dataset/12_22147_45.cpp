/*
 * B.c
 *
 *  Created on: Apr 13, 2012
 *      Author: goodwine
 */

#include <stdio.h>

int main() {
	int t, n, s, p, x, _, m, ts, tss;
	scanf("%i", &t);
	for (_ = 1; _ <= t; _++) {
		scanf("%i %i %i", &n, &s, &p);
		if (p > 0)
			ts = p * 3 - 2;
		else
			ts = 0;
		if (p > 1)
			tss = p * 3 - 4;
		else
			tss = p;
		m = 0;
		while (n--) {
			scanf("%i", &x);
			if (x >= ts) {
				m++;
			} else if (s > 0 && x >= tss) {
				m++;
				s--;
			}
		}
		printf("Case #%i: %i\n", _, m);
	}
	return 0;
}
