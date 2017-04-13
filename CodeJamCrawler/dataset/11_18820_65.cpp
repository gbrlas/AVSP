#include<stdio.h>
#include<algorithm>
using namespace std;
long long N,t,C,L,sol;
pair <long long,int> nr[1100];
long long nn[1000100];
void solve(){
	int i,j,lim;
	long long s=0;
	for(i=0,j=0;i<N;++i,++j){
		if(j==C)
			j-=C;
		nn[i]=(nr[j].first<<1);
	}
	for(lim=0;lim<=N && s<t;++lim)
		s+=nn[lim];
	--lim;
	sort(nr,nr+C);
	for(i=C-1;i>=0 && L;--i){
		if(s-t>nr[i].first*2){
			--L;
			nn[lim]-=(s-t)/2;
			s=t;
		}
		for(j=nr[i].second;j<N && L;j+=C){
			if(j>lim){
				nn[j]>>=1;
				--L;
			}
		}
	}
	if(L)
		nn[lim]-=(s-t)/2;
	for(i=0;i<N;++i)
		sol+=nn[i];
}
int main(){
	freopen("d.i","r",stdin);
	freopen("d.o","w",stdout);
	int test,i,T;
	scanf("%d",&T);
	for(test=1;test<=T;++test){
		sol=0;
		scanf("%lld%lld%lld%lld",&L,&t,&N,&C);
		for(i=0;i<C;++i){
			scanf("%lld",&nr[i].first);
			nr[i].second=i;
		}
		solve();
		printf("Case #%d: %lld\n",test,sol);
	}
	return 0;
}
