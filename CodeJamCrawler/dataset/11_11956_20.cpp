#include <cstdio>

typedef long long i64;

i64 gcd(i64 a, i64 b) {
	return b == 0? a : gcd(b, a % b);
}

int cases;
i64 n, pd, pg;

bool isBroken() {
	if(pd != 0 && (100 / gcd(pd, 100) > n))
		return true;
	if(pg == 100 && pd != 100)
		return true;
	if(pg == 0 && pd != 0)
		return true;
	return false;
}

int main() {
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	scanf("%d", &cases);
	for(int I = 1; I <= cases; ++I) {
		scanf("%lld%lld%lld", &n, &pd, &pg);
		i64 w = 100 / gcd(pd, 100);
		printf("Case #%d: %s\n", I, isBroken()? "Broken" : "Possible");
	}
	return 0;
}
