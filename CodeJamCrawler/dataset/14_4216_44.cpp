#include<stdio.h>
#include<iostream>
using namespace std;
double c,f,x;
double calctime(double rate,double tspent)
{
	double t1=x/rate;
	t1+=tspent;
	double t2=c/rate;
	rate+=f;
	tspent+=t2;
	double t3=x/rate;
	t3+=tspent;
	if(t3<t1)
	{
		return calctime(rate,tspent);
	}
	return t1;
}
int main()
{
	freopen("B-small.in", "r", stdin);
    freopen("B-small.txt", "w", stdout);
	int t,i;
	double time;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		time=calctime(2,0);
		printf("Case #%d: %0.7lf\n",i,time);
	}
}
