#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void SC(unsigned int a,unsigned int b, int i){
  //printf("a: %d,b: %d",a,b);
  printf("Case #%d: ",1+i);
  if (a>b){
    printf("OFF\n");
    return;
  };
  if((b+1)%(1<<a)==0) {
    printf("ON\n");
    return;
  };
printf("OFF\n");
}
int main( int argc, char *argv[] ){
  if(argc<2){
    printf("Need a file\n");
    return 0;
  }
    FILE * fp;
    char * line = NULL;
    char * buf = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
      exit(EXIT_FAILURE);
    unsigned int Case=0,a,b;
    if(read=getline(&line, &len, fp)!=-1) Case=atoi(line);
    for (int i=0;i<Case;i++){
      if(read=getline(&line, &len, fp)!=-1){
        buf=strtok(line, " ");
        a=atoi(buf);
        buf = strtok (NULL, " ");
        b=atoi(buf);
        SC(a,b,i);
      }
    }
      if (line)     free(line);
      exit(EXIT_SUCCESS);
}

