#include <stdio.h>

int min(int a, int b){
  return (a > b ? b : a);
}

void main(){
  int T, i, j, N, p, S, t;
  scanf("%d", &T);
  for (i=0; i < T; i++){
    scanf("%d %d %d", &N, &S, &p);
    int A = 0;
    int B = 0;
    for(j = 0; j < N; j++){ 
      scanf(" %d", &t);
      if(p == 1){
	if(t > 0) A++;
      }
      else{
	if(t >= 3*p - 2) A++;
	else if(t >= 3*p - 4) B++;
      }
    }
    
    printf("Case #%d: %d\n", i+1, (A + (B > S ? S : B)));
  }
}
