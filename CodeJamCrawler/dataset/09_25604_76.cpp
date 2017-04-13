#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#define MAXJ 19
using namespace std;
int mat[509][22];
char msg[]="welcome to code jam";
int main(){
  int casos,maxi,i,j,cuenta=1;
  char linea[509];
  scanf("%d\n",&casos);
  while(cuenta<=casos){
   memset(mat,0,sizeof(mat));              
   gets(linea); 
   maxi=strlen(linea);
   for(i=0;i<=maxi;i++)
     mat[i][0]=1;
     
   for(i=1;i<=MAXJ;i++){
     for(j=1;j<=maxi;j++){
       if(linea[j-1]==msg[i-1])
         mat[j][i]=(mat[j][i-1]+mat[j-1][i])%10000;
       else
         mat[j][i]=mat[j-1][i];                      
     }                     
   }
   
   printf("Case #%d: %04d\n",cuenta++,mat[maxi][MAXJ]);
  }
  
    
 return 0;    
}
