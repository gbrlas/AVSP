#include <stdio.h>
#include <stdlib.h>

void convert(char [],char [],int );

void convert(char initial[100],char output[100],int counter){

  int i=0;
  for(i=0; i<=counter; i++){
    switch ( initial[i]){
    case 'a':
      output[i]='y';
      break;
case 'b':
      output[i]='h';
      break;
case 'c':
      output[i]='e';
      break;
case 'd':
      output[i]='s';
      break;
case 'e':
      output[i]='o';
      break;
case 'f':
      output[i]='c';
      break;
case 'g':
      output[i]='v';
      break;
case 'h':
      output[i]='x';
      break;
case 'i':
      output[i]='d';
      break;
case 'j':
      output[i]='u';
      break;
case 'k':
      output[i]='i';
      break;
case 'l':
      output[i]='g';
      break;
case 'm':
      output[i]='l';
      break;
case 'n':
      output[i]='b';
      break;
case 'o':
      output[i]='k';
      break;
case 'p':
      output[i]='r';
      break;
case 'q':
      output[i]='z';
      break;
case 'r':
      output[i]='t';
      break;
case 's':
      output[i]='n';
      break;
case 't':
      output[i]='w';
      break;
case 'u':
      output[i]='j';
      break;
case 'v':
      output[i]='p';
      break;
case 'w':
      output[i]='f';
      break;
case 'x':
      output[i]='m';
      break;
case 'y':
      output[i]='a';
      break;
case 'z':
      output[i]='q';
      break;
    default:
      output[i]=' ';
      break;
    }
  }
  return;
}

void main(){
  int i,j,k,times;  
  char current,size,initial[100],output[100];
 
scanf("%d\n",&times);
 k=0;
 for(k=0;k<=times;k++){
  i=0;
  size=0;
  do{
    scanf("%c",&current);
    
    if(current!='\n'){
      initial[i]=current;
    i++;
    }

  }while(current!='\n');
  size=i-1;
   
 convert(initial,output,size);
 printf("Case #%d: ",k+1);
 for(j=0;j<=size; j++){
   printf("%c",output[j]);
  }
 printf("\n");

 }
}

