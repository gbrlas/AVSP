#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[20], s2[20];;

int main()
{
	s2[0] = 1;
	for (int i = 1; i < 20; ++i)
		s2[i] = s2[i - 1] << 1;
	int t, cases = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);

		int res = -1;
		for (int i = 1; i < s2[n] - 1; ++i)
		{
			int patrick1 = 0, patrick2 = 0, sean = 0;
			for (int j = 0; j < n; ++j)
			{
				if (i & s2[j])
				{
					patrick1 ^= a[j];
				}
				else
				{
					patrick2 ^= a[j];
					sean += a[j];
				}
			}
			if (patrick1 == patrick2) res = max(res, sean);
		}
		printf("Case #%d: ", ++cases);
		if (res == -1)
			printf("NO\n");
		else
			printf("%d\n", res);
	}
}