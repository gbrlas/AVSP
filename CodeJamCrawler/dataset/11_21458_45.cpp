#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
 // FILE * output;
 // output=fopen("BotTrust.out","w");
  freopen("output.txt","w",stdout);
  freopen("A-small-attempt0.in","r",stdin);
  int t=0;  
  scanf("%d", &t);
  for (int i=0; i<t; ++i){
      int n;
      scanf("%d", &n);
      int orange[n];
      int blue[n];
      char all[n];
      int contO=0, contB=0;
      for (int j=0; j<n; j++){
          char color;
          int button;
          scanf (" %c %d", &color, &button);
          all[j]=color;
          if (color==79){
             orange[contO]=button;
             contO++;    
          }else{
             blue[contB]=button;
             contB++;
          }
      }

      int oPos=1, bPos=1, oArray=0, bArray=0, time=1;
      for (int j=0; j<n; j++){
          bool pushedO=false, pushedB=false;
          while (!(pushedO||pushedB)){
              if ((all[j]=='O')&&(oPos==orange[oArray])){
                 pushedO=true;
                 oArray++;
              }else if ((all[j]=='B')&&(bPos==blue[bArray])){
                 pushedB=true;
                 bArray++;
              }
              
              if (!pushedO){
                  if (oPos<orange[oArray]){     
                     oPos++;    }
                  else if (oPos>orange[oArray])
                     oPos--;
              }
              if (!pushedB){   
                  if (bPos<blue[bArray])
                     bPos++;    
                  else if (bPos>blue[bArray])
                     bPos--;
              }
              time ++;
          }
        
      }    
  printf("Case #%d: %d\n", i+1, time-1);    
//  fprintf(output,"Case #%d: %d\n", i+1, time-1);     
      
      
  }
  
//  system("PAUSE");
  return 0;
}
