#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int d[10010],l[10010];
int n,fd,ans,T;

int dfs(int x,int can,int st){
	if (can>=fd) return 1;
	//if (T==5)
	//	printf("%d %d\n", x,can);
	int tt=st;
	for (int i=st+1; i<n; ++i)
		if (d[i]<=can)
			tt=i;
	for (int i=st+1; i<=tt; ++i)
		if (d[i]<=can){
			int t=min(d[i]-d[x],l[i])+d[i];
			if (dfs(i,t,tt)==1) return 1;
		}
	return 0;
}

int main(){
	int test=0;
	scanf("%d",&test);
	for (T=1; T<=test; ++T){
		printf("Case #%d: ", T);
		scanf("%d",&n);
		for (int i=0; i<n; ++i)
			scanf("%d%d",d+i,l+i);
		scanf("%d",&fd);
		if (dfs(0,d[0]*2,0)==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
