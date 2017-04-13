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
#define LARGE

int main()	{

	freopen("4.in","r",stdin);
	
#ifdef SMALL	
	freopen("4_small_2.in","r",stdin);
	freopen("4_small_2.out","w",stdout);
#endif

#ifdef LARGE	
	freopen("4_large.in","r",stdin);
	freopen("4_large.out","w",stdout);
#endif
	
	int tc;
	cin>>tc;
	for(int tt=1; tt<=tc; tt++)	{
		int n;
		cin>>n;
		vector<int> v(n+1);
		vector<bool> vis(n);
		for(int i=0;i<n;i++)
			cin>>v[i+1];

		double ans = 0;
		for(int i=1;i<=n;i++) {
			if(vis[i]) continue;
			int cnt = 0;
			for(int j=i;!vis[j];cnt++, vis[j]=1, j=v[j]);
			if(cnt == 1) cnt=0;
			ans += cnt;
		}
		cout.precision(9);
		cout.setf(ios::fixed);
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	

	return 0;
}
