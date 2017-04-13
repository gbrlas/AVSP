#include <cstdio>
#include <cstdlib>
#include <cstring>

int gcd(int a, int b)
{
	int tmp ;

	if(a>b)
	{
		tmp = a ;
		a = b ;
		b = tmp ;
	}
	
	while(a)
	{
		b %= a ;
		tmp = a ;
		a = b ;
		b = tmp ;
	}

	return b ;
}

void sol(int tc)
{
	int pd, pg, n ;
	int pd1, pd2 ;
	int gd ;
	
	scanf("%d%d%d",&n,&pd,&pg) ;
	
	pd1 = gcd(100,pd) ;
	pd2 = pd/pd1 ;
	gd = 100/pd1 ;
	
	if(gd>n)
	{
		printf("Case #%d: Broken\n",tc) ;
		return ;
	}
	
	if((pg==100&&pd!=100)||(pg==0&&pd!=0))
	{
		printf("Case #%d: Broken\n",tc) ;
		return ;
	}
	printf("Case #%d: Possible\n",tc) ;
}

int main(void)
{
	int i, t ;
	
	scanf("%d",&t) ;
	for(i=1;i<=t;i++)
	{
		sol(i) ;
	}

	return 0 ;
}
