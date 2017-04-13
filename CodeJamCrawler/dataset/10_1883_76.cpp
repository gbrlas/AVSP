#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	for (int cc=1; cc<=t; cc++)
	{
		int l, p, c;
		scanf("%d %d %d", &l, &p, &c);

		int cases = 0;
		while(p > l)
		{
			cases++;
			p = (p + c-1)/c;
		}
		int res = 0;
		while(cases > 1)
		{
			cases = (cases+1)/2;
			res++;
		}
		printf("Case #%d: %d\n", cc, res);
	}
}
