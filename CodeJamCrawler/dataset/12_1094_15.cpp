#include<stdio.h>
int main()
{
char a[27]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char s[1000],c;
int t,n=1,i,j;
scanf("%d\n",&t);
while(n<=t)
{i=0;
while((c=getchar())!='\n')
{
s[i]=c;
i++;
}
printf("Case #%d: ",n);
for(j=0;j<i;j++)
{
if(s[j]!=' ')
printf("%c",a[s[j]-'a']);
else
printf(" ");
}
printf("\n");
n++;
}
return 0;
}

