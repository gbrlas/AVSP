#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std ;

int pt[1100000] ;
int top = 0 ;
int pcnt[1100000] ;

int isp(int n)
{
	int i ;
	
	for(i=0;i<top&&pt[i]*pt[i]<=n;i++)
	{
		if(n%pt[i]==0)
		{
			return 0 ;
		}
	}
	
	return 1 ;
}

int go(int n)
{
	int p, pos = 0, cnt, out = 0 ;

	if(isp(n))
	{
		if(n<=1000000)
		{
			pcnt[n]++ ;
		}
		return 1 ;
	}
	
	while(pos<top&&pt[pos]*pt[pos]<=n)
	{
		if(n%pt[pos]==0)
		{
			p = pt[pos] ;
			cnt = 0 ;
			while(n%p==0)
			{
				n /= p ;
				cnt++ ;
			}
			if(pcnt[p]<cnt)
			{
				pcnt[p] = cnt ;
				out = 1 ;
			}
		}
		pos++ ;
	}
	
	return out ;
}

int sol(void)
{
	int n ;
	int i ;
	int min = 0, max = 0 ;
	
	scanf("%d",&n) ;

	for(i=2;i<=n;i++)
	{
		if(isp(i))
		{
			min++ ;
		}
	}
	if(min==0)
	{
		min = 1 ;
	}
	
	memset(pcnt,0,sizeof(pcnt)) ;
	max = 1 ;
	for(i=2;i<=n;i++)
	{
		max += go(i) ;
	}
	
	return max-min ;
}

int main(void)
{
	int i, t ;
	
	pt[top++] = 2 ;
	for(i=3;i<=1000000;i+=2)
	{
		if(isp(i))
		{
			pt[top++] = i ;
		}
	}

	scanf("%d",&t) ;

	for(i=1;i<=t;i++)
	{
		printf("Case #%d: %d\n",i,sol()) ;
	}

	return 0 ;
}
