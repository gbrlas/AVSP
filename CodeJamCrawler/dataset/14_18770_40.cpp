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

#define MAXN 10010

int v[MAXN];

int main() {
  //~ cin.sync_with_stdio(false);
  int nt,nteste=1,n,x,ans;
  scanf("%d",&nt);
  while (nt--) {
    scanf("%d%d",&n,&x);
    for (int i=0; i<n; i++)
      scanf("%d",&v[i]);
    sort(v,v+n);
    int i,j;
    i = 0; j = n-1; ans = 0;
    while (j>=i) {
      if (j == i) { ans++; break; }
      if (v[j]+v[i] <= x) { ans++; j--; i++; }
      else { ans++; j--; }
    }
    printf("Case #%d: %d\n",nteste++,ans);
  }
  
  return 0;
}
