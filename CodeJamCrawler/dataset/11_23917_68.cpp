#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cctype>
#include<queue>
using namespace std;

const int N = 1100006;
int hlp[N];

void solve(){
	long long n;
	scanf("%lld",&n);
	if(n==1) {
		printf("0\n");
		return;
	}
	long long res = 1;
	for(long long d=1; d*d<=n; d++) if(hlp[d]){
		long long k = d;
		while(k<=n){
			res++;
			k*=d;
		}
		res--;
	}
	printf("%lld\n",res);
}

main(){
	for(int i=1; i<N; i++) hlp[i]=1;
	hlp[0]=hlp[1]=0;
	for(int i=2; i<N; i++){
		if(hlp[i]) for(int j=2*i; j<N; j+=i) hlp[j]=0;
	}
	int T;
	scanf("%d",&T);
	for(int testcase=1; testcase<=T; testcase++){
		printf("Case #%d: ",testcase);
		solve();
	}
	return 0;
}
