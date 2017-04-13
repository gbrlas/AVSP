#include <cstdio>
#include <cstdlib>
#include <cstring>

int n ;
unsigned int val[1100] ;

void calc(int turn)
{
	int i ;
	unsigned int u = 0, min = 10000000, s = 0 ;

	scanf("%d",&n) ;
	for(i=0;i<n;i++)
	{
		scanf("%u",&val[i]) ;
		u ^= val[i] ;
		if(val[i]<min)
		{
			min = val[i] ;
		}
		s += val[i] ;
	}
	
	if(u!=0)
	{
		printf("Case #%d: NO\n",turn) ;
	}
	else
	{
		printf("Case #%d: %u\n",turn,s-min) ;
	}
}

int main(void)
{
	int i, t ;

	scanf("%d",&t) ;

	for(i=1;i<=t;i++)
	{
		calc(i) ;
	}

	return 0 ;
}
