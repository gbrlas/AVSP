#include <cstdio>
#include <cstdlib>
#include <cstring>

int n, wn, ans, buf[2100] ;
int c[2100] ;
int r[2100][2100] ;
int top[2100] ;
int w[2100][2] ;
int rn ;
int lim ;

void build(void)
{
	int i, j, id, c ;

	rn = 1 ;
	
	memset(r,0,sizeof(r)) ;
	
	for(i=0;i<n;i++)
	{
		r[0][i] = 1 ;
	}
	
	for(i=0;i<wn;i++)
	{
		for(j=0;j<rn;j++)
		{
			if(r[j][w[i][0]]==1&&r[j][w[i][1]]==1)
			{
				id = j ;
				break ;
			}
		}
		
		c = 0 ;
		for(j=0;j<n;j++)
		{
			if(r[id][j]==1)
			{
				if(j==w[i][0]||j==w[i][1])
				{
					r[rn][j] = 1 ;
					c = 1-c ;
				}
				else if(c==1)
				{
					r[rn][j] = 1 ;
					r[id][j] = 0 ;
				}
			}
		}
		rn++ ;
	}
	
	lim = n ;
	for(i=0;i<rn;i++)
	{
		int cnt = 0 ;
		for(j=0;j<n;j++)
		{
			if(r[i][j]==1)
			{
				cnt++ ;
			}
		}
		if(cnt<lim)
		{
			lim = cnt ;
		}
	}
}

void check(void)
{
	int i, max = 0, j ;
	int tbuf[2100] ;
	
	for(i=0;i<n;i++)
	{
		if(c[i]>max)
		{
			max = c[i] ;
		}
	}
	
	if(max<=ans)
	{
		return ;
	}
	
	for(i=0;i<rn;i++)
	{
		memset(tbuf,0,sizeof(tbuf)) ;
		for(j=0;j<n;j++)
		{
			if(r[i][j]==1)
			{
				tbuf[c[j]] = 1 ;
			}
		}
		
		for(j=1;j<=max;j++)
		{
			if(tbuf[j]==0)
			{
				return ;
			}
		}
	}
	
	if(max>ans)
	{
		ans = max ;
		for(i=0;i<n;i++)
		{
			buf[i] = c[i] ;
		}
	}
}

void test(int id)
{
	int i ;
	
	if(id==n)
	{
		check() ;
		return ;
	}
	
	for(i=1;i<=lim;i++)
	{
		c[id] = i ;
		test(id+1) ;
	}
}

void sol(int tc)
{
	int i ;
	
	ans = 0 ;

	scanf("%d%d",&n,&wn) ;
	for(i=0;i<wn;i++)
	{
		scanf("%d",&w[i][0]) ;
		w[i][0]-- ;
	}
	for(i=0;i<wn;i++)
	{
		scanf("%d",&w[i][1]) ;
		w[i][1]-- ;
	}
	
	build() ;
	
	test(0) ;

	printf("Case #%d: %d\n",tc,ans) ;
	printf("%d",buf[0]) ;
	for(i=1;i<n;i++)
	{
		printf(" %d",buf[i]) ;
	}
	printf("\n") ;
/*
	fprintf(stderr,"Case #%d: %d\n",tc,ans) ;
	fprintf(stderr,"%d",buf[0]) ;
	for(i=1;i<n;i++)
	{
		fprintf(stderr," %d",buf[i]) ;
	}
	fprintf(stderr,"\n") ;
*/
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
