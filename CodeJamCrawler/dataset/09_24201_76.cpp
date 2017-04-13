#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <string>

using namespace std;

#define NMAX 505

int T, n, dp[NMAX][20];
char w[20] = "welcome to code jam";
char s[NMAX];

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d\n", &T);
	for (int k=0; k<T; k++) {
		cin.getline(s, NMAX);
		n = strlen(s);
		memset(dp, 0, sizeof(dp));
		for (int i=0; i<n; i++) {
			for (int j=0; j<20; j++) {
				if (s[i] == w[j]) {
					if (j==0) {
						dp[i][j]++;
						continue;
					}
					for (int z=0; z<i; z++) {
						if (s[z] == w[j-1]) dp[i][j] += dp[z][j-1];
					}
					dp[i][j] %= 1000;
				}
			}
		}
		int res = 0;
		for (int i=0; i<n; i++) {
			res += dp[i][18];
		}
		printf("Case #%d: %.4d\n", k+1, res);
	}
	return 0;
}


