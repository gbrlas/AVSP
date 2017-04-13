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

#define N 11
int n;
PII a[N];
int p[N];
LL best;
int res[N];
int mark[N];

bool inter(PII a1, PII a2, PII a3,PII a4)
{
  int x1=a1.X, y1=a1.Y;
  int x2=a2.X, y2=a2.Y;
  int x3=a3.X, y3=a3.Y;
  int x4=a4.X, y4=a4.Y;
	int d =(x2-x1)*(y3-y4)-(y2-y1)*(x3-x4);
	int dt=(x3-x1)*(y3-y4)-(y3-y1)*(x3-x4);
	int ds=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
	if(d<0) d=-d,dt=-dt,ds=-ds;
	if(d>0) return 0<=dt && dt<=d && 0<=ds && ds<=d;
	if(ds!=0 || dt!=0) return false;
	if(x1>x2) swap(x1,x2);
	if(x3>x4) swap(x3,x4);
	if(y1>y2) swap(y1,y2);
	if(y3>y4) swap(y3,y4);
	return x1<=x4 && x3<=x2 && y1<=y4 && y3<=y2;
}

void rec(int i)
{
  if(i==n)
  {
    LL ar=0;
    for(int j=0;j<n;j++)
    {
      int k=(j+1)%n;
      ar += LL(a[p[j]].X) * a[p[k]].Y - LL(a[p[j]].Y) * a[p[k]].X;
    }
    if(ar<0) ar=-ar;
    if(best<ar) {
      bool bad=false;
      for(int k=1;k+1<n-1 && !bad;k++)
        if(inter(a[p[k]],a[p[k+1]],a[p[n-1]],a[p[0]])) bad=true;
      if(!bad)
      {
        best=ar;
        for(int i=0;i<n;i++)
          res[i]=p[i];
      }
    }
    return;
  }
  for(int j=1;j<n;j++)
    if(!mark[j])
    {
      bool bad=false;
      for(int k=0;k+1<i-1 && !bad;k++)
        if(inter(a[p[k]],a[p[k+1]],a[p[i-1]],a[j])) bad=true;
      if(!bad) {
        p[i]=j;
        mark[j]=1;
        rec(i+1);
        mark[j]=0;
      }
    }
}

int main()
{
	freopen("b1.in","r",stdin);
	freopen("b1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      scanf("%d%d",&a[i].X,&a[i].Y);
    best=0;
    fill(mark,0);
    p[0]=0;
    mark[0]=1;
    rec(1);
    for(int i=0;i<n;i++)
      printf("%d%c",res[i],i<n-1?' ':'\n');
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
