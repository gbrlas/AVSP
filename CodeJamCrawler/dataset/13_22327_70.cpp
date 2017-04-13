#include <cstdio>
#include <cstring>

using namespace std;

int g[310][310];
int M[110][110];
int use[310];
int stack[310];
int n,m;

int dfs( int x ){
	use[x]=stack[x]=1;
	for (int i=0; i<n+m; ++i)
		if (g[x][i])
			if (use[i]==0){
				if (!dfs(i)) return 0;
			}else
				if (stack[i]) return 0;
	stack[x]=0;
	return 1;
}

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		scanf("%d %d", &n,&m);
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				scanf("%d", &M[i][j]);
		memset(g,0,sizeof(g));
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j){
				for (int k=0; k<m; ++k)
					if (M[i][j]>M[i][k])
						g[i][k+n]=1;
				for (int k=0; k<n; ++k)
					if (M[i][j]>M[k][j])
						g[j+n][k]=1;
			}
		memset(use,0,sizeof(use));
		int flag=1;
		for (int i=0; i<n+m; ++i)
			if (use[i]==0)
				if (! dfs(i)){
					flag=0; break;
				}
		printf("Case #%d: ", T);
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
