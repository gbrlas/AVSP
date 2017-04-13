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
//#define LARGE 1

int main() {
#ifdef LARGE
	freopen("b_large.i", "rt", stdin);
	freopen("b_large.o", "wt", stdout);
#elif SMALL
	freopen("b_small.i", "rt", stdin);
	freopen("b_small.o", "wt", stdout);
#else
	freopen("b_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int n;
		cin>>n;
		vector<pair<int,int> > v(n);
		vector<int> arr(n);
		for(int i=0;i<n;i++) {
			cin>>arr[i];
			v[i].first=arr[i];
			v[i].second = i;
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for(int i=0;i<n;i++) {
			int val = v[i].first;
			int ind = v[i].second;
			int c1 = 0, c2 = 0;
			for(int j=0;j<ind;j++)
				if(arr[j] > val)
					c1++;
			for(int j=ind+1;j<n;j++)
				if(arr[j] > val)
					c2++;
			ans += min(c1, c2);
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}

	return 0;
}
