#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int t,n;

int main()
{
    freopen("A-large.in.txt","r",stdin);
	freopen("A-large.out.txt","w",stdout);
	scanf("%d",&t);
	for(int o=1;o<=t;o++)
	{
		vector<__int64>s1;
		vector<__int64>s2;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			__int64 a;
			scanf("%I64d",&a);
			s1.push_back(a);
		}
		for(int j=0;j<n;j++)
		{
			__int64 a;
			scanf("%I64d",&a);
			s2.push_back(a);
		}
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end(),greater<int>());
        __int64 res=0;
		for(int k=0;k<n;k++)
			res+=s1[k]*s2[k];

		printf("Case #%d: %I64d\n",o,res);

	}

	return 0;
}

