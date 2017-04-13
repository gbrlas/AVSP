#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL; 

const int maxn = 200 + 10;

int n, cnt; 
LL m, f; 

struct Node{
	LL s,p; 
} data[maxn];

bool cmp(Node a, Node b) {
	if (a.s != b.s) return a.s < b.s; 
	return a.p > b.p; 
}

LL check(LL k ) {
	LL now = m - k * f, day = 0; 
	for (int i = 0; i < cnt; ++i) {
		LL j = now / data[i].p; 
		LL t = (i == 0 ? data[i].s + 1 : data[i].s - data[i - 1].s);
		//printf("%d\n", t);
		if (j / t < k) {
			day += j; 
			break; 
		}
		day += t * k;
		now -= t * k * data[i].p; 
	}
	return day; 
}

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%I64d%I64d%d", &m, &f, &n); 
		for (int i = 0; i < n; ++i) scanf("%I64d%I64d", &data[i].p, &data[i].s);
		sort(data, data + n, cmp);
		cnt = 1; 

		//printf("%d\n", n);
		for (int i = 1; i < n; ++i) {
			while (cnt && data[i].p <= data[cnt - 1].p) cnt--;
			data[cnt++] = data[i]; 
		}

		//puts("!!");
		LL ans = 0, g = 1, h = m / f, w = 100000;
		while (h - g > w) {
			LL p = (h - g) / 3;
			LL k1 = g + p, k2 = g + 2 * p;
			//printf("%I64d %I64d\n", k1, k2);
			if (check(k1) > check(k2)) {
				h = k2;
				ans = max(ans, check(k1));
			}
			else {
				g = k1;
				ans = max(ans, check(k2));
			}
		}


		for (LL i = g; i <= h; ++i) ans = max(ans, check(i));
		printf("Case #%d: %I64d\n" , nCase ,  ans); 
	}

	return 0;
}
