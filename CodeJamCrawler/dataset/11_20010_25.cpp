#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

int main()
{
	freopen("E:/input.txt", "r", stdin);
	freopen("E:/output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int k = 0; k < T; ++k)
	{
		int n;
		scanf("%d", &n);
		int mv = numeric_limits<int>::max();
		int sum = 0;
		int xorsum = 0;
		for (int i = 0; i < n; ++i)
		{
			int v;
			scanf("%d", &v);
			mv = min(mv, v);
			sum += v;
			xorsum ^= v;
		}
		printf("Case #%d: ", k + 1);
		if (xorsum != 0)
			printf("NO\n");
		else
			printf("%d\n", sum - mv);
	}
	return 0;
}