#include <cstdio>
#include <algorithm>
using namespace std;

int tqn,tqi;
long long n,m,T,ans,mu,le,ri,mid;

long long est(long long k){
	long long place=1;
	long long pw=n-1;
	while(k>0){
		place+=(1LL<<pw);
		--pw;
		k=(k-1)/2LL;
	}
	return place;
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&tqn);
	for(tqi=1;tqi<=tqn;tqi++){
		scanf("%lld%lld",&n,&m);
		if((1LL<<n)==m){
			printf("Case #%d: %lld %lld\n",tqi,m-1,m-1);
			continue;
		}
		T=1LL<<n;ans=(1LL<<n);mu=2LL;
		while(T/2LL>m){
			T/=2LL;
			mu*=2LL;
		}
		le=0,ri=(1LL<<n)-1;
		while(le<ri){
			mid=(le+ri+1)/2LL;
			if(est(mid)>m)ri=mid-1;else le=mid;
		}
		printf("Case #%d: %lld %lld\n",tqi,le,(1LL<<n)-mu);
	}
	return 0;
}