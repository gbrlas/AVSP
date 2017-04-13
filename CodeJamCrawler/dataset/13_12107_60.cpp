#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long int
#define MAXP 15
#define MAXB 100000000000000LL
#define MAXN 110

using namespace std;
int main(){
  int M[MAXN][MAXN];
  int maxCol[MAXN];
  int maxLin[MAXN];
  int i,j,k;
  int T;
  int n,m;
  scanf("%d",&T);
  
  for(k = 0; k < T; k++){
    scanf("%d %d",&n,&m);
    
    memset(maxLin, 0, sizeof(maxLin));
    memset(maxCol, 0, sizeof(maxCol));    
    for(i = 0; i < n; i++)
      for(j = 0; j < m; j++){
        scanf("%d", &M[i][j]);
        maxLin[i] = max(maxLin[i], M[i][j]);
        maxCol[j] = max(maxCol[j], M[i][j]);     
    }
    
    bool can = true;
    for(i = 0; i < n; i++)
      for(j = 0; j < m; j++){
        if(M[i][j] < maxLin[i] && M[i][j] < maxCol[j])
          can = false;
      }
    printf("Case #%d: ",k + 1);
    if(can)
      printf("YES\n");
    else
      printf("NO\n");
    
  }


  return 0;
}
