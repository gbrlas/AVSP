#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

vector<int> g[3000],h[3000];
int n,m,N;
bool in[3000];
int col[3000];

int getans(){
	vector<int> now;
	now.clear();
	for (int i=0;i<n;i++) if (in[i]) now.PB(i);//,printf("%d ",i);puts("");
	for (int i=0;i<n;i++)
	if (in[i]){
		for (int j=0;j<g[i].size();j++){
			int k=g[i][j];
			if (!in[k]) continue;
			if (k<i) continue;
			//printf("cut %d %d\n",i,k);
			swap(g[i][j],g[i][g[i].size()-1]);
			g[i].pop_back();
			for (int z=i+1;z<k;z++) in[z]=false;
			int a1=getans();
			memset(in,false,sizeof(in));
			for (int z=0;z<now.size();z++) if (now[z]>=i&&now[z]<=k) in[now[z]]=true;
			
			int ci=col[i],ck=col[k];
			int a2=getans();
			int ans=min(a1,a2);
			int c1=ci,c2=col[i];
			if (c1<=ans&&c2<=ans){
				for (int z=i;z<=k;z++) if (col[z]==c1) col[z]=c2;
				else if (col[z]==c2) col[z]=c1;
			}
			else col[i]=min(c1,c2);
			c1=ck,c2=col[k];
			if (c1<=ans&&c2<=ans){
				for (int z=i;z<=k;z++) if (col[z]==c1) col[z]=c2;
				else if (col[z]==c2) col[z]=c1;
			}
			else col[k]=min(c1,c2);
			g[i].PB(k);
			//printf("after %d %d\n",i,k);	for (int z=0;z<n;z++) printf("%d ",col[z]);puts("");
			return ans;
		}
	}
	int k=rand();
	for (int z=0;z<now.size();z++) col[now[z]]=(z+k)%now.size()+1;
	return now.size();
}
int o[3000],p[3000];

int next(int i,int la){
	for (int z=0;z<g[i].size();z++) if (g[i][z]==la) return g[i][(z+1)%g[i].size()];
}

bool check(int i){
	bool vi[20];
	for (int z=0;z<g[i].size();z++){
		int j=g[i][z];
		//printf("st: %d ",i);
		memset(vi,false,sizeof(vi));
		vi[col[i]]=true;
		int la=i;
		for (;j!=i;){
			//printf("%d ",j);
			vi[col[j]]=true;
			int k=j;
			j=next(j,la);
			la=k;
		}
		//puts("");
		for (int t=1;t<=N;t++) if (!vi[t]) return false;
	}
	return true;
}

int main(){
	srand(time(0));
	int T,ti=0;
	for (scanf("%d",&T);T--;){
		printf("Case #%d: ",++ti);
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) g[i].clear();//,g[i].PB((i+1)%n),g[i].PB((i+n-1)%n);
		for (int i=0;i<m;i++)	scanf("%d",&o[i]);
		for (int i=0;i<m;i++)	scanf("%d",&p[i]);
		for (int i=0;i<m;i++){
			o[i]--;p[i]--;
			g[o[i]].PB(p[i]);
			g[p[i]].PB(o[i]);
		}
		again:;
		memset(in,true,sizeof(in));
		memset(col,0,sizeof(col));
		N=getans();
		for (int i=0;i<n;i++) h[i]=g[i],g[i].PB((i+1)%n),g[i].PB((i+n-1)%n);
		for (int i=0;i<n;i++) sort(g[i].begin(),g[i].end());
		bool ok=true;
		for (int i=0;i<n;i++) if (!check(i)) ok=false;
		if (!ok){
			for (int i=0;i<n;i++) g[i]=h[i];
			goto again;
		}		
		printf("%d\n",N);
		for (int i=0;i<n;i++){
			if (i) printf(" ");
			printf("%d",min(col[i],N));
		}
		puts("");
	}
    return 0;
}
