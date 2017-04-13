#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(int i,int j)
{
	return (i>j);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t=0;
	cin>>t;
	for (int tt=0;tt<t;++tt)
	{
		int n,s,p,ans;
		n=s=p=ans=0;
		vector<int> a;
		cin>>n>>s>>p;
		for (int i=0;i<n;++i)
		{
			int da=0;
			cin>>da;
			a.push_back(da);
		}
		sort(a.begin(),a.end(),comp);
		for (vector<int>::size_type i=0;i<a.size();++i)
		{
			int d=a[i]/3,mo=a[i]%3;
			if ((d>=p) || (d==p-1 && mo>0)) ans++;
			else
				if (((d>=1 && d==p-1 && mo==0) || (d==p-2 && mo==2)) && s>0)
				{
					s--;
					ans++;
				}
		}
		cout<<"Case #"<<tt+1<<": "<<ans<<'\n';
	}
	return 0;
}
