#include <stdio.h>

int main()
{
	double C, F, X, time;
	int i;
	int cases;
	double Rate;

	scanf("%d", &cases);

	for(i=1; i<=cases; i++)
	{
		scanf("%lf", &C);
		scanf("%lf", &F);
		scanf("%lf", &X);

		time = 0;
		Rate = 2;
		if ( X <= C )
			time = X/Rate;
		else
		{
			while (1)
			{
				time += C/Rate;

				if ( (X-C)/Rate < X/(Rate+F) ) // don't buy
				{
					time += (X-C)/Rate;
					break;
				}
				else
				{
					Rate = Rate+F;
				}
			}
		}

		printf("Case #%d: %0.7lf\n", i, time);
	}

	return 0;
}
