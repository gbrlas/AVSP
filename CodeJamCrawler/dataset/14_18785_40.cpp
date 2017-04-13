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

#define MAXM 12

int n,m,ans,mx;
int id[5][MAXM],q[5];
char mat[MAXM][MAXM];
vector<string> v[5];

void solve() {
  int t = 0;
  for (int i=0; i<n; i++) {
    if (!q[i]) return;
    v[i].clear();
    for (int j=0; j<q[i]; j++)
      v[i].push_back(mat[id[i][j]]);
    sort(v[i].begin(),v[i].end());
    for (int j=0; j<int(v[i].size()); j++) {
      t += v[i][j].size();
      if (j) {
        int k = 0;
        while (k<v[i][j-1].size() && k<v[i][j].size() && v[i][j-1][k] == v[i][j][k]) k++;
        t -= k;
      }
    }
    t++;
  }
  
  if (t > mx) { mx = t; ans = 1; }
  else if (t == mx) ans++;
  return;
}

void go(int i) {
  if (i == m) { solve(); return; }
  for (int j=0; j<n; j++) {
    id[j][q[j]++] = i;
    go(i+1);
    q[j]--;
  }
  return;
}

int main() {
  //~ cin.sync_with_stdio(false);
  int nt,nteste=1;
  scanf("%d",&nt);
  while (nt--) {
    scanf("%d%d",&m,&n);
    for (int i=0; i<m; i++)
      scanf(" %s",mat[i]);
    memset(q,0,sizeof(q));
    ans = mx = 0;
    go(0);
    printf("Case #%d: %d %d\n",nteste++,mx,ans);
  }
  
  return 0;
}
