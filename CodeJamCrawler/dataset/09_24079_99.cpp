#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

int l, d, n;
char s[5000][20];
char t[100000];
bool a[5000], b[5000];

int main(void) {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int i, j, k, m,x;

	scanf("%d%d%d", &l, &d, &n);

	for(i = 0; i < d; i++) scanf("%s", s[i]);
	for(x = 0; x < n; x++) {
		scanf("%s", t);

		for(i = 0; i < d; i++) {
			a[i] = 1;
			b[i] = 0;
		}

		m = strlen(t);
		k = 0;
		int r = 0;
		bool q = 0;
		bool w = 0;
		for(i = 0; i < m; i++) {
			if(t[i] != '(') {
				for(j = 0; j < d; j++) a[j] = (a[j] && (t[i] == s[j][k]));
				k++;
			}
			else {
				for(j = 0; j < d; j++) {
					q = 0;
					for(r = i+1; r < m && t[r] != ')'; r++) q = (q || (t[r] == s[j][k]));
					a[j] = (a[j] && q);
				}
				k++;
				i = r;
			}
		}

		int sol = 0;
		if(k == l)
			for(i = 0; i < d; i++) sol += a[i];

		printf("Case #%d: %d\n", x+1, sol);
	}

	exit(0);
}