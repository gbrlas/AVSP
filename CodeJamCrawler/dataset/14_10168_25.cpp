// https://code.google.com/codejam/contest/2974486/dashboard
#include <stdio.h>
int main()
{
	int t, count, a, b, x, p, c;
	scanf("%d", &t);
	count = 1;
	while (t--) {
		scanf("%d", &a);
		int temp[4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &x);
				if (i == (a  - 1)) {
					temp[j] = x;
				}
			}
		}
		scanf("%d", &b);
		int temp1[4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d", &x);
				if (i == (b  - 1)) {
					temp1[j] = x;
				}
			}
		}

		printf("Case #%d: ", count++);

		c = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (temp1[j] == temp[i]) {
					c++;
					p = i;
				}
			}
		}
		if (c == 1) {
			printf("%d\n", temp[p]);
		}
		else if (c > 1) {
			printf("Bad magician!\n");
		}
		else if (c == 0) {
			printf("Volunteer cheated!\n");
		}
	}
}
