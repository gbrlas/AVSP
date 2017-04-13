#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt)
	{
		double c, f, x;
		scanf("%lf %lf %lf", &c, &f, &x);
		double res = x/2.0;
		int farms = 0;
		double tot = 0;
		while (tot <= res)
		{
			double prod = 2.0+farms*f;
			double time = tot+x/prod;
			res = min(time, res);
			tot += c/prod;
			farms++;
		}
		printf("Case #%d: %.7lf\n", tt, res);
	}
	return 0;
}
