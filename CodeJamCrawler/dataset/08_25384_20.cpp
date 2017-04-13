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
#define MOD 10007
int H,W,R,x,y;
int M[105][105];
int DP[105][105];
int solve(int r,int c)
{
  if (r<1||c<1) return 0;
  int &res=DP[r][c];
  if (res!=-1) return res;
  if (M[r][c]) return res=0;
  if (r==1&&c==1) return res=1;
  return res=(solve(r-1,c-2)+solve(r-2,c-1))%MOD;
}
void solve_case()
{
  scanf("%d %d %d",&H,&W,&R);
  mset(M,0);
  REP(i,R)
    scanf("%d %d",&x,&y),
    M[x][y]=1;
  mset(DP,-1);
  printf("%d\n",solve(H,W));
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
