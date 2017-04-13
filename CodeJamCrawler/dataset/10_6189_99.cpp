#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

int main()	{
	
	freopen("c_large.in","r",stdin);
	freopen("c_large.out","w",stdout);

	long long t, r, k, n;
	cin>>t;
	for(int tt=1;tt<=t;tt++)	{
		cin>>r>>k>>n;
		vector<long long> v(n), rep(n), cnt(n);
		vector<bool> vis(n);
		for(int i=0;i<n;i++)
			cin>>v[i];

		long long ind=0, round=0, sum=0;
		while(1)	{
			if(round==r || vis[ind]) break;
			rep[ind] = round;
			cnt[ind] = sum;
			vis[ind]=1;
			for(long long cnt=0, rsum=0; rsum+v[ind]<=k && cnt<n; cnt++, sum+=v[ind], rsum+=v[ind], ind=(ind+1)%n);
			round++;
		}
		if(round != r)	{
			long long rem = (r-round)%(round-rep[ind]);
			sum+=((r-round)/(round-rep[ind]))*(sum-cnt[ind]);
			round = 0;
			while(round<rem)	{
				for(long long cnt=0, rsum=0; rsum+v[ind]<=k && cnt<n; cnt++, sum+=v[ind], rsum+=v[ind], ind=(ind+1)%n);
				round++;
			}
		}

		cout<<"Case #"<<tt<<": "<<sum<<endl;
	}

	return 0;
}
