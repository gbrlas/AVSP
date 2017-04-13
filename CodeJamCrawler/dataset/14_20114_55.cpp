#include <stdio.h>

double calculateTime(double C, double F, double X)
{
	
	double timePast = 0, curSpeed = 2.0;
	while (true)
	{
		double waitingTime = 0.0;
		waitingTime = C / curSpeed;
		if (waitingTime + X / (curSpeed + F) > X / curSpeed)
		{
			timePast += X / curSpeed;
			break;
		}
		timePast += C / curSpeed;
		curSpeed += F;
	}
	return timePast;
}

void main()
{
	freopen("B-small-attempt0.in", "r", stdin);  
	freopen("B-small-attempt0.out", "w", stdout);  
	int T = 0, caseNum = 0;
	scanf("%d", &T);
	while (T--)
	{
		double c = 0, f = 0, x = 0, res = 0;
		scanf ("%lf %lf %lf", &c, &f, &x);
		
		++caseNum; 
		
		if (c >= x)
			res = x / (double)2;
		else 
		{ 
			res = calculateTime(c, f, x);
		}
		printf("Case #%d: %.7f\n", caseNum, res);
		 
	}
}