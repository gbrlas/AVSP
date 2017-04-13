#include <cstdio>
#include <cstdlib>
#include <cstring>

int mx, my ;
char map[110][110] ;
char c[110][110] ;
char cm[110][110] ;
int d[256][2][2] ;
int ans ;

void go(int x, int y)
{
	int nx, ny ;
	int cx, cy ;
	
	if(y==my)
	{
		ans = (ans+1)%1000003 ;
		return ;
	}
	
	nx = x+1 ;
	ny = y ;
	if(nx==mx)
	{
		nx = 0 ;
		ny++ ;
	}

	c[y][x] = 0 ;
	
	cx = x+d[map[y][x]][0][0] ;
	if(cx==-1)
	{
		cx = mx-1 ;
	}
	if(cx==mx)
	{
		cx = 0 ;
	}
	
	cy = y+d[map[y][x]][0][1] ;
	if(cy==-1)
	{
		cy = my-1 ;
	}
	if(cy==my)
	{
		cy = 0 ;
	}
	
	if(cm[cy][cx]==0)
	{
		cm[cy][cx] = 1 ;
		go(nx,ny) ;
		cm[cy][cx] = 0 ;
	}
	
	c[y][x] = 1 ;
	
	cx = x+d[map[y][x]][1][0] ;
	if(cx==-1)
	{
		cx = mx-1 ;
	}
	if(cx==mx)
	{
		cx = 0 ;
	}

	cy = y+d[map[y][x]][1][1] ;
	if(cy==-1)
	{
		cy = my-1 ;
	}
	if(cy==my)
	{
		cy = 0 ;
	}

	if(cm[cy][cx]==0)
	{
		cm[cy][cx] = 1 ;
		go(nx,ny) ;
		cm[cy][cx] = 0 ;
	}
}

int sol(void)
{
	int i ;

	scanf("%d%d",&my,&mx) ;
	for(i=0;i<my;i++)
	{
		scanf("%s",map[i]) ;
	}
	
	ans = 0 ;
	
	memset(cm,0,sizeof(cm)) ;
	
	go(0,0) ;
	
	return ans ;
}

int main(void)
{
	int i, t ;

	d['|'][0][0] = 0 ;
	d['|'][0][1] = 1 ;
	d['|'][1][0] = 0 ;
	d['|'][1][1] = -1 ;

	d['-'][0][0] = 1 ;
	d['-'][0][1] = 0 ;
	d['-'][1][0] = -1 ;
	d['-'][1][1] = 0 ;

	d['\\'][0][0] = 1 ;
	d['\\'][0][1] = 1 ;
	d['\\'][1][0] = -1 ;
	d['\\'][1][1] = -1 ;

	d['/'][0][0] = -1 ;
	d['/'][0][1] = 1 ;
	d['/'][1][0] = 1 ;
	d['/'][1][1] = -1 ;

	scanf("%d",&t) ;
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: %d\n",i,sol()) ;
	}

	return 0 ;
}
