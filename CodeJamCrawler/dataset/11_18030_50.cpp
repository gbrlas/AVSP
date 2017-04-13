#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int pD, pG;
long long n;

int gcd(int a, int b)
{
	if (!b) return a;
	else return gcd(b, a % b);
}

bool check()
{
	int d = gcd(pD, 100), pA = 100 / d, loseA = (100 - pD) / d;
	if (pA > n) return 0;
	if (pG == 100 && pD != 100) return 0;
	if (pG == 0 && pD != 0) return 0;
	return 1;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		scanf("%I64d%d%d", &n, &pD, &pG);
		if (check()) printf("Case #%d: Possible\n", nCase);
		else printf("Case #%d: Broken\n", nCase);
	}

	return 0;
}
