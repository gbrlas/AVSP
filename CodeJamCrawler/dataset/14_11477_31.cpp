#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
#define LARGE 1

int main() {
#ifdef LARGE
	freopen("a_large.i", "rt", stdin);
	freopen("a_large.o", "wt", stdout);
#elif SMALL
	freopen("a_small.i", "rt", stdin);
	freopen("a_small.o", "wt", stdout);
#else
	freopen("a_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int n,x;
		cin>>n>>x;
		vector<int> v(n);
		vector<bool> b(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(v.rbegin(), v.rend());
		int ans=0;
		for(int i=0;i<n;i++) {
			if(b[i]) continue;
			for(int j=i+1;j<n;j++)
				if(!b[j] && v[i]+v[j] <= x) {
					b[j] = 1;
					break;
				}
			ans++;
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}

	return 0;
}
