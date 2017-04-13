#include <stdio.h>

int main(void) {
	// your code goes here
	int k,T;
	double C,F,X,y,rate,cookie;
	scanf("%d",&T);
	k=T;
	while(T--)
	{
		y=0;
		cookie=0;
		rate=2.0;
	scanf("%lf %lf %lf",&C,&F,&X);
	while(cookie<X)
	{
	if(C>=X)
	{
		y=X/rate;
		cookie=X;
		
		break;
	}
	else if(C<X)
	{
		
		cookie=C;
		if(((X-C)/rate)>=X/(rate+F))
		{
			y+=C/rate;
		cookie=0;
		rate+=F;
		
			
			}
		else if(((X-C)/rate)<X/(rate+F))
		{
			y+=(X/rate);
			cookie=X;
		}
		

	}
	}
	printf("Case #%d: %.7lf\n",k-T,y);
	
	}
	return 0;
}
