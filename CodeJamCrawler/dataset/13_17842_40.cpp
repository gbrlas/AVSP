#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S 4


char * trans(int i){
  switch(i){
  case 0 :
    return "O won" ;
    break ;
 case 1 :
    return "X won" ;
    break ;
 case 2 :
    return "Draw" ;
    break ;
 case 3 :
    return "Game has not completed" ;
    break ;

  }


  return "KO" ;
}


char* func(int *t){
  


  int i ;
  int j ;
  int tmp1 = 0 ;
  int tmp2 ;
  for(i=0 ; i< S ; i++){
    tmp1 = 0 ;
    tmp2 = 0;
    for(j=0 ; j < S ; j++ ){
      tmp1 += t[i*S+j] ;
      tmp2 += t[j*S+i] ;
    }
    printf("tmp1 = %d tmp2 = %d \n", tmp1 ,tmp2);
    if(tmp1 == 4 || tmp1 == 103 || tmp2 == 4 || tmp2 == 103){
      return trans(0) ;
    }
    if(tmp1 == 40 || tmp1 == 130 || tmp2 == 40 || tmp2 == 130){
      return trans(1) ;
    }
  }
  tmp1 = 0 ;
  tmp2 = 0 ;
  for(i=0 ; i< S ; i++){
    tmp1 +=  t[i*S+i] ;
    tmp2 +=  t[i*S+S-1-i] ;
  }
  printf("tmp1 = %d tmp2 = %d \n", tmp1 ,tmp2);
  if(tmp1 == 4 || tmp1 == 103 || tmp2 == 4 || tmp2 == 103){
    return trans(0) ;
  }
  if(tmp1 == 40 || tmp1 == 130 || tmp2 == 40 || tmp2 == 130){
    return trans(1) ;
  }
  
  

  int c = 0 ;
  for(i=0 ; i< S ; i++){
    for(j=0 ; j < S ; j++){
      if(t[i*S+j] == 0){
	return trans(3);
      }
    }
  }
  return trans(2);

}

int conv(int c){
 switch(c){
  case 'O' :
    return 1 ;
    break ;
 case 'T' :
    return 100 ;
    break ;
 case 'X' :
    return 10 ;
    break ;
 case '.' :
    return 0 ;
    break ;

  }
  
 return -1 ;
}


int main(void){

 
 
  FILE* out = fopen("outputqualif.txt", "w+") ;
  FILE * in = fopen("A-large.in", "r+" );
  int N ;
 
  int i ;
  int j ;
  
  int t[S][S] ;
  fscanf(in, "%d", &N);
  int d = 0 ;
  int c= fgetc(in);

  for(d=0 ; d < N ; d++){
     c = fgetc(in);
   
    for(i=0 ; i< S ; i++){
      for(j=0 ; j < S ; j++){
	printf("(%c)", c);
	t[i][j] = conv(c) ;
	c = fgetc(in);
	
      }
      printf("\n");
      c = fgetc(in);
    }
    for(i=0 ; i< S ; i++){
      for(j=0 ; j < S ; j++){
	printf("%d", t[i][j]);
      }
      printf("\n");
    }
    
    //printf("%s \n", func(t));
    fprintf(out, "Case #%d: %s\n", d+1, func(t));
  }

  


  /* for(i=0 ; i< N ; i++){ */
 

  /*   fscanf(in,"%s %s %s",n,s,d); */
 
  /* } */
  
  /* fprintf(fichier, "Case #%d: %s\n", cas, resf); */
  fclose(out);
  fclose(in);

  return 0 ;

}
