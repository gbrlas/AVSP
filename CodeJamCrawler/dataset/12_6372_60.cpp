#include <stdio.h>

int bpow(int a, int k){
  int ans = 1;
  if(k <= 0) return 1;
  for(; k > 0; k >>= 1){
    if(k % 2 != 0) ans *= a;
    a *= a;
  }
  return ans;
}

int digits(int n){
  int ans = 0;
  for(; n != 0; n/=10) ans++;
  return ans;
}

int digit(int n, int k){
  int t = bpow(10, k);
  return (n/t) % 10;
}

int shuf(int n, int k){
  int t = bpow(10, k);
  int T = bpow(10, digits(n)-k);
  return (n % t)*T + n/t;
}

void main(){
  int T, i, j, n, A, B;
  int ms[10];
  scanf("%d", &T);
  for (i=0; i < T; i++){
    int ans = 0;
    scanf("%d %d", &A, &B);
    for(n = A; n <= B; n++){
      //printf("%d: ", n);
      int k = 0, l = 0;
      for(j = 0; j < digits(n)-1; j++){
	if(digit(n, j) == 0) continue;
	int m = shuf(n,j+1);
	if(m > n && m <= B){
	  int ok = 1;
	  for(l = 0; l < k; l++) if(ms[l] == m) ok = 0;
	  if(ok){
	    ms[k++] = m;
	    //printf("%d ", m);
	    ans++;
	  }
	}
      }
      //printf("\n");
    }
    printf("Case #%d: %d\n", i+1, ans);
  }
}
