#include <cstdio>
#include <cmath>

#define REP(i,n) for (int i = 0; i < n; i++)

typedef long long ll;

int dp[10000001];

inline bool is_palindrome(ll x)
{
	int digits[15], count = 0;
	for (; x > 0; x /= 10) {
		digits[count++] = x % 10;
	}
	for (int l = 0, r = count-1; l < r; l++, r--) {
		if (digits[l] != digits[r]) {
			return false;
		}
	}
	return true;
}

int main()
{
	for (int i = 1; i <= 10000000; i++) {
		dp[i] = dp[i-1] + (is_palindrome(i) && is_palindrome(i*i));
	}

	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		int x = ceil(sqrt(a)), y = floor(sqrt(b));
		int answer = dp[y] - dp[x-1];
		printf("Case #%d: %d\n", i, answer);
	}

	return 0;
}
