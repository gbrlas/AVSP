#include <stdio.h>
#include <assert.h>

#define MAX_LEN 20
#define MAX_DICT 10000
#define MAX_PATT 10000

struct Pattern {
	bool x[MAX_LEN][256];
	int len;

	void build(char * s, int l) {
		len = l;
		for (int i = 0; i < l; i++)
			for (int j = 0; j < 256; j++)
				x[i][j] = false;

		int n = 0;
		bool inbrackets = false;
		for (char * p = s; *p != '\0'; p++) {
			if (!inbrackets) {
				if (*p == '(') {
					inbrackets = true;
				} else {
					x[n++][(int) *p] = true;
				}
			} else {
				if (*p == ')') {
					inbrackets = false;
					n++;
				} else {
					x[n][(int) *p] = true;
				}
			}
		}
		assert(n == l);
	}

	void output() {
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < 256; j++) {
				if (x[i][j]) printf("%c", (char) j);
			}
			printf(" ");
		}
		printf("\n");
	}

	bool matches(char * s) {
		for (int i = 0 ; s[i] != '\0'; i++) {
			if (!x[i][(int) s[i]]) return false;
		}
		return true;
	}
};

char dictionary[MAX_DICT][MAX_LEN];
char buff[MAX_PATT];

int main() {
	int l, d, n;
	scanf("%d%d%d", &l, &d, &n);
	assert(l < MAX_LEN);
	assert(d < MAX_DICT);
	for (int i = 0; i < d; i++) {
		scanf("%s", &dictionary[i][0]);
	}

	for (int i = 0; i < n; i++) {
		Pattern patt;
		scanf("%s", buff);
		patt.build(buff, l);
		//patt.output();
		int count = 0;
		for (int j = 0; j < d; j++) {
			if (patt.matches(&dictionary[j][0])) count++;
		}
		printf("Case #%d: %d\n", i + 1, count);
	}

	return 0;
}

