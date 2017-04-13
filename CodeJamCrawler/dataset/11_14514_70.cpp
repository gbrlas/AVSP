#include<cstdio>
#include<cstdlib>

using namespace std;

#define B 0
#define O 1

int main(){
  int T, N, i, j;
  int seq[100][3];//robo, botão
  char R;
  int b1, b2;
  int tempo;

  scanf("%d", &T);
  for(i = 1; i <= T; i++){
    scanf("%d", &N);

    for(j = 0; j < N; j++){
      scanf(" %c", &R);
      scanf("%d", &b1);
      if(R == 'B')
	seq[j][0] = B;
      else
	seq[j][0] = O;
      seq[j][1] = b1;
    }
    tempo = 0;
    int pos[]={1,1}, t[] = {0, 0};
    int folga, desloc;

    for(j = 0; j < N; j++){
      folga = (tempo - t[seq[j][0]]);
      desloc = abs(pos[seq[j][0]] - seq[j][1]);
      if(desloc < folga)
	folga = desloc;
      tempo += desloc + 1 - folga;
      t[seq[j][0]] = tempo;
      pos[seq[j][0]] = seq[j][1];

    }
    printf("Case #%d: %d\n", i, tempo);
  }
  return 0;
}
