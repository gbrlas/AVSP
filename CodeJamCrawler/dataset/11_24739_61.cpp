#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std ;

int cmp(const void *a, const void *b)
{
	return ((double *)a)[0] > ((double *)b)[0] ? 1 : -1 ;
}

int cmp2(const void *a, const void *b)
{
	return ((double *)a)[2] > ((double *)b)[2] ? 1 : -1 ;
}

double calcdis(double len, double adds, double s, double r, double &t)
{
	double out = 0 ;
	double sp, mt ;
	
	if(t>0)
	{
		sp = adds+r ;
		mt = len/sp ;
		if(mt>t)
		{
			mt = t ;
		}
		len -= mt*sp ;
		t -= mt ;
		out += mt ;
	}
	
	sp = adds+s ;
	mt = len/sp ;
	out += mt ;
	
	return out ;
}

double sol(void)
{
	double len, pos[1100][3], s, r, t, slen = (double) 0 ;
	int i, n ;
	double ans ;
	
	scanf("%lf%lf%lf%lf%d",&len,&s,&r,&t,&n) ;
	for(i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&pos[i][0],&pos[i][1],&pos[i][2]) ;
	}
	
	qsort(&(pos[1]),n,sizeof(pos[0]),cmp) ;
	
	pos[0][1] = (double) 0 ;
	for(i=1;i<=n;i++)
	{
		if(pos[i][0]>pos[i-1][1])
		{
			slen += pos[i][0] - pos[i-1][1] ;
		}
	}
	if(len>pos[i-1][1])
	{
		slen += len-pos[i-1][1] ;
	}
	
	pos[0][0] = (double) 0 ;
	pos[0][1] = slen ;
	pos[0][2] = (double) 0 ;
	
	qsort(pos,n+1,sizeof(pos[0]),cmp2) ;
	
	ans  = (double) 0 ;
	for(i=0;i<=n;i++)
	{
		ans += calcdis(pos[i][1]-pos[i][0],pos[i][2],s,r,t) ;
	}
	
	return ans ;
}

int main(void)
{
	int i, t ;
	
	scanf("%d",&t) ;
	
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: %.9lf\n",i,sol()) ;
	}

	return 0 ;
}
