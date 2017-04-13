#include"macro.h"
#define LMAX 2000000000000000LL
long long solve() {
	int n;
	vector<long long> a;
	vector<long long> b;
	a.clear();
	b.clear();
	scanf("%d",&n);
	FOR(i,1,n) {
		long long t;
		scanf("%lld",&t);
		a.pb(t);
	}

	FOR(i,1,n) {
		long long t;
		scanf("%lld",&t);
		b.pb(t);
	}
	long long answer = LMAX;
	vector<long long> ora=a;
		sort(a.begin(), a.end());
		do {
			long long can = 0LL;
			for(int i=0; i<n; i++)
				can= can + ((long long)a[i])*((long long)b[i]);
			answer = min(answer, can);
		} while(next_permutation(a.begin(), a.end()));
	
	return answer;
}
int main() {
	freopen("A-small-attempt5.in","r",stdin);
	freopen("5.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; i++)
		cout<<"Case #"<<i<<": "<<solve()<<endl;
}