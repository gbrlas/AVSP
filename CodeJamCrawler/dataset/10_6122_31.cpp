#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;
#define MAXN 2000

int m[MAXN];
int t[20][2000];
int cnt[MAXN];
int p;
int dc(int beg,int end)
{
	int ans=0;
	for(int i=beg;i<=end;i++)
	{
		if(cnt[i]<p)
		{
			ans++;	
			for(int j=beg;j<=end;j++)
				cnt[j]++;
			break;
		}
	}
	if(!ans)
		return ans;
	else
		return dc(beg,(beg+end)/2) + dc((beg+end)/2,end)+1;	
	
}
int main()
{
	freopen("B-small-attempt.in","r",stdin);
	freopen("BSout.txt","w",stdout);	
	
	int ca,cs=1;
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%d",&p);
		int n=1;
		for(int i=0;i<p;i++)
			n*=2;
		for(int i=0;i<n;i++)
		{	
			scanf("%d",&m[i]);
			cnt[i]=m[i];
		}
		int N=0;
		for(int h=n/2;h;h/=2,N++)
			for(int i=0;i<h;i++)
				scanf("%d",&t[N][i]);	
		printf("Case #%d: ",cs++);
		printf("%d\n",dc(0,n-1));		
				
		
	}
	return 0;	
}
