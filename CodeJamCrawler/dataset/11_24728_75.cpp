#include <cstdio>
#include <cstdlib>
#include <cstring>

char map[110][110] ;
double wp[110], owp[110], oowp[110] ;
int n ;

double getwp(int id, int t = -1)
{
	int i ;
	int played, win ;

	played = win = 0 ;
	for(i=0;i<n;i++)
	{
		if(i==t)
		{
			continue ;
		}
		if(map[id][i]!='.')
		{
			played++ ;
		}
		if(map[id][i]=='1')
		{
			win++ ;
		}
	}
	return played==0?(double)0:((double)win)/((double)played) ;
}

void sol(int tc)
{
	int i, j ;
	double sum ;
	int cnt ;

	scanf("%d",&n) ;
	for(i=0;i<n;i++)
	{
		scanf("%s",map[i]) ;
	}
	
	for(i=0;i<n;i++)
	{
		wp[i] = getwp(i) ;
	}
	
	for(i=0;i<n;i++)
	{
		sum = (double) 0 ;
		cnt = 0 ;
		for(j=0;j<n;j++)
		{
			if(map[i][j]!='.')
			{
				sum += getwp(j,i) ;
				cnt++ ;
			}
		}
		
		owp[i] = cnt==0?(double)0:sum/((double)cnt) ;
	}
	
	for(i=0;i<n;i++)
	{
		sum = (double) 0 ;
		cnt = 0 ;
		for(j=0;j<n;j++)
		{
			if(map[i][j]!='.')
			{
				sum += owp[j] ;
				cnt++ ;
			}
		}

		oowp[i] = cnt==0?(double)0:sum/((double)cnt) ;
	}
	
	printf("Case #%d:\n",tc) ;
	for(i=0;i<n;i++)
	{
		printf("%.12lf\n",(wp[i]/((double)4))+(owp[i]/((double)2))+(oowp[i]/((double)4))) ;
	}
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
