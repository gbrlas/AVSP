#include<cstdio>
#include<cstdlib>

using namespace std;

int main(){
  int T, N, i, j;
  long long soma, somax, menor, lido;
  scanf("%d", &T);
  for(i = 1; i <= T; i++){
    soma = 0;
    somax = 0;
    menor = 0x7fffffffffffffff;
    scanf("%d", &N);
    for(j = 0; j < N; j++){
      scanf("%Ld", &lido);
      //      printf("%Ld ", lido);
      if(lido < menor)
	menor = lido;
      soma += lido;
      somax = somax^lido;
    }
    printf("Case #%d: ", i);
    if(somax == 0)
      printf("%Ld\n", soma-menor);
    else
      printf("NO\n");
  }

  return 0;
}
