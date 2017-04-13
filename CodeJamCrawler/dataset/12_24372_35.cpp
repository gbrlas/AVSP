#include<stdio.h>
#include<string.h>
int main(void)
{
int i,t=0,c;
char *A="yhesocvxduiglbkrztnwjpfmaq",in[10000],ch;
scanf("%d%*c",&c,&ch);
while(c--)
{
t++;
scanf("%[^\n]%*c",in,ch);
for(i=0;i<strlen(in);i++)
    if(in[i]!=' ')
        in[i]=A[in[i]-'a'];
printf("Case #%d: %s\n",t,in);

}
return 0;
}
