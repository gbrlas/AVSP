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
#define N 10010
#define pi 3.14159265358979323846
#define DBG(vari) cerr<<#vari<<"="<<(vari)<<endl;
#define FOREACH(i,t) for(__typeof(t.begin()) i=t.begin();i!=t.end();i++)

int a[N];
int main()
{
	freopen("A-small.txt","w",stdout);
	int n,m,k,i,j,T,ca=0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",++ca);
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		sort(a,a+n);
		int ans=0;
		for(i=0,j=n-1;i<=j;)
		{
			if(a[i]+a[j]<=m)ans++,i++,j--;
			else ans++,j--;
		}
		printf("%d\n",ans);
	}
	return 0;
}