#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace  std;
bool Com(long long a,long long b)
{
	return a > b ;
}
struct Node
{
	long long next[2000];
	int len ;
}node[2000];
long long list[2000];
int main()
{
	int i,j,P,K,L,N,p;
	//int list[101];
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	while(1 == scanf("%d",&N))
	{
		for(i = 1 ; i <= N ; i ++)
		{
			scanf("%d %d %d",&P,&K,&L);
			for(j = 0 ; j < L ; j ++)
			{
				cin >> list[j] ;
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
			long long ans = 0 ;
			for(j = 0 ; j < K ; j ++)
			{
				for(p = node[j].len-1 ; p >= 0 ; p --)
				{
					ans += node[j].next[p]*(p+1);
				}
			}
			printf("Case #%d: ",i);
			cout << ans << endl ;
		}
	}
	return 0;
}