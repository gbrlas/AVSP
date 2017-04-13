#include <stdio.h>

void ordena(int horario[100], int n){
  int i, j, t;
  for(i=n;i>0;i--){
    for(j=1;j<i;j++){
      if(horario[j-1]>horario[j]){
	t=horario[j-1];
	horario[j-1]=horario[j];
	horario[j]=t;
      }
    }
  }
}

int menor_rec(int v1, int v2){
  if(v1==-1) return v2;
  if(v2==-1) return v1;
  if(v1<v2) return v1;
  else return v2;
}

int menor(int v1, int v2, int v3, int v4){
  int x;
  x=menor_rec(menor_rec(v1, v2), menor_rec(v3, v4));
  if(x==-1) return 5;
  if(x==v2) return 2;
  if(x==v4) return 4;
  if(x==v1) return 1;
  if(x==v3) return 3;
}

int main(){
  int n, i, chega_a[101], sai_a[101], chega_b[101], sai_b[101], p;
  int hora, min, tempo, na, nb, tot_a, tot_b, as, ac, bs, bc, ema, emb;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &tempo);
    scanf("%d %d", &na, &nb);
    for(p=0;p<na;p++){
      scanf("%d:%d", &hora, &min);
      sai_a[p]=hora*60+min;
      scanf("%d:%d", &hora, &min);
      chega_b[p]=hora*60+min+tempo;
    }
    sai_a[p]=-1;
    chega_b[p]=-1;
    ordena(sai_a, na);
    ordena(chega_b, na);
    for(p=0;p<nb;p++){
      scanf("%d:%d", &hora, &min);
      sai_b[p]=hora*60+min;
      scanf("%d:%d", &hora, &min);
      chega_a[p]=hora*60+min+tempo;
    }
    sai_b[p]=-1;
    chega_a[p]=-1;
    ordena(sai_b, nb);
    ordena(chega_a, nb);
    
    tot_a=tot_b=as=ac=bs=bc=ema=emb=0;
    p=1;
    while(p){
      tempo=menor(sai_a[as], chega_b[bc], sai_b[bs], chega_a[ac]);
      switch (tempo){
      case 1:
	//SAI DE A
	if(ema==0) {ema++; tot_a++;}
	ema--;
	as++;
	//if(as==na) sai_a[as]=-1;
	break;
      case 2:
	//CHEGA EM B
	emb++;
	bc++;
	//if(bc==na) chega_b[bc]=-1;
	break;
      case 3:
	//SAI DE B
	if(emb==0) {emb++; tot_b++;}
	emb--;
	bs++;
	//if(bs==nb) sai_b[bs]=-1;
	break;
      case 4:
	//CHEGA EM A
	ema++;
	ac++;
	//if(ac==nb) chega_a[ac]=-1;
	break;
      case 5:
	//TODOS COM -1
	p=0;
      }
    }
    printf("Case #%d: %d %d\n", i+1, tot_a, tot_b);
  }
  return 0;
}
