#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

int a,b;

int calc(int x){
	int l=0;;
	int t=x;
	int ll=1;
	while (x>0){
		++l;
		x/=10;
		ll=ll*10;
	}
	int ret=0;
	int now=10;
	for (int i=1; i<l; ++i){
		int aa=t%now, bb=t/now;
		int tt=aa*ll/now+bb;
		/*if (t==449)
					*/
		if (tt>t && tt<=b){
			++ret;
			//printf("%d %d\n", t,tt);
		}
		now=now*10;
	}
	return ret;
}

int main(){
	int test=0;
	scanf("%d",&test);
	for (int T=1; T<=test; ++T){
		printf("Case #%d: ", T);
		scanf("%d%d",&a,&b);
		int ans=0;
		for (int i=a; i<=b; ++i)
			ans+=calc(i);
		printf("%d\n", ans);
	}
}
