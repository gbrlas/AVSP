#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<inttypes.h>
#include <wchar.h>
void TP(unsigned long S[],int R,int K, int N, int i){
  //R run time
  //N people
  //K seats
int start=0;
uint64_t  Euros=0;
int sum=0;
int Ssum=0;
int count;
//sum
for (int i=0;i<N;i++){
Ssum+=S[i];
}
if (Ssum<=K){ Euros=R*Ssum;}
else {
for (int i=0;i<R;i++){
  sum=0;
  count=0;
  for (int j=start;;j++){
    j=j%N;
    if(count==N) {
      start=0;
      break;
    };
    sum+=S[j];
    if (sum==K){
      Euros+=sum;
      start=j+1;
      break;
    }
    if (sum>K){
      Euros+=sum;
     Euros-=S[j];
     start=j;
     break;
    }
        count++;

    
  }
}
}
     printf("Case #%d: ",i+1);
     printf("%" SCNu64 "\n",Euros);

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
    int Case=0,N=0;
    unsigned long R=0, K=0;
    if(read=getline(&line, &len, fp)!=-1) Case=atoi(strtok(line, " "));
    for (int i=0;i<Case;i++){
      if(read=getline(&line, &len, fp)!=-1){//get a line
        buf=strtok(line, " ");
        if (buf != NULL) R=atoi(buf);
        //initial array
              buf = strtok (NULL, " ");
              if (buf != NULL) K=atoi(buf);
              buf = strtok (NULL, " ");
              if (buf != NULL) N=atoi(buf);
              unsigned long S[N];
              memset(S,0,sizeof(S[0]));
              if(read=getline(&line, &len, fp)!=-1){
                buf=strtok(line, " ");
                int j=0;
              while (buf != NULL)
              {
                S[j]=atoi(buf);
                j++;
                buf = strtok (NULL, " ");
              }
              }
     TP(S, R, K,N,i);
    }
      printf("\n");
}
if (line)     free(line);
exit(EXIT_SUCCESS);

}

