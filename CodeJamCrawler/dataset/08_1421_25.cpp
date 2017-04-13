#include <stdio.h>

int main()
{                   
	int c;
	scanf("%d", &c);
	for (int cc = 1; cc <= c; cc++)
	{
		int sx, sy, a;
		scanf("%d %d %d", &sx, &sy, &a);
		for (int x1 = 0; x1 <= sx; x1++) for (int y1 = 0; y1 <= sy; y1++) for (int x2 = 0; x2 <= sx; x2++) for (int y2 = 0; y2 <= sy; y2++) if (x1*y2 - y1*x2 == a)
		{
			printf("Case #%d: 0 0 %d %d %d %d\n", cc, x1, y1, x2, y2);
			goto next;
		}
bad:
		printf("Case #%d: IMPOSSIBLE\n", cc);
next:;
	}
	return 0;
}
