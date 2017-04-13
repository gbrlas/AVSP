#include <cstdio>

using namespace std;

int main(void){
  int i, t, n, k, aux;

  scanf("%d", &t);
  for(i = 1; i <= t; i++){
    aux = 1;
    scanf("%d%d", &n, &k);
    aux = aux << n;
    printf("Case #%d: ", i);
    if((k != 0) && ((k+1)%aux == 0))
      printf("ON\n");
    else
      printf("OFF\n");
  }

  return 0;
}
