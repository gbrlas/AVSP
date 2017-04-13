#include"macro.h"
long long  solve() {
	long long  p,l,k;

	scanf("%lld",&p);
	scanf("%lld",&k);
	scanf("%lld",&l);
	vector<long long > f;

	if (p*k<l) return -1;

	f.clear();
	for(long long  i=0; i<l; i++) {
		long long  t;
		scanf("%d",&t);
		f.pb(t);
	}
	sort(f.begin(), f.end());
	
	long long  pos=1;
	long long  but=0;

	long long answer=0;
	FORD(i,f.sz-1, 0) {
		answer=((lo)answer)+((lo)pos)*((lo)f[i]);
		but++;
		if (but==k) {
			pos++;
			but=0;
		}
	}

	return answer;
}
int  main() {
	freopen("A-large.in","r",stdin);
	freopen("1-large.out","w",stdout);
	long long  t;
	scanf("%lld",&t);
	FOR(i,1,t)  {
		long long  answer=solve();
		if (answer==-1)
			cout<<"Case #"<<i<<": "<<"Impossible"<<endl;
		else cout<<"Case #"<<i<<": "<<answer<<endl;
	}
}
