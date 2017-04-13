#include <cstdio>
#include <cmath>

char n[100] ;

bool check(void)
{
	long long c = 0, d ;
	double tmp ;
	long long i = 0 ;
	
	while(n[i]!='\0')
	{
		c = c*2+n[i]-'0' ;
		i++ ;
	}
	
	
	tmp = sqrt(c) ;
	d = (long long)tmp ;
	for(i=-100;i<=100;i++)
	{
		if((d+i)*(d+i)==c)
		{
			printf("%s",n) ;
			return true ;
		}
	}
	return false ;
}

bool go(int pos)
{
	if(n[pos]=='\0')
	{
		return check() ;
	}
	
	if(n[pos]=='?')
	{
		n[pos] = '0' ;
		if(go(pos+1)==true)
		{
			return true ;
		}
		n[pos] = '1' ;
		if(go(pos+1)==true)
		{
			return true ;
		}
		n[pos] = '?' ;
	}
	else
	{
		return go(pos+1) ;
	}
	
	return false ;
}

void sol(int tc)
{
	scanf("%s",n) ;
	
	printf("Case #%d: ",tc) ;
	
	go(0) ;
	
	printf("\n") ;
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
