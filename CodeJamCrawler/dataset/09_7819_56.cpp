#include <stdlib.h>
#include <stdio.h>

char s[1000];

int compare(const void * lhs, const void * rhs) {
	return ((int) *((char *) lhs)) - ((int) *((char *) rhs));
}

int main() {
	int nt;
	scanf("%d", &nt);
	for (int t = 1; t <= nt; t++) {
		scanf("%s", s);
		int i = 0;
		while (s[i] != '\0') i++;
		int j = i - 1;
		
		while (j > 0) {
			if (s[j - 1] < s[j]) {
				int k = i - 1;
				while (s[j - 1] >= s[k]) k--;
				char c = s[k];
				s[k] = s[j - 1];
				s[j - 1] = c;
				qsort(s + j,  i - j, sizeof(char), &compare);
				break;
			}
			j--;
		}
		if (j == 0) {
			j = i - 1;
			while (s[j] == '0') j--;
			qsort(s,  j + 1, sizeof(char), &compare);
			s[i] = '0';
			s[i + 1] = '\0';
			qsort(s + 1,  i, sizeof(char), &compare);
		}

		printf("Case #%d: %s\n", t, s);
		
	}
	return 0;
}

