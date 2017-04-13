#include <stdio.h>

struct Point
{
	__int64 x , y ; 
};
Point point[1000] ;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int n, A, B, C, D, x , y , M ;
	int text , Case ;
	while ( 1 == scanf("%d",&text))
	{
		for (Case = 0 ; Case < text ; Case ++)
		{
			scanf("%d%d%d%d%d%d%d%d",&n,&A,&B,&C,&D,&x,&y,&M) ;
			int length = 0  , i , j , k ;
			point[length].x = x , point[length++].y = y ;
			for( i = 1 ; i < n ; i ++)
			{
				point[length].x = (A*point[length-1].x+B) %M ;
				point[length].y = (C*point[length-1].y+D) %M ;
				length++ ;
			}
			int ans = 0;
			for ( i = 0 ; i < n ; i ++)
				for ( j = i + 1 ; j < n ; j ++)
					for ( k = j + 1 ; k < n ; k ++)
					{
						if((point[i].x+point[j].x+point[k].x)%3 == 0 
							&&(point[i].y+point[j].y+point[k].y)%3 == 0 )
							ans ++;
					}
					printf("Case #%d: %d\n",Case +1 ,ans);
		}
	}
	return 0 ; 
}