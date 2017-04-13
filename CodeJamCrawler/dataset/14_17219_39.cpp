#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define pb push_back
#define sz(a) ((int)(a).size())
#define mp make_pair
#define fi first
#define se second

typedef pair<int,int> pint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

#define MAX_N 12

int n;
double a[MAX_N],b[MAX_N];
int dp[1030][1030];

int f(int u1, int u2)
{
	if (u1==0)
		return 0;
	if (dp[u1][u2]!=-1)
		return dp[u1][u2]; 
	int lo=u1&-u1,hi;
	for (int i=u2; i>0; i-=(i&-i))
		hi=i&-i;
	int ans=f(u1^lo,u2^hi);
	lo=u2&-u2;
	int b1,b2=31-__builtin_clz(lo);
	for (int i=u1; i>0; i-=(i&-i))
	{
		b1=31-__builtin_clz(i&-i);
		if (a[b1]>b[b2])
			ans=max(ans,1+f(u1^(i&-i),u2^lo));
	}
	return dp[u1][u2]=ans;
}

int g(int u1, int u2)
{
	if (u1==0)
		return 0;
	if (dp[u1][u2]!=-1)
		return dp[u1][u2];
	int ans=0,b1,b2;
	vi vb;
	vector<double> vs;
	for (int i=u2; i>0; i-=(i&-i))
	{
		b2=31-__builtin_clz(i&-i);
		vb.pb(i&-i);
		vs.pb(b[b2]);
	}
	for (int i=u1; i>0; i-=(i&-i))
	{
		b1=31-__builtin_clz(i&-i);
		if (a[b1]>vs.back())
			ans=max(ans,1+g(u1^(i&-i),u2^vb.front()));
		else if (a[b1]>vs.front())
			ans=max(ans,g(u1^(i&-i),u2^vb[(upper_bound(all(vs),a[b1])-vs.begin())]));
		else
			ans=max(ans,g(u1^(i&-i),u2^vb.front()));
	}		
	return dp[u1][u2]=ans;
}

void resetdp()
{
	for (int i=0; i<1024; i++)
		for (int j=0; j<1024; j++)
			dp[i][j]=-1;
}

int main()
{
	int tc,ba;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++)
	{
		scanf("%d",&n);
		for (int i=0; i<n; i++)
			scanf("%lf",a+i);
		for (int i=0; i<n; i++)
			scanf("%lf",b+i);
		sort(a,a+n);
		sort(b,b+n);
/*		for (int i=0; i<n; i++)
			printf("%lf ",a[i]);
		printf("\n");
		for (int i=0; i<n; i++)
			printf("%lf ",b[i]);
		printf("\n"); */
		printf("Case #%d: ",t);
		ba=(1<<n)-1;
		resetdp();
		int ans1=f(ba,ba);
		resetdp();
		int ans2=g(ba,ba);
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
