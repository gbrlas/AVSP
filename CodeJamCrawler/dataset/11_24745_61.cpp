#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std ;

int map[510][510] ;
int mx, my ;
int ans ;

int in(int x, int y)
{
	if(x>=0&&y>=0&&x<mx&&y<my)
	{
		return 1 ;
	}
	return 0 ;
}

void calc(int cx, int cy)
{
	int s, x, y, y1, y2, x1, x2 ;
	int sumx = 0, sumy = 0 ;
	
	s = 1 ;
	while(in(cx-s,cy-s)&&in(cx+s,cy+s))
	{
		y1 = cy+s ;
		y2 = cy-s ;
		for(x=cx-s+1;x<=cx+s-1;x++)
		{
			sumx += map[x][y1]*(x-cx) ;
			sumy += map[x][y1]*(y1-cy) ;
			sumx += map[x][y2]*(x-cx) ;
			sumy += map[x][y2]*(y2-cy) ;
		}
		
		x1 = cx+s ;
		x2 = cx-s ;
		for(y=cy-s+1;y<=cy+s-1;y++)
		{
			sumx += map[x1][y]*(x1-cx) ;
			sumy += map[x1][y]*(y-cy) ;
			sumx += map[x2][y]*(x2-cx) ;
			sumy += map[x2][y]*(y-cy) ;
		}
		
		if(sumx==0&&sumy==0)
		{
			if(s*2+1>ans)
			{
				ans = s*2+1 ;
			}
		}

		sumx += map[cx+s][cy+s]*s ;
		sumy += map[cx+s][cy+s]*s ;
		sumx += map[cx+s][cy-s]*s ;
		sumy += map[cx+s][cy-s]*-s ;
		sumx += map[cx-s][cy+s]*-s ;
		sumy += map[cx-s][cy+s]*s ;
		sumx += map[cx-s][cy-s]*-s ;
		sumy += map[cx-s][cy-s]*-s ;
		
		s++ ;
	}
}

void calc2(int cx1, int cy1)
{
	int cx2 = cx1+1, cy2 = cy1+1 ;
	int s, sx1 = 0, sx2 = 0, sy1 = 0, sy2 = 0 ;
	int x, y, x1, x2, y1, y2 ;
	
	if(in(cx2,cy2)==0)
	{
		return ;
	}
	
	s = 1 ;
	while(in(cx1-s+1,cy1-s+1)&&in(cx2+s-1,cy2+s-1))
	{
		y1 = cy1-s+1 ; y2 = cy2+s-1  ;
		for(x=cx1-s+2;x<=cx1;x++)
		{
			sx1 += map[x][y1]*((cx1-x)*2+1) ;
			sy1 += map[x][y1]*(s*2-1) ;
			sx1 += map[x][y2]*((cx1-x)*2+1) ;
			sy2 += map[x][y2]*(s*2-1) ;
		}
		for(x=cx2;x<=cx2+s-2;x++)
		{
			sx2 += map[x][y1]*((x-cx2)*2+1) ;
			sy1 += map[x][y1]*(s*2-1) ;
			sx2 += map[x][y2]*((x-cx2)*2+1) ;
			sy2 += map[x][y2]*(s*2-1) ;
		}
		
		x1 = cx1-s+1 ; x2 = cx2+s-1 ;
		for(y=cy1-s+2;y<=cy1;y++)
		{
			sx1 += map[x1][y]*(s*2-1) ;
			sy1 += map[x1][y]*((cy1-y)*2+1) ;
			sx2 += map[x2][y]*(s*2-1) ;
			sy1 += map[x2][y]*((cy1-y)*2+1) ;
		}
		for(y=cy2;y<=cy2+s-2;y++)
		{
			sx1 += map[x1][y]*(s*2-1) ;
			sy2 += map[x1][y]*((y-cy2)*2+1) ;
			sx2 += map[x2][y]*(s*2-1) ;
			sy2 += map[x2][y]*((y-cy2)*2+1) ;
		}

		if(sx1==sx2&&sy1==sy2&&s*2>ans)
		{
			ans = s*2 ;
		}
		
		//cx1-s+1 cy1-s+1 cy1+s-1 cy2+s-1
		sx1 += map[cx1-s+1][cy1-s+1]*(s*2-1) ;
		sy1 += map[cx1-s+1][cy1-s+1]*(s*2-1) ;
		sx1 += map[cx1-s+1][cy2+s-1]*(s*2-1) ;
		sy2 += map[cx1-s+1][cy2+s-1]*(s*2-1) ;
		sx2 += map[cx2+s-1][cy1-s+1]*(s*2-1) ;
		sy1 += map[cx2+s-1][cy1-s+1]*(s*2-1) ;
		sx2 += map[cx2+s-1][cy2+s-1]*(s*2-1) ;
		sy2 += map[cx2+s-1][cy2+s-1]*(s*2-1) ;
		
		s++ ;
	}
}

void sol(int tc)
{
	int x, y ;

	ans = 0 ;
	scanf("%d%d%*d",&my,&mx) ;
	
	for(y=0;y<my;y++)
	{
		for(x=0;x<mx;x++)
		{
			scanf("%1d",&map[x][y]) ;
		}
	}
	
	for(x=0;x<mx;x++)
	{
		for(y=0;y<my;y++)
		{
			calc(x,y) ;
			calc2(x,y) ;
		}
	}
	
	if(ans<3)
	{
		printf("Case #%d: IMPOSSIBLE\n",tc) ;
	}
	else
	{
		printf("Case #%d: %d\n",tc,ans) ;
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
