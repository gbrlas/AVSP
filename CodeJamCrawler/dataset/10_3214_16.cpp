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
#define MXN 1100
using namespace std;
typedef long long LL;
typedef vector<long> VL;
long m[MXN],i,j,p,T,x,ans(0),t;
long P[20];
bool v[20][MXN];

int main(){
	scanf("%d",&T);
	for (long Ti=1;Ti<=T;Ti++){
		scanf("%d",&p);
		P[0]=1;ans=0;
		REP(i,1,p) P[i]=P[i-1]*2;
		REP(i,1,P[p]) scanf("%d",&m[i]);
		DEP(i,p-1,0) REP(j,1,P[i]) scanf("%d",&x);
		REP(i,1,p) REP(j,0,1024) v[i][j]=0;
		REP(i,1,P[p]){
			t=1;
			REP(j,1,p){
				t*=2;
				if (j>m[i]&&!v[j][(i-1)/t]){
					ans++;v[j][(i-1)/t]=1;
				}
			}
		}
		printf("Case #%d: %d\n",Ti,ans);
	}
}
