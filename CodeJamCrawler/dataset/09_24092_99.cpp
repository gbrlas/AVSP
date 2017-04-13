#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

long long MOD = 10000;

char s[] = "welcome to code jam";
int t, n;
long long a[505][20];
char w[505];

int main(void) {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int i, j, k, x;

	scanf("%d", &t);
	gets(w);
	int m = strlen(s);
	for(x = 0; x < t; x++) {
		gets(w);
		n = strlen(w);
		memset(a, 0, sizeof(a));
		a[0][0] = 1;

		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++)
				if(w[i] == s[j]) {
					a[i+1][j+1] = (a[i+1][j+1]+a[i][j])%MOD;
				}
			for(j = 0; j <= m; j++) a[i+1][j] = (a[i+1][j]+a[i][j])%MOD;
		}

				cout << "Case #" << x+1 << ": ";
				k = a[n][m];
				int r = 4;
				while(k > 0) {
					k /= 10;
					r--;
				}
				while(r--) printf("0");
				if(a[n][m]) cout << a[n][m];
				cout << endl;
	}

	exit(0);
}