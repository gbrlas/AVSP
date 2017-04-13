#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;

int fExit,N,K,j,wn,w[400],Ci[400],a[400][400],was[2000000],T,tq,act[400],Kt[400],i,x;

void rec(int cur_mask){
	if(fExit)return ;
	if(cur_mask==(1<<N)-1){
		fExit=1;
		for(int j=1;j<=wn;j++)printf(" %d",w[j]);
		puts("");
		return ;
	}
	if(was[cur_mask])return ;
	was[cur_mask]=1;
	for(int i=1;i<=N;i++)if((cur_mask&(1<<(i-1)))==0&&act[Kt[i]]){
		w[++wn]=i;
		--act[Kt[i]];for(int j=1;j<=Ci[i];j++)++act[a[i][j]];
		rec(cur_mask+(1<<(i-1)));		
		++act[Kt[i]];for(int j=1;j<=Ci[i];j++)--act[a[i][j]];
		--wn;
	}
}

int main (int argc, char * const argv[]) {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(tq=1;tq<=T;tq++){
		scanf("%d%d",&K,&N);
		wn=0;
		for(i=1;i<=200;i++)act[i]=0;
		for(i=1;i<=K;i++){
			scanf("%d",&x);
			++act[x];
		}
		fExit=0;
		for(i=0;i<(1<<N);i++)was[i]=0;
		for(i=1;i<=N;i++){
			scanf("%d%d",&Kt[i],&Ci[i]);
			for(j=1;j<=Ci[i];j++)scanf("%d",&a[i][j]);
		}
		printf("Case #%d:",tq);
		rec(0);
		if(!fExit)puts(" IMPOSSIBLE");
	}
    return 0;
}
