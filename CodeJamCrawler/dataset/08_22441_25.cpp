#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int v[1234], r[1234];

int main (){

  int t, cases = 1, n;
  scanf("%d",&t);
  
  while(t--){
    
    scanf("%d",&n);

    for (int i=0; i<n; i++)
      scanf("%d",&v[i]);
    for (int i=0; i<n; i++)
      scanf("%d",&r[i]);

    sort(v, v+n);
    sort(r, r+n);
    
    for (int i=0; i<n/2; i++)
      swap(r[i], r[n-1-i]);

    int s = 0;
    for (int i=0; i<n; i++)
      s += v[i] * r[i];
    
    printf("Case #%d: %d\n",cases++, s);
  }
  
  return 0;
}
