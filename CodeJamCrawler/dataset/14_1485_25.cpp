#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int t,n=0;
	cin>>t;
	while(n!=t)
	{
		double C,F,X,rate=2.0,tt=0;
	     cin>>C>>F>>X;
	     double current_time=X/2,next_time=C/rate+X/(rate+F);
	    while(current_time>next_time)
	     {
				tt+=C/rate;
				rate+=F;
				current_time=X/rate;
				next_time=C/rate+X/(rate+F);
				
				}
				tt+=X/rate;
			 
			printf("Case #%d: %.7lf\n",n+1,tt);	
		n++;
		}
		
		return 0;
}
