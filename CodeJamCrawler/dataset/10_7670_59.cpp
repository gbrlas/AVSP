#include <stdio.h>
#include <string.h>
#define ABS(a) ((a)>0?(a):(-(a)))
#define MIN(a,b) ((a)<(b)?(a):(b))
int dp[200][256];
int in[110], n, m, D, I;

int h[300], p;
int *s, tm[300];
void insert(int x) {
	h[++p] = x;
	tm[x] = p;
	int i = p, j, a, b;
	while(i > 1) {
		j = i / 2;
		if(s[h[j]] <= s[h[i]]) break;
		tm[h[i]] ^= tm[h[j]] ^= tm[h[i]] ^= tm[h[j]];
		h[i] ^= h[j] ^= h[i] ^= h[j];
		i = j;
	}
}

void del() {
	if(p == 0) return;
	h[1] = h[p];
	--p;
	tm[h[1]] = 1;
	int i = 1, j;
	while(i <= p) {
		j = i * 2;
		if(j > p) break;
		if(j + 1 <= p && s[h[j + 1]] < s[h[j]]) ++j;
		if(s[h[j]] >= s[h[i]]) break;
		tm[h[i]] ^= tm[h[j]] ^= tm[h[i]] ^= tm[h[j]];
		h[i] ^= h[j] ^= h[i] ^= h[j];
		i = j;
	}
}

void change(int x) {
	int i = x, j;
	while(i > 1) {
		j = i / 2;
		if(s[h[j]] <= s[h[i]]) break;
		tm[h[i]] ^= tm[h[j]] ^= tm[h[i]] ^= tm[h[j]];
		h[i] ^= h[j] ^= h[i] ^= h[j];
		i = j;
	}
}

void f(int * ss) {
	s = ss;
	p = 0;
	for(int i = 0; i < 256; ++i) {
		insert(i);
	}
	for(int i = 0; i < 256; ++i) {
		int x = h[1];
		del();
		//if(s[x] < 50) printf("f %d %d\n", x, s[x]);
		for(int l = 0; l <= m; ++l) {
			if(x - l >= 0) {
				if(s[x - l] > s[x] + I) {
					s[x - l] = s[x] + I;
					change(tm[x - l]);
				}
			}
			if(x + l < 256) {
				if(s[x + l] > s[x] + I) {
					s[x + l] = s[x] + I;
					change(tm[x + l]);
				}
			}			
		}
	}
}

int solve() {
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < 256; ++i) {
		dp[0][i] = MIN(ABS(in[0] - i), D);
	}
	//printf("s 0\n");
	f(dp[0]);
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < 256; ++j) {
			dp[i][j] = dp[i - 1][j] + D;
			for(int l = 0; l <= m; ++l) {
				if(j - l >= 0) dp[i][j] = MIN(dp[i][j], dp[i - 1][j - l] + ABS(in[i] - j));
				if(j + l < 256) dp[i][j] = MIN(dp[i][j], dp[i - 1][j + l] + ABS(in[i] - j));				
			}
		}
		//printf("s %d\n", i);
		f(dp[i]);
	}
	int ret = dp[n - 1][0];
	for(int i = 0; i < 256; ++i) {
		ret = MIN(ret, dp[n - 1][i]);
	}
	return ret;
}

int main() {
	int t;
	freopen("B-large.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		scanf("%d %d %d %d", &D, &I, &m, &n);
		for(int i = 0; i < n; ++i) scanf("%d", in + i);
		printf("Case #%d: %d\n", tt + 1, solve());
	}
	return 0;
}
