#include <stdio.h>

char C[50][4], D[50][4];

main()
{
	int T = 0, TC;
	int i, j, k, c, d, len, len1, res;
	char entrada[105], resultado[105];
	scanf("%d", &TC);
	while (T++ < TC) {
		scanf("%d", &c);
		for (i = 0; i < c; i++)
			scanf("%s", C[i]);
		scanf("%d", &d);
		for (i = 0; i < d; i++)
			scanf("%s", D[i]);
		scanf("%d %s", &len, entrada);
		resultado[0] = entrada[0];
		len1 = 1;
		for (i = 1; i < len; i++) {
			if (len1) {
				for (j = 0; j < c; j++) {
					if (entrada[i] == C[j][0] && resultado[len1-1] == C[j][1]) {
						resultado[len1-1] = C[j][2];
						break;
					}
					if (entrada[i] == C[j][1] && resultado[len1-1] == C[j][0]) {
						resultado[len1-1] = C[j][2];
						break;
					}
				}
				if (j == c) {
					for (j = 0; j < len1; j++)
						for (k = 0; k < d; k++) {
							if (entrada[i] == D[k][0] && resultado[j] == D[k][1]) {
								len1 = 0;
								break;
							}
							if (entrada[i] == D[k][1] && resultado[j] == D[k][0]) {
								len1 = 0;
								break;
							}
						}
					if (j == len1)
						resultado[len1++] = entrada[i];
				}
			} else
				resultado[len1++] = entrada[i];
		}
		printf("Case #%d: [", T);
		if (len1) {
			printf("%c", resultado[0]);
			for (i = 1; i < len1; i++)
				printf(", %c", resultado[i]);
		}
		printf("]\n");
	}
	return 0;
}

