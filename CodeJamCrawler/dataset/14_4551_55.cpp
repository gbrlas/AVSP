#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

bool fequals(double a, double b)
{
	double epsilon=0.00001;
	if( -0.00001 <= (a - b) && (a - b) <= 0.00001 )
	{
		return true;
	}	
	return false;
	//return fabs(a-b) < 0.00001;
}


void process(double C, double F, double X, int testNum)
{
	double cost=0, rate=2, doNotBuyCost, buyCost;
	//if(fequals(X,C) || X < C)
	if( X <= C)
	{
		printf("Case #%d: %.7lf\n",testNum, X/2);
		return;
	}

	while(1)
	{
		doNotBuyCost = X/rate;
		buyCost = C/rate + (X/(rate+F));

		//if( (!fequals(buyCost,doNotBuyCost)) && buyCost < doNotBuyCost)
		if( buyCost < doNotBuyCost)
		{
			// Buy Farm
			cost += (C/rate);
			rate += F;
		}
		else
		{
			cost += (X/rate);
			printf("Case #%d: %.7lf\n",testNum, cost);
			break;
		}
	}
}


int main()
{
	freopen("B-large.in", "rt", stdin);	
	freopen("B_Large_Output.txt", "wt", stdout);
		

	int t,test;
	double C,F,X;	
	scanf("%d", &t);	
	for(test=1;test<=t;++test)
	{
		scanf("%lf %lf %lf\n",&C,&F,&X);
		process(C,F,X,test);
	} // end of test loop

	fclose(stdin);
	fclose(stdout);
	return 0;
}
