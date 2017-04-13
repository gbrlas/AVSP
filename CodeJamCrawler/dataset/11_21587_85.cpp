#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i != n; i++)
	{
		int m;
		scanf("%d", &m);

		int min = 2000000;
		int sum = 0;
		int xor = 0;
		for (int j = 0; j != m; j++)
		{
			int x;
			scanf("%d", &x);
			if (x < min) min = x;
			sum += x;
			xor ^= x;
		}

		printf("Case #%d: ", i+1);
		if (xor)
			printf("NO\n");
		else
			printf("%d\n", sum - min);
	}

	return 0;
}
