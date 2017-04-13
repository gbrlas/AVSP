#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#define DB(x) cerr << #x << "=" << x << endl
#define DBV(x) cerr << x
#define DBL cerr << endl
#define sz(c) ((int)(c).size())
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long int64;

using namespace std;

const int inf = 1e9;
const int maxw = 110;
const int maxh = 510;

struct Dinic {
  static const int maxn=2*maxw*maxh;
  static const int maxm=maxn*8;

  int n,m;
  int he[maxn],q[maxn],lay[maxn];
  int ve[maxm],ne[maxm],cap[maxm];

  Dinic(int N=0) {
    n=N,m=0;
    memset(he,~0,sizeof(he));
  }

  void reset(int N) {
    n=N;
    m=0;
    memset(he,~0,sizeof(he));
    for (int i = 0; i < n; ++i) he[i] = -1;
  }

  void add(int x,int y,int c) {
    assert(x >= 0 && x < n);
    assert(y >= 0 && y < n);
    ve[m]=y,ne[m]=he[x],cap[m]=c,he[x]=m++;
    ve[m]=x,ne[m]=he[y],cap[m]=0,he[y]=m++;
  }

  bool dfs(int v,int t,int &f) {
    if (v==t) return true;
    for (int &i=q[v]; i!=-1; i=ne[i])
      if (lay[ve[i]]==lay[v]+1 && cap[i]>0) {
        int ff=min(f,cap[i]);
        if (dfs(ve[i],t,ff)) {
          cap[i]-=ff;
          cap[1^i]+=ff;
          f=ff;
          return true;
        }
      }
    return false;
  }

  int flow(int s,int t) {
    int res=0;
    while (true) {
      for (int i=0; i<n; ++i) lay[i]=0;
      q[0]=s,lay[s]=1;
      for (int l=0,r=1; l<r; ++l) 
        for (int i=he[q[l]]; i!=-1; i=ne[i])
          if (lay[ve[i]]==0 && cap[i]>0) {
            q[r++]=ve[i];
            lay[ve[i]]=lay[q[l]]+1;
          }
      if (lay[t]==0) break;
      for (int i=0; i<n; ++i) q[i]=he[i];
      for (int f; dfs(s,t,f=inf); res+=f);
    }
    return res;
  }

};

Dinic flowFinder;
int w, h, b, wh;
int a[maxh][maxw];

void addedge(int y1, int x1, int y2, int x2) {
  int u = y1 * w + x1;
  int v = y2 * w + x2;
  flowFinder.add(u + wh, v, 1);
}

void solve(int testcase) {
  printf("Case #%d: ", testcase);
  int blocks;
  scanf("%d %d %d", &w, &h, &blocks);
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) a[y][x] = 0;
  }
  for (int i = 0; i < blocks; ++i) {
    int x0, y0, x1, y1;
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
    for (int y = y0; y <= y1; ++y)
      for (int x = x0; x <= x1; ++x)
        a[y][x] = 1;
  }
  //DB(w); DB(h);
  //for (int y = 0; y < h; ++y) { for (int x = 0; x < w; ++x) DBV(a[y][x]); DBL; } DBL;
  wh = w * h;
  flowFinder.reset(2 * w * h + 2);
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x) {
      if (a[y][x] == 0) {
        flowFinder.add(y * w + x, y * w + x + wh, 1);
        if (y + 1 < h && a[y + 1][x] == 0) {
          addedge(y, x, y + 1, x);
          addedge(y + 1, x, y, x);
        }
        if (x + 1 < w && a[y][x + 1] == 0) {
          addedge(y, x, y, x + 1);
          addedge(y, x + 1, y, x);
        }
      }
    }
  int source = 2 * w * h;
  int sink = 2 * w * h + 1;
  for (int x = 0; x < w; ++x) {
    if (a[0][x] == 0) flowFinder.add(source, x, 1);
    if (a[h - 1][x] == 0) flowFinder.add((h - 1) * w + x + wh, sink, 1);
  }
  int res = flowFinder.flow(source, sink);
  //DB(flowFinder.maxm); DB(flowFinder.m); DB(res); DB(w); DBL;
  assert(res <= w);
  printf("%d\n", res);
}

int main() {
  freopen("C-small-attempt2.in", "r", stdin);
  //freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i)
    solve(i);
  return 0;
}
