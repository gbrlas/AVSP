#include"macro.h"
int solve() {
	int p,l,k;

	scanf("%d",&p);
	scanf("%d",&k);
	scanf("%d",&l);
	vector<int> f;

	if (p*k<l) return -1;

	f.clear();
	for(int i=0; i<l; i++) {
		int t;
		scanf("%d",&t);
		f.pb(t);
	}
	sort(f.begin(), f.end());
	
	int pos=1;
	int but=0;

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
int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("1-0.out","w",stdout);
	int t;
	scanf("%d",&t);
	FOR(i,1,t)  {
		int answer=solve();
		if (answer==-1)
			cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<endl;
		else cout<<"Case #"<<i<<": "<<answer<<endl;
	}
}
