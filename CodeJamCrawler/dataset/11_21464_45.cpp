#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
  freopen("outputBLarge.txt","w",stdout);
  freopen("B-large.in","r",stdin);
  int t=0;  
  scanf("%d", &t);
  for (int i=0; i<t; ++i){
      int c;
      scanf("%d", &c);
      char combine[91][91];
      for (int o=0; o<91; ++o)
          for(int p=0; p<91; ++p)
              combine[o][p]=0;
      char aux1, aux2, aux3;
      for (int j=0; j<c; ++j){
         scanf(" %c%c%c", &aux1, &aux2, &aux3);         
         combine[aux1][aux2]=aux3; 
         combine[aux2][aux1]=aux3; 
      }
      int d;
      scanf("%d", &d);
      int opposed[91][91];
      for (int o=0; o<91; ++o)
          for(int p=0; p<91; ++p)
              opposed[o][p]=0;  
      for (int j=0; j<d; ++j){
          scanf(" %c%c", &aux1, &aux2);    
          opposed[aux1][aux2]=1;
          opposed[aux2][aux1]=1;
      }
      int n;
      scanf("%d ", &n);
      int contInv=-1;
      char invocations[100];
      for (int j=0; j<n; ++j){
          contInv++;
          scanf("%c", &invocations[contInv]);
          bool stop=false;
          while((contInv>0)&&(!stop)){
              if (combine[invocations[contInv]][invocations[contInv-1]]!=0){
//printf("combinar %c %c me da %c\n",invocations[contInv], invocations[contInv-1],combine[invocations[contInv]][invocations[contInv-1]]); 
                  invocations[contInv-1]=combine[invocations[contInv]][invocations[contInv-1]];
                  invocations[contInv]=0;
//printf("invocations[%d]= %c", contInv-1,invocations[contInv-1]);
                  contInv--;                                                              
              }else
                   stop=true;
          }    
          for (int z=0; z<contInv; ++z){
              if (opposed[invocations[z]][invocations[contInv]]==1){        
//printf("opuestos %c %c\n",invocations[z], invocations[contInv]); 
                  for(int y=0; y<=contInv; ++y){
                      invocations[y]=0;        
                  }
                  contInv=-1;
              }
          }                         
      }
      
         
      printf("Case #%d: [", i+1);
      if (contInv>=0)
         printf("%c", invocations[0]);
      for (int z=1; z<=contInv; z++)
         printf(", %c", invocations[z]); 
      printf("]\n");    
    
  }
  
//  system("PAUSE");
  return 0;
}
