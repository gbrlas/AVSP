// GCJ 2012
// B

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<functional>
using namespace std;

int main() {
  int tc, n, s, p, res;
  int tot[105];
  
  scanf("%d", &tc);
  for(int t = 1; t <= tc; ++t) {
    scanf("%d%d%d", &n, &s, &p);
    for(int i = 0; i < n; ++i)
      scanf("%d", &tot[i]);
    
    sort(tot, tot+n, greater<int>());
    //for(int i = 0; i < n; ++i)
      //printf("%d ", tot[i]);
    //puts("");
    
    res = 0;
    for(int i = 0; i < n; ++i) {
      for(int k = 0; k <= 10; ++k)
        for(int l = 0; l <= 10; ++l)
          for(int m = 0; m <= 10; ++m) {
            if(k+l+m == tot[i]) {
              if(abs(k-l) <= 1 && abs(k-m) <= 1 && abs(l-m) <= 1 && max(k, max(l,m)) >= p) {
                ++res;
                goto next;
              }
            }
          }
      for(int k = 0; k <= 10; ++k)
        for(int l = 0; l <= 10; ++l)
          for(int m = 0; m <= 10; ++m) {
            if(k+l+m == tot[i]) {
              if(abs(k-l) <= 2 && abs(k-m) <= 2 && abs(l-m) <= 2 && max(k, max(l,m)) >= p && s > 0) {
                --s;
                ++res;
                goto next;
              }
            }
          }
      next: 1==1;
    }
    
    /*
    for(int i = 0; i < n; ++i) {
      if(p - tot[i]/3 > 4) { // impossible
        continue;
      } else if(tot[i]/3 >= p) { // no need of surprise
        ++res;
      } else { // check
        int pembagi = tot[i]/3;
        int sisa = tot[i]%3;
        if(pembagi == p-1) {
          if(sisa == 0 && s > 0) { // use surprise
            --s;
            ++res;
          } else {
            ++res;
          }
        } else if(pembagi == p-2) {
          if(sisa == 2 && s > 0) {
             --s;
             ++res;
          } else {
            // impossible
          }
        } else {
          // impossible
        }
      }
    }
    */
    printf("Case #%d: %d\n", t, res);
  }
  
  
  return 0;
}

