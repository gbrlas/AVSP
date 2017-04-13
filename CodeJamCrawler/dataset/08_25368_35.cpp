//DEDICATED TO EMMA WATSON, THE BRITISH *SUNSHINE*
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
//#include <fstream>

#define eps 10e-10
#define INF 1000000000
#define PI 3.141592653589793238462
#define EU 2.71828182845904523536
#define sz(a) (int)a.size()
#define pb(a) push_back(a)
#define mset(a,hodnota) memset(a,hodnota,sizeof(a))
#define wh(a) a.begin(),a.end()
#define REP(i,n) for(__typeof(n) i=0;i<(n);++i)
#define REPS(i,n) for(int(i)=0;i<int(n.size());++i)
#define FOR(i,a,b) for(__typeof(b) i=(a);i<=(b);++i)
#define FORD(i,a,b) for(__typeof(a) i=(a);i>=(b);--i)
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define SQR(a) ((a)*(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;

int M,V;
int type[100];
int val[100];
int curv[100];
int mask,a,b;
void solve_case()
{
  scanf("%d %d",&M,&V);
  mset(type,0);
  mask=0;
  FOR(i,1,M)
  {
    if (i<=(M-1)/2)
    {
      scanf("%d %d",&a,&b);
      mask|=(b<<i);
      type[i]=a;
    }else
      scanf("%d",&val[i]);
  }
  int m=mask,mini=100;
  while(1)
  {
    int cur=__builtin_popcount(m);
    memcpy(curv,val,sizeof(val));
    FORD(i,(M-1)/2,1)
    {
      int typ=type[i];
      if (m&(1<<i))typ=1-typ;
      if (typ==1)
        curv[i]=curv[2*i] && curv[2*i+1];
      else 
        curv[i]=curv[2*i] || curv[2*i+1];
    }
    if (curv[1]==V)
      mini=min(mini,cur);
    if (m==0)break;
    m--;
    m=m&mask;  
  }
  if (mini==100) printf("IMPOSSIBLE\n");
  else printf("%d\n",mini);
}


int cases;
int main( )
{
  scanf("%d\n",&cases);
  REP(ii,cases)
  {
    printf("Case #%d: ",ii+1);
    solve_case();
  }         
  return 0;
}
