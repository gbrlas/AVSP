#include <stdio.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int cc=1;cc<=t;cc++)
	{
		double c,f,x;
		scanf("%lf%lf%lf",&c,&f,&x);
		double res=0.0,per=2.0;
		while(x/per > c/per+x/(per+f))
		{
			res+=c/per;
			per+=f;
		}
		res+=x/per;
		printf("Case #%d: %.7f\n",cc,res);
	}
}