#include <stdio.h>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
struct Node
{
	set<int> S;
	int id ;
	int col ;
	int flag ;
}node[1000001];
int Path[1000001];
set<int>::iterator ip;
int A,B ;
int num ;
int P ;
void dfs(int now,int col)
{
	int i,j;
	set<int>::iterator it;
	if(node[now].S.size() == 0)
		return ;
	for(it = node[now].S.begin() ; it != node[now].S.end() ; it ++)
	{
		for(j = 0 ; j < num ; j ++)
		{
			if(node[j].flag || node[j].S.find((*it)) == node[j].S.end())
				continue ;
			node[j].col = col ;
			node[j].flag = 1 ;
			dfs(j,col);
		}
	}
}
void solve()
{
	int i,j,x;
	num = 0 ;
	int ans ;
	for(i = A ; i <= B ; i ++)
	{
		j = i ; 
		x = 2 ;
		node[num].S.clear() ;
		node[num].id = num ;
		node[num].col = num ;
		node[num].flag = 0 ;
		while(j != 1)
		{
			if(j%x == 0)
			{
				j /= x ;
				if(x < P)
					continue ;
				if(node[num].S.find(x) != node[num].S.end())
					continue ;
				node[num].S.insert(x) ;
			}
			else
				x ++ ;
		}

		num ++ ;
	}
	/*for(i = 0 ; i < num ; i ++)
	{
		for(it = node[i].S.begin() ; it != node[i].S.end() ; it ++)
		{
			printf("%d\n",(*it));
		}
		printf("**********************\n");
	}*/
	for(i = 0 ; i < num ; i ++)
	{
		if(node[i].flag)
			continue ;
		node[i].flag = 1 ;
		dfs(i,node[i].col);
	}
	memset(Path,0,sizeof(Path));
	for(i = 0 ; i < num ; i ++)
	{
		Path[node[i].col] = 1 ;
	}
	ans = 0 ;
	for(i = 0 ; i < num ; i ++)
	{
		if(Path[i])
			ans ++ ;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin) ;
	freopen("sh.out","w",stdout) ;
	int i,T ;
	while(1 == scanf("%d",&T))
	{
		for(i = 1 ; i <= T ; i ++)
		{
			scanf("%d %d %d",&A,&B,&P);
			printf("Case #%d: ",i);
			solve();
		}
	}
	return 0 ;
}