#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPalindrom(char *str);
int isPerfectSquare(int num);

int main () {
	int N, c, count;
	char buf1[16];
	char buf2[16];
	int start, end;

	FILE *ifp, *ofp;
	ifp = fopen("C-small-attempt0.in", "r");
	ofp = fopen("output.txt", "w");

	//scanf("%d", &N);
	fscanf(ifp, "%d", &N);

	for (c = 1; c <= N; ++c) {
		count = 0;
		//scanf("%s %s", buf1, buf2);
		fscanf(ifp, "%s %s", buf1, buf2);
		start = atoi(buf1);
		end = atoi(buf2);
		while (start <= end) {
			if (isPerfectSquare(start)) {
				sprintf(buf1, "%d", start);
				if (isPalindrom(buf1)) {
					++count;
				}
			}
			++start;
		}
		fprintf(ofp, "Case #%d: %d\n", c, count);
	}

	fclose(ifp);
	fclose(ofp);
	return 0;
}

int isPalindrom(char *str) {
	char *end = str;
	while (*end != '\0') end++;
	end--;

	while (end > str) {
		if (*end != *str) return 0;
		end--;
		str++;
	}
	return 1;
}
int isPerfectSquare(int num) {
	int res = sqrt(num);
	if (res*res == num) {
		char buf[16];
		sprintf(buf, "%d", res);
		if (isPalindrom(buf)) return 1;
	}
	return 0;
}