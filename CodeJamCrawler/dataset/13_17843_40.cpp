#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define S 4


/* char* func(int *t){ */
  
/*   return 'c' ; */

/* } */

int is_digit(char c){
  if((c >= 48 && c<= 57)){
    return 1 ;
  }
  return 0 ;
}

int is_palin(int n){
  int i ;
  int tmp = n ;
  int taille = 1 ;
  int puiss = 1 ;
  while(tmp/10 > 0){
    taille++ ;
    puiss *= 10 ; 
    tmp /= 10 ;
  }
  // printf("taille = %d, puiss = %d \n", taille, puiss);
  int puiss2 = 1 ;
  for(i=0 ; i< taille/2 ; i++){
    if(n/puiss != n%10){
      return 0;
    }

     n = n%puiss ;
    n /= 10 ;
    puiss /=100 ;
    // printf("n = %d \n", n);

  }

  return 1 ;
}

void func(int a, int b, FILE* out, int cas){

  int size = b+1 ;
  int *t  = malloc(size*sizeof(int));

  int i ;
  for(i= 0 ; i < size ; i++){
    t[i] = is_palin(i) ;
  }
  // si oui ou non c'est un palin
  int nb = 0 ;
  printf("size = %d \n", (b-a+1) );
  int sq ;
  for(i= a ; i < size ; i++){
    sq = (int)sqrt(i) ;
    //yprintf("sq =%d t[i] %d", sq, t[i]);
    if(t[i] == 1 &&  sq*sq == i && t[sq] == 1){
      printf("i+a = %d %d \n", i+a, (int)sqrt(i+a)*(int)sqrt(i+a));
      nb++ ;
    }
  }
  //  printf("nb = %d \n", nb);
  fprintf(out, "Case #%d: %d\n",cas, nb);
}


int main(void){

 
 
  FILE* out = fopen("outputqualifC.txt", "w+") ;
  FILE* in = fopen("C-small-attempt1.in", "r" );
  int T = 103 ;
 
  int i = 0;
  int a,b  ;

  fscanf(in, "%d", &T);
  printf("T = %d \n", T);
  for(i= 0 ; i < 100 ; i++){
    fscanf(in, "%d %d", &a, &b);
    printf("a b %d %d \n", a,b);
    func(a,b, out, i+1);
  }

  int d = 0 ;
 
  /* for(i= 0 ; i < 1000; i++){ */
  /*   printf("%d %d \n", i, is_palin(i)); */
  /* } */
  /* printf("T = %d \n", T); */



  //func(4,4, out, 200);

  fclose(out);
  fclose(in);

  return 0 ;

}
