#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MODULUS 10000
#define PATTERN "welcome to code jam"
#define MAX_PAT_LEN 20
#define MAX_IMG_LEN 1000


int a[MAX_IMG_LEN][MAX_PAT_LEN];
char img[MAX_IMG_LEN + 10];
char * pat = PATTERN;
int modulus = MODULUS;

int recurse(int i, int j) {
	if (a[i][j] < 0) {
		if (pat[j - 1] == img[i - 1]) {
			a[i][j] = (recurse(i - 1, j) + recurse(i - 1, j - 1)) % modulus;
		} else {
			a[i][j] = recurse(i - 1, j);
		}
	}
	return a[i][j];
}

int main() {
	int n;
	gets(img);
	sscanf(img, "%d", &n);
	for (int c = 1; c <= n; c++) {
		gets(img);
		int mi = strlen(img);
		int mp = strlen(pat);
		for (int i = 0; i <= mi; i++) {
			a[i][0] = 1;
			for (int j = 1; j <= mp; j++) {
				a[i][j] = (i < j ? 0 : -1);
			}
		}

		int ans = recurse(mi, mp);

		if (ans < 10) {
			printf("Case #%d: 000%d\n", c, ans);
		} else if (ans < 100) {
			printf("Case #%d: 00%d\n", c, ans);
		} else if (ans < 1000) {
			printf("Case #%d: 0%d\n", c, ans);
		} else if (ans < 10000) {
			printf("Case #%d: %d\n", c, ans);
		} else assert(false);
	}
	return 0;
}

