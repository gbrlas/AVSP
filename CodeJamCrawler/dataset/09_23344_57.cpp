#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int n, m, k;
char ss[100000];
char str[1000][1000], feature[1000][1000];

double solve(int l) {
	char s2[100];
	int i, j = -1, ct = 0, r;
	double pp;
	for (i = l;; i++) {
		if (ss[i] == '(') {
			if (j == -1) j = 1;
			else j++;
		}
		if (ss[i] == ')') {
			j--;
		}
		if (isalpha(ss[i])) {
			ct = 1;
		}
		if (j == 0) break;
	}

	if (ct == 0) {
		for (j = l; ; j++) if (ss[j] == '(') break;
		sscanf(ss+j+1, "%lf", &pp);
		return pp;
	}
	else {
		for (j = l; ; j++) if (ss[j] == '(') break;
		sscanf(ss + j + 1, "%lf%s", &pp,s2);
		for (i = 0; i < k; i++) {
			if (strcmp(s2, feature[i]) == 0) break;
		}
		for (r = j + 1; ; r++) if (ss[r] == '(') break;
		if (i < k) {
			return pp * solve(r);
		}
		else {
			ct = 0;
			for (i = r; ; i++) {
				if (ss[i] == '(') ct++;
				if (ss[i] == ')') ct--;
				if (ct == 0) break;
			}
			return pp * solve(i + 1);
		}
	}
}

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int i, j, t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d:\n", t);
		scanf("%d", &n);
		gets(str[0]);
		strcpy(ss, "");
		for (i = 0; i < n; i++) {
			gets(str[i]);
			strcat(ss, str[i]);
		}
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			scanf("%*s%d", &k);
			for (j = 0; j < k; j++) scanf("%s", feature[j]);
			printf("%.10lf\n", solve(0));
		}
	}
	return 0;
}
