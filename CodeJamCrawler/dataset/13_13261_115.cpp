#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int f[105][105];
int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int n,m;
		scanf("%d %d",&n,&m);
		int t[105]={},y[105]={};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&f[i][j]);
				t[i]=max(t[i],f[i][j]);
				y[j]=max(y[j],f[i][j]);
			}
		}
		bool ok=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(f[i][j]!=min(t[i],y[j])){
					ok=false;
				}
			}
		}
		printf("Case #%d: ",q);
		if(ok) puts("YES");
		else puts("NO");
	}
}