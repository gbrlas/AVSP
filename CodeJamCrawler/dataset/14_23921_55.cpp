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
using namespace std;
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#define ll long long
#define ull unsigned long long
#define inf 1001001001
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
#define FOREACH(i,t) for(typeof(t.begin()) i=t.begin();i!=t.end();i++)

int a[N],b[N];
int main()
{
	int T,i,j,k,ca=0,n,m;
	//ofstream f1("D-small-attempt0.in",ios::trunc);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
		{
			scanf("%1d%*c%d",&j,&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%1d%*c%d",&j,&b[i]);
		}
		sort(a,a+n);sort(b,b+n);
		/*for(i=0;i<n;i++)printf("%d ",a[i]);
		puts("");
		for(i=0;i<n;i++)printf("%d ",b[i]);
		puts("");
		*/
		int ans=0,res=0;
		for(i=n-1,j=n-1,k=0;i>=k;i--)
		{
			while(j>=0&&a[i]<=b[j])k++,j--;
			if(j>=0)ans++,j--;
			else break;
		}
		for(i=0,j=0;i<n&&j<n;i++)
		{
			while(j<n&&b[j]<=a[i])j++;
			if(j==n)break;
			res++;j++;
		}
		res=n-res;
		printf("Case #%d: %d %d\n",++ca,ans,res);
		//f1<<"Case #"<<++ca<<": "<<ans<<" "<<res<<endl;
	}
	return 0;
}