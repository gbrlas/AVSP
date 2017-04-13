#include <stdio.h>

int main()
{
	int t, c, i, j;
	int r1, r2;
	int a1[5][5], a2[5][5];
	int same, val;

	freopen("pa.in", "r", stdin);
	freopen("pa.out", "w", stdout);

	scanf("%d", &t);
	for (c = 1; c <= t; c++) {
		scanf("%d", &r1);
		for (i = 1; i <= 4; i++) 
			for (j = 1; j <= 4; j++) 
				scanf("%d", &a1[i][j]);
		scanf("%d", &r2);
		for (i = 1; i <= 4; i++) 
			for (j = 1; j <= 4; j++) 
				scanf("%d", &a2[i][j]);
		
		same = 0;
		for (i = 1; i <= 4; i++) 
			for (j = 1; j <= 4; j++) 
				if (a1[r1][i] == a2[r2][j]) {
					same++;
					val = a1[r1][i];
				}
		printf("Case #%d: ", c);
		if (same == 1) {
			printf("%d\n", val);
		} else if (same == 0) {
			printf("Volunteer cheated!\n");
		} else {
			printf("Bad magician!\n");
		}
	}
	return 0;
}

