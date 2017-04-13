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


int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d:\n",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int K = k;
    int x = n*m-k;
    char a[55][55]={0};
    bool swp = false;
    if(n>m) {
      swap(n,m);
      swp = true;
    }
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++) a[i][j]='.';
    a[0][0]='c';
    if(n==1) {
      for(int j=0;j<k;j++) a[0][m-1-j]='*';
    } else if(n==2) {
      if(x==2 || (x>1 && x%2)) {
        puts("Impossible");
        continue;
      }
      for(int i=0;i<2;i++)
        for(int j=(x+1)/2;j<m;j++) a[i][j]='*';
      if(x==1) a[1][0]='*';
    } else {
      if(x==2 || x==3 || x==5 || x==7) {
        puts("Impossible");
        continue;
      }
      int N=n,M=m;
      while(k>0) {
        int mn = min(N,M), mx = max(N,M);
        if(k >= mn) {
          if(N<M) {
            for(int i=0;i<N;i++) a[i][M-1]='*';
            M--;
          } else {
            for(int j=0;j<M;j++) a[N-1][j]='*';
            N--;
          }
          k -= mn;
        } else if(k<=mx-2) {
          if(N>M) {
            for(int i=0;i<k;i++) a[N-i-1][M-1]='*';
          } else {
            for(int j=0;j<k;j++) a[N-1][M-1-j]='*';
          }
          k=0;
        } else {
          assert(N==M && k==N-1);
          for(int i=2;i<N;i++) a[i][M-1]='*';
          a[N-1][M-2]='*';
          k=0;
        }
      }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cnt += a[i][j]=='*';
    assert(cnt==K);
    if(!swp) {
      for(int i=0;i<n;i++) puts(a[i]);
    } else {
      for(int j=0;j<m;j++) {
        for(int i=0;i<n;i++) putchar(a[i][j]);
        putchar('\n');
      }
    }
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
