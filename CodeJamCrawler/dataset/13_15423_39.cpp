#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define mod 1000002013
#define maxn 1000000

int tqn,tqi,n,m,en,i,l,r,d,wn;
pair<pair<int,int>,int>e[maxn];
long long ol,ne,val[maxn],kol[maxn];

long long prog(long long t){
	return (t*(t-1)/2)%mod;
}

int main (int argc, char * const argv[]) {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&tqn);
	for(tqi=1;tqi<=tqn;tqi++){
		scanf("%d%d",&n,&m);
		en=ol=0;
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&l,&r,&d);
			e[++en]=make_pair(make_pair(l,1),d);
			e[++en]=make_pair(make_pair(r,2),d);
			ol=(ol+1LL*d*1LL*prog(r-l))%mod;
		}
		sort(e+1,e+en+1);
		wn=ne=0;
		for(i=1;i<=en;i++)if(e[i].first.second==1){
			++wn;
			val[wn]=e[i].first.first;
			kol[wn]=e[i].second;			
		}else{
			while(wn>0&&kol[wn]<=e[i].second){
				e[i].second-=kol[wn];
				ne=(ne+1LL*kol[wn]*1LL*prog(e[i].first.first-val[wn]))%mod;
				--wn;
			}
			ne=(ne+1LL*e[i].second*1LL*prog(e[i].first.first-val[wn]))%mod;
			kol[wn]-=e[i].second;
		}
		printf("Case #%d: %lld\n",tqi,(ne-ol+mod)%mod);
	}
    return 0;
}
