#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define S size()
#define B begin()
#define E end()
#define P push_back
#define For(i,a) for(typeof((a).B) i=(a).B;i!=(a).E;i++)
#define fu(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=b-1;i>=a;--i)
typedef long long int64;
using namespace std;

const int MaxN=30000;

int f[MaxN],d[MaxN],l[MaxN];

bool solve()
{
	int n,ll;

	memset(f,0,sizeof f);
	memset(d,0,sizeof d);
	memset(l,0,sizeof l);
	scanf("%d",&n);
	cerr<<n<<endl;
	for(int i=0;i<n;i++)
		scanf("%d%d",&d[i],&l[i]);
	cin>>ll;
	f[0]=d[0];

	int j=0;

	for(int i=1;i<n;i++)
	{
		while(j<i && f[j]+d[j]<d[i]) j++;
		f[i]=min(l[i],d[i]-d[j]);
	}

	for(int i=0;i<n;i++)
		if(d[i]+f[i]>=ll) return true;
	return false;
}

int main()
{
	int test;

	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>test;
	cerr<<test<<endl;
	for(int no=1;no<=test;no++)
		printf("Case #%d: %s\n",no,solve()?"YES":"NO");
	return 0;
}

