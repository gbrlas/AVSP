#include <stdio.h>
#include <string.h>

int main()
{
	FILE* inp = fopen("B.txt","r"), *outp = fopen("out.txt","w");
	int t; fscanf(inp,"%i",&t);
	int i = 1;
	for(;i<=t;++i)
	{
		double c,f,x;
		fscanf(inp,"%lf %lf %lf",&c,&f,&x);
		double time = 0, rate = 2;
		while(1)
		{
			if(x <= c + x*rate/(rate+f))
			{
				time += x/rate;
				break;
			}
			else
			{
				time += c/rate;
				rate += f;
			}
		}
		fprintf(outp,"Case #%i: %0.7lf\n",i,time);
	}
	return 0;
}