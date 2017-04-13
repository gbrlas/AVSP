#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int recycled(int a,int l,int r)
{
	int t,len=int(log10(double(a)))+1,sa=a,res=0;
	vector<int>pul(0);
	for(int i=0;i!=len;i++)
	{
		if(a>sa&&a<=r)
		{
			//printf("%d %d\n",sa,a);
			if(find(pul.begin(),pul.end(),a)==pul.end()&&find(pul.begin(),pul.end(),a)==pul.end())
			{
				res++;
				pul.push_back(a);
			}
		}
		t=a%10;
		while(t==0)
		{
			a/=10;
			t=a%10;
			i++;
		}
		a=(a/10)+pow(double(10),len-1)*t;
	}
	return res;
}

int main()
{
	/*freopen("Csmall.in","w",stdout);
	int N=50;
	cout<<N<<endl;
	for(int i=0;i!=N;i++)
		printf("1 1000\n");*/

	/*freopen("Csmall.out","r",stdin);
	freopen("info.out","w",stdout);
	int N=288;
	vector<pair<int,int> >pul(0);
	for(int i=0;i!=N;i++)
	{
		int a,b;
		scanf("%d %d\n",&a,&b);
		if(find(pul.begin(),pul.end(),make_pair(a,b))==pul.end()&&find(pul.begin(),pul.end(),make_pair(b,a))==pul.end())
			pul.push_back(make_pair(a,b));
		else
			cout<<a<<" "<<b<<endl;
	}
	cout<<pul.size();*/


	freopen("Clarge.in","r",stdin);
	freopen("Clarge.out","w",stdout);
	int T,a,b;
	unsigned long long int ans=0;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		ans=0;
		scanf("\n%d %d",&a,&b);
		for(int j=a;j<=b;j++)
			ans+=recycled(j,a,b);
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}