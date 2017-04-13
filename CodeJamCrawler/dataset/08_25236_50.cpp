/*
 ============================================================================
 Name        : google.c
 Author      : Joey Allcock
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int lines, i, j, k, c, s, q, clear, cleared;
	char sin[101][101];
	char qin[101][101];
	int used[101];

	scanf("%d", &lines);

	for (i = 1; lines > 0; i++) {
		c = 0;
		scanf("%d\n", &s);
		for (j = 0; j < s; j++)
			gets(sin[j]);
		scanf("%d\n", &q);
		if (q >= s) {
			for (j = 0; j < s; j++)
				used[j] = 0;
			for (j = 0; j < q; j++) {
				gets(qin[j]);
				for (k = 0; k < s; k++) {
					if (strcmp(qin[j], sin[k]) == 0) {
						used[k] = 1;
						cleared = k;
						break;
					}
				}
				clear = 1;
				for (k = 0; k < s; k++) {
					if (used[k] == 0) {
						clear = 0;
						break;
					}
				}
				if (clear == 1) {
					c++;
					for (k = 0; k < s; k++)
						used[k] = 0;
					used[cleared] = 1;
				}
			}
		}
		printf("Case #%d: %d\n", i, c);
		--lines;
	}
	return 0;
}
