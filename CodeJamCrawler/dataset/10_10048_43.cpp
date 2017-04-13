#include <cstdio>

using namespace std;

int main(void){
  long int k, r, n, p, g, total, embarcados;
  long int grupos[1001];
  int i, j, t;
  /*k pessoas de cada vez
    r vezes por dia
    t casos de teste
    n grupos por teste
  */

  scanf("%d", &t);

  for(i = 1; i <= t; i++){
    scanf("%li %li %li", &r, &k, &n);
    for(g = 0; g < n; g++){
      scanf("%li", &(grupos[g]));
    }
    g = 0;
    total = 0;
    for(j = 1; j <= r; j++){
      p = 0;
      embarcados = 0;
      while((embarcados < n) && (grupos[g] <= k-p)){
	p += grupos[g];
	g = (g + 1) % n;
	embarcados++;
      }
      total += p;
    }
    printf("Case #%li: %li\n", i, total);
  }

  return 0;
}
