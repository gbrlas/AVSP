#include <cstdio>
#include <cstdlib>
#include <cstring>

int n ;
int v[11000] ;
int back[11000] ;
int end[11000] ;

bool test(int c)
{
	int pos, i ;
	
	memcpy(v,back,sizeof(v)) ;
	memset(end,0,sizeof(end)) ;
	
	for(pos=0;pos<10010;pos++)
	{
		while(v[pos])
		{
			for(i=0;i<c;i++)
			{
				if(v[pos+i]==0)
				{
					i = -1 ;
					break ;
				}
			}
			if(i==-1)
			{
				if(end[pos-1]==0)
				{
					return false ;
				}
				end[pos-1]-- ;
				end[pos]++ ;
				v[pos]-- ;
			}
			else
			{
				for(i=0;i<c;i++)
				{
					v[pos+i]-- ;
				}
				end[pos+c-1]++ ;
			}
		}
	}
	
	return true ;
}

int bs(int a, int b)
{
	int m ;
	
	while(b-a>1)
	{
		m = (a+b)/2 ;
		if(test(m)==true)
		{
			a = m ;
		}
		else
		{
			b = m-1 ;
		}
	}

	if(test(b)==true)
	{
		return b ;
	}
	return a ;
}

int sol(void)
{
	int i, t ;

	scanf("%d",&n) ;
	
	if(n==0)
	{
		return 0 ;
	}

	memset(v,0,sizeof(v)) ;
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&t) ;
		v[t]++ ;
	}
	
	memcpy(back,v,sizeof(v)) ;
	
	return bs(1,n) ;
}

int main(void)
{
	int i, t ;

	scanf("%d",&t) ;
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: %d\n",i,sol()) ;
	}

	return 0 ;
}
