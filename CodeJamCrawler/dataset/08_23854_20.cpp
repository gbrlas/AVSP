#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define GI ({int _; scanf("%d", &_); _;})
#define X first
#define Y second
#define pb push_back
#define INF (1<<25)
#define REP(i,n) for(int i = 0; i < n; ++i)
#define FOR(i, s, e) for(int i = s; i < e; ++i)
#define cs c_str()

typedef long long ll;
typedef pair<int,int> ipair;


#define M int(1e4+1)

int dp[M][2];
int type[M], val[M], change[M];

int fill(int node) {
  if(type[node] == 0) {
    fill(2*node); fill(2*node+1);
    val[node] = val[2*node+1] || val[2*node];
  }
  else if(type[node] == 1) {
    fill(2*node); fill(2*node+1);
    val[node] = val[2*node+1] && val[2*node];
  }
  else 
    return val[node];
}

int go(int node, int v) {
  // if node is a leaf
  int &res = dp[node][v];
  
  if(res != -1) return res;
  
  if(type[node] == -1) {
    if(val[node] == v) 
      return res=0;
    else
      return res=INF;
  }
  
  if(type[node] == 0) {
    // OR gate
    if(val[node] == v) return res = 0;
    
    if(val[node] == 0) {
      //but we want it to be v = 1
      int ret = INF;
      ret = min(ret, go(2*node, 1));
      ret = min(ret, go(2*node+1, 1));
      if(change[node])
        ret = min(ret, 1 + go(2*node, 1) + go(2*node+1, 1));
      return dp[node][v] = ret >= INF ? INF : ret;
    }
    else {
      //we want us to be 0
      int ret = INF;
      //either both should be 0
      ret = min(ret, go(2*node, 0) + go(2*node+1, 0));
      
      //or change ourselves and one of the node should be 0
      if(change[node]) {
      ret = min(ret, 1 + go(2*node, 0));
      ret = min(ret, 1 + go(2*node+1, 0)); }
      
      return dp[node][v] = ret >= INF ? INF : ret;
    }
  }
  
  //AND gate
  if(val[node] == v) return res = 0;
  
  if(val[node] == 0) {
    // we want to be 1
    int ret = INF;
    ret = min(ret, go(2*node, 1) + go(2*node+1, 1));
    if(change[node]) {
      ret = min(ret, 1 + go(2*node, 1));
      ret = min(ret, 1 + go(2*node + 1, 1)); 
    }
    return dp[node][v] = ret >= INF ? INF : ret;
  }
  else {
    //we want to be 0
    int ret = INF;
    ret = min(ret, go(2*node, 0));
    ret = min(ret, go(2*node+1, 0));
    if(change[node]) 
    ret = min(ret, 1 + go(2*node, 0) + go(2*node + 1, 0));
    return dp[node][v] = ret >= INF ? INF : ret;
  }
  return res;
}

void solve() {
  int m = GI, v = GI;
  static int kase = 0; ++kase;
  REP(i, m) dp[i+1][0] = dp[i+1][1] = -1, val[i+1] = -1, change[i+1] = 0;
  
  REP(i, (m-1)/2) {
    int node = i + 1;
    type[node] = GI;
    change[node] = GI;
  }
  
  FOR(j, (m-1)/2, m) {
    int node = j+1;
    val[node] = GI;
    change[node] = 0;
    type[node] = -1;
  }
  
  fill(1);
  //int ans = go(1, v);
  int ans = go(1,v);
  
  if(ans == INF) {
    printf("Case #%d: IMPOSSIBLE\n", kase, ans);
    return;
  }
  else {
    printf("Case #%d: %d\n", kase, ans);
  }
}

int main() {
  int t = GI; while(t--) solve();
  return 0;
}