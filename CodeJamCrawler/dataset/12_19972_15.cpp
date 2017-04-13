#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
   char G[3001] = {0};
   char Ga[101] = {0};
   char lineCount[31] = {0};
   char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
   char beta[26] =  {'y','n','f','i','c','w','l','b','k','u','o','m','x','s','e','v','z','p','d','r','j','g','t','h','a','q'};
   int T = 0;
   int i = 0;
   int dumb;
   int x = 0;
   int y = 0;
   int z = 0;
   int zz = 0;
   
   
   //while (fscanf(fp, "%d,%d\n", &i, &isquared) == 2)
     //    printf("i: %d,  isquared: %d\n", i, isquared);
         
         
FILE *fp;
//fp = fopen("output.txt", "w");
//fprintf(fp,"30");
//f
//fclose(fp);
fp = fopen("A-small-attempt5.in", "r");
 //if (fp == NULL) {
 //        printf("I couldn't open results.dat for reading.\n");
  //       exit(0);
  //    }
fscanf(fp, "%d\n", &T);

//printf("%d",T);
//scanf("%d",&i);
//printf("%d",T);
//scanf("%d",&i);

   //scanf("%d",&T);
   fflush(stdin);
   for(i = 0; i < T; i++) {
      //printf("enter: \n");
      //while
      fscanf(fp,"%[^\n]\n",&Ga);
      fflush(stdin);
      //printf("\nyou entered: %s\n",Ga);
      lineCount[i] = strlen(Ga);
      strcat(G,Ga);
      //printf("%s",Ga);
      //printf("length of G: %d : %d\nG: %s",strlen(G),strlen(G),G);
   }
   fclose(fp);
  // printf("%s",G);
   fflush(stdin);
  // scanf("%d",&dumb); 
    
   ///////////
   //convert beta --> alpha
   fp = fopen("output.txt", "w");
      int j = 0;
      for(j = 0; j < strlen(G); j++) {
            //printf("j: %d",j);
            //search beta for G[j]
            if (j == 0) {
                  fprintf(fp,"Case #%d: ",x+1);
            } 
            //% (y + lineCount[x]) == 0){printf("Case #%d: ",x+1);}
            int k = 0;
            int foundNum = 0;         
            for(k = 0; k < 26;k++) {
               //printf("\nk: %d\nG[j]: %c\nbeta[k]: %c\n",k,G[j],beta[k]);   
               if(G[j] == beta[k]) {
                 // printf("found it: G[j]: %c beta[k]: %c\nalpha[k]: %c\n",G[j],beta[k],alpha[k]);                
                  foundNum = k;             
               } else if(G[j] == ' ') {
                  foundNum = 30;
               }
            }
           // printf("k: %d\nalpha[k]: %c\n",foundNum,alpha[foundNum]);
           if(foundNum != 30) {
              fprintf(fp,"%c",alpha[foundNum]);
           } else {
              fprintf(fp," ");
           }
           // scanf("%d",&dumb);
            //char stringPlus = alpha[foundNum];
            //printf("%c",alpha[foundNum]);
            //int dumb1 = 0;
            //scanf("%d",&dumb); 
            if (j  == y + (lineCount[x] - 1) && x != T - 1 ) {
                  fprintf(fp,"\n");
                  y = y + lineCount[x];
                  x = x + 1;
                  fprintf(fp,"Case #%d: ",x+1);
                  //printf("%d",j);
                  //printf("%d",y - lineCount[x-1]);
                  
            }
      }
      fflush(stdin);
         fclose(fp);
      
      fflush(stdin);
    //scanf("%d",&zz); 
 


     
    
    
    
    
    
    
 return 0;
    
}
