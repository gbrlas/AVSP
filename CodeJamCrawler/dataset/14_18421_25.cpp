#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, n1;
	scanf("%d", &n);
	for(n1=1;n1<=n;n1++)
	{
		double c,f,x,r,t,t1,t2,result;
		scanf("%lf%lf%lf", &c, &f, &x);
		t=0; r=2;
		if(x<c)
		{
			result = x/2;
		}
		else
		{
			while(1)
			{
				t+=c/r;
				t1=x/(r+f);
				t2=(x-c)/r;
				//printf(" - t=%lf, 1=%lf, 2=%lf\n", t, t1, t2);
				if(t2<=t1)
				{
					t+=t2;
					result = t;
					break;
				}
				else
				{
					r+=f;
					//printf(" + t=%lf, r=%lf\n", t, r);
				}
			}
		}


		printf("Case #%d: %0.7lf\n", n1, result);
	}
	return 0;
}
