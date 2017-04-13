
#include <stdio.h>

int main () {
	
	unsigned long T, r, t, n, area, test;

	scanf("%d", &T);

	for (test = 1; test <= T; test++)
	{
	scanf("%ld %ld", &r, &t);
	area = 0;
	n = 1;
	while (1) {
		if (area + (2*r - 3 + 4*n) <= t ) {
			area += (2*r - 3 + 4*n);
			n++;
		} else {
			printf("Case #%d: %ld\n", test, n-1);
			break;
		}
	}
	}

}

