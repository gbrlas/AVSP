#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#define REP(op,s,t) for (op=(s);op<=(t);op++) 
#define DEP(op,s,t) for (op=(s);op>=(t);op--) 
#define sz size()
#define maxlong 98765432
#define PB push_back
#define MXN 110
using namespace std;
typedef long long LL;
typedef vector<long> VL;
long T,r,i,j,k,X1,X2,Y1,Y2,x,y,ans;
bool g[MXN][MXN],gn[MXN][MXN];

bool check(){
	long i,j;
	REP(i,1,x) REP(j,1,y) if (g[i][j]) return 1;
	return 0;
}
int main(){
	scanf("%d",&T);
	for (long Ti=0;Ti<T;Ti++){
		scanf("%d",&r);
		x=0;y=0;ans=0;
		REP(i,1,r){
			scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
			x=max(x,X2);y=max(y,Y2);
			REP(j,X1,X2) REP(k,Y1,Y2) g[j][k]=1;
		}
		while (check()){
			ans++;
			REP(i,1,x) REP(j,1,y) gn[i][j]=0;
			REP(i,1,x) REP(j,1,y){
				if (!g[i-1][j]&&!g[i][j-1]) {gn[i][j]=0;continue;}
				if (g[i-1][j]&&g[i][j-1]) {gn[i][j]=1;continue;}
				gn[i][j]=g[i][j];
			}
			REP(i,1,x) REP(j,1,y) g[i][j]=gn[i][j];
		}
		printf("Case #%d: %d\n",Ti+1,ans);
		REP(i,1,x) REP(j,1,y) g[i][j]=0;
	}
}
