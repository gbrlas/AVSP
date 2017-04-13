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
int M,N,A;
inline int cross(int x0,int y0,int x1,int y1,int x2,int y2)
{
    return (x1 - x0)*(y2 - y0) - (x2 - x0)*(y1 - y0);
}

void solve_case()
{
  scanf("%d %d %d",&N,&M,&A);
  REP(x0,N+1)
  FOR(x1,x0,N)
    FOR(x2,x1,N)
      REP(y1,M+1)        
      REP(y2,M+1)
           if (abs(cross(x0,0,x1,y1,x2,y2))==A)
           {
             printf("%d 0 %d %d %d %d\n",x0,x1,y1,x2,y2);
             goto hell;
           }
//       {
//         int x1=xx1-x0;
//         int x2=xx2-x0;
//         if (x1==0)
//         {
//           if (A==x2*y1)
//           {
//             printf("%d 0 %d %d %d %d\n",x0,x1,y1,x2,0);
//             goto hell;
//           }
//         }else if ((A+x2*y1)%x1==0)
//         {
//           int y2=(A+x2*y1)/x1;
//           if (y2<=M)
//           {
//             printf("%d 0 %d %d %d %d\n",x0,x1,y1,x2,y2);
//             goto hell;
//           }
//         }
//       }
 printf("IMPOSSIBLE\n");     
hell:;
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
