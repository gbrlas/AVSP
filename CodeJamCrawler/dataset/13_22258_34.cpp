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

#define N 37

int main()
{
	freopen("a2.in","r",stdin);
	freopen("a2.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    LL B;
    int n;
    scanf("%lld%d",&B,&n);
    LL a[N]={0};
    for(int i=0;i<n;i++)
      scanf("%lld",a+i);
    double res = 0;
    sort(a,a+N);
    LL s[N+1];
    s[0]=0;
    for(int i=0;i<N;i++)
      s[i+1]=s[i]+a[i];
    for(int k=1;k<36;k++)
    {
      for(int j=k;j<36;j++)
      {
        LL x = min((B + s[j] - (j-k))/j, a[j]-1);
        if(x<a[j-1]) continue;
        LL win = 0;
        for(int h=0;h<k;h++)
          win += x-a[h];
        LL lose = 0;
        for(int h=k;h<j;h++)
          lose += x+1-a[h];
        assert(win + lose <= B);
        double profit = (36.-k)*win/k-lose;
        if(res < profit)
          res = profit;
      }
    }
    printf("%.10lf\n",res);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
