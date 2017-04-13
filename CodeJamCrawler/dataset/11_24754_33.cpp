#include <cstdio>
#include <cstdlib>
#include <cstring>

int uper[110][2] ;
int lower[110][2] ;
int mx, nl, nu, n, pos ;
double area[210][2] ;

double myabs(double n)
{
	return n<0 ? -n : n ;
}

double calcarea(void)
{
	double s = (double)0 ;
	int i ;
	
	for(i=0;i<pos-1;i++)
	{
		s += area[i][0]*area[i+1][1] ;
		s -= area[i][1]*area[i+1][0] ;
	}
	
	s += area[i][0]*area[0][1] ;
	s -= area[i][1]*area[0][0] ;
	
	return myabs(s/2) ;
}

bool test(double cut, double a)
{
	int i ;
	
	pos = 0 ;
	for(i=0;i<nl;i++)
	{
		area[pos][0] = lower[i][0] ;
		area[pos][1] = lower[i][1] ;
		pos++ ;
		if(lower[i][0]<=cut&&cut<=lower[i+1][0])
		{
			area[pos][0] = cut ;
			area[pos][1] = (lower[i+1][1]-lower[i][1])*(cut-lower[i][0])/(lower[i+1][0]-lower[i][0])+lower[i][1] ;
			pos++ ;
			break ;
		}
	}
	
	for(i=nu-1;i>=0;i--)
	{
		if(uper[i-1][0]<=cut&&cut<=uper[i][0])
		{
			area[pos][0] = cut ;
			area[pos][1] = (uper[i][1]-uper[i-1][1])*(cut-uper[i-1][0])/(uper[i][0]-uper[i-1][0])+uper[i-1][1] ;
			pos++ ;
			i-- ;
			break ;
		}
	}

	for(;i>=0;i--)
	{
		area[pos][0] = uper[i][0] ;
		area[pos][1] = uper[i][1] ;
		pos++ ;
	}
	
	if(calcarea()<a)
	{
		return true ;
	}
	else
	{
		return false ;
	}
}

void bs(double a)
{
	double min, max, m ;
	int t = 1000 ;

	min = (double) 0 ;
	max = (double) mx ;
	
	while(t&&(max-min>1e-7))
	{
		m = (max+min)/2 ;
		
		if(test(m,a)==true)
		{
			min = m ;
		}
		else
		{
			max = m ;
		}
		
		t-- ;
	}
	
	printf("%.9lf\n",(max+min)/2) ;
}

void sol(void)
{
	int i ;
	double ta ;

	scanf("%d%d%d%d",&mx,&nl,&nu,&n) ;
	
	for(i=0;i<nl;i++)
	{
		scanf("%d%d",&lower[i][0],&lower[i][1]) ;
	}
	for(i=0;i<nu;i++)
	{
		scanf("%d%d",&uper[i][0],&uper[i][1]) ;
	}

	for(pos=0,i=0;i<nl;i++)
	{
		area[pos][0] = lower[i][0] ;
		area[pos][1] = lower[i][1] ;
		pos++ ;
	}

	for(i=nu-1;i>=0;i--)
	{
		area[pos][0] = uper[i][0] ;
		area[pos][1] = uper[i][1] ;
		pos++ ;
	}
	
	ta = calcarea() ;

	for(i=1;i<n;i++)
	{
		bs(ta*i/n) ;
	}
}

int main(void)
{
	int i, t ;
	
	scanf("%d",&t) ;
	for(i=1;i<=t;i++)
	{
		printf("Case #%d:\n",i) ;
		sol() ;
	}

	return 0 ;
}
