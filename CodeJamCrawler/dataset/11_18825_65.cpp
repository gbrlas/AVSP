#include<stdio.h>
#include<algorithm>
using namespace std;
int T,N;
long long L,H,sol,nr[10100];
/*long long diviz(long long x,long long y){
	if(!y)
		return x;
	return diviz(y,x%y);
}
void solve(){
	sort(nr,nr+N);
	sol=nr[0];
	for(int i=1;i<N;++i){
		if(sol>H)
			break;
		if(sol==1)
			sol*=nr[i];
		else{
			if(!(nr[i]%sol==0 || sol%nr[i]==0)){
				sol=(sol*nr[i])/diviz(sol,nr[i]);
			}
		}
	}
	long long s=sol;
	while(sol<L)
		sol+=s;
}*/
void solve(){
	int i,j,ok;
	sol=0;
	for(i=L;i<=H && !sol;++i){
		ok=1;
		for(j=0;j<N && ok;++j){
			if(!(nr[j]%i==0 || i%nr[j]==0))
				ok=0;
		}
		if(ok)
			sol=i;
	}
	if(!sol)
		sol=H+100;
}
int main(){
	freopen("d.i","r",stdin);
	freopen("d.o","w",stdout);
	int test,i;
	scanf("%d",&T);
	for(test=1;test<=T;++test){
		scanf("%d%lld%lld",&N,&L,&H);
		for(i=0;i<N;++i)
			scanf("%lld",&nr[i]);
		solve();
		if(sol>H)
			printf("Case #%d: NO\n",test);
		else
			printf("Case #%d: %lld\n",test,sol);
	}
	return 0;
}
