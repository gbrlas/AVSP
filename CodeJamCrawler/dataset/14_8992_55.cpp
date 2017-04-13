#include <stdio.h>
#include <stdlib.h>


double cal(double c, double f, double x)
{
	double rate = 2.0;
	double total = 0.0;
	while(1)
	{
		double old = x/rate;
		double new = c/rate+x/(rate+f);
		if(new < old)
		{
			total += c/rate;
			rate +=f;
		}
		else
		{
			return total+x/rate;
		}
	}
}

int main()
{
	int size = 0;
	scanf("%d",&size);
	for(int tmp=1;tmp<=size;tmp++)
	{
		double c;
		double f;
		double x;
		scanf("%lf",&c);
		scanf("%lf",&f);
		scanf("%lf",&x);
		double result = cal(c,f,x);
		printf("Case #%d: %lf\n", tmp,result);
	}
	return 0;
}