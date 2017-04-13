#include<cstdio>
double c,f,x;
int left,right,mid1,mid2;
long double check(int n)
{
	long double ret=0.0,work=2.0;
	int i;
	for(i=1;i<=n;++i)
	{
		ret+=c/work;
		work+=f;
	}
	ret+=x/work;
	return ret;
}
int main()
{
	int t,tt;
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	for(scanf("%d",&tt),t=1;t<=tt;++t)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		left=0;
		right=x/c;
		while(left+6<right)
		{
			mid1=left+(right-left)/3;
			mid2=left+(right-left)*2/3;
			if(check(mid1)<check(mid2))
				right=mid2;
			else
				left=mid1;
		}
		while(check(left)>check(left+1))
			++left;//,printf("%d\n",left);
		printf("Case #%d: %.10lf\n",t,(double)check(left));
	}
	return 0;
}
