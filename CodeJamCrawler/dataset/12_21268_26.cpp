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
#pragma comment(linker, "/STaCK:266777216")
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
#define aLL(a) (a).begin(),(a).end()
#define fiLL(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MaX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

#define N 222
int n;
LL M,F;
pair<LL,LL> a[N];

LL mul(LL a,LL b) { return b>0 && a>INF/b?INF:a*b; }

LL cnt(LL x)
{
	LL ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=mul(min(a[i].Y,x)-(i?a[i-1].Y:0),a[i].X);
		MIN(ans,INF);
		if(x<=a[i].Y) return ans;
	}
	return INF;
}

LL foo(LL days,LL part)
{
	LL r=days%part;
	LL q=days/part;
	return mul(r,cnt(q+1))+mul(part-r,cnt(q))+mul(F,part);
}

bool possible(LL days)
{
	LL L=1;
	LL R=days+1;
	while(L+1<R)
	{
		LL L1=(2*L+R)/3;
		LL R1=(L+2*R)/3;
		LL mL=foo(days,L1);
		LL mR=foo(days,R1);
		if(mL<=M || mR<=M) return true;
		if(mL<mR) R=R1-1; else L=L1+1;
	}
	return foo(days,L)<=M;
}

int main()
{
	freopen("c1.in","r",stdin);
	freopen("c1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		scanf("%lld%lld%d",&M,&F,&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld",&a[i].X,&a[i].Y);
			a[i].Y++;
		}
		sort(a,a+n);
		int lo=0;
		int hi=M+1;
		while(lo+1<hi)
		{
			int mid=(lo+hi)/2;
			if(possible(mid)) lo=mid; else hi=mid;
		}
		printf("%lld\n",lo);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
