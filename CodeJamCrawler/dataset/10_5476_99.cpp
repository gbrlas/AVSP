#include <stdio.h>

int main() {
  int T, N, K;
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d%d", &N, &K);
//    printf("Case #%d: %s\n", t+1, ((K >> (N-1))&1) ? "ON" : "OFF");
    printf("Case #%d: %s\n", t+1, (K+1) & ((1<<N)-1) ? "OFF" : "ON");
    }                                                             
  return 0;
  }
  