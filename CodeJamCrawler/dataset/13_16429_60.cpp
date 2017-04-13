#include <cstdio>
#include <vector>

using namespace std;

const int N = 21;
const int K = 41;
const int XX = 201;

bool dp[1<<N];
int link[1<<N];

int k[K];
int ne[N];

int ile[XX];

vector<int> G[N];

void test(){
	int t, n;
	scanf("%d %d", &t, &n);
	fill(ile, ile+XX, 0);
	for(int i=1; i<=t; i++){
		scanf("%d", k+i);
		ile[k[i]]++;
	}
	int X = 0;
	for(int i=1; i<=n; i++){
		int l;
		scanf("%d %d", ne+i, &l);
		X = max(ne[i], X);
		ile[ne[i]] -- ;
		G[i].clear();
		for(int x=1; x<=l; x++){
			int a;
			scanf("%d", &a);
			ile[a] ++;
			X = max(X, a);
			G[i].push_back(a);
		}
	}
	X++;
	for(int i=1; i<X; i++) if(ile[i]<0){
		puts("IMPOSSIBLE");
		return ;
	}
	fill(dp, dp+(1<<n), 0);
	fill(link, link+(1<<n), 0);
	dp[0] = 1;
	link[0] = -1;

	for(int m=0; m<(1<<n); m++){
		if(!dp[m]) continue;
		
		for(int x=1; x<=n; x++){
			int nm = m|(1<<(x-1));
			if(m&(1<<(x-1))) continue;
			fill(ile, ile+X, 0);
			for(int i=1;i<=t;i++) ile[k[i]]++;
			for(int y=1; y<=n; y++){
				if(nm&(1<<(y-1)))continue;
				ile[ne[y]]--;
				for(vector<int>::iterator it = G[y].begin(); it != G[y].end(); it++){
					ile[*it]++;
				}
			}

			if(ile[ne[x]]<=0) continue;

			bool ok =true;

			for(int i=0; i<X; i++){
				if(ile[i] < 0){
					ok=false;
					break;
				}
			}
			if(!ok) continue;

			if(dp[nm]&&link[nm]>x);
			dp[nm]=1;
			link[nm]=x;
		}
	}
	if(dp[(1<<n)-1]){
		int x = (1<<n)-1;
		vector<int> res;
		while(link[x]!=-1){
			res.push_back(link[x]);
			x^=1<<(link[x]-1);
		}
		for(vector<int>::iterator it = res.begin(); it != res.end(); it++){
			printf("%d ",*it);
		}
		puts("");
	} else {
		puts("IMPOSSIBLE");
	}
/*
	for(int i=0; i<(1<<n); i++){
		printf("%d: ", i);
		for(int x=1; x<=n; x++){
			if(i&(1<<(x-1)))printf("%d",x);
		}
		printf("; %d %d\n", dp[i], link[i]);
	}
*/	
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		printf("Case #%d: ", i);
		test();
	}
}
