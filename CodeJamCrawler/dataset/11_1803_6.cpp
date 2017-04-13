#include <stdio.h>

main()
{
	int T = 0, TC;
	int i, bool;
	int N, D, G;
	scanf("%d", &TC);
	while (T++ < TC) {
		scanf("%d %d %d", &N, &D, &G);
		bool = 1;
		if (N < 100) {
			bool = 0;
			for (i = N; i >= 1; i--)
				if ((int)(i*(D/100.0)) == i*(D/100.0)) {
					bool = 1;
					break;
				}
		}
		if (bool) {
			if ((D != 100 && G == 100) || (D != 0 && G == 0))
				printf("Case #%d: Broken\n", T);
			else
				printf("Case #%d: Possible\n", T);
		} else
			printf("Case #%d: Broken\n", T);
	}
	return 0;
}

