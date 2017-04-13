#include <stdio.h>
#include <iostream>

using namespace std;

#define MAXN 1000
#define X 10007

int pd[MAXN][MAXN], h, w, n;

int conta(int i, int j){

  if (i >= h || j >= w) return 0;

  if (pd[i][j] != -1) return pd[i][j];
  
  int ans = 0;
  ans = conta(i+1, j+2)%X + conta(i+2, j+1)%X;
  
  pd[i][j] = ans%X;
  return pd[i][j];
}

int main (){
  
  int t,cases=1;
  scanf("%d",&t);

  while (t--){

    scanf("%d %d %d",&h, &w, &n);
    
    memset(pd,-1,sizeof(pd));

    pd[h-1][w-1] = 1;
    for (int i=0; i<n; i++){
      int a, b;
      scanf("%d %d",&a, &b);
      pd[a-1][b-1] = 0;
    }

    printf("Case #%d: ",cases++);
    printf("%d\n",conta (0,0)); 
  }
  
  return 0;
}
