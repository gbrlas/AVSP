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

bool ispal(long long x) {
	long long y = 0;
	long long xx = x;
	while(xx) {
		y = y*10+xx%10;
		xx/=10;
	}
	return x == y;
}

int main() {
#ifdef LARGE
	freopen("c_large.i", "rt", stdin);
	freopen("c_large.o", "wt", stdout);
#elif SMALL
	freopen("c_small.i", "rt", stdin);
	freopen("c_small2.o", "wt", stdout);
#else
	freopen("c_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	vector<long long> all;
	for(long long i=1;i<=10000000;i++) {
		if(!ispal(i))
			continue;
		long long val = i*i;
		if(!ispal(val))
			continue;
		all.push_back(val);
	}
	for(int tt=1;tt<=t;tt++) {
		long long a,b;
		cin>>a>>b;
		long long ans = 0;
		for(int i=0;i<all.size();i++)
			if(all[i] >= a && all[i] <= b)
				ans++;
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}

	return 0;
}
