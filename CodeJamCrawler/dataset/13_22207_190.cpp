#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

#define N 20
int dp[1<<N];
int pre[1<<N];

void recalc(VI &a,int *b,int n)
{
	VI c;
	for(int i=0;i<a.sz;i++)
	{
		int j = lower_bound(b,b+n,a[i]) - b;
		if(j<n && b[j]==a[i])
			c.pb(j);
	}
	a=c;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int TST,tst=0;
	for(cin >> TST;TST-- > 0;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		int k,n;
		cin >> k >> n;
		VI avail(k);
		for(int i=0;i<k;i++)
			cin >> avail[i];
		VI keys(n);
		VI ins[N];
		int tmp[N];
		for(int i=0;i<n;i++)
		{
			cin >> keys[i] >> k;
			tmp[i]=keys[i];
			ins[i]=VI(k);
			for(int j=0;j<k;j++)
				cin >> ins[i][j];
		}
		sort(tmp,tmp+n);
		int len = unique(tmp,tmp+n)-tmp;

		recalc(avail,tmp,len);
		recalc(keys,tmp,len);
		for(int i=0;i<n;i++)
			recalc(ins[i],tmp,len);

		fill(dp,0);
		dp[0]=1;
		for(int mask=1;mask<bit(n);mask++)
		{
			int cur[N]={0};
			for(int i=0;i<avail.sz;i++)
				cur[avail[i]]++;
			for(int i=0;i<n;i++)
				if(!(mask & bit(i)))
				{
					cur[keys[i]]--;
					for(int j=0;j<ins[i].sz;j++)
						cur[ins[i][j]]++;
				}
			bool bad=false;
			for(int i=0;i<n;i++)
				if(cur[i]<0) bad=true;
			if(bad) continue;
			for(int i=0;i<n;i++)
				if((mask & bit(i)) && cur[keys[i]] && (dp[mask ^ bit(i)]))
				{
					dp[mask]=1;
					pre[mask]=i;
					break;
				}
		}
		int mask=bit(n)-1;
		if(!dp[mask]) {puts("IMPOSSIBLE"); continue;}
		VI res;
		while(mask)
		{
			int i=pre[mask];
			res.pb(i+1);
			mask ^= bit(i);
		}
		for(int i=0;i<res.sz;i++)
			printf("%d%c",res[i],i<res.sz-1?' ':'\n');
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
