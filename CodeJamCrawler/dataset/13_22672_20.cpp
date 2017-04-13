#include<stdio.h>
int main(){
    char a[4][4],check;
    int i,j,t,countxr,countor,counttr;
    int k,countxc,countoc,counttc;
    int counttdf,countxdf,countodf;
    int counttdb,countxdb,countodb;
    int countdot;
    int test;
    scanf("%d",&t);
    for(test=0;test<t;test++) {
    scanf(" ");
    for(i=0;i<4;i++){
        gets(a[i]);
    }
    printf("Case #%d: ",test+1);
   for(i=0;i<4;i++){
      countxr=countor=counttr=0;
      countxc=countoc=counttc=0;
      countdot=0;
      for(j=0;j<4;j++) {
         if(a[i][j]=='T') counttr++;
         else if(a[i][j]=='X' && countor==0){check=a[i][j]; countxr++;}
         else if(a[i][j]=='O' && countxr==0) {check=a[i][j]; countor++;}
         if(a[i][j]=='.') countdot=1;
      }
      if(check=='X' && (countxr+counttr)==4) {printf("X won\n");break;}
      else if(check=='O' && (countor+counttr)==4){ printf("O won\n");break;}
       
      for(k=0;k<4;k++){
         if(a[k][i]=='T')counttc++;
         else if(a[k][i]=='X' && countoc==0){check=a[k][i]; countxc++;}
         else if(a[k][i]=='O' && countxc==0) {check=a[k][i]; countoc++;}
      }
      if(check=='X' && (countxc+counttc)==4) {printf("X won\n");break;}
      else if(check=='O' && (countoc+counttc)==4){ printf("O won\n");break;}      
      
   }
   if((countoc+counttc)!=4  && (countxc+counttc)!=4 &&  (countxr+counttr)!=4  && (countor+counttr)!=4 ) {
       counttdf=countxdf=countodf=0;
       counttdb=countxdb=countodb=0;
       for(i=0;i<4;i++) {
          if(a[i][i]=='T')counttdf++;
          else if(a[i][i] =='X' && countodf ==0)countxdf++;
          else if(a[i][i] =='O' && countxdf ==0) countodf++;
       }
       for(i=0;i<4;i++) {
          if(a[i][3-i]=='T')counttdb++;
          else if(a[i][3-i] =='X' && countodb ==0)countxdb++;
          else if(a[i][3-i] =='O' && countxdb ==0) countodb++;
       }
//      printf("Tf=%d Of=%d  Xf=%d\n",counttdf,countodf,countxdf);
  //     printf("Tb=%d Ob=%d  Xb=%d\n",counttdb,countxdb,countodb);
       if((counttdf+countxdf)==4 || (counttdb+countxdb)==4) printf("X won\n");
       else if((counttdf+countodf)==4 || (counttdb+countodb)==4) printf("O won\n");
       else if(countdot==1) printf("Game has not completed\n");
       else printf("Draw\n");
   }
   }
   getch();
}
