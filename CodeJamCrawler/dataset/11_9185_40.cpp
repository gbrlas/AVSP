#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<stdio.h>
using namespace std;

#define SMALL
//#define LARGE

long long a[1000000];
long long cum[1000000];

int main()	{

	freopen("2.in","r",stdin);
	
#ifdef SMALL	
	freopen("2_small_2.in","r",stdin);
	freopen("2_small_2.out","w",stdout);
#endif

#ifdef LARGE	
	freopen("2_large.in","r",stdin);
	freopen("2_large.out","w",stdout);
#endif
	
	int tc;
	cin>>tc;
	for(int tt=1; tt<=tc; tt++)	{
		long long L, t, N, C, i;

		cin>>L>>t>>N>>C;

		long long ans = 0;

		for(i=0;i<C;i++) { 
			cin>>a[i];
			ans += a[i]*2;
			if(i == 0) cum[i] = 0;
			else cum[i] = cum[i-1]+a[i-1];
		}
		for(;i<N;i++) {
			a[i] = a[i-C];
			ans += a[i]*2;
			cum[i] = cum[i-1]+a[i-1];
		}

		long long best = 0;

		if(L > 0)
		for(int i=0;i<N;i++) {
			for(int j=i+1;j<N;j++) {
				long long val, cur = 0;
				if(cum[i]*2 >= t) val = a[i];
				else val = max(0LL, a[i]-(t-cum[i]*2)/2);

				cur += val;

				if(L == 2) {
					if(cum[j]*2-val >= t) cur += a[j];
					else cur += max(0LL, a[j]-(t-(cum[j]*2-val))/2);
				}

				best = max(best, cur);
			}
		}
		
		cout<<"Case #"<<tt<<": "<<ans-best<<endl;

		cerr<<"finished "<<tt<<endl;
	}
	
	return 0;
}
