#include<stdio.h>
#include<string.h>
int main()
{
char ora[27]="yhesocvxduiglbkrztnwjpfmaq";
int t,i,j;
scanf("%d",&t);
char a[30][101];
char b[30][101];
gets(a[0]);
for(i=0;i<t;i++)
{
gets(a[i]);
int n=strlen(a[i]);
for(j=0;j<n;j++)
{
if(a[i][j]==' ')
b[i][j]=' ';
else
b[i][j]=ora[(a[i][j])-97];
}
b[i][n]='\0';
}
for(i=0;i<t;i++)
printf("Case #%d: %s\n",(i+1),b[i]);
return 0;
}