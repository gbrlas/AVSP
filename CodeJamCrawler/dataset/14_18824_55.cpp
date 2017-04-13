#include<cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d\n",&T);
	for(int ix=0;ix<T;ix++)
	{
		printf("Case #%d: ",ix+1);
		double C,F,X;
		scanf("%lf %lf %lf",&C,&F,&X);
		double t = 0.0,cookie = 0.0,rate = 2.0;
		while(true)
		{
			if(cookie < C)
			{
				t += (C-cookie) / rate;
				cookie = C;
			}
			else
			{
				if((X-cookie)/rate > X/(rate+F))
				{
					cookie = 0.0;
					rate += F;
				}
				else
				{
					t += (X-cookie)/rate;
					printf("%lf\n",t);
					break;
				}
			}
		}
	}
	return 0;
}