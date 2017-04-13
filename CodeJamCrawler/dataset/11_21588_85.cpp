#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i != n; i++)
	{
		int m, r;
		scanf("%d", &m);

		r = 0;

		for (int j = 0; j != m; j++)
		{
			int x;
			scanf("%d", &x);
			if (x != j+1)
				r++;
		}

		printf("Case #%d: %f\n", i+1, (float)r);
	}
	return 0;
}
