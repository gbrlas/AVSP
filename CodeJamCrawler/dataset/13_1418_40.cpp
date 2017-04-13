#include <cstdio>
long long all[11]={1, 4, 9, 121, 484, 12321, 1234321, 123454321, 12345654321ll, 1234567654321ll, 123456787654321ll};
int main() {
	int n, a0, b0;
	long long a, b;
	scanf("%d", &n);
	for(int t=1; t<=n; ++t) {
		//scanf("%lld %lld", &a, &b);
		scanf("%I64d %I64d", &a, &b);
		for(a0=0; all[a0]<a; ++a0);
		for(b0=a0; all[b0]<=b; ++b0);
		//printf("%d %d\n", a0, b0);
		printf("Case #%d: %d\n", t, b0-a0);
	}
}
