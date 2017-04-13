#include <iostream>
#define T 100
#define C 500
#define F 4
#define X 2000
int main()
{
	int cases=0;
	double c=0.0,f=0.0,x=0.0;
	double rate=2.0;
	double time1=0.0,time2=0.0,total[T]={0.0};
	freopen( "B-small-attempt0.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	scanf("%d",&cases);
	for(int t=0;t<cases;t++)
	{
		rate=2.0;
		time1=0.0;
		time2=0.0;
		scanf("%lf %lf %lf",&c,&f,&x);
		while(time1>=time2)
		{
			time1=x/rate;
			time2=c/rate+x/(rate+f);
			if(time1>=time2)
			{
				total[t]+=c/rate;
				rate+=f;
			}
		}
		total[t]=total[t]+time1;
	}
	for(int i=0;i<cases;i++)
	{
		printf("Case #%d: %.7f\n",i+1,total[i]);
	}
	return 0;
}