/*
 ============================================================================
 Name        : google2.c
 Author      : Joey Allcock
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ns[2000][5];

void sort(int i, int len) {
	int l, k, j;
	int t[5];
	k = i;
	l = len;

	if(len - i >= 1) {
		while (l >= i) {
			if ((ns[k][2] * 100 + ns[k][3]) > (ns[l][2] * 100 + ns[l][3]) && k < l) {
				for (j = 0; j < 5; j++) {
					t[j] = ns[l][j];
					ns[l][j] = ns[k][j];
					ns[k][j] = t[j];
				}
				k = l;
				l--;
			} else if ((ns[k][2] * 100 + ns[k][3]) < (ns[l][2] * 100 + ns[l][3]) && k > l) {
				for (j = 0; j < 5; j++) {
					t[j] = ns[l][j];
					ns[l][j] = ns[k][j];
					ns[k][j] = t[j];
				}
				t[0] = k;
				k = l;
				l = t[0];
			} else {
				l--;
			}
	    }
		sort(i, k - 1);
		sort(k + 1, len);
	}
}

void plusmin(int f[2], int t) {
	f[1] += t;
	if (f[1] > 60) {
		++f[0];
		f[1] %= 60;
	}
}

int main(void) {
	int i, j, k, lines, t, na, nb, ca, cb, n;

	scanf("%d", &lines);

	for (i = 1; lines > 0; i++, --lines) {
		scanf("%d", &t);
		scanf("%d %d", &na, &nb);
		for (j = 0; j < na; j++) {
			scanf("%d:%d %d:%d", &ns[j][0], &ns[j][1], &ns[j][2], &ns[j][3]);
			plusmin(&ns[j][2], t);
			ns[j][4] = 0;
		}
		for (j = 0; j < nb; j++) {
			scanf("%d:%d %d:%d", &ns[j + na][0], &ns[j + na][1], &ns[j + na][2], &ns[j + na][3]);
			plusmin(&ns[j + na][2], t);
			ns[j + na][4] = 1;
		}
		ca = na;
		cb = nb;
		if (na == 0) {
			ca = 0;
		} else if (nb == 0) {
			cb = 0;
		} else {
			n = na + nb;
			sort(0, n - 1);

			for (j = 1; j < n; j++) {
				for (k = j + 1; k <= n; k++) {
					if ((ns[n - k][4] % 2) != (ns[n - j][4] % 2) && ns[n - k][4] < 2 &&
					  (ns[n - k][2] < ns[n - j][0] || (ns[n - k][2] == ns[n - j][0] && ns[n - k][3] <= ns[n - j][1]))) {
						if ((ns[n - j][4] % 2) == 1)
							--cb;
						else
							--ca;
						ns[n - k][4] += 2;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d %d\n", i, ca, cb);
	}
	return 0;
}
