#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxm = 1000000 + 10;
const int maxp = 300000;

int prime[maxp];
bool isPrime[maxm];
long long n;

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	int p = 0;
	memset(isPrime, 1, sizeof(isPrime));
	for (int i = 2; i < maxm; ++i)
		if (isPrime[i]) {
			prime[p++] = i;
			for (int j = i + i; j < maxm; j += i) isPrime[j] = 0;
		}

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%I64d",&n);
		long long ans = 1;
		if (n == 1) {
			ans = 0;
			printf("Case #%d: %I64d\n", nCase, ans);
			continue;
		}

		for (int i = 0; i < p && (long long)prime[i] * prime[i] <= n; ++i) {
			long long cnt = 0, tmp = prime[i];
			while (tmp * prime[i] <= n) {
				++cnt;
				tmp *= prime[i];
			}
			ans += cnt;
		}

		printf("Case #%d: %I64d\n", nCase, ans);
	}

	return 0;
}
