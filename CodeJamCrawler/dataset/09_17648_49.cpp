#include <iostream>

using namespace std;

string s[55];

int getRightOne(int r)
{
	for(int i=s[r].size()-1;i>-1;--i)
		if(s[r][i]=='1')
			return i;
	return -1;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int zz,n;
	cin>>zz;
	for(int z=1;z<=zz;++z)
	{
		int r=0;
		cin>>n;
		for(int i=0;i<n;++i) cin>>s[i];
		for(int i=0;i<n;++i)
			if(getRightOne(i)>i)
			{
				int j=i+1;
				while(getRightOne(j)>i) ++j;
				string t=s[j];
				for(int k=j;k>i;--k) s[k]=s[k-1];
				s[i]=t;
				r+=j-i;
			}
		printf("Case #%d: %d\n",z,r);
	}
	return 0;
}

