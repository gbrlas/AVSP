#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[808][808] ;
int listA[808];
int listB[808];
int n;
__int64 solve(int A[],int B[])
{
	int i,j;
	__int64 sum = 0 ;
	for(i = 0 ; i < n ; i ++)
	{
		sum += A[i]*B[n-i-1] ;
	}
	return sum ;
}
__int64 solve_2(int A[],int B[])
{
	int i,j;
	__int64 sum = 0 ;
	for(i = 0 ; i < n ; i ++)
	{
		sum += A[i]*B[i] ;
	}
	return sum ;
}
int main()
{
	int T,i,j;
	__int64 temp ;
	__int64 ans ;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	while(1 == scanf("%d",&T))
	{
		for(i = 1 ; i <= T ; i ++)
		{
			scanf("%d",&n);
			for(j = 0 ; j < n ; j ++)
			{
				scanf("%d",&listA[j]);
			}
			for(j = 0 ; j < n ; j ++)
			{
				scanf("%d",&listB[j]);
			}
			sort(&listA[0],&listA[n]);
			sort(&listB[0],&listB[n]);
			ans = solve(listA,listB) ;
			temp = solve(listB,listA);
			if(temp < ans)
				ans = temp ;
			temp = solve_2(listA,listB);
			if(temp < ans)
				ans = temp ;
			printf("Case #%d: %I64d\n",i,ans);

		}
	}
	return 0 ;
}