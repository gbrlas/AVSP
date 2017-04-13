#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
typedef __int64 ll;
typedef int (*CMP)(const void*, const void*);

ll l, t, n, c;
ll in[2000];
ll d[2000];
int p[2000];

int cmp(int * a, int * b) {
	if(in[*a] > in[*b]) return -1;
	else if(in[*a] < in[*b]) return 1;
	return 0;
}

ll f(int x, ll y) {
	//printf("%d %I64d\n", x, y);
	ll ret = 0;
	int j = x;
	for(int i = 0; i < c; ++i) {
		d[j] = n / c;
		j = (j + 1) % c;
	}
	j = x;
	for(int i = 0; i < n % c; ++i) {
		d[j]++;
		j = (j + 1) % c;
	}
	d[x]--;
	in[c] = y;
	d[c] = 1;
	for(int i = 0; i <= c; ++i) p[i] = i;
	qsort(p, c + 1, sizeof(p[0]), (CMP)cmp);
	/*
	for(int i = 0; i <= c; ++i) {
		j = p[i];
		printf("%d %I64d %I64d\n", j, in[j], d[j]);
	}
	*/
	for(int i = 0; i <= c; ++i) {
		j = p[i];
		ll tmp = MIN(l, d[j]);
		ret += tmp * in[j];
		l -= tmp;
		d[j] -= tmp;
		ret += d[j] * in[j] * 2;
	}
	return ret;
}

ll solve() {
	ll sum = 0;
	ll ans = 0;
	for(int i = 0; i < c; ++i) sum += in[i];
	t /= 2;
	ll tmp = MIN(t / sum, n / c);
	ans += tmp * sum * 2;
	t -= tmp * sum;
	n -= tmp * c;
	for(int i = 0; i < c; ++i) {
		if(n == 0) return ans;
		if(t >= in[i]) {
			ans += in[i] * 2;
			t -= in[i];
			--n;
		} else {
			ans += t * 2;
			return ans + f(i, in[i] - t);
			
		}
	}
}

int main() {
	int cs;
	freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);
	scanf("%d", &cs);
	for(int cas = 0; cas < cs; ++cas) {
		scanf("%I64d %I64d %I64d %I64d", &l, &t, &n, &c);
		for(int i = 0; i < c; ++i) scanf("%I64d", in + i);
		printf("Case #%d: %I64d\n", cas + 1, solve());
	}	
	return 0;
}
/*
99
2 20 8 2 3 5
1 4 2 2 10 4
*/
