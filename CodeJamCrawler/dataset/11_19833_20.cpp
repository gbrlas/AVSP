#include <cstdio>
#include <algorithm>
using namespace std;
int tc;
int fgcd(const int &A, const int &B) {
	if (B == 0)
		return A;
	else
		return fgcd(B, A % B);
}
inline void solve() {
	long long N, Pd, Pg;
	scanf("%lld %lld %lld", &N, &Pd, &Pg);
	long long bawahD = 100 / __gcd(Pd, 100LL);
	if ((bawahD > N) || (Pd > 0LL && Pg == 0LL) || (Pd < 100LL && Pg == 100LL))
		printf("Case #%d: Broken\n", tc+1);
	else
		printf("Case #%d: Possible\n", tc+1);
}

int main() {
	int T;
	scanf("%d", &T);
	for (tc = 0; tc < T; tc++)
		solve();
	return 0;
}
