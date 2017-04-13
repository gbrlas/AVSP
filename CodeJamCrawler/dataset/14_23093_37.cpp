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
inline void MAX(int& a,int b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

int p,q,n;
int h[111],g[111];
int DP[111][222][1111][2];

int dp(int i, int j, int k, int who) {
  if(i==n) return 0;
  int& res = DP[i][j][k][who];
  if(res>=0) return res;
  res=0;
	if (who==0) {
	  MAX(res, dp(i,j,k+1,1));
	  if (j<=p) {
		  MAX(res, dp(i+1,h[i+1],k,1) + g[i]);
	  } else {
		  if (k) {
			  MAX(res, dp(i,j-p,k-1,0));
		  }
		  MAX(res, dp(i,j-p,k,1));
	  }
  } else {
		if (k) {
			if (j<=p) {
				MAX(res, dp(i+1,h[i+1],k-1,1) + g[i]);
			} else {
				MAX(res, dp(i,j-p,k-1,1));
			}
		}
		if (j<=q) {
			MAX(res, dp(i+1,h[i+1],k,0));
		} else {
			MAX(res, dp(i,j-q,k,0));
		}
  }
  return res;
}


int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    scanf("%d%d%d",&p,&q,&n);
    for(int i=0;i<n;i++)
      scanf("%d%d",h+i,g+i);
    fill(DP,-1);
    int res = dp(0,h[0],0,0);
    printf("%d\n",res);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
