#include <cstdio>
#include <cstdlib>
#include <cstring>

double calc(void)
{
	int i, n, val ;
	double ans = (double) 0 ;
	
	scanf("%d",&n) ;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&val) ;
		if(val!=i)
		{
			ans += (double) 1 ;
		}
	}

	return ans ;
}

int main(void)
{
	int i, t ;

	scanf("%d",&t) ;

	for(i=1;i<=t;i++)
	{
		printf("Case #%d: %.6lf\n",i,calc()) ;
	}

	return 0 ;
}
