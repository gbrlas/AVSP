#include <stdio.h>
#include <string.h>
int l, d, n;
char in[6000][20];
char s[40000];
int mark[6000];


int solve() {
	memset(mark, 0, sizeof(mark));
	int i = 0, j, k, t = 0;
	while(s[i]) {
		if(s[i] == '(') {
			for(k = 0; k < d; ++k) {
				if(mark[k]) continue;
				for(j = i + 1; s[j] != ')'; ++j) {
					if(in[k][t] == s[j]) break;
				}
				if(s[j] == ')') mark[k] = 1;
			}
			while(s[i] != ')') ++i;
		} else {
			for(k = 0; k < d; ++k) {
				if(mark[k]) continue;
				mark[k] = (s[i] != in[k][t]);
			}
		}
		++i;
		++t;
	}
	int ans = 0;
	for(i = 0; i < d; ++i) ans += (!mark[i]);
	return ans;
}

int main() {
	int i;
	freopen("Aout.txt", "w", stdout);
	scanf("%d %d %d", &l, &d, &n);
	for(i = 0; i < d; ++i) {
		scanf("%s", in + i);
	}
	for(i = 0; i < n; ++i) {
		scanf("%s", s);
		printf("Case #%d: %d\n", i + 1, solve());
	}
	return 0;
}
/*
3 5 5
abc
bca
dac
dbc
cba
(ab)(bc)(ca)
abc
(abc)(abc)(abc)
(zyx)bc
*/
