#include <stdio.h>
#include <iostream>

int ans[10000] , res[100000];

int main()
{
	freopen("C-small-attempt2.in","r",stdin);
	freopen("shark.out","w",stdout);
	int text , Case ;
	while ( 1 == scanf("%d",&text))
	{
		for (Case = 0 ; Case < text ; Case ++)
		{
			int n , i ; 
			scanf("%d",&n) ; 
			memset(ans , -1 , sizeof(ans)) ;
			int Count , ID = 0 ;
			for ( i = 1 ; i <= n ; i ++)
			{
				Count = 0 ;
				while (Count != i)
				{
					ID = (ID + 1) ;
					if(ID > n)
						ID -= n ;
					if(ans[ID] == -1)
						Count ++ ;
				
				}
				ans[ID] = i ;
			}
			int m , temp;
			scanf("%d",&m);
			for ( i = 0 ; i < m ; i ++)
			{
				scanf("%d",&temp) ;
				res[i] = ans[temp] ; 
			}
			printf("Case #%d:",Case+1);
			for ( i = 0 ; i < m ; i ++)
				printf(" %d",res[i]);
			printf("\n");
		//	for ( i = 1 ; i <= n ; i ++)
		//		printf("%d ",ans[i]);
		//	printf("\n");
		}
	}
	return 0 ; 
}