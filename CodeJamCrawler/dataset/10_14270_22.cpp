#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void solve(int * Pointx, int * Pointy, int N,int i){
  int count=0;
  //int x2,y2;
  for (int j=0;j<N;j++){
    for (int k=j;k<N;k++){
      if ( (Pointx[j]<Pointx[k]) && (Pointy[j]>Pointy[k]) )  {
        count++;
      }
      if ( (Pointx[k]<Pointx[j]) && (Pointy[k]>Pointy[j]) ) {
        count++;
      }
    }
  }

  printf("Case #%d: %d\n",i+1,count);
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
      int Case=0,N;
      if(read=getline(&line, &len, fp)!=-1) Case=atoi(line);
      for (int i=0;i<Case;i++){
        if(read=getline(&line, &len, fp)!=-1) N=atoi(line);
        int Pointx[N],Pointy[N];
        memset(Pointx,0,sizeof(Pointx[0]));
        memset(Pointy,0,sizeof(Pointy[0]));
        for (int j=0;j<N;j++){
          if(read=getline(&line, &len, fp)!=-1){
            buf=strtok(line, " ");
            Pointx[j]=atoi(buf);
            buf = strtok (NULL, " ");
            Pointy[j]=atoi(buf);
          }
        }
      solve(Pointx,Pointy,N,i);
      }
                    if (line)     free(line);
                    exit(EXIT_SUCCESS);
}
