#include<cstdio>
int main()
{
	int t, i, j, T;
	double C, F, X, p_time, c_time, rate;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%lf %lf %lf",&C,&F,&X);
		rate=2.0;
		p_time=(X/rate);
		c_time=0;
		while(1)
		{
			c_time+=(C/rate);
			rate+=F;
			c_time+=(X/rate);
			if(c_time>p_time)
				break;
			p_time=c_time;
			c_time-=(X/rate);
		}
		printf("Case #%d: ",t);
		printf("%.7lf\n",p_time);
	}
	return 0;
}


