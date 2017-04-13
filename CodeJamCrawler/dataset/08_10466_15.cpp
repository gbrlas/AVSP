#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
long long a[1000];
long long b[1000];
long long ans;
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int TC,tc,n,i;

	cin>>TC;
	for(tc=0;tc<TC;tc++)
	{
		ans = 0;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);

		ans = 0;
		for(i=0;i<n;i++)
			ans+=a[i]*b[n-i-1];
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}
