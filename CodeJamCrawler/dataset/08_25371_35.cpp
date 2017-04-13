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
#define INF 100000000
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

#define LIM 10005
int M,V;
int type[LIM];
int val[LIM][2];
int curv[LIM];
int mask[LIM],a,b;
void solve_case()
{
  scanf("%d %d",&M,&V);
  mset(type,0);
  mset(mask,0);  
  mset(val,0x3f);
  FOR(i,1,M)
  {
    if (i<=(M-1)/2)
    {
      scanf("%d %d",&a,&b);
      mask[i]=b;
      type[i]=a;
    }else
    {
      scanf("%d",&a);
      val[i][a]=0;
      val[i][1-a]=INF;
    }
  }
  FORD(i,(M-1)/2,1)
  {
    //dont change
    if (type[i])
    {//and
      val[i][0]=min(val[i*2][0]+min(val[i*2+1][0],val[i*2+1][1]),val[i*2+1][0]+min(val[i*2][0],val[i*2][1]));
      val[i][1]=val[i*2][1]+val[i*2+1][1];      
    }else
    {//or
      val[i][1]=min(val[i*2][1]+min(val[i*2+1][0],val[i*2+1][1]),val[i*2+1][1]+min(val[i*2][0],val[i*2][1]));
      val[i][0]=val[i*2][0]+val[i*2+1][0];      
    }  
    if (mask[i])
    {
      //change
      if (!type[i])
      {//and
        val[i][0]<?=min(val[i*2][0]+min(val[i*2+1][0],val[i*2+1][1]),val[i*2+1][0]+min(val[i*2][0],val[i*2][1]))+1;
        val[i][1]<?=val[i*2][1]+val[i*2+1][1]+1;
      }else
      {//or
        val[i][1]<?=min(val[i*2][1]+min(val[i*2+1][0],val[i*2+1][1]),val[i*2+1][1]+min(val[i*2][0],val[i*2][1]))+1;
        val[i][0]<?=val[i*2][0]+val[i*2+1][0]+1;      
      }        
    }
    val[i][0]=min(val[i][0],INF);
    val[i][1]=min(val[i][1],INF);    
  }

  if (val[1][V]>=INF) printf("IMPOSSIBLE\n");
  else printf("%d\n",val[1][V]);
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

