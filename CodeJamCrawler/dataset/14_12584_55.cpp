#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>

using namespace std;

#define ll long long
#define inf 2000000000
#define mod 1000000007
#define vv vector<int>
#define pp pair<int,int>
#define vvp vector<pp>
#define pb push_back
#define st set<int>
#define mp map<string,int>
#define pr(cn,x) ((cn).find(x)!=(cn).end()) 
#define tr(cn,it) for(typeof((cn).begin()) it=(cn).begin();it!=(cn).end();it++)

void bubble_sort(double ar[],int n)
{
	int i,j;
	double temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ar[i]>ar[j])
			{
				temp=ar[i];
				ar[i]=ar[j];
				ar[j]=temp;
			}
		}
	}
}

int Deceit(double ar1[],double ar2[],int n)
{
	int j,k,ans;
	j=n-1; ans=0;
	for(k=n-1;k>=0;k--)
	{
		while((j>=0)&&(ar1[k]<ar2[j]))
		j--;
		if(j>=0)
		ans++;
		j--;
		if(j<0)
		break;
	}
	return ans;
}

int War(double ar1[],double ar2[],int n)
{
	int i,j,k,ans;
	j=n-1; ans=0;
	for(k=n-1;k>=0;k--)
	{
		while((j>=0)&&(ar2[k]<ar1[j]))
		j--;
		if(j>=0)
		ans++;
		j--;
		if(j<0)
		break;
	}
	return ans;
}

int main()
{
	int tc,n,i,j,ans1,ans2;
	scanf("%d",&tc);
	for(j=1;j<=tc;j++)
	{
		scanf("%d",&n);
		double ar1[1005],ar2[1005];
		for(i=0;i<n;i++)
		scanf("%lf",&ar1[i]);
		bubble_sort(ar1,n);
		for(i=0;i<n;i++)
		scanf("%lf",&ar2[i]);
		bubble_sort(ar2,n);
		ans1=Deceit(ar1,ar2,n);
		ans2=War(ar1,ar2,n);
		printf("Case #%d: %d %d\n",j,ans1,n-ans2);
	}
	return 0;
}
