#include <cstdio>
#include <cstdlib>
#include <cstring>

int calc(void)
{
	int i, n ;
	char tmp[10] ;
	int pos, po=1, pb=1, io=0, ib=0 ;
	int O[110], no=0 ;
	int B[110], nb=0 ;
	int all[110] ;
	int ans = 0, taro, tarb, p ;
	
	scanf("%d",&n) ;
	
	for(i=0;i<n;i++)
	{
		scanf("%s%d",tmp,&pos) ;
		if(tmp[0]=='O')
		{
			O[no++] = pos ;
		}
		else
		{
			B[nb++] = pos ;
		}
		all[i] = tmp[0] ;
	}
	
	pos = 0 ;
	taro = O[0] ;
	tarb = B[0] ;
	while(io<no||ib<nb)
	{
		ans++ ;
		p = 0 ;
		if(io<no)
		{
			if(taro!=po)
			{
				if(taro>po)
				{
					po++ ;
				}
				else
				{
					po-- ;
				}
			}
			else if(all[pos]=='O')
			{
				p = 1 ;
				pos++ ;
				io++ ;
				taro = O[io] ;
			}
		}
		if(ib<nb)
		{
			if(tarb!=pb)
			{
				if(tarb>pb)
				{
					pb++ ;
				}
				else
				{
					pb-- ;
				}
			}
			else if(all[pos]=='B'&&p==0)
			{
				pos++ ;
				ib++ ;
				tarb = B[ib] ;
			}
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
		printf("Case #%d: %d\n",i,calc()) ;
	}

	return 0 ;
}
