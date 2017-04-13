#include <stdio.h>
#include <Windows.h>
double totalTime[1000001], spendTime[1000001];

int main(void)
{
	int t;
	int i, j;
	double c, f, x;
	
	int res;

	scanf("%d", &t);
	for(i = 0 ; i < t ; i++)
	{
		res = 0;
		memset(totalTime, 0.0, sizeof(totalTime));
		memset(spendTime, 0.0, sizeof(spendTime));

		scanf("%lf %lf %lf", &c, &f, &x);

		totalTime[0] = x/2.0;
		for(j = 1 ; j <= 1000000 ; j++)
		{
			spendTime[j] = spendTime[j-1]+(c/(2+((j-1)*f)));
			totalTime[j] = spendTime[j]+(x/(2+j*f));
			if(totalTime[res] > totalTime[j]){
				res = j;
			}
		}

		printf("Case #%d: %.7lf\n", i+1, totalTime[res]);
	}

	return 0;
}
