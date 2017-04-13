#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>
//~ #include <unordered_map>
//~ #include <unordered_set>

using namespace std;

#define INF 0x3f3f3f3f
#define SZ(x) (int)((x).size())

typedef long long ll;
typedef pair<int,int> ii;

#define MAXN 1010

int n,v[MAXN],h[MAXN],esq[MAXN];
int mem[MAXN][MAXN],rnd;
int dp[MAXN][MAXN];

bool cmp(int a, int b) {
  return v[a] < v[b];
}

int solve(int x, int y) {
  if (x == n-1) return 0;
  if (mem[x][y] == rnd) return dp[x][y];
  mem[x][y] = rnd;
  
  int z = x -y;
  int pos = h[x];
  if (y >= esq[pos]) pos += y-esq[pos];
  else pos -= esq[pos]-y;
  
  return dp[x][y] = min(abs(pos-y) + solve(x+1,y+1), abs(pos-(n-1-z)) + solve(x+1,y));
}

int main() {
  //~ cin.sync_with_stdio(false);
  int nt,nteste=1;
  scanf("%d",&nt);
  memset(mem,0,sizeof(mem));
  rnd++;
  while (nt--) {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
      scanf("%d",&v[i]);
      h[i] = i;
    }
    
    sort(h,h+n,cmp);
    for (int i=0; i<n; i++) {
      esq[i] = 0;
      for (int j=0; j<i; j++)
        if (v[j] < v[i]) esq[i]++;
    }
    
    ++rnd;
    printf("Case #%d: %d\n",nteste++,solve(0,0));
  }
  
  return 0;
}
