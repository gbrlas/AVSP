#include"macro.h"
#define mod 1000000007


long long dp[500010];
long long a[500010];
long long b[500010];
long long solve() {
	long long n,m,x,y,z;
	scanf("%lld %lld %lld %lld %lld",&n,&m,&x,&y,&z);
	for(int i=0; i<m; i++) 
		scanf("%lld",&a[i]);
	
	for(int i=0; i<n; i++) {
		b[i]=(long long) a[i%m];
		a[i%m] = (x*a[i%m]+y*(i+1)) %z;
		//printf("%d ",b[i]);
	}

	//printf("\n");

	memset(dp,0,sizeof(dp));

	long long answer=0;
	for(int i=0; i<n; i++) {
		dp[i]=1;
		for(int j=i-1; j>=0; j--)
			if (b[i]>b[j]) 
				dp[i]=((dp[i]%mod) + (dp[j] % mod)) % mod;
		answer= ((answer%mod) + (dp[i]%mod)) %mod;
	}
	
	return answer;
}
int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C0.out","w",stdout);
		int t;
	scanf("%d",&t);
	FOR(i,1,t)  {		
		long long answer = solve();				
		cout<<"Case #"<<i<<": "<<answer<<endl;
	}
}
