#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long a[100];
inline long long toint(string& s)
{
	long long ans =0;
	for(int i=0;i<(int)s.size();i++)
	{
		ans*=2;
		ans+=s[i]-'0';
	}
	return ans;
}
int main()
{
	freopen("Ain.txt","rt",stdin);
	freopen("Aout.txt","wt",stdout);
	long long TC,x;
	string s;
	int i,j,n,k;
	cin>>TC;
	for(int tc=1;tc<=TC;tc++)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>s;
			x = toint(s);
			a[i] = x&(-x);
		}
		int ans = 0;

		for(i=0;i<n;i++)
		{
			x = 1ll<<(n-(i+1));
			j = i;
			while(a[j]&&a[j]<x) j++;
			for(k=j;k>i;k--)
			{
				swap(a[k],a[k-1]);
				ans++;
			}
		}
			printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}