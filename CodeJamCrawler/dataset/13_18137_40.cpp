#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
int t,count,co,cx;
char d[5][5];
bool vx,vo;
using namespace std;
int main(){
   scanf("%d",&t);
   for (int i=1; i<=t; i++) {
      int count=0; vx=false; vo=false;
     for (int j=0; j<=3; j++) 
     scanf("%s\n",&d[j]);
     
       //  for (int j=0; j<=3; j++) {
       //  for (int k=0; k<=3; k++)
      //   printf("%c",d[j][k]);
       //  printf("\n");
      //   }
         for (int j=0; j<=3; j++)
         for (int k=0; k<=3; k++)
         if (d[j][k]!='.')
         count++;
     
     for (int j=0; j<=3; j++) {    
     co=0; cx=0;
     for (int k=0; k<=3; k++)
     if (d[j][k]=='O')
     co++;
     else if (d[j][k]=='X')
     cx++;
     else if (d[j][k]=='T') {
     co++; cx++;
     }
        if (co==4) vo=true;
        if (cx==4) vx=true;
   //     printf("CO:%d CX:%d\n",co,cx);
     }
     for (int j=0; j<=3; j++) {    
     co=0; cx=0;
     for (int k=0; k<=3; k++)
     if (d[k][j]=='O')
     co++;
     else if (d[k][j]=='X')
     cx++;
     else if (d[k][j]=='T') {
     co++; cx++;
     }
        if (co==4) vo=true;
        if (cx==4) vx=true;
    //    printf("CO:%d CX:%d\n",co,cx);
     }
     co=0; cx=0;
     for (int j=0; j<=3; j++) 
     if (d[j][j]=='O')
     co++;
     else if (d[j][j]=='X')
     cx++;
     else if (d[j][j]=='T') {
     co++; cx++;
     } 
     if (co==4) vo=true;
     if (cx==4) vx=true;
   //  printf("CO:%d CX:%d\n",co,cx);
     co=0; cx=0;
     for (int j=0; j<=3; j++) 
     if (d[3-j][j]=='O')
     co++;
     else if (d[3-j][j]=='X')
     cx++;
     else if (d[3-j][j]=='T') {
     co++; cx++;
     }        
     if (co==4) vo=true;
     if (cx==4) vx=true;
   //  printf("CO:%d CX:%d\n",co,cx);
     if (vx==true) printf("Case #%d: X won\n",i);
     else if (vo==true) printf("Case #%d: O won\n",i);
     else {
         if (count==16) printf("Case #%d: Draw\n",i);
         else printf("Case #%d: Game has not completed\n",i);
     }
   scanf("\n");
  }
//   scanf("\n");
   return 0;
}
