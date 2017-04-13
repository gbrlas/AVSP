/*
 * C.c
 *
 *  Created on: Apr 13, 2012
 *      Author: goodwine
 */

#define MAX 5000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//short x[200005][200005];
short x[MAX + 5][MAX + 5];

void calc() {
	memset(x, 0, sizeof(x));
	unsigned int i, j;
	char str[10], tmp[3][10];
	for (i = 1; i <= MAX; i++) {
		sprintf(str, "%i", i);
		for (j = 0; j < strlen(str); j++) {
			memset(tmp[0], 0, sizeof(tmp[0]));
			strncpy(tmp[0], str, j + 1);
			memset(tmp[1], 0, sizeof(tmp[1]));
			strcpy(tmp[1], str + j + 1);
			memset(tmp[2], 0, sizeof(tmp[2]));
			strcat(tmp[2], tmp[1]);
			strcat(tmp[2], tmp[0]);
			if (atoi(tmp[2]) <= MAX)
				x[i][atoi(tmp[2])] = 1;
		}
	}
}
;

int main() {
	int _, t, m, a, b, i, j;
	calc();
	scanf("%i", &t);
	for (_ = 1; _ <= t; _++) {
		m = 0;
		scanf("%i %i", &a, &b);
		for (i = a; i < b; i++) {
			for (j = i + 1; j <= b; j++) {
				if (x[i][j] == 1) {
					m++;
				}
			}
		}
		printf("Case #%i: %i\n", _, m);
	}
	return 0;
}
