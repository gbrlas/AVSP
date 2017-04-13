#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void solve(long long num)
{
	long long l,t,n,c;
	cin>>l>>t>>n>>c;
	long long d[n];
	long long ld[c];
	for(long long i=0;i<c;i++)
		cin>>ld[i];
	long long nld=0;
	for(long long i=0;i<n;i++)
	{
		d[i]=ld[nld];
		nld++;
		nld%=c;
	}

	vector<long long> tmax(n+1);
	tmax[0]=0;
	for(long long i=1;i<=n;i++)tmax[i]=tmax[i-1]+d[i-1]*2;
	vector<long long> dn(n+1);
	for(long long i=0;i<=n;i++)
	{
		if(tmax[i]<=t)dn[i]=0;
		else if(tmax[i]>=t && tmax[i-1]>=t)dn[i]=d[i-1];
		else if(tmax[i]>=t)
		{
			dn[i]=d[i-1]-(t-tmax[i-1])/2;
		}
	}
	vector<pair<long long,long long> > dnn;
	for(long long i=0;i<=n;i++)dnn.push_back(make_pair(dn[i],i));
	greater<pair<long,long> > cmp;
	sort(dnn.begin(),dnn.end(),cmp);
	vector<bool> add(n,true);
	long long res=0;
	for(long long i=0;i<l;i++)
	{
		add[dnn[i].second-1]=false;
		res+=dnn[i].first;
		if(tmax[dnn[i].second-1]<t)
			res+=(d[dnn[i].second-1]-dnn[i].first)*2;
	}
	for(long long i=0;i<n;i++)if(add[i])res+=d[i]*2;
	cout<<fixed;
	cout.precision(0);
	cout<<"Case #"<<num<<": "<<res<<'\n';
}
int main()
{
	long long t;
	cin>>t;
	for(long long i=0;i<t;i++)
		solve(i+1);
	return 0;
}
