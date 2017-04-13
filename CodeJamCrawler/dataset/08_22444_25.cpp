#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int i64;

i64 v[1234], r[1234];

int main (){

  i64 t, cases = 1, n;
  scanf("%lld",&t);
  
  while(t--){
    
    scanf("%lld",&n);

    for (int i=0; i<n; i++)
      scanf("%lld",&v[i]);
    for (int i=0; i<n; i++)
      scanf("%lld",&r[i]);

    sort(v, v+n);
    sort(r, r+n);
    
    for (int i=0; i<n/2; i++)
      swap(r[i], r[n-1-i]);

    i64 s = 0;
    for (int i=0; i<n; i++)
      s += v[i] * r[i];
    
    printf("Case #%lld: %lld\n",cases++, s);
  }
  
  return 0;
}
