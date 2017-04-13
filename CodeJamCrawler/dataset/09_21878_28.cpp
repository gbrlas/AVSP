#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
#include <list>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<string> VS;
typedef pair<int,int> para;

#define FOREACH(i,n) for(__typeof((n).begin()) i=((n).begin());i!=(n).end();++i)
#define REP(a,n) for(int a=0;a<(n);a++)
#define PB push_back
#define ALL(v) v.begin(),v.end()
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define F first
#define S second

const int N = 107;

int n,k,T;

int gr[N][N], pr[N][N];

inline int sgn(int x){
  if(x<0)
    return -1;
  if(x>0)
    return 1;
  return 0;
}

bool cut(int a, int b){
  REP(i,k)
    if(pr[a][i] == pr[b][i])
      return true;
  REP(i,k-1)
    if(sgn(pr[a][i+1]-pr[b][i+1]) != sgn(pr[a][i] -pr[b][i]))
      return true;
  return false;
}

bool st[N];
int Y;

void dfs(int a){
  REP(i,n)
    if(gr[a][i] != Y && st[i]){
      st[i] = false;
      dfs(i);
    }
}

int tw[66007];

int main()
{
  scanf("%d",&T);
  FOR(I,1,T){
    Y = I;
    scanf("%d %d",&n,&k);
    REP(i,n)
      REP(j,k)
        scanf("%d",&pr[i][j]);
    REP(i,n)
      for(int j=i+1;j<n;j++)
        if(cut(i,j)){
          gr[i][j] = gr[j][i] = Y;
        }
    tw[0] = 0;
    int ogr = 1<<n;
    for(int msk=1;msk < ogr; msk++){
      bool f = true;
      for(int i=0,a=1;i<n;i++,a<<=1)
        for(int j=0,b=1;j<n;j++,b<<=1)
          if(i!=j && (msk & a) && (msk & b) && gr[i][j] == Y)
            f = false;
      if(f)
        tw[msk] = 1;
      else{
        int dm = msk;
        int wc = 10000;
        for(;;){
          dm = (dm - 1) & msk;
          if(dm == 0)
            break;
          wc = min(wc, tw[dm]+tw[dm^msk]);
        }
        tw[msk] = wc;
      }
    }
    printf("Case #%d: %d\n",I,tw[(1<<n)-1]);
  }
	return 0;
}
