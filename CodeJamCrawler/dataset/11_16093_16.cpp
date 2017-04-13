#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int t, tt = 0;
	int n, d, g;
	freopen("A-small-attempt1.in", "r+", stdin);
	freopen("A-small-attempt1.out", "w+", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &n, &d, &g);
		int td, ts;
		bool f = false;
		for (ts = 1; ts <= n; ts++)
		{
			if (ts * d % 100 == 0)
			{
				td = ts * d / 100;
				if (g >= 1 - (d == 0) && g <= 99 + (d == 100))
				{
					f = true;
				}
			}
		}
		printf("Case #%d: ", ++tt);
		if (f)
		{
			puts("Possible");
		}
		else
		{
			puts("Broken");
		}
	}
	return 0;
}