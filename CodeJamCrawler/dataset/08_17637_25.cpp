#include <cstdio>
#include <iostream>

using namespace std;

int c, n, m, a;

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d", &c);
	for (int tst = 1; tst <= c; ++tst)
	{
		scanf("%d%d%d", &n, &m, &a);

		printf("Case #%d: ", tst);
		bool f = 0;
		for (int x1 = 0; !f && x1 <= n; ++x1)
		{
			for (int y2 = 0; y2 <= m; ++y2)
			{
				for (int x2 = 0; x2 <= n; ++x2)
				{
					if (f) break;
					if (x2 == 0)
					{
						if (x1 * y2 == a)
						{
							int y1 = 0;
							f = 1;
							printf("0 0 %d %d %d %d\n", x1, y1, x2, y2);
						}
						continue;
					}

					int y1 = x1 * y2 - a;
					if (y1 % x2 != 0) continue;
					y1 = y1 / x2;
					if (0 <= y1 && y1 <= m)
					{
						f = 1;
						printf("0 0 %d %d %d %d\n", x1, y1, x2, y2);
					}
				}
				if (f) break;
			}
			if (f) break;
		}
		if (!f) printf("IMPOSSIBLE\n");
	}

	return 0;
}
