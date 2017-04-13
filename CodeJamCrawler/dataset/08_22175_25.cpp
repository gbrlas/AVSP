#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

char buff[100000];
char tmp[100000];
int k, len, perm[100];

void permutate() {
  for(int i=0; i<len; i+=k) {
    for(int j=0; j<k; j++) tmp[perm[j] + i] = buff[j+i];
  }
}


int main() {
  int  tcase;
  scanf("%d", &tcase);
  for(int zz =0 ; zz<tcase; zz++) {
    scanf("%d%s", &k, buff);
    len = strlen(buff);
    int best = len + 100;
    for(int i=0; i<k; i++) perm[i] = i;
    do {
      permutate();
      int ans = 1;
      for(int i=1; i<len; i++) if(tmp[i]!=tmp[i-1]) ans++;
      best = min(best, ans);
    } while(next_permutation(perm, perm+k)) ;
    printf("Case #%d: %d\n", zz+1, best);
  }
}
