#include <cstdio>
#include <cstdlib>
#include <cstring>

int n, d ;

struct v
{
	int pos, cnt ;
} ;

struct v ven[210] ;

double max(double a, double b)
{
	return a > b ? a : b ;
}

int can(double t)
{
	double cd = (double) d ;
	int i ;
	double lm = ven[0].pos-t ;
	
	for(i=0;i<n;i++)
	{
		lm = max(lm,ven[i].pos-t) ;
		lm += cd*ven[i].cnt ;
		if(lm-cd>ven[i].pos+t)
		{
			return 0 ;
		}
	}
	
	return 1 ;
}

void sol(int tc)
{
	int i, ccnt = 0 ;
	double a = (double) 0, b, m ;

	scanf("%d%d",&n,&d) ;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&ven[i].pos,&ven[i].cnt) ;
	}
	
	b = (double) d ;
	
	while(can(b)==0)
	{
		a = b ;
		b *= 10 ;
	}

	while(b-a>1e-9)
	{
		ccnt++ ;
		m = (a+b)/2 ;
		if(ccnt>10000)
		{
			break ;
		}
		if(can(m)==1)
		{
			b = m ;
		}
		else
		{
			a = m ;
		}
	}
	
	printf("Case #%d: %.10lf\n",tc,(a+b)/2) ;
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
