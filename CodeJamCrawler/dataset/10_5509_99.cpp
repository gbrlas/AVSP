#include <stdio.h>

typedef long long ll;

int main() {
  int T, N, K, R, G[4000];
  
  ll sofar[40000];                   
  int rid[40000];
  
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d%d%d", &R, &K, &N);
    for(int i=0; i<N; i++) scanf("%d", &G[i]);
   
    int at = 0;
    ll tot = 0, got = 0;
    for(int i=0; i<N; i++) tot += G[i];
    
    if(tot <= K) {
      got = R * ll(tot);
      goto skip;
      } 
    
    for(int i=0; i<N; i++) sofar[i] = rid[i] = -1;
    
    for(int r=0; r<R; r++) {
      // printf("%d/%d:%d G%d\n", t, r, at, got);
      if(rid[at] != -1 && ((R - rid[at]) % (r - rid[at]) == 0)) {
        got += ((got-sofar[at]) * ll((R-rid[at]) / (r-rid[at])-1));
        break;
        }
      rid[at] = r; sofar[at] = got;  
      int room = K;
      while(G[at] <= room) { got += G[at]; room -= G[at]; at++; at %= N; }
      }
    
//    printf("Case #%d: %s\n", t+1, ((K >> (N-1))&1) ? "ON" : "OFF");
    skip:
    // got = 1000000; got *= got;
    printf("Case #%d: %lld\n", t+1, got);
    }                                                             
  return 0;
  }      
  