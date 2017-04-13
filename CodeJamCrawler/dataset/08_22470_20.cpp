#include <stdio.h>
#include <iostream>

using namespace std;

int pd[1500][12], w, h;
char b[12][12];

int eval(int bm, int d){

  for (int j=0; j<w; j++)
    if (bm & (1 << j) && b[d][j] == 'x') return 0;
  for (int j=1; j<w-1; j++)
    if ((bm & (1 << j)) && ((bm & (1 << (j+1))) || (bm & (1 << (j-1)))))
      return 0;

  if (d == 0) return __builtin_popcount(bm);

  if (pd[bm][d] != -1) return pd[bm][d];

  int ans = 0;
  //Escolhe os filhos
  for (int i=0; i<(1<<w); i++){
    
    int filho = i;
    for (int j=0; j<w; j++)
      if ((1 << j) & bm){
	if (j < w-1)
	  filho &= ~(1 << j+1);
	if (j > 0)
	  filho &= ~(1 << j-1);
      }
    ans = max(ans,eval(filho, d-1));
  }
  pd[bm][d] = ans +  __builtin_popcount(bm);
  return pd[bm][d];
}

int main (){

  int t,cases=1;
  scanf("%d",&t);
  
  while(t--){

    scanf("%d %d",&h,&w);

    for (int i=0; i<h; i++)
      scanf("%s",b[i]);

    memset(pd,-1,sizeof(pd));

    int ans = 0;
    for (int i=0; i<(1 << w); i++)
      ans = max(ans,eval(i, h-1));

    printf("Case #%d: %d\n",cases++,ans);
  }

  return 0;
}
