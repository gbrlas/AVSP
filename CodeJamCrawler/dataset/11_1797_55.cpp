#include <stdio.h>

int nums[30], N, max;

void metodo(int si, int no, int by1, int by2, int n)
{
	if (n == N) {
		if (by1 == by2 && si && no) {
			if (max < si)
				max = si;
			if (max < no)
				max = no;
		}
	} else {
		metodo(si+nums[n], no, by1^nums[n], by2, n+1);
		metodo(si, no+nums[n], by1, by2^nums[n], n+1);
	}
}

main()
{
	int T = 0, TC;
	int i;
	scanf("%d", &TC);
	while (T++ < TC) {
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d", &nums[i]);
		max = 0;
		metodo(0, 0, 0, 0, 0);
		if (max)
			printf("Case #%d: %d\n", T, max);
		else
			printf("Case #%d: NO\n", T);
	}
	return 0;
}

