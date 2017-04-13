#include<cstdio>
#include<vector>
using namespace std;

int n,k;

vector<int> adj[101];
bool free2[101];
int left[101];
bool color[101];

bool go(int v){
	//printf("v=%d\n",v);
	if(!color[v]) return false;
	color[v]=false;
	for(int i=0; i<adj[v].size(); i++){
		int u=adj[v][i];
		//printf("u=%d, left[u]=%d\n",u,left[u]);
		if(left[u]==-1 || go(left[u])){
			//printf("%d z %d\n",v,u);
			left[u]=v;
			free2[v]=false;
			return true;
		}
	}
	return false;
}

bool add_path(){
	for(int i=0; i<n; i++) color[i]=true;
	//printf("n=%d\n",n);
	for(int i=0; i<n; i++){
		if(free2[i] && go(i)) {
			//printf("dalo rade: %d\n", i);
			free2[i]=false;
			return true;
		}
	}
	//printf("false\n");
	return false;
}

int flow(){
	int res=0;
	for(int i=0; i<n; i++) {free2[i]=true; left[i]=-1;}
/*	for(int i=0; i<n; i++){
		printf("%d) ",i);
		for(int j=0; j<adj[i].size(); j++) printf("%d, ",adj[i][j]);
		printf("\n");
	}*/
	while(add_path()) res++;
	//printf("res=%d\n",res);
	return res;
}

main(){
int t[101][29];
	int s; scanf("%d",&s);
	for(int a=1; a<=s; a++){
		scanf("%d %d",&n,&k);
		for(int i=0; i<n; i++) adj[i].clear();
		for(int i=0; i<n; i++){
			for(int j=0; j<k; j++) scanf("%d", &t[i][j]);
		}
		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			bool ok=true;
			for(int l=0; l<k && ok; l++)
				ok &= (t[i][l]<t[j][l]);
			if(ok)
			adj[i].push_back(j);
		}
		printf("Case #%d: %d\n",a, n-flow());
	//	printf("n=%d\n",n);
	}
}
