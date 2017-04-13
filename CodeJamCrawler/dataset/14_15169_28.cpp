#include<stdio.h>
#include<stdlib.h>

double func(double C,double F, double X,double cost,double rate)
{
	if(X/rate <= (C/rate + X/(rate+F)))
	{
		return cost+X/rate;
	}
	else
		return func(C,F,X,cost + C/rate,rate+F);

}

int main()
{
	double X,C,F;
	int T,i;
	FILE *f1,*f2;
	f1 = fopen("B-small.txt","r");
	f2 = fopen("output.txt","w");
	fscanf(f1,"%d",&T);
	for(i = 1 ;i <= T; i++)
	{
		double ans = 0.0;
		fscanf(f1,"%lf %lf %lf",&C,&F,&X);
		ans = func(C,F,X,0,2);
		fprintf(f2,"Case #%d: ",i);
		fprintf(f2,"%lf\n",ans);
	}
	return 0;
}
