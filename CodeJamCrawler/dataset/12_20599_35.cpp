#include<stdio.h>
#include<string.h>
char a[110],t;
int l[35];
int main(){
  int i,n,t,c;
    l[0]=121; l[1]=104; l[2]=101; l[3]=115; l[4]=111; l[5]=99; l[6]=118 ; l[7]=120; l[8]=100; l[9]=117;
    l[10]=105; l[11]=103; l[12]=108; l[13]=98; l[14]=107; l[15]=114; l[16]=122; l[17]=116; l[18]=110; l[19]=119;
    l[20]=106; l[21]=112; l[22]=102; l[23]=109; l[24]=97; l[25]=113;
    scanf("%d%c",&n,&t);
    c=1;
    while(c<=n){
      gets(a);
      t=strlen(a);
      printf("Case #%d: ",c);
      for(i=0;i<t;i++){
        if(a[i]!=' ') printf("%c",l[a[i]-'a']);
        else printf(" ");
      }
      printf("\n");
      memset (a,'NUL',t);
      c++;
    }
  return 0;
}
