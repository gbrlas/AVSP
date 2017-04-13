#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 20000
#define INF 25000

int change[MAXN];
int gate[MAXN];
int pd[MAXN][2];
int valor[MAXN];
int n;

int calc (int x, int val){

  if (x > (n-1)/2){
    if (valor[x] == val) return 0;
    else return INF;
  }

  if (pd[x][val] != -1) return pd[x][val];

  int resp = INF;
  int resp2 = INF;

  if (gate[x] == 1){ //AND

    if (val == 0)
      resp = min(calc(2*x, 0) + min(calc(2*x+1, 0), calc(2*x+1, 1)),
		 calc(2*x+1, 0) + min(calc(2*x, 0), calc(2*x, 1)));
    else
      resp = calc(2*x, 1) + calc(2*x+1, 1);
  }
  else { //OR

    if (val == 1)
      resp = min(calc(2*x, 1) + min(calc(2*x+1, 0), calc(2*x+1, 1)),
		 calc(2*x+1, 1) + min(calc(2*x, 0), calc(2*x, 1)));
    else
      resp = calc(2*x, 0) + calc(2*x+1, 0);

  }

  if (change[x] == 1){

    if (gate[x] == 0){ //AND
      if (val == 0)
	resp2 = min(calc(2*x, 0) + min(calc(2*x+1, 0), calc(2*x+1, 1)),
		   calc(2*x+1, 0) + min(calc(2*x, 0), calc(2*x, 1)));
      else
	resp2 = calc(2*x, 1) + calc(2*x+1, 1);
    }
    else { //OR
      if (val == 1)
	resp2 = min(calc(2*x, 1) + min(calc(2*x+1, 0), calc(2*x+1, 1)),
		   calc(2*x+1, 1) + min(calc(2*x, 0), calc(2*x, 1)));
      else
	resp2 = calc(2*x, 0) + calc(2*x+1, 0);
    }
  }
  pd[x][val] = min(resp, resp2+1);
  return pd[x][val];
}

int main (){

  int t, v, cases = 1;
  scanf("%d",&t);

  while(t--){

    scanf("%d %d",&n, &v);

    memset(pd,-1, sizeof(pd));
    
    for(int i=1; i<=(n-1)/2; i++){
      scanf("%d %d",&gate[i], &change[i]);
    } 
    for (int i=1; i<=(n+1)/2; i++){
      scanf("%d",&valor[i + (n-1)/2]);
    }

    int ans = calc(1,v);

    printf("Case #%d: ",cases++);
    if (ans >= INF)
      printf("IMPOSSIBLE\n");
    else
      printf("%d\n",ans);

  }
  
  return 0;
}
