#include <stdio.h>
int main()
{
	FILE* in=fopen("B-small-attempt3.in", "r");
	FILE* out=fopen("1.out", "w");
	int t,k=0;
	fscanf(in,"%d",&t);
	while(t--)
	{
		double a,c,r,f,x,time=0.0;r=2.0;a=0.0;k++;
		fscanf(in,"%lf %lf %lf",&c,&f,&x);
		while(a<x)
		{
			if(a>=c)
			{
				if((x/(r+f))>((x-c)/r))
				{
					time=time+((x-a)/r);
					a=x;
				}
				else
				{
					a=a-c;
					r=r+f;
				}
			}
			else
			{
				time=time+((c<x?c:x))/r;
				a=a+((c<x?c:x));
			}
		}	
		fprintf(out,"Case #%d: %lf\n",k,time);	
	}
	return 0;
	fclose(in);
	fclose(out);
}
