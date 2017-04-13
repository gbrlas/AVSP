#include<stdio.h>
#include<math.h>
int max(int a,int b)
{
	return a<b?b:a;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int test(long long l,long long p,long long c)
{
	int r;
	if(l*c>=p)r=0;
	else
	{
		long long x=sqrt(p*l);
		if(x==l)r=1+max(test(l,x+1,c),test(x+1,p,c));
		else if(x+1==p)r=1+max(test(l,x,c),test(x,p,c));
		else r=1+min(max(test(l,x,c),test(x,p,c)),max(test(l,x+1,c),test(x+1,p,c)));
	}
	//printf("%I64d %I64d %I64d:%d\n",l,p,c,r);
	return r;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		long long l,p,c;
		scanf("%I64d%I64d%I64d",&l,&p,&c);
		printf("Case #%d: %d\n",tt,test(l,p,c));
	}
}
