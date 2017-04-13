#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<iomanip>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<memory.h>
#include<iomanip>
using namespace std;

typedef pair<int,int> ii;

int main()
{
	int test_count;
	cin>>test_count;
	for(int test_num=0;test_num<test_count;test_num++)
	{
		double t;
		int x,s,r,n;
		cin>>x>>s>>r>>t>>n;
		vector<ii> mas(n);
		for(int i=0;i<n;i++)
		{
			int a,b,w;
			scanf("%d%d%d",&a,&b,&w);
			x-=(b-a);
			mas[i]=ii(w,b-a);
		}
		if (x) mas.push_back(ii(0,x));
		sort(mas.begin(),mas.end());
		double ans=0;
		for(int i=0;i<mas.size();i++)
		{
			int l = mas[i].second;
			int v = mas[i].first;
			double t2 = double(l)/(v+r); 
			if (t>t2)
			{
				t-=t2;
				ans+=t2;
			}
			else
			{
				ans+=t+double(l-(v+r)*t)/(v+s);
				t=0;
			}
		}
		printf("Case #%d: %.7lf\n",test_num+1,ans);
	}
	

	return 0;
	
}