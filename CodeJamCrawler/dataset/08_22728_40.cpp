#include <stdio.h>
#include <algorithm>
using namespace  std;
bool Com(int a,int b)
{
	return a > b ;
}
struct Node
{
	int next[20];
	int len ;
}node[20];
int main()
{
	int i,j,P,K,L,N,p;
	int list[101];
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	while(1 == scanf("%d",&N))
	{
		for(i = 1 ; i <= N ; i ++)
		{
			scanf("%d %d %d",&P,&K,&L);
			for(j = 0 ; j < L ; j ++)
			{
				scanf("%d",&list[j]) ;
			}
			sort(&list[0],&list[L],Com);
			int index = 0 ;
			for(j = 0 ; j < K ; j ++)
			{
				node[j].len = 0 ;
			}
			while(index < L)
			{
				for(j = 0 ; j < K ; j ++)
				{
					node[j].next[node[j].len ++] = list[index ++] ;
					if(index == L)
						break ;
				}
			}
			int a,b;
			int ans = 0 ;
			for(j = 0 ; j < K ; j ++)
			{
				for(p = node[j].len-1 ; p >= 0 ; p --)
				{
					ans += node[j].next[p]*(p+1);
				}
			}
			printf("Case #%d: ",i);
			printf("%d\n",ans);
		}
	}
	return 0;
}