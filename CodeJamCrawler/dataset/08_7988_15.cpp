#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int t,n;

int main()
{
    freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int o=1;o<=t;o++)
	{
		vector<int>s1;
		vector<int>s2;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			s1.push_back(a);
		}
		for(int j=0;j<n;j++)
		{
			int a;
			scanf("%d",&a);
			s2.push_back(a);
		}
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end(),greater<int>());
        int res=0;
		for(int k=0;k<n;k++)
			res+=s1[k]*s2[k];

		cout<<"Case #"<<o<<": "<<res<<endl;
	}

	return 0;
}

