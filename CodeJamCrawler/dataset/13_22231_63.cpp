#define _CRT_SECURE_NO_WARNINGS

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

#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

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

#define MOD 1000002013

struct ev
{
  int x,tp,cnt;
  ev(){}
  ev(int x_,int tp_,int cnt_):x(x_),tp(tp_),cnt(cnt_){}
  bool operator<(const ev &e) const
  {
    return x < e.x || x == e.x && tp < e.tp;
  }
};

int main()
{
	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    LL n;
    int m;
    scanf("%lld%d",&n,&m);
    fprintf(stderr,"n=%lld m=%d\n",n,m);
    int ans=0;
    map<PII,LL> pas;
    for(int i=0;i<m;i++) {
      int o,e,p;
      scanf("%d%d%d",&o,&e,&p);
      LL d = e - o;
      LL sum = d * (2*n-d+1) / 2 % MOD;
      ans = (ans + p * sum) % MOD;
      pas[mp(o,-1)]+=p;
      pas[mp(e,+1)]+=p;
    }
    map<LL,LL> cur;
    map<LL,LL>::iterator it1;
    int px=0;
    for(map<PII,LL>::iterator it=pas.begin();it!=pas.end();++it)
    {
      LL x = it->X.X;
      LL cnt = it->Y;
      for(it1 = cur.begin();it1!=cur.end();++it1) {
        LL y = it1->X;
        LL num = it1->Y % MOD;
        LL sum = (2*(n+y)-x-px+1) * (x-px) / 2 % MOD;
        ans = (ans - sum * num) % MOD;
      }
      if(it->X.Y==-1) {
        cur[x]+=cnt;
      } else {
        for(it1=--cur.end();cnt>0;--it1)
        {
          LL w = min(it1->Y, cnt);
          it1->Y-=w;
          cnt-=w;
        }
      }
      px=x;
    }
    if(ans<0) ans+=MOD;
    printf("%d\n",ans);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
