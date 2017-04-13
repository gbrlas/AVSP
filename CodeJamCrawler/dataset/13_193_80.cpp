#include<stdio.h>
const int OS=0;
const int XS=1;
const int DS=2;
const int NS=3;
int solve(char (*s)[5]){
int oc,xc,dc,tc;
oc=0;xc=0;dc=0;tc=0;
for(int i=0;i<4;i++)
if(s[i][i]=='O')oc++;
else if(s[i][i]=='X')xc++;
else if(s[i][i]=='.')dc++;
else tc++;
if(oc==4||oc==3&&tc)
return OS;
if(xc==4||xc==3&&tc)
return XS;
oc=0;xc=0;dc=0;tc=0;
for(int i=0;i<4;i++)
if(s[i][3-i]=='O')oc++;
else if(s[i][3-i]=='X')xc++;
else if(s[i][3-i]=='.')dc++;
else tc++;
if(oc==4||oc==3&&tc)
return OS;
if(xc==4||xc==3&&tc)
return XS;
int dots=0;
for(int i=0;i<4;i++){
oc=0;xc=0;dc=0;tc=0;
for(int j=0;j<4;j++)
if(s[i][j]=='O')oc++;
else if(s[i][j]=='X')xc++;
else if(s[i][j]=='.')dc++;
else tc++;
if(oc==4||oc==3&&tc)
return OS;
if(xc==4||xc==3&&tc)
return XS;
dots+=dc;
}
for(int i=0;i<4;i++){
oc=0;xc=0;dc=0;tc=0;
for(int j=0;j<4;j++)
if(s[j][i]=='O')oc++;
else if(s[j][i]=='X')xc++;
else if(s[j][i]=='.')dc++;
else tc++;
if(oc==4||oc==3&&tc)
return OS;
if(xc==4||xc==3&&tc)
return XS;
}
if(dots)return NS;
return DS;
}
int main(){
int t;
char s[5][5];
scanf("%d",&t);
int test=1;
char newline;
scanf("%c",&newline);
while(t--){
for(int i=0;i<4;i++){
for(int j=0;j<4;j++)
scanf("%c",&s[i][j]);
scanf("%c",&newline);
}
printf("Case #%d: ",test++);
switch(solve(s)){
case 0:printf("O won\n");break;
case 1:printf("X won\n");break;
case 2:printf("Draw\n");break;
default:printf("Game has not completed\n");
}
scanf("%c",&newline);
}
return 0;
}
