# include <cstdio>
# include <vector>
# include <algorithm>
# include <cmath>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	int t, tcase, a, b, c, x, m, n;
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	scanf("%d", &t);

	for(tcase = 1; tcase <= t; tcase++)
	{
		scanf("%d", &n);

		scanf("%d %d", &a, &b);
		if(n == 3) scanf("%d", &c);

		x = ((n == 3) ? gcd(abs(a-b), abs(a-c)) : abs(a-b));
		m = (a+x-1)/x;
		printf("Case #%d: %d\n", tcase, m*x-a);
	}

	return 0;
}
