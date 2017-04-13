#include <stdio.h>

int wm[101];

int main()
{
	int T;
	scanf("%d", &T);

	for (int tst = 1; tst <= T; tst++)
	{
		int X, S, R, t, N;

		for (int i = 0; i <= 100; i++)
			wm[i] = 0;
		
		scanf("%d %d %d %d %d", &X, &S, &R, &t, &N);
		wm[0] = X;

		for (; N; N--)
		{
			int B, E, w;
			scanf("%d %d %d", &B, &E, &w);

			wm[0] -= E-B;
			wm[w] += E-B;
		}

		double rtim = (double)t;
		double res = 0.0;

		for (int i = 0; i <= 100; i++)
		{
			double rt = (double)wm[i] / (double)(R + i);
			if (rt < rtim)
			{
				rtim -= rt;
				res += rt;
			}
			else
			{
				double dst = (double)wm[i];
				res += rtim;
				dst -= (double)(R + i) * rtim;
				res += dst / (double)(S + i);
				rtim = 0;
			}
		}

		printf("Case #%d: %.9f\n", tst, res);
	}

	return 0;
}
