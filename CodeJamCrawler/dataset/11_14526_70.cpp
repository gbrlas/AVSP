#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int base(char c){
  switch(c){
  case 'A':
    return 0;
  case 'D':
    return 1;
  case 'E':
    return 2;
  case 'F':
    return 3;
  case 'Q':
    return 4;
  case 'R':
    return 5;
  case 'S':
    return 6;
  case 'W':
    return 7;
  }
  if(c == '\n')
    printf("CAGADA!!\n");
  return 8;//colula/linha sempre zeros
}

int main(){
  int T, C, D, N, i, j;
  char form[9][9], oposite[9][9], lista[100];
  char a, b, c;
  int k;
  scanf("%d", &T);
  for(i = 1; i <= T; i++){
    memset(form, 0x00, sizeof(form));
    memset(oposite, 0x00, sizeof(oposite));
    scanf("%d", &C);
    for(j = 0; j < C; j++){
      getchar();
      scanf("%c%c%c", &a, &b, &c);
      a = base(a);
      b = base(b);
      form[a][b] = c;
      form[b][a] = c;
    }
    scanf("%d", &D);
    for(j = 0; j < D; j++){
      getchar();
      scanf("%c%c", &a, &b);
      a = base(a);
      b = base(b);
      oposite[a][b] = 1;
      oposite[b][a] = 1;
    }
    scanf("%d", &N);
    getchar();
    lista[0] = getchar();
    int L, R;//posição do elemento base mais a esquerda e do ultimo a inserir
    L = 0; R = 1;
    for(j = 1; j < N; j++){
      lista[R++] = getchar();
      if(L != R && R != 1){//tem outros elementos base anteriores
	if(form[base(lista[R-1])][base(lista[R-2])]){//combinam
	  lista[R-2] = form[base(lista[R-1])][base(lista[R-2])];
	  R--;
	  for(; base(L) == 9 && L < R; L++);
	}
	else{//verifica se existe um oposto
	  for(k = L; k < R-1 && !(oposite[base(lista[k])][base(lista[R-1])]); k++);
	  if(k != R-1){//existe um oposto
	    L = 0;
	    R = 0;
	    if(j != N-1){
	      lista[R++] = getchar();
	      j++;
	    }
	  }
	}
      }
    }
    //getchar();

    printf("Case #%d: [", i);
    if(R > 0)//pelo menos um elemento
      printf("%c", lista[0]);
    for(j = 1; j < R; j++){
      printf(", %c", lista[j]);
    }
    printf("]\n");
  }
  return 0;
}
