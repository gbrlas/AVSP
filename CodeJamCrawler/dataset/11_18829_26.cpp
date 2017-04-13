#include<stdio.h>
#include<algorithm>
#define eps 1e-8
using namespace std;
double sol;
double X,S,R,dif,t;
int N;
struct benzi{
	double d,v;
}nr[1010];
struct cmp{
	bool operator()(benzi a,benzi b)const{
		return (a.v<b.v);
	}
};
void solve(){
	int i;
	double ax,d;
	sort(nr,nr+N,cmp());
	ax=dif/R;
	if(ax<=t){
		sol+=ax;
		t-=ax;
	}
	else{
		sol=t;
		dif-=t*R;
		sol+=(dif/S);
		t=0;
	}
	if(-eps<=t && t<=eps)
		t=0;
	for(i=0;i<N;++i){
		d=nr[i].d;
		ax=d/(R+nr[i].v);
		if(!t){
			ax=d/(S+nr[i].v);
			sol+=ax;
			continue;
		}
		if(ax<=t){
			sol+=ax;
			t-=ax;
		}
		else{
			sol+=t;
			d-=t*(R+nr[i].v);
			ax=d/(S+nr[i].v);
			sol+=ax;
			t=0;
		}
		if(-eps<=t && t<=eps)
			t=0;
	}
}

int main(){
	freopen("air.in","r",stdin);
	freopen("air.out","w",stdout);
	int T,tt,i;
	double inc,sf;
	scanf("%d",&T);
	for(tt=1;tt<=T;++tt){
		sol=0;
		scanf("%lf%lf%lf%lf%d",&X,&S,&R,&t,&N);
		dif=X;
		for(i=0;i<N;++i){
			scanf("%lf%lf%lf",&inc,&sf,&nr[i].v);
			nr[i].d=sf-inc;
			dif-=nr[i].d;
		}
		solve();
		printf("Case #%d: %.7lf\n",tt,sol);
	}
	return 0;
}
