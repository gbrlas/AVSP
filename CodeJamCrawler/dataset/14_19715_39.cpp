#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	long long t,k;
	cin>>t;
	for(long long k=1;k<=t;k++)
	{
		double c,f,x;
		scanf("%lf %lf %lf",&c,&f,&x);
		double ft=c/2.0,tm=x/2.0,a=f,s; 
		while(1)
		{
			double temp=ft+(x/(a+2.0));
			if(temp<tm)
			{
				tm=temp;
				ft+=c/(a+2.0);
				a+=f;
			}
			else
			break;
		}
		printf("Case #%lld: %lf\n",k,tm);
	}
	return 0;
}
