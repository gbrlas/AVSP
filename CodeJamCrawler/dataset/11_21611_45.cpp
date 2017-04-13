#include <stdio.h>
#include <string.h>

int cards[10010];
int q[10000];

int main()
{
	int T;
	scanf("%d", &T);

	for (int tst = 1; tst <= T; tst++)
	{
		int N;
		scanf("%d", &N);
		if (N == 0)
		{
			printf("Case #%d: 0\n", tst);
			continue;
		}

		memset(cards, 0, sizeof(int)*10010);

		for (int i = 0; i < N; i++)
		{
			int c;
			scanf("%d", &c);
			cards[c-1]++;
		}

		int res = 100000;
		int qs = 0;
		int qe = 0;
		int k = 0;

		for (int i = 0; i < 10010; i++)
		{
			if (cards[i] > k)
			{
				for (int j = k; j < cards[i]; j++)
					q[qe++] = i;
				k = cards[i];
			}
			else if (cards[i] < k)
			{
				for (int j = cards[i]; j < k; j++)
				{
					if (i - q[qs] < res)
						res = i - q[qs];
					qs++;
				}
				k = cards[i];
			}
		}
		printf("Case #%d: %d\n", tst, res);
	}

	return 0;
}
