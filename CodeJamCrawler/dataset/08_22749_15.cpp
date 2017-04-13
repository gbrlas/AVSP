#include <stdio.h>
#include <algorithm>
using namespace std;
int Case,T;
char cmd[2000];
char temp[2000];
int list[10];
int Path[10];
int k;
int len ;
int Min;
void solve()
{
	int i,j;
	int ans ;
	int l = strlen(cmd);
	int t = 0 ;
	for(i = 0 ; i < l ;)
	{
		for(j = 0 ; j < len ; j ++)
		{
			temp[i++] = cmd[list[j]-1+t];
		}
		t += k ;
	}
	ans = 0 ;
	for(i = 0 ; i < l ;)
	{
		j = i ;
		while(j+1 < l && temp[j] == temp[j+1])
		{
			j ++ ;
		}
		j ++ ;
		i = j ;
		ans ++ ;
	}
	if(Min == -1 || ans < Min)
		Min = ans ;
}
void dfs()
{
	int i;
	if(len == k)
	{
		solve();
		return ;
	}
	for(i = 1 ; i <= k ; i ++)
	{
		if(Path[i])
			continue ;
		Path[i] = 1 ;
		list[len ++] = i ;
		dfs();
		len -- ;
		Path[i] = 0 ;
	}
}
int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D.out","w",stdout);
	scanf("%d",&T);
	for(Case = 1 ; Case <= T ; Case ++)
	{
		scanf("%d",&k);
		scanf("%s",cmd);
		memset(Path,0,sizeof(Path));
		len = 0 ;
		Min = -1 ;
		dfs();
		printf("Case #%d: %d\n",Case,Min);
	}
	return 0;
}