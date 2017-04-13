#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const double eps=1e-6;

struct node{
	int B,E,w;
}walkway[1024];

bool cmp(node a,node b){
	return a.w<b.w;
}

int main(){
	int cases;
	scanf("%d",&cases);
	int X,S,R,t,N;
	for(int T=1;T<=cases;++T){
		scanf("%d%d%d%d%d",&X,&S,&R,&t,&N);
		for(int i=0;i<N;++i){
			scanf("%d%d%d",&walkway[i].B,
				       &walkway[i].E,
				       &walkway[i].w);
			X-=walkway[i].E-walkway[i].B;
		}
		sort(walkway,walkway+N,cmp);

		double ans=0.0;
		double time=t;
		if(R*t<=X){
			ans=t+(X-R*t)*1.0/S;
			time=0.0;
		}else{
			ans=X*1.0/R;
			time-=ans;
		}
		for(int i=0;i<N;++i){
			double len=walkway[i].E-walkway[i].B;
			double tmp;
			if(time>eps){
				tmp=len/(walkway[i].w+R);
				if(tmp<time+eps){
					time-=tmp;
				}else{
					tmp=time+(len-(walkway[i].w+R)*time)/(S+walkway[i].w);
					time=0.0;
				}
			}else{
				tmp=len/(S+walkway[i].w);
			}
			ans+=tmp;
		}
		printf("Case #%d: %.10f\n",T,ans);
	}
	return 0;
}
