#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<time.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define mod 1000000007
#define pii pair<int,int>
#define vi vector<int>
#define VS vector<string>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define N 1010
#define pi 3.14159265358979323846
#define DBG(vari) cerr<<#vari<<"="<<(vari)<<endl;
#define FOREACH(i,t) for(__typeof(t.begin()) i=t.begin();i!=t.end();i++)

int f[N];pii a[N];
void update(int x,int v)
{
	while(x<N)f[x]+=v,x+=x&-x;
}
int query(int x)
{
	int ans=0;
	while(x>0)ans+=f[x],x-=x&-x;
	return ans;
}
int main()
{
	freopen("A-small.txt","w",stdout);
	int n,m,k,i,j,T,ca=0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",++ca);
		scanf("%d",&n);
	    int ans=0;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i].x);a[i].y=i;update(i,1);
		}
		sort(a+1,a+n+1);
		int s=n;
		for(i=1;i<=n;i++)
		{
			int l=query(a[i].y-1),r=s-1-l;
			//cerr<<l<<" "<<r<<"\n";
			ans+=min(l,r);update(a[i].y,-1);
			s--;
		}
		printf("%d\n",ans);
	}
	return 0;
}