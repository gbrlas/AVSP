#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <utility>

using namespace std;


#define llong long long 
const double pi = acos(-1.0);

const int N = 1005;
double d[N];
int n,a[N],vis[N];


void init(){
	int i,j,k;
	d[1] = 0;
	for(i = 2;i<N;i++){
		d[i] = 0;
		for(j = 2;j<i;j++){
			d[i] += d[j];
		}
		d[i] *= 2;
		d[i] += 2;
		d[i] /= i-1;
	}
}

void dfs(int v,int &cnt){
	int i,j,k;
	if(vis[v])return ;
	vis[v] = 1;
	dfs(a[v],++cnt);
}
int main(){
	freopen("D-large.in","r",stdin);
	//freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,t,nc = 0;
	scanf("%d",&t);
	init();
	while(t--){
		scanf("%d",&n);
		for(i = 1;i<=n;i++)scanf("%d",&a[i]);
		memset(vis,0,sizeof(vis));
		double ans = 0;
		for(i = 1;i<=n;i++){
			if(!vis[i]){
				k = 0;
				dfs(i,k);
				ans += d[k];
			}
		}
		printf("Case #%d: %.6lf\n",++nc,ans);
	}
	return 0;
}