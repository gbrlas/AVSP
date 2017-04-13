#include <stdio.h>

int pux[200];
int puy[200];
int lux[200];
int luy[200];

#define LD(x) ((long double)(x))

int main()
{
	int T;
	scanf("%d", &T);

	for (int tst = 1; tst <= T; tst++)
	{
		int W, L, U, G;
		scanf("%d %d %d %d", &W, &L, &U, &G);

		long double fld = 0.0L;

		scanf("%d %d", lux, luy);
		for (int i = 1; i < L; i++)
		{
			scanf("%d %d", lux+i, luy+i);
			fld -= (long double)((lux[i] - lux[i-1]) * (luy[i] + luy[i-1]));
		}

		scanf("%d %d", pux, puy);
		for (int i = 1; i < U; i++)
		{
			scanf("%d %d", pux+i, puy+i);
			fld += (long double)((pux[i] - pux[i-1]) * (puy[i] + puy[i-1]));
		}

		fld /= (long double)G;

		printf("Case #%d:\n", tst);

		long double lx = 0.0L;
		long double ly = puy[0] - luy[0];
		long double af = 0.0L;
		int ip = 1;
		int il = 1;

		for (int i = 1; i < G;)
		{
			if (pux[ip] < lux[il])
			{
				long double h = LD(puy[ip]) - LD(luy[il] - luy[il-1])*LD(pux[ip] - lux[il-1])/LD(lux[il]-lux[il-1]) - LD(luy[il-1]);
				long double df = (LD(pux[ip]) - lx) * (h + ly);

				if (af + df > fld)
				{
					long double h1 = ly;
					long double h2 = h;
					long double d = LD(pux[ip]) - lx;
					while (d > 0.0L)
					{
						d *= 0.5L;
						long double hh = 0.5L * (h1 + h2);
						long double s = d * (h1 + hh);
						if (af + s > fld)
						{
							h2 = hh;
						}
						else
						{
							h1 = hh;
							lx += d;
							af += s;
						}
					}
					ly = h1;
					printf("%lf\n", lx);
					af = 0.0L;
					i++;
				}
				else
				{
					af += df;
					lx = pux[ip];
					ly = h;
					ip++;
				}
			}
			else
			{
				long double h = LD(puy[ip] - puy[ip-1])*LD(lux[il] - pux[ip-1])/LD(pux[ip]-pux[ip-1]) + LD(puy[ip-1]) - LD(luy[il]);
				long double df = (LD(lux[il]) - lx) * (h + ly);

				if (af + df > fld)
				{
					long double h1 = ly;
					long double h2 = h;
					long double d = LD(lux[il]) - lx;
					while (d > 0.0L)
					{
						d *= 0.5L;
						long double hh = 0.5L * (h1 + h2);
						long double s = d * (h1 + hh);
						if (af + s > fld)
						{
							h2 = hh;
						}
						else
						{
							h1 = hh;
							lx += d;
							af += s;
						}
					}
					ly = h1;
					printf("%lf\n", lx);
					af = 0.0L;
					i++;
				}
				else
				{
					af += df;
					lx = lux[il];
					ly = h;
					il++;
				}
			}
		}
	}

	return 0;
}
