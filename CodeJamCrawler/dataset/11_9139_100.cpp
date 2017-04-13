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

int main()	{

	freopen("3.in","r",stdin);
	
#ifdef SMALL	
	freopen("3_small.in","r",stdin);
	freopen("3_small.out","w",stdout);
#endif

#ifdef LARGE	
	freopen("3_large.in","r",stdin);
	freopen("3_large.out","w",stdout);
#endif
	
	int tc;
	cin>>tc;
	for(int tt=1; tt<=tc; tt++)	{
		int n;
		cin>>n;
		vector<int> v(n);
		int val = 0, cnt = 0, mn = 100000000;
		for(int i=0;i<n;i++) {
			cin>>v[i];
			val ^= v[i];
			cnt += v[i];
			mn = min(mn, v[i]);
		}

		cout<<"Case #"<<tt<<": ";

		if(val != 0) {
			cout<<"NO"<<endl;
			continue;
		}

		cout<<cnt-mn<<endl;
	}
	

	return 0;
}
