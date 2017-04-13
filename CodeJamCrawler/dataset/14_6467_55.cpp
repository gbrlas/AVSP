#include <stdio.h>
int main() {
	// your code goes here
	int t,n=1;
	double c,f,x,r=2;
	double res=0,sum,pre;
	scanf("%d",&t);
	while(t--)
	{
	r=2;
	scanf("%lf %lf %lf",&c,&f,&x);
	pre=x/2;
	sum=c/r;
	r+=f;
	res=sum+x/r;
	while(pre>res)
	{
		pre=res;
		sum+=c/r;
		r+=f;
		res=sum+x/r;
	}
	printf("Case #%d: %.7lf\n",n++,pre);
	}
	return 0;
}
