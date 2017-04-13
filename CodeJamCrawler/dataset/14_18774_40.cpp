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

#define MAXN 12

int help[MAXN];
int n,v[MAXN],ans,pos,vv[MAXN],h[MAXN];
int id[2][MAXN],q[2],sz[2];
bool us[MAXN];

void solve() {
  int k = 0;
  //~ printf("pos %d sz %d q %d--------\n",pos,sz[0],q[0]);
  if (q[0] != sz[0]) return;
  memset(us,false,sizeof(us));
  for (int i=0; i<1; i++) {
    if (q[i] != sz[i]) return;
    for (int j=0; j<q[i]; j++) {
      if (k == pos) k++;
      vv[k++] = v[id[i][j]];
      //~ printf("%d ",v[id[i][j]]);
      us[id[i][j]] = true;
    }
  }
  //~ printf("\n");
  us[n-1] = true;
  for (int i=n-2; i>=0; i--)
    if (!us[i]) {
      if (k == pos) k++;
      vv[k++] = v[i];
    }
  
  
  for (int i=0; i<n; i++)
    h[i] = help[i];
  
  /*printf("vv: ");
  for (int i=0; i<n; i++)
    printf("%d ",vv[i]);
  printf("\n");*/
  
  int t = 0;
  for (int i=0; i<n; i++) {
    int x = vv[i];
    for (int j=0; j<n; j++)
      if (h[j] == x) {
        while (j != i) {
          j--;
          swap(h[j],h[j+1]);
          t++;
        }
        break;
      }
  }
  
  if (ans > t) ans = t;
  return;
}

void go(int i) {
  if (i == n-1) { solve(); return; }
  for (int j=0; j<2; j++) {
    if (q[j] < sz[j]) {
      id[j][q[j]++] = i;
      go(i+1);
      q[j]--;
    }
  }
  return;
}

int main() {
  //~ cin.sync_with_stdio(false);
  int nt,nteste=1;
  scanf("%d",&nt);
  while (nt--) {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
      scanf("%d",&v[i]);
      help[i] = v[i];
    }
    ans = INF;
    sort(v,v+n);
    for (pos=0; pos<n; pos++) {
      vv[pos] = v[n-1];
      q[0] = q[1] = 0;
      sz[0] = pos; sz[1] = n-1-pos;
      go(0);
    }
    printf("Case #%d: %d\n",nteste++,ans);
  }
  
  return 0;
}
