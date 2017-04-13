#include <iostream>
#include <vector>
#include <memory>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <vector>
#include <deque>
#include <list>
using namespace std;

#define bitcount  __builtin_popcount
#define all(x)    x.begin(), x.end()
#define gcd       __gcd

typedef long long lnt;

char v[55];
char mp[55][55];
int mpn[55];
int n, k;

int dx[] = {1,1,1,0,-1,-1,-1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};

char go(int x, int y) {

  for (int di = 0; di < 8; di++) {
    int i;
    for (i = 1; i < k; i++) {
        int xx = x+i*dx[di];
        int yy = y+i*dy[di];
        if (xx < 0 || xx >= n || yy < 0 || yy >= mpn[xx] || mp[x][y] != mp[xx][yy]) {
            break;
        }
    }
    if (i == k) {
        return mp[x][y];
    }
  }
  return 0;
}

int main(void) {
    int ti, t;
    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++) {
        printf("Case #%d: ", ti);

        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%s", v);
            mpn[i] = 0;
            for (int j = n-1; j >= 0; j--) {
                if (v[j] == '.') {
                    continue;
                }
                mp[i][mpn[i]++] = v[j];
            }
            for (int j = mpn[i]; j < n; j++) {
                mp[i][j] = '.';
            }
        }

        bool b=false, e=false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mpn[i]; j++) {
                char r = go(i,j);
                if (r == 'B') b = true;
                if (r == 'R') e = true;
            }
        }

        if (b && e) {printf("Both\n");continue;}
        if (e) {printf("Red\n");continue;}
        if (b) {printf("Blue\n");continue;}
        printf("Neither\n");

    }
    return 48-48;
}
